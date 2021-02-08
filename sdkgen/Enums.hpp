#pragma once

#include <cstdint>

namespace sdk {
    enum class TypeType : uint16_t {
        Embedded = 0,
        Pointer = 2
    };

    enum class DescriptorType : uint32_t {
        Unknown = 0,
        Class = 4,
        Class_Inflated = 5, // e.g. Foo<Bar>
        TResourcePtr = 6,
        Enum = 8,
        TArray = 48,
        Primitive = 1024 // e.g. int, float, double
    };
}