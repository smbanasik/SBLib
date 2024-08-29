#ifndef SB_LIB_DATA_MANP_HPP
#define SB_LIB_DATA_MANP_HPP

#include "../types.hpp"

namespace SB_LIB {

    // TODO: redo this to utilize three pointers (end target) rather than mlen length
    template<typename T>
    void ll_copy(T* addr_one, T* addr_two, mlen length) {
        for (mlen idx = 0; idx < length; idx++) {
            *(addr_one + idx) = *(addr_two + idx);
        }
    }

    // TODO: does this do what we want?
    template<typename ForwardIterator>
    void copy(ForwardIterator first, ForwardIterator last, ForwardIterator target) {
        for (; first != last; ++first, ++target) {
            *target = *first;
        }
    }

    template<typename T>
    void swap(T& one, T& two) {
        T temp = one;
        one = two;
        two = one;
    }
    
    template<typename ForwardIterator>
    void fill(ForwardIterator first, ForwardIterator last, const ForwardIterator::value_type& value) {
        for(; first != last; ++first) {
            *first = value;
        }
    }

}
#endif