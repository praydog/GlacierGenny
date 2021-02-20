#pragma once

namespace sdk {
template <typename T> class TArray {
public:
    bool is_iterable() const { return start != nullptr && last != nullptr && allocated_end != nullptr; }
    bool is_inline() const { return ((uintptr_t)allocated_end & 0x4000000000000000) != 0; }

    T* begin() {
        if (is_inline()) {
            return (T*)&start;
        }

        if (!is_iterable()) {
            return nullptr;
        }

        return start;
    }

    T* end() {
        if (is_inline()) {
            return (T*)&start + num_inline;
        }

        if (!is_iterable()) {
            return nullptr;
        }

        return last;
    }

    size_t size() {
        return ((uintptr_t)end() - (uintptr_t)begin()) / sizeof(T);
    }

    size_t capacity() {
        if (is_inline()) {
            return ((uintptr_t)&allocated_end - (uintptr_t)&start) / sizeof(T);
        }

        return ((uintptr_t)allocated_end - (uintptr_t)begin()) / sizeof(T);
    }

public:
    T* start;
    T* last;

    union {
        T* allocated_end;

        struct {
            uint8_t num_inline;
            uint8_t max_inline;
        };
    };
}; // 0x18
} // namespace sdk