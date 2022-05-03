#ifndef ENABLE_IF_HPP
# define ENABLE_IF_HPP

#include  <true_false_type.hpp>

//////////////  enable_if

namespace ft {

template<bool B, class T = void>
struct enable_if {};
 
template<class T>
struct enable_if<true, T> { typedef T type; };

// https://runebook.dev/ru/docs/cpp/types/is_same

template<class T, class U>
struct is_same : false_type {};
 
template<class T>
struct is_same<T, T> : true_type {};

} // namespace ft

//////////////  is_same_f function

namespace ft {

template <class T1, class T2>
bool
    is_same_f(T1 , T2 ) {
        return (false);
    }

template <class T1>
bool
    is_same_f(T1 , T1 ) {
        return (true);
    }
} // namespace ft

#endif
