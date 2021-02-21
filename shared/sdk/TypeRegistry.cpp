#include "Pool.hpp"

#include "TypeRegistry.hpp"

sdk::TypeRegistry* sdk::TypeRegistry::get() {
    return (TypeRegistry*)get_tagged_pool("ioi_typeinforegistry");
}

bool sdk::is_a(Type_CLASS* a, Type_CLASS* b) {
    if (a == nullptr || b == nullptr) {
        return false;
    }

    if (a == b) {
        return true;
    }

    if (a->descriptor == nullptr || a->descriptor->type_index != (uint32_t)sdk::DescriptorType::CLASS) {
        return false;
    }

    if (a->descriptor->full_inheritance != nullptr) {
        for (auto i = 0; i < a->descriptor->num_full_inheritance; ++i) {
            auto c = (*a->descriptor->full_inheritance)[i].klass;

            if (c == b) {
                return true;
            }

            if (c == a) {
                continue;
            }

            if (is_a(c, b)) {
                return true;
            }
        }
    }

    if (a->descriptor->base_inheritance != nullptr) {
        for (auto i = 0; i < a->descriptor->num_inheritance; ++i) {
            auto c = (*a->descriptor->base_inheritance)[i].klass;

            if (c == b) {
                return true;
            }

            if (c == a) {
                continue;
            }

            if (is_a(c, b)) {
                return true;
            }
        }
    }

    return false;
}
