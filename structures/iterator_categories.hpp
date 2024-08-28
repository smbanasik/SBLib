#ifndef SB_LIB_ITERATOR_CATEGORIES_HPP
#define SB_LIB_ITERATOR_CATEGORIES_HPP
namespace SB_LIB {
    enum class IteratorCategory {
        INPUT,
        OUTPUT,
        FORWARD,
        BIDIRECTIONAL,
        RANDOM_ACCESS
    }
}
#endif