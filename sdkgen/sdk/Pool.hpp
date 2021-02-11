#pragma once

#include "TypeRegistry.hpp"

namespace sdk {
    void* get_tagged_pool(const char* name);
    void* get_config_vars();
}