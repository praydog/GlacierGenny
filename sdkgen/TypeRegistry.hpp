#pragma once

#include <string_view>

#include "ReClass.hpp"

class TypeRegistry : public sdk::ZTypeRegistry {
public:
    auto begin() {
        return (sdk::TypeRegistryType*)this->types;
    }

    auto end() {
        if (this->num_types <= 0) {
            return (sdk::TypeRegistryType*)this->types;
        }

        return (sdk::TypeRegistryType*)this->types + this->num_types;
    }

    sdk::TypeRegistryType* get_entry(std::string_view name) {
        for (auto& t : *this) {
            if (t.name == nullptr) {
                continue;
            }

            if (t.name == name) {
                return &t;
            }
        }

        return nullptr;
    }

    template <typename T = sdk::Type_CLASS>
    T* get_descriptor(std::string_view name) {
        auto entry = get_entry(name);

        if (entry == nullptr) {
            return nullptr;
        }

        return (T*)entry->type_info;
    }
};