#include <iostream>
#include <iterator_tag_structs.hpp>
#include <ft_enable_if.hpp>
#include <type_traits>

template <typename T>
std::string str(T t, 
        typename ft::enable_if < ft::is_same < T, std::string >::value >::type *ptrt = nullptr ) {
    std::cout << "is   std::string: ";
    return (t);
}

template <typename T>
std::string str(T t, 
        typename ft::enable_if < !(ft::is_same < std::string, T >::value) >::type *ptrt = nullptr ) {
    std::cout << "not  std::string: ";
    return std::to_string(t);
}

std::string str(const char *t) {
    std::cout << "char string:      ";
    return (t);
}

int main()
{
    {
        std::cout << std::endl << "\033[35m" << "check ft::is_same_f " << "\033[0m" << std::endl;

        std::cout << std::boolalpha;
        std::cout << "int, char str: " << ft::is_same_f(2, "Hello") << std::endl;
        std::cout << "int, int: " << ft::is_same_f(2, 2) << std::endl;
        std::cout << "int, char: " << ft::is_same_f(2, '2') << std::endl;
        int a = 2;
        int *ap = &a;
        std::cout << "int, int *: " << ft::is_same_f(a, ap) << std::endl;
        std::string str_cpp("Hello ");
        std::string str_cpp_2("Hello2 ");
        std::cout << "std::string, std::string: " << ft::is_same_f(str_cpp, str_cpp_2) << std::endl;
        std::cout << "std::string, std::string: " << ft::is_same_f(str_cpp, str_cpp) << std::endl;
        std::cout << "std::string, char[]: " << ft::is_same_f(str_cpp, "Hello") << std::endl;
    }

    {
        std::cout << std::endl << "\033[35m" << "check ft::enable_if " << "\033[0m" << std::endl;

        std::string c = "hello";
        std::cout << "str(5)                     : " << str(5) << std::endl;
        std::cout << "str(5u)                    : " << str(5u) << std::endl;
        std::cout << "str(\"Hello \")              : " << str("Hello ") << std::endl;
        std::cout << "str(std::string(\"Hello \")) : " << str(std::string("Hello ")) << std::endl;
    }
    return 0;
}
