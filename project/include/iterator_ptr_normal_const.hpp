#ifndef CONST_ITERATOR_PTR_NORMAL_HPP
#define CONST_ITERATOR_PTR_NORMAL_HPP

#include <cstddef>
#include <iterator_base.hpp>
#include <iterator_tag_structs.hpp>

namespace ft {
// Итераторы как указатели для контейнеров
// const_normal_iterator
template <
    typename _iterTag,
    typename _Container,
    typename _Dist = std::ptrdiff_t,
    typename _Pt = const _Container*,
    typename _Rt = const _Container&>
class const_normal_iterator : public iterator_base<
                            ::std::random_access_iterator_tag,
                            _Container,
                            _Dist,
                            _Pt,
                            _Rt> {
    protected:
    _Pt _M_current;

    public:
    /* Constructs and destructs, operator= */
    const_normal_iterator();
    explicit const_normal_iterator(_Pt Ptr);
    const_normal_iterator(const const_normal_iterator & obj);
    const_normal_iterator & operator=(const const_normal_iterator & obj);
    const_normal_iterator & operator=(const _Pt ptr);

    // getters
    _Pt base() const;

    // Forward iterator requirements and getters
    _Rt                 operator*() const;
    _Rt                 operator->() const;
    const_normal_iterator &   operator++();
    const_normal_iterator     operator++(int);

    // Bidirectional iterator requirements and getters
    const_normal_iterator &   operator--();
    const_normal_iterator     operator--(int);

    // Random access iterator requirements and getters
    _Rt                 operator[](const _Dist n);
    const_normal_iterator     operator+(const _Dist n) const;
    const_normal_iterator     operator-(const _Dist n) const;
    const_normal_iterator &   operator+=(const _Dist n);
    const_normal_iterator &   operator-=(const _Dist n);
    _Dist               operator-(const const_normal_iterator & itSecond) const;

    // bool
    bool    operator==(const const_normal_iterator & itSecond) const;
    bool    operator==(int & adrrdInt) const;
    bool    operator!=(const const_normal_iterator & itSecond) const;
    bool    operator!=(int & adrrdInt) const;

    bool    operator>(const const_normal_iterator & itSecond) const;
    bool    operator<(const const_normal_iterator & itSecond) const;
    bool    operator>=(const const_normal_iterator & itSecond) const;
    bool    operator<=(const const_normal_iterator & itSecond) const;

}; // typename не скомпилится

// definitions
// Constructs and destructs, operator=
template <
    typename _iterTag,
    typename _Container,
    typename _Dist,
    typename _Pt,
    typename _Rt>
const_normal_iterator<_iterTag, _Container, _Dist, _Pt, _Rt>::
    const_normal_iterator() {}

template <
    typename _iterTag,
    typename _Container,
    typename _Dist,
    typename _Pt,
    typename _Rt>
const_normal_iterator<_iterTag, _Container, _Dist, _Pt, _Rt>::
    const_normal_iterator(_Pt Ptr) : _M_current(Ptr) {}

template <
    typename _iterTag,
    typename _Container,
    typename _Dist,
    typename _Pt,
    typename _Rt>
const_normal_iterator<_iterTag, _Container, _Dist, _Pt, _Rt>::
    const_normal_iterator(const const_normal_iterator<_iterTag, _Container, _Dist, _Pt, _Rt>& obj) : _M_current(obj.base()) {}

template <
    typename _iterTag,
    typename _Container,
    typename _Dist,
    typename _Pt,
    typename _Rt>
const_normal_iterator<_iterTag, _Container, _Dist, _Pt, _Rt>&
const_normal_iterator<_iterTag, _Container, _Dist, _Pt, _Rt>::
    operator=(const const_normal_iterator<_iterTag, _Container, _Dist, _Pt, _Rt>& obj) {
    if (this != &obj) {
        _M_current = obj.base();
    }
    return (*this);
}

template <
    typename _iterTag,
    typename _Container,
    typename _Dist,
    typename _Pt,
    typename _Rt>
const_normal_iterator<_iterTag, _Container, _Dist, _Pt, _Rt>&
const_normal_iterator<_iterTag, _Container, _Dist, _Pt, _Rt>::
    operator=(const _Pt ptr) {
    _M_current = ptr;
    return (*this);
}

// getters
template <
    typename _iterTag,
    typename _Container,
    typename _Dist,
    typename _Pt,
    typename _Rt>
_Pt const_normal_iterator<_iterTag, _Container, _Dist, _Pt, _Rt>::
    base() const {
    return (_M_current);
}

