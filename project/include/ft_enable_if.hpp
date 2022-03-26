#ifndef FT_ENABLE_IF_HPP
# define FT_ENABLE_IF_HPP

namespace ft {

template<bool B, class T = void>
struct enable_if {};
 
template<class T>
struct enable_if<true, T> { typedef T type; };

// template< bool B, class T = void >
// using enable_if_t = typename enable_if<B,T>::type;

}

#endif
