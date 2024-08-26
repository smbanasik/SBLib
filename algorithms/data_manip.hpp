#ifndef SB_LIB_DATA_MANP_HPP
#define SB_LIB_DATA_MANP_HPP

#include "../types.hpp"

namespace SB_LIB {

    template<typename T>
    void ll_copy(T* addr_one, T* addr_two, mlen length) {
        for (mlen idx = 0; idx < length; idx++) {
            *(addr_one + idx) = *(addr_two + idx);
        }
    }

    template<typename ForwardIterator>
    void copy(ForwardIterator first, ForwardIterator last, ForwardIterator target) {
        for (; first != last; ++first, ++target) {
            *target = *first;
        }
    }

}
#endif