#ifndef SB_LIB_ARRAY_HPP
#define SB_LIB_ARRAY_HPP

#include "../types.hpp"
#include "../structures/iterator_categories.hpp"
#include "../structures/reverse_iterator.hpp"

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

    explicit Array(const T& fill_value) {
        fill(fill_value);
    }

    class Iterator {
    public:
        // TODO: Consider redoing IteratorCategory implementation,
        // also consider modifying random_access
        // typedef typename ??? difference_type
        typedef typename T value_type;
        typedef typename T& reference;
        typedef typename T* pointer;
        typedef typename IteratorCategory::RANDOM_ACCESS iterator_category;
        
        Iterator() {
            locale = nullptr;
        }
        
        ~Iterator() {
            locale = nullptr;
        }

        // STL containers do not permit this, I have browsed through 
        // some implementations that make use of a base iterator class,
        // which has some sort of address to iterator constructor.
        // However, for now this is fine.
        Iterator(T* ptr) {
            locale = ptr;
        }
        
        Iterator(const Iterator& other) {
            locale = other.locale;
        }
        
        Iterator(Iterator&& other) noexcept {
            locale = other.locale;
            other.locale = nullptr;
        }
        
        Iterator& operator=(const Iterator& other) {
            locale = other.locale;
            return *this;
        }
        
        Iterator& operator=(Iterator&& other) {
            T* temp = locale;
            locale = other.locale;
            other.locale = temp;
            return *this;
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

        friend bool operator==(const Iterator& lhs, const Iterator& rhs) {
            return lhs.locale == rhs.locale;
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
            return *(locale + index);
        }

        Iterator& operator+= (mlen index) {
            locale += index;
            return *this;
        }
        
        Iterator& operator-= (mlen index) {
            locale -= index;
                return *this;
        }

        friend Iterator operator+(Iterator lhs, mlen rhs) {
            lhs += rhs;
            return lhs;
        }
        
        friend Iterator operator+(mlen lhs, const Iterator& rhs) {
            return lhs + rhs.locale;
        }
        
        friend Iterator operator-(Iterator lhs, mlen rhs) {
            lhs -= rhs;
            return rhs;
        }
        
        friend Iterator operator-(mlen lhs, const Iterator& rhs) {
            return lhs - rhs.locale;
        }
        
        friend Iterator operator <=> (const Iterator& lhs, const Iterator& rhs) {
            return lhs.locale <=> rhs.locale;
        }

    private:
        T* locale;
    };
    class ConstIterator {
    public:
        typedef typename T value_type;
        typedef typename T& reference;
        typedef typename T* pointer;
        typedef typename IteratorCategory::RANDOM_ACCESS iterator_category;
    
        ConstIterator() {
            locale = nullptr;
        }

        ~ConstIterator() {
            locale = nullptr;
        }
        
        ConstIterator(T* ptr) {
            locale = ptr;
        }

        ConstIterator(const ConstIterator& other) {
            locale = other.locale;
        }

        ConstIterator(ConstIterator&& other) noexcept {
            locale = other.locale;
            other.locale = nullptr;
        }

        ConstIterator& operator=(const ConstIterator& other) {
            locale = other.locale;
            return *this;
        }

        ConstIterator& operator=(ConstIterator&& other) {
            T* temp = locale;
            locale = other.locale;
            other.locale = temp;
            return *this;
        }

        const ConstIterator& operator++() const {
            locale++;
            return *this;
        }

        const ConstIterator operator++(int) const {
            Iterator old = *this;
            operator++();
            return old;
        }

        const ConstIterator get_next() const {
            ConstIterator next = this;
            return ++next;
        }

        friend bool operator==(const Iterator& lhs, const Iterator& rhs) {
            return lhs.locale == rhs.locale;
        }

        const T& operator*() const {
            return *locale;
        }

        const T* operator->() const {
            return locale;
        }

        ConstIterator& operator--() const {
            locale--;
            return *this;
        }

        ConstIterator operator--(int) const {
            ConstIterator old = *this;
            operator--();
            return old;
        }

        ConstIterator get_prev() const {
            ConstIterator prev = this;
            return --prev;
        }

        ConstIterator& operator[](mlen index) const{
            return *(locale + index);
        }

        ConstIterator& operator+= (mlen index) const {
            locale += index;
            return *this;
        }
        ConstIterator& operator-= (mlen index) const {
            locale -= index;
            return *this;
        }

        friend ConstIterator operator+(ConstIterator lhs, mlen rhs) {
            lhs += rhs;
            return lhs;
        }
        friend ConstIterator operator+(mlen lhs, const ConstIterator& rhs) {
            return lhs + rhs.locale;
        }
        friend ConstIterator operator-(ConstIterator lhs, mlen rhs) {
            lhs -= rhs;
            return rhs;
        }
        friend ConstIterator operator-(mlen lhs, const ConstIterator& rhs) {
            return lhs - rhs.locale;
        }
        friend ConstIterator operator <=> (const ConstIterator& lhs, const ConstIterator& rhs) {
            return lhs.locale <=> rhs.locale;
        }

    private:
        T* locale;
    };
    typedef ReverseIterator<Iterator> reverse_iterator;
    typedef ReverseIterator<ConstIterator> const_reverse_iterator;

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
    //rbegin, rend, rcbegin, rcend
    Iterator begin() {
        return Iterator(&arr_data[0]);
    }

    Iterator end() {
        return Iterator(&arr_data[N]);
    }

    Iterator it_at(mlen index) {
        if (N <= index)
            throw "Index out of bounds";
        return Iterator(&arr_data[index]);
    }
    
    ConstIterator cbegin() {
        return ConstIterator(&arr_data[0]);
    }
    
    ConstIterator cend() {
        return Iteartor(&arr_data[N]);
    }

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

    friend const bool operator==(const Array<T, N>& lhs, const Array<T, N>& rhs) {
        if (&lhs == &rhs)
            return true;
        for (mlen idx = 0; idx < N; idx++) {
            if (lhs[idx] != rhs[idx])
                return false;
        }
        return true;
    }
    
    friend const bool operator<=>(const Array<T, N>& lhs, const Array<T, N>& rhs) {
        for (mlen idx = 0; idx < N; idx++) {
            if (lhs[idx] < rhs[idx])
                return -1;
            else if (lhs[idx] > rhs[idx])
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