#pragma once

#include <cstdint>

namespace sdk {
struct Vector2 {
    float x, y;
};

struct Vector3 {
    float x, y, z;
};

#include "ReClass_Internal.hpp"
} // namespace sdk

#include "Enums.hpp"
#include "TypeRegistry.hpp"
#include "ZEntityImpl.hpp"