#pragma once

#include "ReClass.hpp"

namespace sdk {
#pragma pack(push, 1)
struct ZEntityImpl_Inner {
    ZEntityImpl_Inner* get_true_inner() {
        if (uses_offset) {
            auto true_inner = (ZEntityImpl_Inner*)((uintptr_t)this + (offset & ~1));

            return true_inner->get_true_inner();
        }

        return this;
    }

    sdk::EntityData* get_entity_data() {
        return get_true_inner()->entity_data;
    }

private:
    union {
        sdk::EntityData* entity_data;
        int64_t offset;
        bool uses_offset : 1;
    };

    int32_t unk1;
    int32_t impl_type;
};
#pragma pack(pop)
} // namespace sdk