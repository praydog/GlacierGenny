#pragma once

#include "Address.hpp"
#include <vcruntime_typeinfo.h>

namespace utility {
std::type_info* get_type_info(Address obj);
std::string get_demangled_name(const std::type_info* ti);
} // namespace utility