#ifndef FT_ITERATOR_CAT_HPP
#define FT_ITERATOR_CAT_HPP

#include <ft_iterator_base.hpp>
#include <ft_iterator_tag_structs.hpp>
#include <limits>
#include <ft_enable_if.hpp>
#include <iostream>

namespace ft {

template < class T>
random_access_iterator_tag    Iter_cat(const T *) {
    // std::cout << "rand Iter_cat\n";
    random_access_iterator_tag obj;
    return (obj);
}

template <
    typename _iterTag,
    typename _T,
    typename _Dist,
    typename _Pt,
    typename _Rt>
_iterTag    Iter_cat(const iterator_base<_iterTag, _T, _Dist, _Pt, _Rt> &) {
    // std::cout << "_iterTag Iter_cat\n";
    _iterTag obj;
    return (obj);
}


// template < class T>
// int_iterator_tag    Iter_cat(T t, typename enable_if< ::std::numeric_limits<T>::is_specialized, T>::type) {
//     std::cout << "int Iter_cat\n";
//     int_iterator_tag obj;
//     return (obj);
// }

int_iterator_tag    Iter_cat(bool) {
    int_iterator_tag obj;
    return (obj);
}

int_iterator_tag    Iter_cat(char) {
    int_iterator_tag obj;
    return (obj);
}

int_iterator_tag    Iter_cat(signed char) {
    int_iterator_tag obj;
    return (obj);
}

int_iterator_tag    Iter_cat(unsigned char) {
    int_iterator_tag obj;
    return (obj);
}

int_iterator_tag    Iter_cat(wchar_t) {
    int_iterator_tag obj;
    return (obj);
}

int_iterator_tag    Iter_cat(short) {
    int_iterator_tag obj;
    return (obj);
}

int_iterator_tag    Iter_cat(unsigned short) {
    int_iterator_tag obj;
    return (obj);
}

int_iterator_tag    Iter_cat(int) {
    int_iterator_tag obj;
    return (obj);
}

int_iterator_tag    Iter_cat(unsigned int) {
    int_iterator_tag obj;
    return (obj);
}

int_iterator_tag    Iter_cat(long) {
    int_iterator_tag obj;
    return (obj);
}

int_iterator_tag    Iter_cat(unsigned long) {
    int_iterator_tag obj;
    return (obj);
}

}

#endif