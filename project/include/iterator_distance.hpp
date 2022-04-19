#ifndef ITERATOR_DISTANCE_HPP
#define ITERATOR_DISTANCE_HPP

#include <iterator_base.hpp>
#include <iterator_tag_structs.hpp>
#include <iterator_cat.hpp>
#include <iterator_traits.hpp>

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
    distance_with_cat( InputIt first, InputIt last, D& dist, ::std::input_iterator_tag ) {
        for (; first != last; ++first) {
            ++dist;
        }
    }

template< class InputIt, class D >
void
    distance_with_cat( InputIt first, InputIt last, D& dist, ::std::forward_iterator_tag ) {
        for (; first != last; ++first) {
            ++dist;
        }
    }

template< class InputIt, class D >
void
    distance_with_cat( InputIt first, InputIt last, D& dist, ::std::bidirectional_iterator_tag ) {
        for (; first != last; ++first) {
            ++dist;
        }
    }

template< class InputIt, class D >
void
    distance_with_cat( InputIt first, InputIt last, D& dist, ::std::random_access_iterator_tag ) {
        dist += last - first;
    }

}

#endif
