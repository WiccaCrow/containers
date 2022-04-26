// #include <cassert>
// #include <iostream>
// #include "../include/map.hpp"
// #include <map>

#include <iostream>
#include <iomanip>
#include <utility.hpp>
// #include <vector.hpp>
#include <RBTree.hpp>
#include <iterator_binTree_normal.hpp>
// #include <iterator_binTree_reverse.hpp>
#include <map.hpp>
#include <map>

// Example module 97 key compare function
struct ModCmp {
    bool operator()(const int lhs, const int rhs) const
    {
        return (lhs % 97) < (rhs % 97);
    }
};
 
int main()
{
    std::map<int, char, ModCmp> cont;
	cont.insert( std::make_pair(1, 'a') );
	cont.insert( std::make_pair(2, 'b') );
	cont.insert( std::make_pair(3, 'c') );
	cont.insert( std::make_pair(4, 'd') );
	cont.insert( std::make_pair(5, 'e') );
    std::map<int, char, ModCmp>::value_compare comp_func = cont.value_comp();
 
    const std::pair<int, char> val( 2, 'b' );
 
    for (  std::map<int, char, ModCmp>::iterator iter = cont.begin(); iter != cont.end(); ++iter) {
		std::pair<const int, char> it(*iter); 

        bool before = comp_func(it, val);
        bool after = comp_func(val, it);
 
        std::cout << '(' << it.first << ',' << it.second;
        if (!before && !after)
            std::cout << ") equivalent to key " << val.first << '\n';
        else if (before)
            std::cout << ") goes before key " << val.first << '\n';
        else if (after)
            std::cout << ") goes after key " << val.first << '\n';
        else
            assert(0); // Cannot happen
    }

std::cout << std::endl;

	ft::map<int, char, ModCmp> cont_ft;

	cont_ft.insert( ft::make_pair(1, 'a') );
	cont_ft.insert( ft::make_pair(2, 'b') );
	cont_ft.insert( ft::make_pair(3, 'c') );
	cont_ft.insert( ft::make_pair(4, 'd') );
	cont_ft.insert( ft::make_pair(5, 'e') );

    ft::map<int, char, ModCmp>::value_compare comp_func_ft = cont_ft.value_comp();
 
    const ft::pair<int, char> val_ft( 2, 'b' );
    for (  ft::map<int, char, ModCmp>::iterator iter = cont_ft.begin(); iter != cont_ft.end(); ++iter) {
		ft::pair<const int, char> it(*iter); 
        bool before = comp_func_ft(it, val_ft);
        bool after = comp_func_ft(val_ft, it);
 
        std::cout << '(' << it.first << ',' << it.second;
        if (!before && !after)
            std::cout << ") equivalent to key " << val.first << '\n';
        else if (before)
            std::cout << ") goes before key " << val.first << '\n';
        else if (after)
            std::cout << ") goes after key " << val.first << '\n';
        else
            assert(0); // Cannot happen
    }
}