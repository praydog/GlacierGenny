#pragma once

#include <cstdint>

namespace sdk {
enum class TypeType : uint16_t {
    EMBEDDED = 0,
    POINTER = 2,
};

enum class DescriptorType : uint32_t {
    UNKNOWN = 0,
    CLASS = 4,
    CLASS_INFLATED = 5, // e.g. Foo<Bar>
    T_RESOURCE_PTR = 6,
    ENUM = 8,
    T_ARRAY = 48,
    PRIMITIVE = 1024, // e.g. int, float, double
};
} // namespace sdk