    // Forward iterator requirements
template <
    typename _iterTag,
    typename _Container,
    typename _Dist,
    typename _Pt,
    typename _Rt>
_Rt const_normal_iterator<_iterTag, _Container, _Dist, _Pt, _Rt>::
    operator*() const {
    return (*_M_current);
}

template <
    typename _iterTag,
    typename _Container,
    typename _Dist,
    typename _Pt,
    typename _Rt>
_Rt const_normal_iterator<_iterTag, _Container, _Dist, _Pt, _Rt>::
    operator->() const {
    // return (&operator*());
    return (operator*());
}

template <
    typename _iterTag,
    typename _Container,
    typename _Dist,
    typename _Pt,
    typename _Rt>
const_normal_iterator<_iterTag, _Container, _Dist, _Pt, _Rt>& 
const_normal_iterator<_iterTag, _Container, _Dist, _Pt, _Rt>::
    operator++() {
    ++_M_current;
    return *this;
}

template <
    typename _iterTag,
    typename _Container,
    typename _Dist,
    typename _Pt,
    typename _Rt>
const_normal_iterator<_iterTag, _Container, _Dist, _Pt, _Rt> 
const_normal_iterator<_iterTag, _Container, _Dist, _Pt, _Rt>::
    operator++(int) {
    const_normal_iterator<_iterTag, _Container, _Dist, _Pt, _Rt> tmp = *this;
    ++_M_current;
    return (tmp);
}

    // Bidirectional iterator requirements

template <
    typename _iterTag,
    typename _Container,
    typename _Dist,
    typename _Pt,
    typename _Rt>
const_normal_iterator<_iterTag, _Container, _Dist, _Pt, _Rt>& 
const_normal_iterator<_iterTag, _Container, _Dist, _Pt, _Rt>::
    operator--() {
    --_M_current;
    return *this;
}

template <
    typename _iterTag,
    typename _Container,
    typename _Dist,
    typename _Pt,
    typename _Rt>
const_normal_iterator<_iterTag, _Container, _Dist, _Pt, _Rt> 
const_normal_iterator<_iterTag, _Container, _Dist, _Pt, _Rt>::
    operator--(int) {
    const_normal_iterator<_iterTag, _Container, _Dist, _Pt, _Rt> tmp = *this;
    --_M_current;
    return (tmp);
}

    // Random access iterator requirements and getters
template <
    typename _iterTag,
    typename _Container,
    typename _Dist,
    typename _Pt,
    typename _Rt>
_Rt
const_normal_iterator<_iterTag, _Container, _Dist, _Pt, _Rt>::
    operator[](const _Dist n) {
    return (*(*this + n));
}

template <
    typename _iterTag,
    typename _Container,
    typename _Dist,
    typename _Pt,
    typename _Rt>
const_normal_iterator<_iterTag, _Container, _Dist, _Pt, _Rt> 
const_normal_iterator<_iterTag, _Container, _Dist, _Pt, _Rt>::
    operator+(const _Dist n) const {
    const_normal_iterator<_iterTag, _Container, _Dist, _Pt, _Rt> tmp(_M_current + n);
    return (tmp);
}

template <
    typename _iterTag,
    typename _Container,
    typename _Dist,
    typename _Pt,
    typename _Rt>
const_normal_iterator<_iterTag, _Container, _Dist, _Pt, _Rt> 
const_normal_iterator<_iterTag, _Container, _Dist, _Pt, _Rt>::
    operator-(const _Dist n) const {
    const_normal_iterator<_iterTag, _Container, _Dist, _Pt, _Rt> tmp(_M_current - n);
    return (tmp);
}

template <
    typename _iterTag,
    typename _Container,
    typename _Dist,
    typename _Pt,
    typename _Rt>
const_normal_iterator<_iterTag, _Container, _Dist, _Pt, _Rt> &
const_normal_iterator<_iterTag, _Container, _Dist, _Pt, _Rt>::
    operator+=(const _Dist n) {
    _M_current+=n;
    return (*this);
}

template <
    typename _iterTag,
    typename _Container,
    typename _Dist,
    typename _Pt,
    typename _Rt>
const_normal_iterator<_iterTag, _Container, _Dist, _Pt, _Rt> &
const_normal_iterator<_iterTag, _Container, _Dist, _Pt, _Rt>::
    operator-=(const _Dist n) {
    _M_current-=n;
    return (*this);
}

template <
    typename _iterTag,
    typename _Container,
    typename _Dist,
    typename _Pt,
    typename _Rt>
_Dist
const_normal_iterator<_iterTag, _Container, _Dist, _Pt, _Rt>::
    operator-(const const_normal_iterator & itSecond) const {
    return (_M_current - itSecond._M_current);
}

