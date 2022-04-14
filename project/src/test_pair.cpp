#include <iostream>
// #include <utility>
#include <functional>
#include <algorithm>
#include <utility.hpp>
#include <ft_vector.hpp>
 
int main()
{
    std::cout << std::endl << "\033[35m" << "check PAIR " << "\033[0m" << std::endl;

    int         n = 1;
    int         a[5] = {1, 2, 3, 4, 5};
    std::string str("Hello ");

    std::cout << "\n\033[34m" << "\t make_pare \n"
                              << "\033[0m" << std::endl;

    // build a pair from two ints
    ft::pair<int , int> p1 = ft::make_pair(n, a[1]);
    std::cout << "The value of p1 is "
              << "(" << p1.first << ", " << p1.second << ")\n";
 
    // build a pair from a reference to int and an array (decayed to pointer)
    ft::pair<int, std::string> p2 = ft::make_pair(n, str);
    p2.first = 7;
    std::cout << "The value of p2 is "
              << "(" << p2.first << ", " << p2.second << ")\n";

    std::cout << "\n\033[34m" << "\t operators (by sort) \n"
                              << "\033[0m" << std::endl;
    ft::vector<ft::pair<int, std::string> > v;
    v.push_back(ft::make_pair(2, "baz"));
    v.push_back(ft::make_pair(2, "bar"));
    v.push_back(ft::make_pair(1, "foo"));

    std::sort(v.begin(), v.end());
    for(int i = 0; (size_t)i < v.size() ; ++i) {
        std::cout << "{" << v[i].first << ", \"" << v[i].second << "\"}\n";
    }
}
