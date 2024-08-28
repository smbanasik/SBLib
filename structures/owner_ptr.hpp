#ifndef SB_LIB_OWNER_PTR_HPP
#define SB_LIB_OWNER_PTR_HPP
namespace SB_LIB {
template<typename T>
class OwnerPtr {
public:

    OwnerPtr() {
        ptr = nullptr;
    }

    OwnerPtr(T& obj) {
        ptr = obj;
    }

    ~OwnerPtr() {

        // TODO: call delete for *T

        ptr = nullptr;
    }

    // TODO: copy, copy assignment
    // TODO: move, move assignment

    // TODO: creation

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
};
}
#endif