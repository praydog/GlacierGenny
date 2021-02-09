#include <iostream>
#include <filesystem>

#include <windows.h>

#include "TypeRegistry.hpp"

#include "Genny.hpp"

std::unordered_set<std::string> g_class_set{};

void* get_tagged_pool(const char* name) {
    auto func = (decltype(get_tagged_pool)*)((uintptr_t)GetModuleHandle(0) + 0xC31B0);

    return func(name);
}

TypeRegistry* get_type_registry() {
    return (TypeRegistry*)get_tagged_pool("ioi_typeinforegistry");
}

void* get_config_vars() {
    return get_tagged_pool("base.config.vars");
}

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
        std::string potential_class_name{ "" };

        bool is_actually_class = false;

        for (auto ns = namespaces.begin(); ns != namespaces.end() - 1; ++ns) {
            if (ns != namespaces.begin()) {
                potential_class_name += ".";
            }

            potential_class_name += *ns;

            if (g_class_set.count(potential_class_name) > 0) {
                class_from_name(g, potential_class_name);
                is_actually_class = true;
            }
            else {
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
        std::string potential_class_name{ "" };

        bool is_actually_class = false;

        for (auto ns = namespaces.begin(); ns != namespaces.end() - 1; ++ns) {
            if (ns != namespaces.begin()) {
                potential_class_name += ".";
            }

            potential_class_name += *ns;

            if (g_class_set.count(potential_class_name) > 0) {
                class_from_name(g, potential_class_name);
                is_actually_class = true;
            }
            else {
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

genny::Class* generate_class(genny::Namespace* g, const std::string& class_name, sdk::ClassDescriptor* klass) {
    auto c = class_from_name(g, class_name);
    c->size(klass->size);

    auto get_short_name = c->static_function("get_short_name");
    get_short_name->returns(g->type("const char*")->size(8));
    get_short_name->procedure(std::string{ "return \"" } + split(class_name, ".").back() + "\"");

    auto get_full_name = c->static_function("get_full_name");
    get_full_name->returns(g->type("const char*")->size(8));
    get_full_name->procedure(std::string{ "return \"" } + class_name + "\"");

    // Inheritance
    if (klass->base_inheritance != nullptr && klass->num_inheritance > 0) {
        std::vector<sdk::HeirarchyDescriptor*> sorted_heirarchy{};

        for (auto i = 0; i < klass->num_inheritance; ++i) {
            auto super = &(*klass->base_inheritance)[i];

            sorted_heirarchy.push_back(super);
        }

        std::sort(sorted_heirarchy.begin(), sorted_heirarchy.end(), [](sdk::HeirarchyDescriptor* a, sdk::HeirarchyDescriptor* b) {
            return a->offset < b->offset;
        });

        sdk::HeirarchyDescriptor* prev = nullptr;

        for (auto it = sorted_heirarchy.begin(); it != sorted_heirarchy.end(); ++it) {
            auto super = *it;

            if (super->klass != nullptr && super->klass->descriptor != nullptr && super->klass->descriptor->name != nullptr) {
                auto super_genny = class_from_name(g, super->klass->descriptor->name);

                c->parent(super_genny);
            }
            else { // We need to generate a fake type to fill the gap in the inheritance.
                printf("%s has bad inheritance (descriptor 0x%p)\n", class_name.c_str(), super);

                auto next = it + 1;

                if (next != sorted_heirarchy.end()) {
                    auto fake_class_ns = g->namespace_("genny");
                    auto fake_class = fake_class_ns->class_(std::string{ "Generated" } + std::to_string((uintptr_t)super));
                    c->parent(fake_class);

                    printf(" 0x%X->0x%X (0x%X)\n", (int32_t)super->offset, (int32_t)(*next)->offset, ((int32_t)(*next)->offset - (int32_t)super->offset));
                }
                else {
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
            auto field_name = std::string{ field->field_name };
            auto ft_name = std::string{ descriptor->name };

            switch ((sdk::TypeType)ft->type_type) {
            case sdk::TypeType::Embedded:
            {
                if (descriptor->type_index == (uint32_t)sdk::DescriptorType::Class) {
                    c->variable(field->field_name)->type(class_from_name(g, descriptor->name))->offset(field->field_offset);
                }
                else if (descriptor->type_index == (uint32_t)sdk::DescriptorType::Primitive) {
                    if (ft_name == "char") {
                        c->variable(field_name)->offset(field->field_offset)->type("char");
                    }
                    else if (ft_name == "bool") {
                        c->variable(field_name)->offset(field->field_offset)->type("bool");
                    }
                    else if (ft_name == "uint8") {
                        c->variable(field_name)->offset(field->field_offset)->type("uint8_t");
                    }
                    else if (ft_name == "int8") {
                        c->variable(field_name)->offset(field->field_offset)->type("int8_t");
                    }
                    else if (ft_name == "uint16") {
                        c->variable(field_name)->offset(field->field_offset)->type("uint16_t");
                    }
                    else if (ft_name == "int16") {
                        c->variable(field_name)->offset(field->field_offset)->type("int16_t");
                    }
                    else if (ft_name == "uint32") {
                        c->variable(field_name)->offset(field->field_offset)->type("uint32_t");
                    }
                    else if (ft_name == "int32") {
                        c->variable(field_name)->offset(field->field_offset)->type("int32_t");
                    }
                    else if (ft_name == "uint64") {
                        c->variable(field_name)->offset(field->field_offset)->type("uint64_t");
                    }
                    else if (ft_name == "int64") {
                        c->variable(field_name)->offset(field->field_offset)->type("int64_t");
                    }
                    else if (ft_name == "float32") {
                        c->variable(field_name)->offset(field->field_offset)->type("float");
                    }
                    else if (ft_name == "float64") {
                        c->variable(field_name)->offset(field->field_offset)->type("double");
                    }
                }
                else { // unsupported type, just generate an array of bytes
                    c->array_(field_name)->count(descriptor->size)->offset(field->field_offset)->type("uint8_t");
                }
            }
                break;
            case sdk::TypeType::Pointer:
            {
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

    for (auto entry = (sdk::EnumFieldDescriptor*)enum_->enum_start; entry != nullptr && entry != enum_->enum_end; ++entry) {
        if (entry->name == nullptr) {
            continue;
        }

        e->value(entry->name, entry->value);
    }

    return e;
}

extern "C"
__declspec(dllexport) void generate() {
    printf("SDKGEN start\n");

    genny::Sdk sdk{};
    auto g = sdk.global_ns();

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

    auto types = get_type_registry();

    // First pass, gather all valid class names
    for (auto& t : *types) {
        if (t.name == nullptr || t.type_info == nullptr || t.type_info->descriptor == nullptr) {
            continue;
        }

        if (t.type_info->descriptor->type_index == (uint32_t)sdk::DescriptorType::Class) {
            g_class_set.insert(t.name);
        }
    }

    for (auto& t : *types) {
        if (t.name == nullptr || t.type_info == nullptr || t.type_info->descriptor == nullptr) {
            continue;
        }

        const auto ti = t.type_info->descriptor->type_index;

        if (ti == (uint32_t)sdk::DescriptorType::Class) {
            generate_class(g, t.name, t.type_info->descriptor);
        }
        else if (ti == (uint32_t)sdk::DescriptorType::Enum) {
            generate_enum(g, t.name, (sdk::EnumDescriptor*)t.type_info->descriptor);
        }
    }

    sdk.generate(SDK_OUTPUT "/sdk");

    printf("Generated sdk\n");
}

BOOL APIENTRY DllMain(HANDLE handle, DWORD reason, LPVOID reserved) {
    return TRUE;
}