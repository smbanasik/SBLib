#ifndef SB_LIB_ARRAY_HPP
#define SB_LIB_ARRAY_HPP
namespace SB_LIB {
    template<typename Iterator>
    class ReverseIterator {
        public:
        // TODO: depending on the iterator type given, we should limit what can be called.
        // I'm unsure how to implement this at this time.
        
        ReverseIterator() : it{} {}
        
        ReverseIterator(Iterator ptr) {
            it = ptr;
        }
        
        ReverseIterator(const ReverseIterator& other) {
            it = other.it;
        }
        
        ReverseIterator& operator=(const ReverseIterator& other) {
            it = other.it;
            return *this;
        }
        
        ReverseIterator& operator++() {
            --it;
            return *this;
        }

        ReverseIterator operator++(int) {
            ReverseIterator old = *this;
            operator++();
            return old;
        }

        ReverseIterator get_next() {
            ReverseIterator next = this;
            return ++next;
        }

        friend bool operator==(const ReverseIterator& lhs, const ReverseIterator& rhs) {
            return lhs.it == rhs.it;
        }
        
        friend bool operator==(const ReverseIterator& lhs, const Iterator& rhs) {
            return lhs.it == rhs;
        }
        
        friend bool operator==(const Iterator& lhs, const ReverseIterator& rhs) {
            return lhs == rhs.it;
        }
        
        // Uh oh! How do we use this? We need the iterator traits!
        // We need to return an Iterator::reference
        // and an Iterator::pointer
        Iterator::reference operator*() {
            return *locale;
        }
        
        Iterator::pointer operator->() {
            return locale;
        }
        
        ReverseIterator& operator--() {
            ++it;
            return *this;
        }

        ReverseIterator operator--(int) {
            ReverseIterator old = *this;
            operator--();
            return old;
        }

        ReverseIterator get_prev() {
            ReverseIterator prev = this;
            return --prev;
        }

        ReverseIterator& operator[](mlen index) {
            return *(it + index);
        }

        ReverseIterator& operator+= (mlen index) {
            it += index;
            return *this;
        }
        ReverseIterator& operator-= (mlen index) {
            it -= index;
                return *this;
        }
        
        friend ReverseIterator operator+(ReverseIterator lhs, mlen rhs) {
            lhs += rhs;
            return lhs;
        }
        friend ReverseIterator operator+(mlen lhs, const ReverseIterator& rhs) {
            return lhs + rhs;
        }
        friend ReverseIterator operator-(ReverseIterator lhs, mlen rhs) {
            lhs -= rhs;
            return rhs;
        }
        friend ReverseIterator operator-(mlen lhs, const ReverseIterator& rhs) {
            return lhs - rhs;
        }
        friend ReverseIterator operator <=> (const ReverseIterator& lhs, const ReverseIterator& rhs) {
            return lhs <=> rhs;
        }
        
        private:
        Iterator it;
    };
}
#endif