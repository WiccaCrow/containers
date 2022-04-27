#include <iostream>
#include <iomanip>
#include <stack.hpp>
#include <stack>

int main() {
    std::cout << std::boolalpha;
 
    ft::stack<int> container;
 
    std::cout << "Initially, container.empty(): " << container.empty() << std::endl;
    std::cout << "Initially, container.size(): " << container.size() << std::endl;

    std::cout << std::endl;

    container.push(42);
    std::cout << "After adding elements (int 42) , container.empty(): " << container.empty() << std::endl;
    std::cout << "Initially, container.size(): " << container.size() << std::endl;
    std::cout << "Initially, container.top(): " << container.top() << std::endl;

    std::cout << std::endl;

    ft::stack<int> container2;
    container2.push(20);
    std::cout << "container2 with int 20: " << container2.top() << std::endl;
    std::cout << "container2 == contaiter: " << ( container2 == container ) << std::endl;
    std::cout << "container2 != contaiter: " << ( container2 != container ) << std::endl;
    std::cout << "container2 >  contaiter: " << ( container2 > container ) << std::endl;
    std::cout << "container2 >= contaiter: " << ( container2 >= container ) << std::endl;
    std::cout << "container2 <  contaiter: " << ( container2 < container ) << std::endl;
    std::cout << "container2 <= contaiter: " << ( container2 <= container ) << std::endl;

    return (0);
}