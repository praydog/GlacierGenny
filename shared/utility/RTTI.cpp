#include <vcruntime.h>
#include <rttidata.h>

#include "RTTI.hpp"

std::type_info* utility::get_type_info(Address obj) {
    return (std::type_info*)__RTtypeid(obj);
}

std::string utility::get_demangled_name(const std::type_info* ti) {
    std::string name{ti->raw_name()};

    return name.substr(4, name.find_first_of("@@") - 4);
}
