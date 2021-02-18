#include <vcruntime.h>
#include <rttidata.h>

#include "RTTI.hpp"

std::type_info* utility::get_type_info(Address obj) {
    return (std::type_info*)__RTtypeid(obj);
}
