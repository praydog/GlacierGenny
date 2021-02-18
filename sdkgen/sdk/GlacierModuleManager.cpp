#include <iostream>

#include <utility/Scan.hpp>

#include "GlacierModuleManager.hpp"

sdk::GlacierModuleManager* sdk::GlacierModuleManager::get() {
    // Search for strings like "Runtime.Entity" around the function call
    static sdk::GlacierModuleManager* (*func)() = nullptr;

    if (func == nullptr) {
        std::cout << "Finding GlacierModuleManager" << std::endl;

        auto ref = utility::scan(GetModuleHandle(0), "E8 ? ? ? ? 48 8B C8 48 8D 15 ? ? ? ? 48 83 C4 ? E9");

        if (!ref) {
            std::cout << "Failed to find GetGlacierModuleManager" << std::endl;
            return nullptr;
        }

        func = (decltype(func))utility::calculate_absolute((*ref) + 1);

        std::cout << "GlacierModuleManager: 0x" << std::hex << func << std::endl;
    }

    return func();
}

sdk::ZSimpleModuleBase* sdk::GlacierModuleManager::find_module(const std::string& name) const {
    for (uint32_t i = 0; i < this->num_modules; ++i) {
        const auto& desc = this->modules[i];

        if (desc.name == nullptr) {
            continue;
        }

        if (desc.name == name) {
            return desc.mod;
        }
    }

    return nullptr;
}
