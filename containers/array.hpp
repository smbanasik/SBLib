#ifndef SB_LIB_ARRAY_HPP
#define SB_LIB_ARRAY_HPP

#include "../types.hpp"

namespace SB_LIB {

template <typename T, mlen N>
class Array {
public:

    Array() = default;

    // TODO: iterator interface
    // RandomAccessIterator
    class Iterator {
    public:
        Iterator() {
            locale = nullptr;
        }

        Iterator(T& data) {
            locale = &data;
        }

        Iterator& operator++() {
            locale++;
            return *this;
        }

        Iterator operator++(int) {
            Iterator old = *this;
            operator++();
            return old;
        }

        Iterator operator--() {
            locale--;
            return *this;
        }

        Iterator operator--(int) {
            Iterator old = *this;
            operator--();
            return old;
        }

        //Iterator operator[](mlen index) {
        //    if (index > N)
        //        throw; // TODO: throw message
        //    return data[index];
        //}

        bool operator==(const Iterator& rhs) {
            this.locale == rhs.locale;
        }
        bool operator!=(const Iterator& rhs) {
            return !(this == rhs);
        }

        T& operator*() {
            return *locale;
        }

        T* operator->() {
            return locale;
        }

    private:
        T* locale;
    };
    class ConstIterator {

    };

    T& at(mlen index) {
        if (index > N)
            throw; // TODO: throw message
        return data[index];
    }

    const T& at(mlen index) const {
        if (index > N)
            throw; // TODO: throw message
        return data[index];
    }

    T& operator[](mlen index) {
        if (index > N)
            throw; // TODO: throw message
        return data[index];
    }

    T& front() {
        return data[0];
    }

    T& back() {
        return data[N];
    }

    //template<mlen M>
    //Array<T, M> subarray(mlen start, mlen end) {
    //
    //}

    consteval mlen size() const {
        return N;
    }

    consteval bool empty() const {
        return (N == 0);
    }

    //void fill(mlen start, mlen end) {
    //
    //}

    
    // Todo:
    // - Access
    //   - create subarray
    // - Operations
    //   - fill
    //   - swap
    //   - fill subsection
    // - Static operators
    //   - relational (equals, spaceship <=>)
    //   - to_array
    // - Constructors
    // - Const versions of functiosn
    // - get read only (returns constant reference)
    

private:

    T data[N];
};
}
#endif