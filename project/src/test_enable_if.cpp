#include <iostream>
#include <iterator.hpp>
#include <ft_enable_if.hpp>
#include <iterator_cat.hpp>

// template <class It>
// void    someFunction(It iter) {
//     std::cout << str(5) << std::endl;
//     std::cout << str(c) << std::endl;
//     std::cout << str(5u) << std::endl;
// }

int main()
{
    typedef ft::normal_iterator<std::random_access_iterator_tag, int*>       iterator_ran;
    typedef ft::normal_iterator<std::bidirectional_iterator_tag, char*>       iterator_bid;
    typedef ft::normal_iterator<ft::int_iterator_tag, int>                 iterator_int;

    iterator_ran    rand_it;
    iterator_bid    bid_it;
    iterator_int    int_it;

    ft::Iter_cat(rand_it);
    ft::Iter_cat(bid_it);
    ft::Iter_cat(int_it);
    return 0;
}
