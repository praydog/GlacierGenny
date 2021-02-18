#include <filesystem>
#include <iostream>

#include <windows.h>

#include "utility/RTTI.hpp"
#include "utility/Scan.hpp"

#include "Genny.hpp"
#include "sdk/Pool.hpp"
#include "sdk/TypeRegistry.hpp"

std::unordered_set<std::string> g_class_set{};

std::vector<std::string> split(const std::string& s, const std::string& token) {
    std::vector<std::string> out{};

    size_t prev = 0;
    for (auto i = s.find(token); i != std::string::npos; i = s.find(token, i + 1)) {
        out.emplace_back(s.substr(prev, i - prev));
        prev = i + 1;
    }

    out.emplace_back(s.substr(prev, std::string::npos));

    return out;
}

genny::Class* class_from_name(genny::Namespace* g, const std::string& class_name) {
    auto namespaces = split(class_name, ".");
    auto new_ns = g;

    if (namespaces.size() > 1) {
        std::string potential_class_name{""};

        bool is_actually_class = false;

        for (auto ns = namespaces.begin(); ns != namespaces.end() - 1; ++ns) {
            if (ns != namespaces.begin()) {
                potential_class_name += ".";
            }

            potential_class_name += *ns;

            if (g_class_set.count(potential_class_name) > 0) {
                class_from_name(g, potential_class_name);
                is_actually_class = true;
            } else {
                new_ns = new_ns->namespace_(*ns);
            }
        }

        if (is_actually_class) {
            auto final_class = class_from_name(g, potential_class_name);

            return final_class->class_(namespaces.back());
        }
    }

    return new_ns->class_(namespaces.back());
}

genny::Enum* enum_from_name(genny::Namespace* g, const std::string& enum_name) {
    auto namespaces = split(enum_name, ".");
    auto new_ns = g;

    if (namespaces.size() > 1) {
        std::string potential_class_name{""};

        bool is_actually_class = false;

        for (auto ns = namespaces.begin(); ns != namespaces.end() - 1; ++ns) {
            if (ns != namespaces.begin()) {
                potential_class_name += ".";
            }

            potential_class_name += *ns;

            if (g_class_set.count(potential_class_name) > 0) {
                class_from_name(g, potential_class_name);
                is_actually_class = true;
            } else {
                new_ns = new_ns->namespace_(*ns);
            }
        }

        if (is_actually_class) {
            auto final_class = class_from_name(g, potential_class_name);

            return final_class->enum_(namespaces.back());
        }
    }

    return new_ns->enum_(namespaces.back());
}

genny::GenericType* type_from_entity_ref(genny::Namespace* g, sdk::ClassDescriptor* descriptor) {
    auto ft_name = std::string{descriptor->name};

    if (ft_name.find("TEntityRef") == std::string::npos) {
        return nullptr;
    }

    auto generic_entity_ref = (genny::GenericType*)g->generic_type("sdk::TEntityRef<void*>")->size(0x10);

    if (descriptor->init_data == nullptr || descriptor->num_init_data != 2) {
        return generic_entity_ref;
    }

    auto type_load_ref = utility::scan((uintptr_t)(*descriptor->init_data)[1].constructor, 0x50, "48 8D 15 ? ? ? ?");

    if (!type_load_ref) {
        return generic_entity_ref;
    }

    auto contained_type = (sdk::Type_CLASS*)utility::calculate_absolute((*type_load_ref) + 3);

    if (contained_type == nullptr || contained_type->descriptor == nullptr ||
        contained_type->descriptor->name == nullptr) {
        return generic_entity_ref;
    }

    // nope
    if (contained_type->descriptor->type_index != (uint32_t)sdk::DescriptorType::CLASS) {
        return generic_entity_ref;
    }

    auto contained_name = std::string{contained_type->descriptor->name};
    auto proper_class = class_from_name(g, contained_name);

    std::stringstream proper_typename;
    proper_class->generate_typename_for(proper_typename, proper_class);

    std::string proper_name{"sdk::TEntityRef<"};
    proper_name += proper_typename.str() + ">";

    auto t = g->generic_type(proper_name)->template_type(proper_class);
    t->size(0x10);

    return t;
}

