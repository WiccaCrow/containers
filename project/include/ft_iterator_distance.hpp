#ifndef FT_ITERATOR_DISTANCE_HPP
#define FT_ITERATOR_DISTANCE_HPP

#include <ft_iterator_base.hpp>
#include <ft_iterator_tag_structs.hpp>
#include <ft_iterator_cat.hpp>
#include <ft_iterator_traits.hpp>

namespace ft {

template< class InputIt >
typename iterator_traits<InputIt>::difference_type
    distance( InputIt first, InputIt last ) {
        typename iterator_traits<InputIt>::difference_type  dist = 0;
        distance_with_cat(first, last, dist, Iter_cat(first));
        return (dist);
    }

template< class InputIt, class D >
void
    distance_with_cat( InputIt first, InputIt last, D& dist, input_iterator_tag ) {
        for (; first != last; ++first) {
            ++dist;
        }
    }

template< class InputIt, class D >
void
    distance_with_cat( InputIt first, InputIt last, D& dist, forward_iterator_tag ) {
        for (; first != last; ++first) {
            ++dist;
        }
    }

template< class InputIt, class D >
void
    distance_with_cat( InputIt first, InputIt last, D& dist, bidirectional_iterator_tag ) {
        for (; first != last; ++first) {
            ++dist;
        }
    }

template< class InputIt, class D >
void
    distance_with_cat( InputIt first, InputIt last, D& dist, random_access_iterator_tag ) {
        dist += last - first;
    }

}

#endif