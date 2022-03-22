#include <iostream>
#include <ft_iterator_tag_structs.hpp>
#include <ft_enable_if.hpp>
#include <type_traits>

template <typename T>
std::string str(T t,  ft::enable_if_t<std::is_same_v<T, std::string> >* = nullptr ) {
    std::cout << "is string: ";
  return t;
}

template <typename T>
std::string str(T t, ft::enable_if_t<!(std::is_same_v<T, std::string>)>* = nullptr) {
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
