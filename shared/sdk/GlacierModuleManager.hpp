#pragma once

#include <string>

#include "ReClass.hpp"

namespace sdk {
class GlacierModuleManager : public ZGlacierModuleManager {
public:
    static GlacierModuleManager* get();

public:
    auto begin() { return (sdk::ModuleDescriptor*)this->modules; }
    auto end() { return (sdk::ModuleDescriptor*)this->modules + this->num_modules; }

    sdk::ZSimpleModuleBase* find_module(const std::string& name) const;
};
} // namespace sdk