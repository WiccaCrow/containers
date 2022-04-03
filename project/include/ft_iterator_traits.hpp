#ifndef FT_ITERATOR_TRAITS_HPP
#define FT_ITERATOR_TRAITS_HPP

#include <ft_iterator_tag_structs.hpp>

namespace ft {
    
template <class _Iterator>
struct iterator_traits {
    typedef typename _Iterator::iterator_category iterator_category;
    typedef typename _Iterator::value_type        value_type;
    typedef typename _Iterator::difference_type   difference_type;
    typedef typename _Iterator::pointer           pointer;
    typedef typename _Iterator::reference         reference;
};

template <class _T>
struct iterator_traits<_T*> {
    typedef ::std::random_access_iterator_tag iterator_category;
    typedef _T                                value_type;
    typedef std::ptrdiff_t                    difference_type;
    typedef _T*                               pointer;
    typedef _T&                               reference;
};

template <class _T>
struct iterator_traits<const _T*> {
    typedef ::std::random_access_iterator_tag iterator_category;
    typedef _T                                value_type;
    typedef std::ptrdiff_t                    difference_type;
    typedef const _T*                         pointer;
    typedef const _T&                         reference;
};

}

#endif