genny::Type* type_from_primitive(genny::Namespace* g, sdk::BaseTypeDescriptor* descriptor) {
    std::string type_name{""};
    auto ft_name = std::string{descriptor->name};

    if (ft_name == "char") {
        type_name = "char";
    } else if (ft_name == "bool") {
        type_name = "bool";
    } else if (ft_name == "uint8") {
        type_name = "uint8_t";
    } else if (ft_name == "int8") {
        type_name = "int8_t";
    } else if (ft_name == "uint16") {
        type_name = "uint16_t";
    } else if (ft_name == "int16") {
        type_name = "int16_t";
    } else if (ft_name == "uint32") {
        type_name = "uint32_t";
    } else if (ft_name == "int32") {
        type_name = "int32_t";
    } else if (ft_name == "uint64") {
        type_name = "uint64_t";
    } else if (ft_name == "int64") {
        type_name = "int64_t";
    } else if (ft_name == "float32") {
        type_name = "float";
    } else if (ft_name == "float64") {
        type_name = "double";
    } else {
        printf("Unhandled primitive: %s\n", ft_name.c_str());
        return nullptr;
    }

    return g->type(type_name);
}

template <typename T = genny::Type> T* type_from_descriptor(genny::Namespace* g, sdk::BaseTypeDescriptor* descriptor);

genny::GenericType* type_from_array(genny::Namespace* g, sdk::TArrayDescriptor* descriptor) {
    auto generic_tarray = (genny::GenericType*)g->generic_type("sdk::TArray<void*>")->size(0x18);

    if (descriptor->contained_type == nullptr || descriptor->contained_type->descriptor == nullptr) {
        return generic_tarray;
    }

    auto inner = type_from_descriptor(g, descriptor->contained_type->descriptor);

    if (inner == nullptr) {
        return generic_tarray;
    }

    auto contained_name = std::string{descriptor->contained_type->descriptor->name};

    std::stringstream proper_typename;
    inner->generate_typename_for(proper_typename, inner);

    std::string proper_name{"sdk::TArray<"};
    proper_name += proper_typename.str() + ">";

    auto t = g->generic_type(proper_name)->template_type(inner);
    t->size(0x18);

    return t;
}

template <typename T> T* type_from_descriptor(genny::Namespace* g, sdk::BaseTypeDescriptor* descriptor) {
    if (descriptor->name == nullptr) {
        return nullptr;
    }

    auto ft_name = std::string{descriptor->name};

    switch ((sdk::DescriptorType)descriptor->type_index) {
    case sdk::DescriptorType::VARIANT:
        if (ft_name == "ZString") {
            return g->type("sdk::ZString")->size(descriptor->size);
        } else if (ft_name == "ZVariant" && descriptor->size == 0x10) {
            return g->class_("ZVariant")->size(0x10);
        }

        return nullptr;
    case sdk::DescriptorType::CLASS:
        return class_from_name(g, ft_name);
    case sdk::DescriptorType::T_ENTITY_REF:
        return type_from_entity_ref(g, (sdk::ClassDescriptor*)descriptor);
    case sdk::DescriptorType::ENUM:
        return enum_from_name(g, ft_name);
    case sdk::DescriptorType::T_ARRAY:
        return type_from_array(g, (sdk::TArrayDescriptor*)descriptor);
    case sdk::DescriptorType::PRIMITIVE:
        return type_from_primitive(g, descriptor);
    default:
        return nullptr;
    }
}

