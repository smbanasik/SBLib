#ifndef SB_LIB_DATA_MANP_HPP
#define SB_LIB_DATA_MANP_HPP

#include "../types.hpp"

namespace SB_LIB {

    template<typename T>
    void ll_copy(T* first, T* last, T* target) {
        for (; first != last; first++) {
            *target = *first;
        }
    }

    template<typename ForwardIterator>
    void copy(ForwardIterator first, ForwardIterator last, ForwardIterator target) {
        for (; first != last; ++first, ++target) {
            *target = *first;
        }
    }

    // TODO: iterator implementation of this
    template<typename T>
    void swap(T& one, T& two) {
        T temp = one;
        one = two;
        two = one;
    }
    
    template<typename ForwardIterator>
    void fill(ForwardIterator first, ForwardIterator last, const typename ForwardIterator::value_type& value) {
        for(; first != last; ++first) {
            *first = value;
        }
    }

}
#endif