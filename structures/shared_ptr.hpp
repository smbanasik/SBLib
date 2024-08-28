#ifndef SB_LIB_SHARED_PTR_HPP
#define SB_LIB_SHARED_PTR_HPP

#include "../types.hpp"

namespace SB_LIB {
template<typename T>
class SharedPtr {
public:

    SharedPtr() {
        ptr = nullptr;
    }

    ~SharedPtr() {

        if (--(*ref_count) == 0)
            // TODO: call delete for *T
            ;

        ptr = nullptr;
    }

    // TODO: copy, copy assignment
    // TODO: move, move assignment

    T* release() {

        T* released = ptr;
        ptr = nullptr;
        return released;
    }

    T* get() {
        return ptr;
    }

    T& operator*() {
        return *ptr;
    }

    T* operator->() {
        return ptr;
    }

    // TODO: comparison
    // TODO: operator <<
    // TODO: swap


private:
    T* ptr;
    mlen* ref_count;
};
}
#endif