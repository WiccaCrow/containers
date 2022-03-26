#ifndef FT_ITERATOR_BASE_HPP
#define FT_ITERATOR_BASE_HPP

#include <cstddef>
#include <ft_iterator_tag_structs.hpp>
#include <ft_iterator_traits.hpp>

namespace ft {
// template struct iterator (for inheritance)
template <
    typename _iterTag,
    typename _T,
    typename _Dist = std::ptrdiff_t,
    typename _Pt = _T*,
    typename _Rt = _T&>
struct iterator_base {
    public:
    typedef _iterTag   iterator_category;
    typedef _T value_type;
    typedef _Dist      difference_type;
    typedef _Rt        reference;
    typedef _Pt        pointer;
};
//
//
// OUTPUT iterator
struct OutIt : public iterator_base<output_iterator_tag, void, void, void, void> {};
//
//
// BIDIRECTIONAL iterator
template <
    typename _iterTag,
    typename _T,
    typename _Dist = std::ptrdiff_t,
    typename _Pt = _T*,
    typename _Rt = _T&>
struct bidirIt : public iterator_base<bidirectional_iterator_tag, _T, _Dist, _Pt, _Rt> {};
//
//
// RANDOM access iterator
template <
    typename _iterTag,
    typename _T,
    typename _Dist = std::ptrdiff_t,
    typename _Pt = _T*,
    typename _Rt = _T&>
struct RandomIt : public iterator_base<random_access_iterator_tag, _T, _Dist, _Pt, _Rt> {};
} // namespace ft

#endif
