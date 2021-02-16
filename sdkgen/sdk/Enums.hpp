#pragma once

#include <cstdint>

namespace sdk {
enum class TypeType : uint16_t {
    EMBEDDED = 0,
    POINTER = 2,
};

enum class DescriptorType : uint32_t {
    VARIANT = 0,
    CLASS = 4,
    T_ENTITY_REF = 5,
    T_RESOURCE_PTR = 6,
    ENUM = 8,
    T_ARRAY = 48,
    PRIMITIVE = 1024, // e.g. int, float, double
};
} // namespace sdk