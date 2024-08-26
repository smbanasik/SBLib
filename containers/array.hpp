#ifndef SB_LIB_ARRAY_HPP
#define SB_LIB_ARRAY_HPP

#include "../types.hpp"

namespace SB_LIB {

template <typename T, mlen N>
class Array {
public:

    Array<T,N> static from_carray(T* arr_start, mlen length) {
        
        Array<T, N> new_arr;

        // TODO: use SB_LIB ll_copy to handle this?

        for (T* addr = arr_start, j = 0; addr < arr_start + length; addr++, j++) {

            new_arr[j] = *(addr);
        }
        
        return new_arr;
    }

    Array() : arr_data{} {}

    Array(const T& fill_value) {
        fill(fill_value);
    }

    // TODO: iterator interface
    // RandomAccessIterator
    class Iterator {
    public:
        Iterator() {
            locale = nullptr;
        }

        Iterator(T& arr_data) {
            locale = &arr_data;
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

        Iterator get_next() {
            Iterator next = this;
            return ++next;
        }

        bool operator==(const Iterator& rhs) {
            return this->locale == rhs.locale;
        }

        // TODO: why can't this be auto generated?
        // Further, why can't we set !(this == that) ????
        bool operator!=(const Iterator& rhs) {
            return !(this->locale == rhs.locale);
        }

        T& operator*() {
            return *locale;
        }

        T* operator->() {
            return locale;
        }

        Iterator& operator--() {
            locale--;
            return *this;
        }

        Iterator operator--(int) {
            Iterator old = *this;
            operator--();
            return old;
        }

        Iterator get_prev() {
            Iterator prev = this;
            return --prev;
        }

        Iterator& operator[](mlen index) {
            return ;
        }

        Iterator& operator+= (Iterator& ) {
        }
        Iterator& operator-= (Iterator& ) {
        }

        //Iterator operator+(mlen index) {
        // }
        //Iterator operator-(mlen index) {
        // }

        //Iterator operator <=> (const iterator& rhs) {
        // }

    private:
        T* locale;
    };
    class ConstIterator {

    };

    // -----Access-----

    // TODO: improve throw messages

    T& at(mlen index) {
        if (N <= index)
            throw "Index Out of Bounds.";
        return arr_data[index];
    }

    T& operator[](mlen index) {
        if (N <= index)
            throw "Index Out of Bounds.";
        return arr_data[index];
    }

    T& f_at(mlen index) {
        return arr_data[index];
    }

    T& front() {
        return arr_data[0];
    }

    T& back() {
        return arr_data[N - 1];
    }

    T* data() {
        return arr_data;
    }

    const T& at(mlen index) const {
        if (N <= index)
            throw "Index Out of Bounds.";
        return arr_data[index];
    }

    const T& operator[](mlen index) const {
        if (N <= index)
            throw "Index Out of Bounds.";
        return arr_data[index];
    }

    const T& front() const {
        return arr_data[0];
    }

    const T& back() const {
        return arr_data[N - 1];
    }

    const T* data() const {
        return arr_data;
    }

    // TODO: iterator access
    // begin, end, cbegin, cend, rbegin, rend, rcbegin, rcend

    // -----Querying-----

    consteval mlen size() const {
        return N;
    }

    consteval bool empty() const {
        return (N == 0);
    }

    consteval mlen max_size() const {
        return N;
    }

    // TODO: friend the equals and inequality operators, declare outside of class
    const bool operator==(const Array<T, N>& other) const {
        if (&other == &this)
            return true;
        for (mlen idx = 0; idx < N; idx++) {
            if (other[idx] != this[idx])
                return false;
        }
        return true;
    }

    // TODO: potentially consider adding self == self contingencies for this

    const bool operator<=>(const Array<T, N>& other) const {
        for (mlen idx = 0; idx < N; idx++) {
            if (this[idx] < other[idx])
                return -1;
            else if (this[idx] > other[idx])
                return 1;
        }
        return 0;
    }

    // -----Manipulation-----

    // TODO: iterators
    template<mlen M>
    Array<T, M> subarray(const mlen start, const mlen end) const {
        // TODO: if end > start, reverse iterate
        // TODO: throw if size invalid
        Array<T, M> new_arr;

        for (mlen idx = start, j = 0; idx < end; idx++, j++) {

            new_arr[j] = this->arr_data[idx];
        }

        return new_arr;
    }

    void fill(const T& value) {
        for (mlen idx = 0; idx < N; idx++) {
            arr_data[idx] = value;
        }
    }

    // TODO: iterators
    void fill(T& value, mlen start, mlen end) {
        // TODO: bounds checking
        for (mlen idx = start; idx < end; idx++) {
            arr_data[idx] = *value;
        }
    }

    // TODO: iterators
    void swap(mlen first, mlen second) {
        // TODO: bounds checking
        T temp = arr_data[first];
        arr_data[first] = arr_data[second];
        arr_data[second] = temp;
    }

private:

    T arr_data[N];
};
}
#endif