genny::Class* generate_class(genny::Namespace* g, const std::string& class_name, sdk::ClassDescriptor* klass) {
    auto c = class_from_name(g, class_name);
    c->size(klass->size);

    auto get_short_name = c->static_function("get_short_name");
    get_short_name->returns(g->type("const char*")->size(8));
    get_short_name->procedure(std::string{"return \""} + split(class_name, ".").back() + "\";");

    auto get_full_name = c->static_function("get_full_name");
    get_full_name->returns(g->type("const char*")->size(8));
    get_full_name->procedure(std::string{"return \""} + class_name + "\";");

    // Inheritance
    if (klass->base_inheritance != nullptr && klass->num_inheritance > 0) {
        std::vector<sdk::HeirarchyDescriptor*> sorted_heirarchy{};

        for (auto i = 0; i < klass->num_inheritance; ++i) {
            auto super = &(*klass->base_inheritance)[i];

            sorted_heirarchy.push_back(super);
        }

        std::sort(sorted_heirarchy.begin(), sorted_heirarchy.end(),
            [](sdk::HeirarchyDescriptor* a, sdk::HeirarchyDescriptor* b) { return a->offset < b->offset; });

        sdk::HeirarchyDescriptor* prev = nullptr;

        for (auto it = sorted_heirarchy.begin(); it != sorted_heirarchy.end(); ++it) {
            auto super = *it;

            if (super->klass != nullptr && super->klass->descriptor != nullptr &&
                super->klass->descriptor->name != nullptr) {
                auto super_genny = class_from_name(g, super->klass->descriptor->name);

                c->parent(super_genny);
            } else { // We need to generate a fake type to fill the gap in the inheritance.
                printf("%s has bad inheritance (descriptor 0x%p)\n", class_name.c_str(), super);

                auto next = it + 1;

                if (next != sorted_heirarchy.end()) {
                    auto fake_class_ns = g->namespace_("genny");
                    auto fake_class =
                        fake_class_ns->class_(std::string{"Generated"} + std::to_string((uintptr_t)super));
                    c->parent(fake_class);

                    printf(" 0x%X->0x%X (0x%X)\n", (int32_t)super->offset, (int32_t)(*next)->offset,
                        ((int32_t)(*next)->offset - (int32_t)super->offset));
                } else {
                    printf(" next is null\n");
                }
            }
        }
    }

    // Fields
    if (klass->fields != nullptr && klass->num_fields > 0) {
        for (auto i = 0; i < klass->num_fields; ++i) {
            auto field = &(*klass->fields)[i];

            if (field->field_name == nullptr || field->field_type == nullptr) {
                continue;
            }

            auto ft = field->field_type;

            if (ft->descriptor == nullptr || ft->descriptor->name == nullptr || ft->descriptor->class_type == nullptr) {
                continue;
            }

            auto descriptor = ft->descriptor;
            auto field_name = std::string{field->field_name};
            auto ft_name = std::string{descriptor->name};

            auto t = type_from_descriptor(g, descriptor);

            switch ((sdk::TypeType)ft->type_type) {
            case sdk::TypeType::EMBEDDED: {
                switch ((sdk::DescriptorType)descriptor->type_index) {
                case sdk::DescriptorType::VARIANT:
                    if (t != nullptr) {
                        c->variable(field_name)->type(t)->offset(field->field_offset);
                    } else {
                        c->array_(field_name)->count(descriptor->size)->offset(field->field_offset)->type("uint8_t");
                    }

                    break;
                case sdk::DescriptorType::CLASS: {
                    if (field->set_field != nullptr) {
                        auto f = c->function("set_" + field_name);

                        f->param("in")->type(t->ref());
                        f->procedure(std::string{"((void(*)(void*, void*))"} +
                                     std::to_string((uintptr_t)field->set_field) + ")(this, &in);");
                    }

                    if (field->field_offset == 0 && field->get_field != nullptr) {
                        auto f = c->function("get_" + field_name);

                        f->param("out")->type(t->ref());
                        f->procedure(std::string{"((void(*)(void*, void*))"} +
                                     std::to_string((uintptr_t)field->get_field) + ")(this, &out);");
                    } else {
                        c->variable(field_name)->type(t)->offset(field->field_offset);
                    }
                }

                break;

                // e.g. TEntityRef<blah>
                case sdk::DescriptorType::T_ENTITY_REF: {
                    if (t == nullptr) {
                        c->array_(field_name)->count(descriptor->size)->offset(field->field_offset)->type("uint8_t");
                    } else {
                        c->variable(field_name)->type(t)->offset(field->field_offset);
                    }
                } break;
                case sdk::DescriptorType::T_ARRAY: {
                    c->variable(field_name)->type(t)->offset(field->field_offset);
                } break;
                case sdk::DescriptorType::ENUM:
                    c->variable(field_name)->type(t)->offset(field->field_offset);
                    break;
                case sdk::DescriptorType::PRIMITIVE: {
                    if (t == nullptr) {
                        if (field->field_offset != 0 && field->get_field == nullptr) {
                            c->array_(field_name)
                                ->count(descriptor->size)
                                ->offset(field->field_offset)
                                ->type("uint8_t");
                        }

                        break;
                    }

                    if (field->set_field != nullptr) {
                        auto f = c->function("set_" + field_name);

                        f->param("in")->type(t->ref());
                        f->procedure(std::string{"((void(*)(void*, void*))"} +
                                     std::to_string((uintptr_t)field->set_field) + ")(this, &in);");
                    }

                    if (field->field_offset == 0 && field->get_field != nullptr) {
                        auto f = c->function("get_" + field_name);

                        f->param("out")->type(t->ref());
                        f->procedure(std::string{"((void(*)(void*, void*))"} +
                                     std::to_string((uintptr_t)field->get_field) + ")(this, &out);");
                    } else {
                        c->variable(field_name)->offset(field->field_offset)->type(t);
                    }
                }

                break;
                default:
                    // unsupported type, just generate an array of bytes
                    c->array_(field_name)->count(descriptor->size)->offset(field->field_offset)->type("uint8_t");
                    break;
                }
            } break;
            case sdk::TypeType::POINTER: {
                /*if (ft->child == nullptr) {
                    continue;
                }*/

                c->variable(field_name)->offset(field->field_offset)->type("void*");
            }

            break;
            default:
                break;
            }
        }
    }

    return c;
}

