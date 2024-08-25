#ifndef SB_LIB_DATA_MANP_HPP
#define SB_LIB_DATA_MANP_HPP

#include "../types.hpp"

namespace SB_LIB {

    template<typename T, mlen N>
    void ll_copy(T* addr_one, T* addr_two) {
        for (mlen idx = 0; idx < N; idx++) {
            *(addr_one + idx) = *(addr_two + idx);
        }
    }

    template<typename ForwardIterator, mlen N>
    void copy(ForwardIterator addr_one, ForwardIterator addr_two) {
        for (mlen count = 0; count < N; count++) {
            (*addr_one++) = (*addr_two++);
        }
    }

}
#endif