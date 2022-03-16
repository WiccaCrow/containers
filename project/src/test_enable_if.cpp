#include <iostream>
#include <ft_iterator_tag_structs.hpp>
#include <ft_enable_if.hpp>
#include <type_traits>

template <class T>
void foo1(const T &) { std::cout << "foo1" << std::endl; }

template < class T, class = typename std::enable_if<std::is_integral<T>::value, T>::type>
void foo2(const T &) { std::cout << "foo2" << std::endl; }

struct X {};

int main()
{
    // foo2(X());
    foo1(5);
    return 0;
}
