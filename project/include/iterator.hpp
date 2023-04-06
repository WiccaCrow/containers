#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include <cstddef>
#include <iterator_tag_structs.hpp>
#include <iterator_base.hpp>
#include <iterator_traits.hpp>
#include <iterator_cat.hpp>
#include <iterator_ptr_normal.hpp>
#include <iterator_ptr_normal_const.hpp>
#include <iterator_ptr_reverse.hpp>
#include <iterator_ptr_reverse_non_class.hpp>
#include <iterator_distance.hpp>
#include <iterator>

namespace ft {

// tag
struct int_iterator_tag;

// template struct iterator (for inheritance)
template <typename _iterTag, typename _T, typename _Dist, typename _Pt, typename _Rt>
    struct iterator;

// structures for ...cat... functions
struct OutIt;
template <typename _iterTag, typename _T, typename _Dist, typename _Pt, typename _Rt>
    struct bidirIt;
template <typename _iterTag, typename _T, typename _Dist, typename _Pt, typename _Rt>
    struct RandomIt;

// iterator_traits
template <class _Iterator>
    struct iterator_traits;
template <class _T>
    struct iterator_traits<_T*>;

}

#endif