    // bool

template <
    typename _iterTag,
    typename _Container,
    typename _Dist,
    typename _Pt,
    typename _Rt>
bool 
const_normal_iterator<_iterTag, _Container, _Dist, _Pt, _Rt>::
    operator==(const const_normal_iterator<_iterTag, _Container, _Dist, _Pt, _Rt> & itSecond) const {
    return (_M_current == itSecond._M_current);
}

template <
    typename _iterTag,
    typename _Container,
    typename _Dist,
    typename _Pt,
    typename _Rt>
bool 
const_normal_iterator<_iterTag, _Container, _Dist, _Pt, _Rt>::
    operator==(int & adrrdInt) const {
    return (_M_current == static_cast<_Pt>(adrrdInt));
}

template <
    typename _iterTag,
    typename _Container,
    typename _Dist,
    typename _Pt,
    typename _Rt>
bool 
const_normal_iterator<_iterTag, _Container, _Dist, _Pt, _Rt>::
    operator!=(const const_normal_iterator<_iterTag, _Container, _Dist, _Pt, _Rt> & itSecond) const {
    return (!(operator==(itSecond)));
}

template <
    typename _iterTag,
    typename _Container,
    typename _Dist,
    typename _Pt,
    typename _Rt>
bool 
const_normal_iterator<_iterTag, _Container, _Dist, _Pt, _Rt>::
    operator!=(int & adrrdInt) const {
    return (!(operator==(static_cast<_Pt>(adrrdInt))));
}

template <
    typename _iterTag,
    typename _Container,
    typename _Dist,
    typename _Pt,
    typename _Rt>
bool 
const_normal_iterator<_iterTag, _Container, _Dist, _Pt, _Rt>::
    operator>(const const_normal_iterator<_iterTag, _Container, _Dist, _Pt, _Rt> & itSecond) const {
    return (_M_current > itSecond._M_current);
}

template <
    typename _iterTag,
    typename _Container,
    typename _Dist,
    typename _Pt,
    typename _Rt>
bool 
const_normal_iterator<_iterTag, _Container, _Dist, _Pt, _Rt>::
    operator<(const const_normal_iterator<_iterTag, _Container, _Dist, _Pt, _Rt> & itSecond) const {
    return (itSecond > *this);
}

template <
    typename _iterTag,
    typename _Container,
    typename _Dist,
    typename _Pt,
    typename _Rt>
bool 
const_normal_iterator<_iterTag, _Container, _Dist, _Pt, _Rt>::
    operator>=(const const_normal_iterator<_iterTag, _Container, _Dist, _Pt, _Rt> & itSecond) const {
    return (!(itSecond > *this));
}

template <
    typename _iterTag,
    typename _Container,
    typename _Dist,
    typename _Pt,
    typename _Rt>
bool 
const_normal_iterator<_iterTag, _Container, _Dist, _Pt, _Rt>::
    operator<=(const const_normal_iterator<_iterTag, _Container, _Dist, _Pt, _Rt> & itSecond) const {
    return (!(*this > itSecond));
}

} // namespace ft

#endif
