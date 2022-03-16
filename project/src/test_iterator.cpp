#include <iostream>

void    check_iterators();
void    check_iterators_normal();
void    check_iterators_reverse();

#include <ft_vector.hpp>
#include <cstdlib>

int main(void) {
    check_iterators();
    return (0);
}


void    check_iterators() {
    std::cout << std::endl << "CHECK ITERATORS " << std::endl;
    check_iterators_normal();
    check_iterators_reverse();
}

void    check_iterators_normal() {
    std::cout << "\tnormal " << std::endl;
    ft::vector<std::string> vector_str(5, "Hello ");
    ft::vector<std::string>::iterator it_v_ft = vector_str.begin();

    // vector: check normal (forward) iterator
    for (it_v_ft = vector_str.begin(); it_v_ft != vector_str.end(); it_v_ft++) {
        std::cout << *it_v_ft;
    }

    // vector: check normal (random access) iterator
    char i = '0';
    for (it_v_ft = vector_str.begin(); it_v_ft != vector_str.end(); ++it_v_ft) {
        *it_v_ft += i++;
    }
    it_v_ft = vector_str.begin();
    std::cout << std::endl << *(it_v_ft + 2) << std::endl;

    for (it_v_ft = vector_str.end(); it_v_ft-- != vector_str.begin(); ) {
        std::cout << *it_v_ft << " ";
    }
    std::cout << std::endl;
    it_v_ft = vector_str.begin();
    std::cout << it_v_ft.operator->() << " ";    
    std::cout << std::endl;

}

void    check_iterators_reverse() {
    std::cout << "\treverse " << std::endl;

    int a[] = {0, 1, 2, 3};
    //             ↑  └───── x, y // ft
    //             └──────── z
 
    std::reverse_iterator<int*>
        x (&a[4]),
        y (&a[4]),
        z (&a[3]);

    ft::reverse_iterator<int*>
        x_ft (&a[4]),
        y_ft (&a[4]),
        z_ft (&a[3]);

    std::cout
        << std::boolalpha
        << "*x == " << *x << "        |  " << *x_ft << " == *x_ft" << '\n' // 3
        << "*y == " << *y << "        |  " << *y_ft << " == *x_ft" << '\n' // 3
        << "*z == " << *z << "        |  " << *z_ft << " == *x_ft" << '\n' // 2
        << "x == y ? " << (x == y) << "  | " << (x_ft == y_ft) << '\n' // true
        << "x != y ? " << (x != y) << " | " << (x_ft != y_ft) << '\n' // false
        << "x <  y ? " << (x <  y) << " | " << (x_ft <  y_ft) << '\n' // false
        << "x <= y ? " << (x <= y) << "  | " << (x_ft <= y_ft) << '\n' // true
        << "x == z ? " << (x == z) << " | " << (x_ft == z_ft) << '\n' // false
        << "x != z ? " << (x != z) << "  | " << (x_ft != z_ft) << '\n' // true
        << "x <  z ? " << (x <  z) << "  | " << (x_ft <  z_ft) << '\n' // true!
        << "x <= z ? " << (x <= z) << "  | " << (x_ft <= z_ft) << '\n' // true
        ;
}