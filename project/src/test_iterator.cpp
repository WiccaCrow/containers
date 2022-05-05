#include <iostream>
#include <iterator.hpp>

void check_iterators();
void check_iterators_normal();
void check_iterators_reverse();

#include <cstdlib>
#include <vector.hpp>

int main(void) {
    check_iterators();
    return (0);
}

void check_iterators() {
    std::cout << std::endl
              << "\033[36m"
              << "CHECK ITERATORS "
              << "\033[0m" << std::endl;
    check_iterators_normal();
    check_iterators_reverse();
}

void check_iterators_normal() {
    std::cout << "\033[34m"
              << "\tnormal "
              << "\033[0m" << std::endl;
    std::cout << "\033[32m"
              << "vector<string> vector_str(5, \"Hello \");"
              << "\033[0m" << std::endl;
    ft::vector<std::string>           vector_str(5, "Hello ");
    ft::vector<std::string>::iterator it_v_ft = vector_str.begin();

    // vector: check normal (forward) iterator
    std::cout << "\033[32m"
              << "\ncout from begin to end (iter++)"
              << "\033[0m" << std::endl;
    for (it_v_ft = vector_str.begin(); it_v_ft != vector_str.end(); it_v_ft++) {
        std::cout << *it_v_ft;
    }

    // vector: check normal (random access) iterator
    std::cout << "\033[32m"
              << "\n\nNow I'll number it from beginning to end (++iter, *it_v_ft += i++;)"
              << "\033[0m" << std::endl;
    char i = '0';
    for (it_v_ft = vector_str.begin(); it_v_ft != vector_str.end(); ++it_v_ft) {
        *it_v_ft += i++;
    }

    std::cout << "\033[32m"
              << "\niter = vector_str.begin(); cout *(iter + 2)"
              << "\033[0m" << std::endl;
    it_v_ft = vector_str.begin();
    std::cout << *(it_v_ft + 2) << std::endl;

    std::cout << "\033[32m"
              << "\ncout from end to begin (iter--)"
              << "\033[0m" << std::endl;
    for (it_v_ft = vector_str.end(); it_v_ft-- != vector_str.begin();) {
        std::cout << *it_v_ft << " ";
    }

    std::cout << "\033[32m"
              << "\n\nit_v_ft = vector_str.begin(); cout it_v_ft.operator->()"
              << "\033[0m" << std::endl;
    it_v_ft = vector_str.begin();
    std::cout << it_v_ft.operator->() << " ";
    std::cout << std::endl;

    std::cout << "\033[32m"
              << "\ndist(begin, end)"
              << "\033[0m" << std::endl;
    std::cout << ft::distance(vector_str.begin(), vector_str.end()) << std::endl
              << std::endl;
    std::cout << ft::distance(vector_str.begin(), vector_str.begin() + 2) << std::endl
              << std::endl;
}

void check_iterators_reverse() {
    std::cout << "\033[34m"
              << "\treverse "
              << "\033[0m" << std::endl;

    std::cout << "\033[32m"
              << "int a[] = {0, 1, 2, 3};"
              << "\033[0m" << std::endl;
    std::cout << "\033[32m"
              << "              ↑  └───── x, y"
              << "\033[0m" << std::endl;
    std::cout << "\033[32m"
              << "              └──────── z"
              << "\033[0m" << std::endl
              << std::endl;
    std::cout << "\033[32m"
              << "reverse_iterator<int*>"
              << "\033[0m" << std::endl;
    std::cout << "\033[32m"
              << "    x (&a[4]),"
              << "\033[0m" << std::endl;
    std::cout << "\033[32m"
              << "    y (&a[4]),"
              << "\033[0m" << std::endl;
    std::cout << "\033[32m"
              << "    z (&a[3]);"
              << "\033[0m" << std::endl
              << std::endl;

    int a[] = {0, 1, 2, 3};

    std::reverse_iterator<int*>
        x(&a[4]),
        y(&a[4]),
        z(&a[3]);

    ft::reverse_iterator<int*>
        x_ft(&a[4]),
        y_ft(&a[4]),
        z_ft(&a[3]);

    std::cout
        << std::boolalpha
        << "*x_std == " << *x << "    |  " << *x_ft << " == *x_ft" << '\n' // 3
        << "*y_std == " << *y << "    |  " << *y_ft << " == *x_ft" << '\n' // 3
        << "*z_std == " << *z << "    |  " << *z_ft << " == *x_ft" << '\n' // 2
        << "x == y ? " << (x == y) << "  | " << (x_ft == y_ft) << '\n'     // true
        << "x != y ? " << (x != y) << " | " << (x_ft != y_ft) << '\n'      // false
        << "x <  y ? " << (x < y) << " | " << (x_ft < y_ft) << '\n'        // false
        << "x <= y ? " << (x <= y) << "  | " << (x_ft <= y_ft) << '\n'     // true
        << "x == z ? " << (x == z) << " | " << (x_ft == z_ft) << '\n'      // false
        << "x != z ? " << (x != z) << "  | " << (x_ft != z_ft) << '\n'     // true
        << "x <  z ? " << (x < z) << "  | " << (x_ft < z_ft) << '\n'       // true!
        << "x <= z ? " << (x <= z) << "  | " << (x_ft <= z_ft) << '\n'     // true
        ;
}
