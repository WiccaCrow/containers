#include <iostream>
#include <ft_iterator_tag_structs.hpp>
#include <ft_enable_if.hpp>
#include <type_traits>

namespace ft {
// https://runebook.dev/ru/docs/cpp/types/is_same

template<class T, class U>
struct is_same : std::false_type {};
 
template<class T>
struct is_same<T, T> : std::true_type {};

template <typename _Tp, typename _Up>
  const bool is_same_v = is_same<_Tp, _Up>::value;

template< bool B, class T = void >
using enable_if_t = typename enable_if<B,T>::type;

}

template <typename T>
std::string str(T t,  typename ft::enable_if<ft::is_same_v<T, std::string> >::type* = nullptr ) {
    std::cout << "is string: ";
  return t;
}

template <typename T>
std::string str(T t, typename ft::enable_if<!(ft::is_same_v<T, std::string>)>::type* = nullptr) {
    std::cout << "not string: ";
  return std::to_string(t);
}

int main()
{
    std::string c = "hello";
    std::cout << str(5) << std::endl;
    std::cout << str(c) << std::endl;
    std::cout << str(5u) << std::endl;
    return 0;
}
