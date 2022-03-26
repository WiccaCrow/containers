#ifndef FT_ITERATOR_PTR_REVERSE_HPP
# define FT_ITERATOR_PTR_REVERSE_HPP

#include <ft_iterator_base.hpp>
#include <ft_iterator_tag_structs.hpp>
#include <ft_iterator_traits.hpp>

namespace ft {
// Итераторы как указатели для контейнеров
// reverse_iterator
template < 
    class Iter>
class reverse_iterator : public iterator_base<
                            typename iterator_traits<Iter>::iterator_category,
                            typename iterator_traits<Iter>::value_type,
                            typename iterator_traits<Iter>::difference_type,
                            typename iterator_traits<Iter>::pointer,
                            typename iterator_traits<Iter>::reference> {
    public:
    typedef typename ft::iterator_traits<Iter>::iterator_category iterator_category;
    typedef typename ft::iterator_traits<Iter>::value_type value_type;
    typedef typename ft::iterator_traits<Iter>::difference_type difference_type;
    typedef typename ft::iterator_traits<Iter>::pointer pointer;
    typedef typename ft::iterator_traits<Iter>::reference reference;
    
    protected:
    Iter _M_current;

    public:
    /* Constructs and destructs, operator= */
    reverse_iterator();
    explicit reverse_iterator(Iter x);
    template< class U >
        reverse_iterator(const reverse_iterator<U>& other) :
                _M_current(other.base()) {}

    reverse_iterator & operator=(const reverse_iterator & other);

    // getters
    Iter base() const;

    // Forward iterator requirements and getters
    reference   operator*() const;
    pointer     operator->() const;
    reverse_iterator &   operator++();
    reverse_iterator     operator++(int);

    // Bidirectional iterator requirements and getters
    reverse_iterator &   operator--();
    reverse_iterator     operator--(int);

    // Random access iterator requirements and getters
    reference   operator[](difference_type n) const;
    reverse_iterator     operator+(difference_type n) const;
    reverse_iterator     operator-(difference_type n) const;
    reverse_iterator &   operator+=(difference_type n) const;
    reverse_iterator &   operator-=(difference_type n) const;

    // bool
    // bool    operator==(const normal_iterator & itSecond) const;
    // bool    operator==(int & adrrdInt) const;
    // bool    operator!=(const normal_iterator & itSecond) const;
    // bool    operator!=(int & adrrdInt) const;

    // bool    operator>(const normal_iterator & itSecond) const;
    // bool    operator<(const normal_iterator & itSecond) const;
    // bool    operator>=(const normal_iterator & itSecond) const;
    // bool    operator<=(const normal_iterator & itSecond) const;
    
};

// definitions
// Constructs and destructs, operator=

template <class Iter>
reverse_iterator<Iter>::
    reverse_iterator() {}

template <class Iter>
reverse_iterator<Iter>::
    reverse_iterator(Iter x) : _M_current(x) {}

template <class Iter>
reverse_iterator<Iter> &
reverse_iterator<Iter>::
    operator=(const reverse_iterator & other) {
    if (this != &other) {
        _M_current = other.base();
    }
    return (*this);
}

// getters
template <class Iter>
Iter
reverse_iterator<Iter>::
    base() const {
    return (_M_current);
}

// // Forward iterator requirements
template <class Iter>
typename reverse_iterator<Iter>::reference
reverse_iterator<Iter>::
    operator*() const {
        Iter tmp = _M_current;
        --tmp;
    return (*tmp);
}

template <class Iter>
typename reverse_iterator<Iter>::pointer
reverse_iterator<Iter>::
    operator->() const {
        Iter tmp = _M_current;
        --tmp;
    return (*tmp);
}

template <class Iter>
reverse_iterator<Iter> &
reverse_iterator<Iter>::
    operator++() {
    --_M_current;
    return *this;
}

template <class Iter>
reverse_iterator<Iter> 
reverse_iterator<Iter>::
    operator++(int) {
    reverse_iterator<Iter> tmp = *this;
    --_M_current;
    return (tmp);
}

// Bidirectional iterator requirements
template <class Iter>
reverse_iterator<Iter> &
reverse_iterator<Iter>::
    operator--() {
    ++_M_current;
    return *this;
}

template <class Iter>
reverse_iterator<Iter>
reverse_iterator<Iter>::
    operator--(int) {
    reverse_iterator<Iter> tmp = *this;
    ++_M_current;
    return (tmp);
}

// Random access iterator requirements and getters
template <class Iter>
typename reverse_iterator<Iter>::reference
reverse_iterator<Iter>::
    operator[](difference_type n) const {
        return (*(*this + n));
}

template <class Iter>
reverse_iterator<Iter> 
reverse_iterator<Iter>::
    operator+(reverse_iterator<Iter>::difference_type n) const {
    reverse_iterator<Iter> tmp(_M_current - n);
    return (tmp);
}

template <class Iter>
reverse_iterator<Iter> 
reverse_iterator<Iter>::
    operator-(reverse_iterator<Iter>::difference_type n) const {
    reverse_iterator<Iter> tmp(_M_current + n);
    return (tmp);
}

template <class Iter>
reverse_iterator<Iter> &
reverse_iterator<Iter>::
    operator+=(reverse_iterator<Iter>::difference_type n) const {
    _M_current -= n;
    return (*this);
}

template <class Iter>
reverse_iterator<Iter> &
reverse_iterator<Iter>::
    operator-=(reverse_iterator<Iter>::difference_type n) const {
    _M_current += n;
    return (*this);
}

/////////