genny::Enum* generate_enum(genny::Namespace* g, const std::string& enum_name, sdk::EnumDescriptor* enum_) {
    auto e = enum_from_name(g, enum_name);

    switch (enum_->size) {
    case 1:
        e->type(g->type("uint8_t"));
        break;
    case 2:
        e->type(g->type("uint16_t"));
        break;
    case 4:
        e->type(g->type("uint32_t"));
        break;
    case 8:
        e->type(g->type("uint64_t"));
        break;
    }

    if (enum_->enum_start == nullptr || enum_->enum_end == nullptr) {
        return e;
    }

    for (auto entry = (sdk::EnumFieldDescriptor*)enum_->enum_start; entry != nullptr && entry != enum_->enum_end;
         ++entry) {
        if (entry->name == nullptr) {
            continue;
        }

        e->value(entry->name, entry->value);
    }

    return e;
}

extern "C" __declspec(dllexport) void generate() {
    printf("SDKGEN start\n");

    genny::Sdk sdk{};
    auto g = sdk.global_ns();

    sdk.include("sdk/ZString.hpp");
    sdk.include("sdk/TEntityRef.hpp");
    sdk.include("sdk/TArray.hpp");
    sdk.include("sdk/ReClass.hpp");
    sdk.include("cstdint");

    g->type("int8_t")->size(1);
    g->type("int16_t")->size(2);
    g->type("int32_t")->size(4);
    g->type("int64_t")->size(8);
    g->type("uint8_t")->size(1);
    g->type("uint16_t")->size(2);
    g->type("uint32_t")->size(4);
    g->type("uint64_t")->size(8);
    g->type("float")->size(4);
    g->type("double")->size(8);
    g->type("bool")->size(1);
    g->type("char")->size(1);
    g->type("int")->size(4);
    g->type("void")->size(0);
    g->type("void*")->size(8);

    auto types = sdk::TypeRegistry::get();

    // First pass, gather all valid class names
    for (auto& t : *types) {
        if (t.name == nullptr || t.type_info == nullptr || t.type_info->descriptor == nullptr) {
            continue;
        }

        if (t.type_info->descriptor->type_index == (uint32_t)sdk::DescriptorType::CLASS) {
            g_class_set.insert(t.name);
        }
    }

    for (auto& t : *types) {
        if (t.name == nullptr || t.type_info == nullptr || t.type_info->descriptor == nullptr) {
            continue;
        }

        const auto ti = t.type_info->descriptor->type_index;

        if (ti == (uint32_t)sdk::DescriptorType::CLASS) {
            generate_class(g, t.name, t.type_info->descriptor);
        } else if (ti == (uint32_t)sdk::DescriptorType::ENUM) {
            generate_enum(g, t.name, (sdk::EnumDescriptor*)t.type_info->descriptor);
        }
    }

    // most types inherit from this class, so we should map it out
    auto IComponentInterface = class_from_name(g, "IComponentInterface");
    IComponentInterface->virtual_function("~IComponentInterface")->vtable_index(0)->returns(g->type("")->size(0));
    IComponentInterface->virtual_function("GetType")->vtable_index(1)->returns(g->type("sdk::ClassTypeOut*")->size(8))->param("out")->type(g->type("sdk::ClassTypeOut*")->size(8));
    IComponentInterface->virtual_function("AddReference")->vtable_index(2)->returns(g->type("int32_t"));
    IComponentInterface->virtual_function("Release")->vtable_index(3)->returns(g->type("int32_t"));
    IComponentInterface->virtual_function("GetAddressOfParent")->vtable_index(4)->returns(g->type("void*"))->param("t")->type(g->type("sdk::Type_CLASS*")->size(8));

    //a very important type, so we have to manually map it out ourselves
    auto ZEntityImpl = class_from_name(g, "ZEntityImpl");
    ZEntityImpl->variable("m_Impl")->type(g->type("sdk::ZEntityImpl_Inner")->size(sizeof(sdk::ZEntityImpl_Inner)))->offset(8);

    sdk.generate(SDK_OUTPUT "/sdk");

    printf("Generated sdk\n");
}

BOOL APIENTRY DllMain(HANDLE handle, DWORD reason, LPVOID reserved) {
    return TRUE;
}
