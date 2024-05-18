#ifndef SB_LIB_ARRAY_HPP
#define SB_LIB_ARRAY_HPP

#include "../types.hpp"

namespace SB_LIB {

template <typename T, mlen N>
class Array {
public:

    T at(mlen index) const {
        if (index > N || index < 0)
            throw; // TODO: throw message
        return data[index];
    }

    T operator[](mlen index) const {
        return data[index];
    }

    T front() const {
        return data[0];
    }

    T back() const {
        return data[N];
    }

    // TODO: iterator interface

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

    

private:

    T data[N];
};
}
#endif