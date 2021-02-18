#include <iostream>

#include <utility/RTTI.hpp>
#include <utility/Scan.hpp>

#include "GlacierModuleManager.hpp"
#include "TArray.hpp"

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

sdk::GlacierModuleManager::ModuleMap sdk::GlacierModuleManager::generate_module_map() {
    sdk::GlacierModuleManager::ModuleMap out{};

    for (auto& desc : *this) {
        auto mod = desc.mod;

        if (mod == nullptr || desc.name == nullptr) {
            continue;
        }

        auto ti_mod = utility::get_type_info(mod);

        if (ti_mod == nullptr) {
            continue;
        }

        printf("0x%p %s: %s\n", mod, desc.name, utility::get_demangled_name(ti_mod).c_str());

        auto interfaces = (sdk::TArray<sdk::IComponentInterface_RECLASS*>*)mod->interfaces;

        if (interfaces == nullptr || IsBadReadPtr(interfaces, sizeof(void*))) {
            continue;
        }

        for (auto intfc : *interfaces) {
            auto ti = utility::get_type_info(intfc);

            if (ti == nullptr) {
                continue;
            }

            auto name = utility::get_demangled_name(ti);
            printf(" 0x%p %s\n", intfc, name.c_str());

            out[desc.name][name] = intfc;
        }
    }

    return out;
}
