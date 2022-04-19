#ifndef ITERATOR_CAT_HPP
#define ITERATOR_CAT_HPP

#include <iterator_base.hpp>
#include <iterator_tag_structs.hpp>
#include <limits>
#include <iostream>

namespace ft {

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

template < class T >
::std::random_access_iterator_tag
    Iter_cat(const T *) {
    // std::cout << "rand Iter_cat\n";
    ::std::random_access_iterator_tag obj;
    return (obj);
}

template < class T >
std::input_iterator_tag
    Iter_cat(const T ) {
    // std::cout << "std_input_iterator_tag Iter_cat\n";
    std::input_iterator_tag obj;
    return (obj);
}

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
        // std::cout << "int Iter_cat\n";
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
