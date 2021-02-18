#pragma once

namespace sdk {
template <typename T> class TArray {
public:
    bool is_iterable() const {
        return start != nullptr && end != nullptr && allocated_end != nullptr &&
               (uintptr_t)allocated_end != 0x4000000000000000;
    }

    T* begin() {
        if (!is_iterable()) {
            return nullptr;
        }

        return start;
    }

    T* end() {
        if (!is_iterable()) {
            return nullptr;
        }

        return end;
    }

public:
    T* start;
    T* last;
    T* allocated_end;
}; // 0x18
} // namespace sdk