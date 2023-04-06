#include <iomanip>
#include <iostream>
#include <is_integral.hpp>
// #include <type_traits> // clang++ -g -Wpedantic -Wall -Wextra -Werror -g -std=c++11 -c src/test_is_integral.cpp -o .obj/test_is_integral.o -I include/
// namespace ft = std;

class A {};

template <class T>
bool f(T) {
    return (ft::is_integral<T>::value);
}

void SHOW(std::string str, bool a) {
    std::cout << std::setw(29) << str << a << '\n';
}

int main() {
    std::cout << std::boolalpha;

    // false
    std::cout << std::setw(34) << "\033[32m" << "false " << "\033[0m" << std::endl;
    SHOW("class A is integral: ", ft::is_integral<A>::value);
    SHOW("float is integral: ", ft::is_integral<float>::value);
    SHOW("\"123\" is integral: ", f("123"));
    // true
    std::cout << std::setw(34) << "\033[32m" << "true " << "\033[0m" << std::endl;
    SHOW("bool is integral: ", ft::is_integral<bool>::value);
    SHOW("\'a\' is integral: ", f('a'));
    SHOW("unsigned short is integral: ", ft::is_integral<unsigned short>::value);
    SHOW("unsigned int is integral: ", ft::is_integral<unsigned int>::value);
    SHOW("wchar_t is integral: ", ft::is_integral<wchar_t>::value);
    SHOW("signed char -2 is integral: ", f(-2));
    SHOW("short is integral: ", ft::is_integral<short>::value);
    SHOW("int is integral: ", ft::is_integral<int>::value);
    SHOW("123 is integral: ", f(123));
    SHOW("int is integral: ", ft::is_integral<long>::value);
    SHOW("const int is integral: ", ft::is_integral<const int>::value);

    return (0);
}
