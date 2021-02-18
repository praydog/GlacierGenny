#pragma once

#include <cstdint>

namespace sdk {
// ZVariant?
class ZString {
public:
    uint32_t size;
    uint32_t pad;
    char* data;
};
} // namespace sdk