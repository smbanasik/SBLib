#ifndef SB_LIB_CIRCULAR_QUEUE_HPP
#define SB_LIB_CIRCULAR_QUEUE_HPP

#include "../types.hpp"
#include "../structures/iterator_categories.hpp"
#include "../structures/reverse_iterator.hpp"

#include <initializer_list>

namespace SB_LIB {

// TODO:
// We need to consider a few things!
// 1) iterator after the last doesn't work for circ queue - add empty space
// 2) can we avoid using two pointers to keep track of them? - unlikely
// 
// We'll have an N+1 sized implementation with two pointers. This gives us
// all of the information that we'll need and the extra space can be used
// to handle the after the end iterator.
// But for big classes, that kind of sucks.
// I'd rather have a constant storage size instead such as "is full" or "is empty,"
// but how can we handle iterators with this?
// The general idea is that if start == end, that's our stop condition, but it's also our
// initial condition.
// Further, iterators are not intrinsically linked to an object, so we can't query it for the information we need.
// https://stackoverflow.com/questions/17239317/circular-queue-without-wasting-an-entry-or-using-counter

template <typename T, mlen N>
class CircularQueue {
public:
    CircularQueue() : arr_data() {}

    CircularQueue(std::initializer_list<T> list) {
        for (auto it = list.begin(); it != list.end(); ++it) {
            arr_data[front] = *it;
            ++front;
        }
    }

    // TODO: cast queue to array

    class Iterator {
    public:
        typedef typename ptr_diff difference_type;
        typedef typename T value_type;
        typedef typename T& reference;
        typedef typename T* pointer;
        typedef typename IteratorRandomAccess iterator_category;

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

        Iterator& operator=(Iterator&& other) noexcept {
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
            Iterator next = *this;
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
            Iterator prev = *this;
            return --prev;
        }

        T& operator[](mlen index) {
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
            return lhs;
        }

        friend Iterator operator-(mlen lhs, const Iterator& rhs) {
            return lhs - rhs.locale;
        }

        friend auto operator <=> (const Iterator& lhs, const Iterator& rhs) {
            return lhs.locale <=> rhs.locale;
        }

    private:
        T* locale;
    };
    class ConstIterator {
    public:
        typedef typename ptr_diff difference_type;
        typedef typename T value_type;
        typedef typename T& reference;
        typedef typename T* pointer;
        typedef typename IteratorRandomAccess iterator_category;

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

        ConstIterator(const Iterator& other) {
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

        ConstIterator& operator++() {
            locale++;
            return *this;
        }

        ConstIterator operator++(int) {
            ConstIterator old = *this;
            operator++();
            return old;
        }

        ConstIterator get_next() {
            ConstIterator next = this;
            return ++next;
        }

        friend bool operator==(const ConstIterator& lhs, const ConstIterator& rhs) {
            return lhs.locale == rhs.locale;
        }

        const T& operator*() const {
            return *locale;
        }

        const T* operator->() const {
            return locale;
        }

        ConstIterator& operator--() {
            locale--;
            return *this;
        }

        ConstIterator operator--(int) {
            ConstIterator old = *this;
            operator--();
            return old;
        }

        ConstIterator get_prev() {
            ConstIterator prev = this;
            return --prev;
        }

        const T& operator[](mlen index) const {
            return *(locale + index);
        }

        ConstIterator& operator+= (mlen index) {
            locale += index;
            return *this;
        }
        ConstIterator& operator-= (mlen index) {
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
        const T* locale;
    };
    typedef ReverseIterator<Iterator> reverse_iterator;
    typedef ReverseIterator<ConstIterator> const_reverse_iterator;

    // -----Access-----

    // TODO: front, back need to be changed
    // add push and pop methods

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
        return arr_data[front];
    }

    T& back() {
        return arr_data[0];
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

    const T& f_at(mlen index) const {
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

    // TODO: update these for front and back

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

    ConstIterator cbegin() const {
        return ConstIterator(&arr_data[0]);
    }

    ConstIterator cend() const {
        return Iterator(&arr_data[N]);
    }

    reverse_iterator rbegin() {
        return reverse_iterator(end() - 1);
    }

    reverse_iterator rend() {
        return reverse_iterator(begin() - 1);
    }

    const_reverse_iterator crbegin() const {
        return const_reverse_iterator(end() - 1);
    }

    const_reverse_iterator crend() const {
        return const_reverse_iterator(begin() - 1);
    }

    // -----Querying-----

    // TODO: size gets diff between front and back
    consteval mlen size() const {
        return N;
    }

    // TODO: are front and back same?
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

    friend const auto operator<=>(const Array<T, N>& lhs, const Array<T, N>& rhs) {
        for (mlen idx = 0; idx < N; idx++) {
            if (lhs[idx] < rhs[idx])
                return -1;
            else if (lhs[idx] > rhs[idx])
                return 1;
        }
        return 0;
    }

private:

    mlen get_prev_front() {
        return (front != 0) ? --front : N - 1;
    }

    mlen get_next_front() {
        return (front != (N - 1) ? ++front : 0;
    }

    T arr_data[N];
    // The most recently entered element in our queue
    T* front;
};
}
#endif