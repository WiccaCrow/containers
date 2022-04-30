#ifndef ITERATOR_BINTREE_REVERSE_HPP
#define ITERATOR_BINTREE_REVERSE_HPP

#include <RBTree.hpp>
#include <iterator_traits.hpp>
#include <iterator_tag_structs.hpp>
#include <cstddef>

namespace ft {

template <
    typename Iter >
class binTree_iterator_reverse {
    public:
    typedef typename iterator_traits<Iter>::iterator_category iterator_category;
    typedef typename iterator_traits<Iter>::value_type value_type;
    typedef typename iterator_traits<Iter>::difference_type difference_type;
    typedef typename iterator_traits<Iter>::pointer pointer;
    typedef typename iterator_traits<Iter>::reference reference;

    protected:
    Iter             _M_current;

    public:
    /* Constructs and destructs, operator= */
    binTree_iterator_reverse();
    explicit binTree_iterator_reverse(Iter x);
    // binTree_iterator_reverse(const binTree_iterator_reverse & obj);
    template< class U >
        binTree_iterator_reverse(const binTree_iterator_reverse<U>& other) :
            _M_current(other.base()) {}
    binTree_iterator_reverse & operator=(const binTree_iterator_reverse & obj);
    // template < class Key, class Value >
    //     binTree_iterator_reverse<Iter>&  operator=(Node<pair<Key, Value> >* obj);
    binTree_iterator_reverse & operator=(const Iter & obj);

    // getters
    Iter base() const;

    // Forward iterator requirements and getters
    reference                       operator*() const;
    pointer                         operator->() const;
    binTree_iterator_reverse &      operator++();
    binTree_iterator_reverse        operator++(int);

    // Bidirectional iterator requirements and getters
    binTree_iterator_reverse &   operator--();
    binTree_iterator_reverse     operator--(int);

    // bool
    bool    operator==(const binTree_iterator_reverse & itSecond) const;
    bool    operator==(int & adrrdInt) const;
    bool    operator!=(const binTree_iterator_reverse & itSecond) const;
    bool    operator!=(int & adrrdInt) const;

};

// definitions
// Constructs and destructs, operator=
template <
    class Iter >
binTree_iterator_reverse<Iter>::
    binTree_iterator_reverse() :
            _M_current() {}

template <
    class Iter >
binTree_iterator_reverse<Iter>::
    binTree_iterator_reverse(Iter x) :
            _M_current(x) {}

template <
    class Iter >
binTree_iterator_reverse<Iter>&
binTree_iterator_reverse<Iter>::
    operator=(const binTree_iterator_reverse<Iter>& obj) {
    if (this != &obj) {
        _M_current = obj.base();
    }
    return (*this);
}

template <
    class Iter >
binTree_iterator_reverse<Iter>&
binTree_iterator_reverse<Iter>::
    operator=(const Iter & obj) {
    _M_current = obj;
    return (*this);
}

// getters
template <
    class Iter >
Iter
    binTree_iterator_reverse<Iter>::
    base() const {
    return (_M_current);
}

    // Forward iterator requirements
template <
    class Iter >
typename binTree_iterator_reverse<Iter>::reference
    binTree_iterator_reverse<Iter>::
    operator*() const {
    Iter tmp = _M_current;
    --tmp;
    return (*tmp);
}

template <
    class Iter >
typename binTree_iterator_reverse<Iter>::pointer
binTree_iterator_reverse<Iter>::
    operator->() const {
    Iter tmp = _M_current;
    --tmp;
    return &(*tmp);
}

template <
    class Iter >
binTree_iterator_reverse<Iter>& 
binTree_iterator_reverse<Iter>::
    operator--() {
    ++_M_current;
    return (*this);
}

template <
    class Iter >
binTree_iterator_reverse<Iter>
binTree_iterator_reverse<Iter>::
    operator--(int) {
    binTree_iterator_reverse<Iter> tmp = *this;
    this->operator--();
    return (tmp);
}

    // Bidirectional iterator requirements

template <
    class Iter >
binTree_iterator_reverse<Iter>& 
binTree_iterator_reverse<Iter>::
    operator++() {
    --_M_current;
    return *this;
}

template <
    class Iter >
binTree_iterator_reverse<Iter>
binTree_iterator_reverse<Iter>::
    operator++(int) {
    binTree_iterator_reverse<Iter> tmp = *this;
    this->operator++();
    return (tmp);
}

    // bool

template <
    class Iter >
bool 
binTree_iterator_reverse<Iter>::
    operator==(const binTree_iterator_reverse<Iter> & itSecond) const {
    return (_M_current == itSecond._M_current);
}

template <
    class Iter >
bool 
binTree_iterator_reverse<Iter>::
    operator==(int & adrrdInt) const {
    return (_M_current == static_cast<pointer>(adrrdInt));
}

template <
    class Iter >
bool 
binTree_iterator_reverse<Iter>::
    operator!=(const binTree_iterator_reverse<Iter> & itSecond) const {
    return (!(operator==(itSecond)));
}

template <
    class Iter >
bool 
binTree_iterator_reverse<Iter>::
    operator!=(int & adrrdInt) const {
    return (!(operator==(static_cast<pointer>(adrrdInt))));
}

} // namespace ft

#endif
