#pragma once

#include <string>
#include <unordered_map>

#include "ReClass.hpp"

namespace sdk {
class GlacierModuleManager : public ZGlacierModuleManager {
public:
    static GlacierModuleManager* get();

public:
    using ModuleMap =
        std::unordered_map<std::string, std::unordered_map<std::string, sdk::IComponentInterface_RECLASS*>>;

    auto begin() { return (sdk::ModuleDescriptor*)this->modules; }
    auto end() { return (sdk::ModuleDescriptor*)this->modules + this->num_modules; }

    sdk::ZSimpleModuleBase* find_module(const std::string& name) const;
    ModuleMap generate_module_map();
};
} // namespace sdk