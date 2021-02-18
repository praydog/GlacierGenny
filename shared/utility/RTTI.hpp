#pragma once

#include "Address.hpp"
#include <vcruntime_typeinfo.h>

namespace utility {
std::type_info* get_type_info(Address obj);
} // namespace utility