    // Random access iterator requirements and getters

//     // bool

// template <
//     typename _iterTag,
//     typename _Container,
//     typename _Dist,
//     typename _Pt,
//     typename _Rt>
// bool 
// normal_iterator<_iterTag, _Container, _Dist, _Pt, _Rt>::
//     operator==(const normal_iterator<_iterTag, _Container, _Dist, _Pt, _Rt> & itSecond) const {
//     return (_M_current == itSecond._M_current);
// }

// template <
//     typename _iterTag,
//     typename _Container,
//     typename _Dist,
//     typename _Pt,
//     typename _Rt>
// bool 
// normal_iterator<_iterTag, _Container, _Dist, _Pt, _Rt>::
//     operator==(int & adrrdInt) const {
//     return (_M_current == static_cast<_Pt>(adrrdInt));
// }

// template <
//     typename _iterTag,
//     typename _Container,
//     typename _Dist,
//     typename _Pt,
//     typename _Rt>
// bool 
// normal_iterator<_iterTag, _Container, _Dist, _Pt, _Rt>::
//     operator!=(const normal_iterator<_iterTag, _Container, _Dist, _Pt, _Rt> & itSecond) const {
//     return (!(operator==(itSecond)));
// }

// template <
//     typename _iterTag,
//     typename _Container,
//     typename _Dist,
//     typename _Pt,
//     typename _Rt>
// bool 
// normal_iterator<_iterTag, _Container, _Dist, _Pt, _Rt>::
//     operator!=(int & adrrdInt) const {
//     return (!(operator==(static_cast<_Pt>(adrrdInt))));
// }

// template <
//     typename _iterTag,
//     typename _Container,
//     typename _Dist,
//     typename _Pt,
//     typename _Rt>
// bool 
// normal_iterator<_iterTag, _Container, _Dist, _Pt, _Rt>::
//     operator>(const normal_iterator<_iterTag, _Container, _Dist, _Pt, _Rt> & itSecond) const {
//     return (_M_current > itSecond._M_current);
// }

// template <
//     typename _iterTag,
//     typename _Container,
//     typename _Dist,
//     typename _Pt,
//     typename _Rt>
// bool 
// normal_iterator<_iterTag, _Container, _Dist, _Pt, _Rt>::
//     operator<(const normal_iterator<_iterTag, _Container, _Dist, _Pt, _Rt> & itSecond) const {
//     return (itSecond > *this);
// }

// template <
//     typename _iterTag,
//     typename _Container,
//     typename _Dist,
//     typename _Pt,
//     typename _Rt>
// bool 
// normal_iterator<_iterTag, _Container, _Dist, _Pt, _Rt>::
//     operator>=(const normal_iterator<_iterTag, _Container, _Dist, _Pt, _Rt> & itSecond) const {
//     return (!(itSecond > *this));
// }

// template <
//     typename _iterTag,
//     typename _Container,
//     typename _Dist,
//     typename _Pt,
//     typename _Rt>
// bool 
// normal_iterator<_iterTag, _Container, _Dist, _Pt, _Rt>::
//     operator<=(const normal_iterator<_iterTag, _Container, _Dist, _Pt, _Rt> & itSecond) const {
//     return (!(*this > itSecond));
// }

} // namespace ft

#endif
