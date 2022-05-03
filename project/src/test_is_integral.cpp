#include <is_integral.hpp>

#include <iostream>
#include <iomanip>

class A {};

template <class T>
bool f(T )
{
    return ( ft::is_integral<T>::value );
}
 
void SHOW(std::string str, bool a) { 
    std::cout << std::setw(29) << str << a << '\n';
}

int main()
{
    std::cout << std::boolalpha;

    // false
    SHOW( "class A is integral: ", ft::is_integral<A>::value );
    SHOW( "float is integral: ", ft::is_integral<float>::value );
    SHOW( "\"123\" is integral: ", f("123") );
    // true
    SHOW( "bool is integral: ", ft::is_integral<bool>::value );
    SHOW( "\'a\' is integral: ", f('a') );
    SHOW( "char16_t is integral: ", ft::is_integral<char16_t>::value );
    SHOW( "char32_t is integral: ", ft::is_integral<char32_t>::value );
    SHOW( "wchar_t is integral: ", ft::is_integral<wchar_t>::value );
    SHOW( "signed char -2 is integral: ", f(-2) );
    SHOW( "short is integral: ", ft::is_integral<short>::value );
    SHOW( "int is integral: ", ft::is_integral<int>::value );
    SHOW( "123 is integral: ", f(123) );
    SHOW( "int is integral: ", ft::is_integral<long>::value );
    SHOW( "const int is integral: ", ft::is_integral<const int>::value );

    return (0);
}
