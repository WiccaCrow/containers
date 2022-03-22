#ifndef FT_ITERATOR_HPP
#define FT_ITERATOR_HPP

#include <cstddef>
#include <ft_iterator_tag_structs.hpp>
#include <ft_iterator_base.hpp>
#include <ft_iterator_traits.hpp>
#include <ft_iterator_cat.hpp>
#include <ft_iterator_ptr_normal.hpp>
#include <ft_iterator_ptr_reverse.hpp>
#include <ft_iterator_ptr_reverse_non_class.hpp>

namespace ft {

// tag
struct input_iterator_tag;
struct output_iterator_tag;
struct forward_iterator_tag;
struct bidirectional_iterator_tag;
struct random_access_iterator_tag;

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
    struct iterators_traits;
template <class _T>
    struct iterators_traits<_T*>;

};

#endif
