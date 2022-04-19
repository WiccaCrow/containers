#ifndef ITERATOR_PTR_REVERSE_NON_CLASS_HPP
# define ITERATOR_PTR_REVERSE_NON_CLASS_HPP

#include <iterator_ptr_reverse.hpp>

template <class Iterator1, class Iterator2>
    bool operator==(const ft::reverse_iterator<Iterator1>& lhs,
                    const ft::reverse_iterator<Iterator2>& rhs) {
    return (lhs.base() == rhs.base());
}

template <class Iterator1, class Iterator2>
    bool operator!=(const ft::reverse_iterator<Iterator1>& lhs,
                    const ft::reverse_iterator<Iterator2>& rhs) {
    return (!(lhs == rhs));
}

template <class Iterator1, class Iterator2>
    bool operator<(const ft::reverse_iterator<Iterator1>& lhs,
                    const ft::reverse_iterator<Iterator2>& rhs) {
    return (rhs.base() < lhs.base());
}

template <class Iterator1, class Iterator2>
    bool operator>(const ft::reverse_iterator<Iterator1>& lhs,
                    const ft::reverse_iterator<Iterator2>& rhs) {
    return (rhs < lhs);
}

template <class Iterator1, class Iterator2>
    bool operator<=(const ft::reverse_iterator<Iterator1>& lhs,
                    const ft::reverse_iterator<Iterator2>& rhs) {
    return (!(rhs < lhs));
}

template <class Iterator1, class Iterator2>
    bool operator>=(const ft::reverse_iterator<Iterator1>& lhs,
                    const ft::reverse_iterator<Iterator2>& rhs) {
    return (!(lhs < rhs));
}

#endif
