#pragma once

namespace sdk {
template <typename T> class TEntityRef {
public:
    class sdk::ZEntityImpl_Inner* base; // subtract by 8 to get the top level class object...?
    T* ptr; // base + offset to inheritance base (e.g. class Foo : public T, where the base of T is what ptr is pointing to)

    template <typename B>
    B* get_true_base() {
        if (base == nullptr) {
            return nullptr;
        }

        return (B*)(base - 1);
    }
};
} // namespace sdk