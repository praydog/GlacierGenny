#include <iostream>

#include "Pool.hpp"
#include "utility/Scan.hpp"

namespace sdk {
void* sdk::get_tagged_pool(const char* name) {
    // v1 offset: game + 0xC31B0
    static decltype(get_tagged_pool)* func = nullptr;

    if (func == nullptr) {
        std::cout << "Finding GetTaggedPool" << std::endl;

        // just look for "ioi_typeinforegistry"
        auto ref = utility::scan(GetModuleHandle(0), "48 8D 0D ? ? ? ? E8 ? ? ? ? 48 89 05 ? ? ? ? 48 85 C0");

        if (!ref) {
            std::cout << "Failed to find GetTaggedPool" << std::endl;
            return nullptr;
        }

        func = (decltype(func))utility::calculate_absolute(*ref + 8);
        std::cout << "GetTaggedPool: " << std::hex << func << std::endl;
    }

    return func(name);
}

void* sdk::get_config_vars() {
    return get_tagged_pool("base.config.vars");
}
} // namespace sdk
