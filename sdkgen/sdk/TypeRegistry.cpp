#include "Pool.hpp"

#include "TypeRegistry.hpp"

sdk::TypeRegistry* sdk::TypeRegistry::get() {
    return (TypeRegistry*)get_tagged_pool("ioi_typeinforegistry");
}
