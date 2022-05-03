#include <iostream>
#include <iomanip>
#include <cassert>
#include <utility.hpp>
// #include <vector.hpp>
#include <RBTree.hpp>
#include <iterator_binTree_normal.hpp>
// #include <iterator_binTree_reverse.hpp>

#include <set.hpp>
#include <set>

// TESTS
void    testSet_copy_insert();
void    testSet_insert();
void    testSet_iterator();
void    testSet_iterator_reverse();
void    testSet_capacity();
void    testSet_lookup();
void    erase_additional_little_test();
void    testSet_erase();
void    testSet_clear();
void    testSet_erase_for_destructor();
void    testSet_swap();
void    testSet_observers();
void    testSet_non_members();
void    testSet_erase_root();
 // UTILITY
void    fill_set(ft::set<int>* my_set, std::set<int>* std_set);
void    tree_picture(ft::set<int> &my_set);
template <typename T>
    void print_int_key_node(ft::Node<T > *node);
void    print_int(const int& n);
template<class Iter >
    void for_each_ft(Iter begin, Iter end, void(*op)(const int& ));
// At the Mountains of Madness

 /*------------------START-------------------*/

int main() {
    testSet_copy_insert();
    testSet_insert(); // 15
    testSet_iterator(); // 7, 8
    testSet_iterator_reverse(); // 9, 10
    testSet_capacity(); // 11, 12, 13
    testSet_lookup(); // 19
    erase_additional_little_test(); // 16
    testSet_erase(); // 16
    testSet_clear(); // 14
    testSet_erase_for_destructor();
    testSet_swap(); // 17
    testSet_observers(); // 23, 24
    testSet_non_members(); // 25-31
    testSet_erase_root(); // 16
    return (0);
}

 /*------------------UTILITY-------------------*/

void    fill_set(ft::set<int> * my_tree, std::set<int>* std_tree) {
    if (my_tree != NULL) {
        my_tree->insert(80  );
        my_tree->insert(40  );
        my_tree->insert(150 );
        my_tree->insert(60  );
        my_tree->insert(20  );
        my_tree->insert(10  );
        my_tree->insert(170 );
        my_tree->insert(140 );
        my_tree->insert(120 );
        my_tree->insert(0   );
        my_tree->insert(-10 );
        my_tree->insert(130 );
        my_tree->insert(110 );
        my_tree->insert(122 );
        my_tree->insert(100 );
        my_tree->insert(90  );
        my_tree->insert(85  );
    }

    if (std_tree != NULL) {
        std_tree->insert(80  );
        std_tree->insert(40  );
        std_tree->insert(150 );
        std_tree->insert(60  );
        std_tree->insert(20  );
        std_tree->insert(10  );
        std_tree->insert(170 );
        std_tree->insert(140 );
        std_tree->insert(120 );
        std_tree->insert(0   );
        std_tree->insert(-10 );
        std_tree->insert(130 );
        std_tree->insert(110 );
        std_tree->insert(122 );
        std_tree->insert(100 );
        std_tree->insert(90  );
        std_tree->insert(85  );
    }
}

void tree_picture(ft::set<int> &my_tree) {
    if ( my_tree.empty() ) {
        std::cout << "Tree is empty. " << std::endl;
        return ;
    }
    // 80
    std::cout << "                                            ________";
    print_int_key_node( my_tree.root().base() );
    std::cout << "_________" << std::endl;

    std::cout << "                           ________________/                      \\_______________" << std::endl;
    // 10 120 // 2h
    std::cout << "                        ";
    print_int_key_node( my_tree.root().base()->left ); // 2h-1w pos
    std::cout << "                                                   ";
    print_int_key_node( my_tree.root().base()->right ); // 2h-2w pos
    if ( my_tree.root().base()->left->_is_empty == false && my_tree.root().base()->right->_is_empty == false) {
        std::cout << std::endl << "              _________/      \\_________                              _________/      \\_________" << std::endl;
    } else if ( my_tree.root().base()->left->_is_empty == false && my_tree.root().base()->right->_is_empty == true ) {
        std::cout << std::endl << "              _________/      \\_________" << std::endl;
    } else if (my_tree.root().base()->left->_is_empty == true && my_tree.root().base()->right->_is_empty == false) {
        std::cout << std::endl << "                                                                      _________/      \\_________" << std::endl;
    } else {
        std::cout << std::endl;
        return ;
    }
    // 0 40 100 140 // 3h
    if ( my_tree.root().base()->left->_is_empty == false ) {
        std::cout << "           ";
        print_int_key_node( my_tree.root().base()->left->left ); // 3h-1w pos // 0
        std::cout << "                      ";
        print_int_key_node( my_tree.root().base()->left->right ); // 3h-2w pos // 40
        std::cout << "                        ";
    } else {
        std::cout << "         "
                     "      " // 3h-1w pos
                     "                     "
                     "      " // 3h-2w pos
                     "                         ";
    }
    if ( my_tree.root().base()->right->_is_empty == false ) {
        print_int_key_node( my_tree.root().base()->right->left ); // 3h-3w pos // 100
        std::cout << "                      ";
        print_int_key_node( my_tree.root().base()->right->right ); // 3h-4w pos // 140
    }
    
    std::cout << std::endl;
    if ( my_tree.root().base()->left->_is_empty == false &&
         my_tree.root().base()->left->left->_is_empty == false ) {
        std::cout << "        __/     \\__"; // 4h-1,2w pos
    } else {
        std::cout << "                   "; // 4h-1,2w pos
    }
    if ( my_tree.root().base()->left->_is_empty == false &&
         my_tree.root().base()->left->right->_is_empty == false ) {
        std::cout << "                __/      \\__"; // 4h-3,4w pos
    } else {
        std::cout << "                            "; // 4h-3,4w pos
    }
    if ( my_tree.root().base()->right->_is_empty == false &&
         my_tree.root().base()->right->left->_is_empty == false ) {
        std::cout << "                __/      \\__"; // 4h-5,6w pos
    } else {
        std::cout << "                            "; // 4h-5,6w pos
    }
    if ( my_tree.root().base()->right->_is_empty == false &&
         my_tree.root().base()->right->right->_is_empty == false ) {
        std::cout << "                __/      \\__"; // 4h-7,8w pos
    }
    std::cout << std::endl;
    // -10 NIL 20 NIL 90 110 130 150
    if ( ( my_tree.root().base()->left->_is_empty && 
           my_tree.root().base()->right->_is_empty ) ||
         ( my_tree.root().base()->left->_is_empty == false &&
           my_tree.root().base()->left->left->_is_empty && 
           my_tree.root().base()->left->right->_is_empty && 
           my_tree.root().base()->right->_is_empty ) ||
         ( my_tree.root().base()->right->_is_empty == false &&
           my_tree.root().base()->right->left->_is_empty && 
           my_tree.root().base()->right->right->_is_empty && 
           my_tree.root().base()->left->_is_empty )
       ) {
           return ;
    }

    if ( my_tree.root().base()->left->_is_empty ) {
        std::cout << "                                                          ";
    } else {
        if (my_tree.root().base()->left->left->_is_empty == false) {
            std::cout << "     ";
            print_int_key_node( my_tree.root().base()->left->left->left ); // 4h-1w pos // -10
            std::cout << "       ";
            print_int_key_node( my_tree.root().base()->left->left->right ); // 4h-2w pos // NIL
            std::cout << "          ";
        } else {
            std::cout << "                                ";
        }
        if (my_tree.root().base()->left->right->_is_empty == false) {
            print_int_key_node( my_tree.root().base()->left->right->left ); // 4h-3w pos // 20
            std::cout << "        ";
            print_int_key_node( my_tree.root().base()->left->right->right ); // 4h-4w pos // NIL
            std::cout << "          ";
        } else {
            std::cout << "                            ";
        }
    }
    if ( my_tree.root().base()->right->_is_empty == false ) {
        if (my_tree.root().base()->right->left->_is_empty == false) {
            print_int_key_node( my_tree.root().base()->right->left->left ); // 4h-5w pos // 90
            std::cout << "        ";
            print_int_key_node( my_tree.root().base()->right->left->right ); // 4h-6w pos // 110
            std::cout << "          ";
        } else {
            std::cout << "                            ";
        }
        if (my_tree.root().base()->right->right->_is_empty == false) {
            print_int_key_node( my_tree.root().base()->right->right->left ); // 4h-7w pos // 130
            std::cout << "        ";
            print_int_key_node( my_tree.root().base()->right->right->right ); // 4h-8w pos // 150
        }
    }
    std::cout << std::endl;
    if ( my_tree.root().base()->left->_is_empty == false &&
         my_tree.root().base()->left->left->_is_empty == false &&
         my_tree.root().base()->left->left->left->_is_empty == false ) {
        std::cout << "     /  \\    " ; // 5h-1,2w pos
    } else {
        std::cout << "             " ; // 5h-1w pos

    }
    if ( my_tree.root().base()->left->_is_empty == false &&
         my_tree.root().base()->left->left->_is_empty == false &&
         my_tree.root().base()->left->left->right->_is_empty == false) {
        std::cout << "     /  \\" ; // 5h-3,4w pos
    } else {
        std::cout << "         " ; // 5h-3,4w pos
    }
    if ( my_tree.root().base()->left->_is_empty == false &&
         my_tree.root().base()->left->right->_is_empty == false &&
         my_tree.root().base()->left->right->left->_is_empty == false) {
        std::cout << "          /  \\" ; // 5h-5,6w pos
    } else {
        std::cout << "              " ; // 5h-5,6w pos
    }
    if ( my_tree.root().base()->left->_is_empty == false &&
         my_tree.root().base()->left->right->_is_empty == false &&
         my_tree.root().base()->left->right->right->_is_empty == false) {
        std::cout << "          /  \\" ; // 5h-7,8w pos
    } else {
        std::cout << "              " ; // 5h-7,8w pos
    }


    if ( my_tree.root().base()->right->_is_empty == false &&
         my_tree.root().base()->right->left->_is_empty == false &&
         my_tree.root().base()->right->left->left->_is_empty == false) {
        std::cout << "          /  \\" ; // 5h-9,10w pos
    } else {
        std::cout << "              " ; // 5h-9,10w pos
    }
    if ( my_tree.root().base()->right->_is_empty == false &&
         my_tree.root().base()->right->left->_is_empty == false &&
         my_tree.root().base()->right->left->right->_is_empty == false) {
        std::cout << "          /  \\" ; // 5h-11,12w pos
    } else {
        std::cout << "              " ; // 5h-11,12w pos
    }
    if ( my_tree.root().base()->right->_is_empty == false &&
         my_tree.root().base()->right->right->_is_empty == false &&
         my_tree.root().base()->right->right->left->_is_empty == false) {
        std::cout << "          /  \\" ; // 5h-13,14w pos
    } else {
        std::cout << "              " ; // 5h-13,14w pos
    }
    if ( my_tree.root().base()->right->_is_empty == false &&
         my_tree.root().base()->right->right->_is_empty == false &&
         my_tree.root().base()->right->right->right->_is_empty == false) {
        std::cout << "          /  \\" ; // 5h-15,16w pos
    } else {
        std::cout << "              " ; // 5h-15,16w pos
    }

    std::cout << std::endl;
    if ( my_tree.root().base()->left->_is_empty == false &&
         my_tree.root().base()->left->left->_is_empty == false &&
         my_tree.root().base()->left->left->left->_is_empty == false) {
        print_int_key_node( my_tree.root().base()->left->left->left->left ); // 5h-1w pos
        std::cout << "  " ;
        print_int_key_node( my_tree.root().base()->left->left->left->right ); // 5h-2w pos
        std::cout << "  " ;
    } else {
        std::cout << "              " ;
    }
    if ( my_tree.root().base()->left->_is_empty == false &&
         my_tree.root().base()->left->left->_is_empty == false &&
         my_tree.root().base()->left->left->right->_is_empty == false) {
        print_int_key_node( my_tree.root().base()->left->left->right->left ); // 5h-3w pos
        std::cout << "  " ;
        print_int_key_node( my_tree.root().base()->left->left->right->right ); // 5h-4w pos
        std::cout << "  " ;
    } else {
        std::cout << "              " ;
    }
    if ( my_tree.root().base()->left->_is_empty == false &&
         my_tree.root().base()->left->right->_is_empty == false &&
         my_tree.root().base()->left->right->left->_is_empty == false) {
        print_int_key_node( my_tree.root().base()->left->right->left->left ); // 5h-5w pos
        std::cout << "  " ;
        print_int_key_node( my_tree.root().base()->left->right->left->right ); // 5h-6w pos
        std::cout << "  " ;
    } else {
        std::cout << "              " ;
    }
    if ( my_tree.root().base()->left->_is_empty == false &&
         my_tree.root().base()->left->right->_is_empty == false &&
         my_tree.root().base()->left->right->right->_is_empty == false) {
        print_int_key_node( my_tree.root().base()->left->right->right->left ); // 5h-7w pos
        std::cout << "  " ;
        print_int_key_node( my_tree.root().base()->left->right->right->right ); // 5h-8w pos
        std::cout << "  " ;
    } else {
        std::cout << "              " ;
    }
    if ( my_tree.root().base()->right->_is_empty == false &&
         my_tree.root().base()->right->left->_is_empty == false &&
         my_tree.root().base()->right->left->left->_is_empty == false) {
        print_int_key_node( my_tree.root().base()->right->left->left->left ); // 5h-9w pos
        std::cout << "  " ;
        print_int_key_node( my_tree.root().base()->right->left->left->right ); // 5h-10w pos
        std::cout << "  " ;
    } else {
        std::cout << "              " ;
    }
    if ( my_tree.root().base()->right->_is_empty == false &&
         my_tree.root().base()->right->left->_is_empty == false &&
         my_tree.root().base()->right->left->right->_is_empty == false) {
        print_int_key_node( my_tree.root().base()->right->left->right->left ); // 5h-11w pos
        std::cout << "  " ;
        print_int_key_node( my_tree.root().base()->right->left->right->right ); // 5h-12w pos
        std::cout << "  " ;
    } else {
        std::cout << "              " ;
    }
    if ( my_tree.root().base()->right->_is_empty == false &&
         my_tree.root().base()->right->right->_is_empty == false &&
         my_tree.root().base()->right->right->left->_is_empty == false) {
        print_int_key_node( my_tree.root().base()->right->right->left->left ); // 5h-13w pos
        std::cout << "  " ;
        print_int_key_node( my_tree.root().base()->right->right->left->right ); // 5h-14w pos
        std::cout << "  " ;
    } else {
        std::cout << "              " ;
    }
    if ( my_tree.root().base()->right->_is_empty == false &&
         my_tree.root().base()->right->right->_is_empty == false &&
         my_tree.root().base()->right->right->right->_is_empty == false) {
        print_int_key_node( my_tree.root().base()->right->right->right->left ); // 5h-15w pos
        std::cout << "  " ;
        print_int_key_node( my_tree.root().base()->right->right->right->right ); // 5h-16w pos
        std::cout << "  " ;
    }
    std::cout << std::endl;
    std::cout << "\n\033[36m" << " only for 5 lvls " << "\033[0m"  << std::endl;

}

template <typename T>
void print_int_key_node(ft::Node<T > *node) {
    if ( node->_is_empty == false ) {
        if ( node->color == 1 ) {
            std::cout << "\033[30;41m" << std::setw(5) << node->data << "\033[0m";
        } else {
            std::cout << "\033[37;40m" << std::setw(5) << node->data << "\033[0m";
        }
    } else {
        std::cout << "\033[37;40m" " NIL " "\033[0m" ;
    }
}

struct ModCmp {
    bool operator()(const int lhs, const int rhs) const
    {
        return (lhs % 97) < (rhs % 97);
    }
};

void    print_int(const int& n) { 
    std::cout << " " << n; 
}

template<class Iter >
void
for_each_ft(Iter begin, Iter end, void(*op)(const int& )) {
    for ( ; begin != end ; ++begin ) {
        op(*begin);
    }
}

 /*------------------TESTS-------------------*/

void    testSet_erase_root() {
    std::cout << std::endl << "\033[35m" << "CHECK testSet erase root " << "\033[0m" << std::endl;
    std::cout << std::endl << "\033[33m" << "_____16_____" << "\033[0m" << std::endl;
    ft::set<int> my_tree;
    fill_set(&my_tree, NULL);
    // left red, right black
    my_tree.erase( my_tree.root() );
    my_tree.erase( my_tree.root() );
    my_tree.erase( my_tree.root() );
    my_tree.erase( my_tree.root() );
    tree_picture( my_tree );
    // left black, right red
    my_tree.erase( my_tree.root() );
    tree_picture( my_tree );
    // left black, right black
    my_tree.erase( my_tree.root() );
    my_tree.erase( my_tree.root() );
    my_tree.erase( my_tree.root() );
    my_tree.erase( my_tree.root() );
    my_tree.erase( my_tree.root() );
    my_tree.erase( my_tree.root() );
    tree_picture( my_tree );
    // left black, right red
    my_tree.erase( my_tree.root() );
    my_tree.erase( my_tree.root() );
    tree_picture( my_tree );
    // left black, right black
    my_tree.erase( my_tree.root() );
    tree_picture( my_tree );

    my_tree.erase( my_tree.find(-10) );
    tree_picture( my_tree );

    my_tree.erase( my_tree.root() );
    tree_picture( my_tree );

    my_tree.erase( my_tree.root() );
    tree_picture( my_tree );

}

void testSet_non_members() {

    std::cout << std::endl << "\033[35m" << "CHECK testSet NON-MEMBER FUNCTIONS " << "\033[0m" << std::endl;
    std::cout << std::endl << "\033[33m" << "_____31_____" << "\033[0m" << std::endl;
    std::cout << "\033[34m" << "\t 31) template< class Key, class Compare, class Alloc > \n"
                               "\t\t void swap( std::set<Key,Compare,Alloc>& lhs, \n"
                               "\t\t std::set<Key,Compare,Alloc>& rhs ); "
              << "\033[0m" << std::endl;

    ft::set<int> alice;
    alice.insert( 1 );
    alice.insert( 2 );
    alice.insert( 3 );

    ft::set<int> bob;
    bob.insert( 7  );
    bob.insert( 8  );
    bob.insert( 9  );
    bob.insert( 10 );
 
    // Print state before swap
    std::cout << "alice:";
    for_each_ft(alice.begin(), alice.end(), print_int);
    std::cout << "\n" "bob  :";
    for_each_ft(bob.begin(), bob.end(), print_int);
    std::cout << '\n';
 
    std::cout << "-- SWAP\n";
    ft::swap(alice, bob);
 
    // Print state after swap
    std::cout << "alice:";
    for_each_ft(alice.begin(), alice.end(), print_int);
    std::cout << "\n" "bob  :";
    for_each_ft(bob.begin(), bob.end(), print_int);
    std::cout << std::endl;

    std::cout << std::endl << "\033[33m" << "_____25-30_____" << "\033[0m" << std::endl;
    std::cout << "\033[35m" << 
                 "\t operator== \n"
                 "\t operator!= \n" 
                 "\t operator< \n" 
                 "\t operator<= \n"
                 "\t operator> \n"
                 "\t operator>= "
                 "\033[0m" << std::endl;

    ft::set<int> eve(alice);
 
    std::cout << std::boolalpha;
 
    // Compare non equal containers
    std::cout << "\n\033[36m" << "\t\t alice > bob " << "\033[0m"  << std::endl;
    std::cout << "alice == bob returns " << (alice == bob) << std::endl;
    std::cout << "alice != bob returns " << (alice != bob) << std::endl;
    std::cout << "alice <  bob returns " << (alice < bob) <<  std::endl;
    std::cout << "alice <= bob returns " << (alice <= bob) << std::endl;
    std::cout << "alice >  bob returns " << (alice > bob) <<  std::endl;
    std::cout << "alice >= bob returns " << (alice >= bob) << std::endl;

 
    // Compare equal containers
    std::cout << "\n\033[36m" << "\t\t alice == eve " << "\033[0m"  << std::endl;
    std::cout << "alice == eve returns " << (alice == eve) << std::endl;
    std::cout << "alice != eve returns " << (alice != eve) << std::endl;
    std::cout << "alice <  eve returns " << (alice < eve) <<  std::endl;
    std::cout << "alice <= eve returns " << (alice <= eve) << std::endl;
    std::cout << "alice >  eve returns " << (alice > eve) <<  std::endl;
    std::cout << "alice >= eve returns " << (alice >= eve) << std::endl;

    std::cout << std::endl;
}

void testSet_observers() {
    std::cout << std::endl << "\033[35m" << "CHECK testSet Observers " << "\033[0m" << std::endl;
    std::cout << std::endl << "\033[33m" << "_____23-24_____" << "\033[0m" << std::endl;
    
    std::cout << "\n\033[36m" << "\t\t std: " << "\033[0m"  << std::endl;
    std::set<int, ModCmp> cont;
	cont.insert( 1 );
	cont.insert( 2 );
	cont.insert( 3 );
	cont.insert( 4 );
	cont.insert( 5 );

    std::set<int, ModCmp>::value_compare comp_func = cont.value_comp();
    const int val = 2;
    for (  std::set<int, ModCmp>::iterator iter = cont.begin(); iter != cont.end(); ++iter) {
		const int it = *iter; 

        bool before = comp_func(it, val);
        bool after = comp_func(val, it);
 
        std::cout << '(' << it ;
        if (!before && !after)
            std::cout << ") equivalent to key " << val << '\n';
        else if (before)
            std::cout << ") goes before key " << val << '\n';
        else if (after)
            std::cout << ") goes after key " << val << '\n';
        else
            assert(0); // Cannot happen
    }
    std::cout << std::endl;

    std::cout << "\n\033[36m" << "\t\t ft: " << "\033[0m"  << std::endl;
	ft::set<int, ModCmp> cont_ft;
	cont_ft.insert( 1 );
	cont_ft.insert( 2 );
	cont_ft.insert( 3 );
	cont_ft.insert( 4 );
	cont_ft.insert( 5 );

    ft::set<int, ModCmp>::value_compare comp_func_ft = cont_ft.value_comp();
    for (  ft::set<int, ModCmp>::iterator iter = cont_ft.begin(); iter != cont_ft.end(); ++iter) {
		const int it = *iter; 
        bool before = comp_func_ft(it, val);
        bool after = comp_func_ft(val, it);
 
        std::cout << '(' << it;
        if (!before && !after)
            std::cout << ") equivalent to key " << val << '\n';
        else if (before)
            std::cout << ") goes before key " << val << '\n';
        else if (after)
            std::cout << ") goes after key " << val << '\n';
        else
            assert(0); // Cannot happen
    }
}

void    testSet_swap() {
    std::cout << std::endl << "\033[35m" << "CHECK testSet Modifiers " << "\033[0m" << std::endl;
    std::cout << std::endl << "\033[33m" << "_____17_____" << "\033[0m" << std::endl;
    
    ft::set<int>   my_tree1;
    my_tree1.insert(25);
    my_tree1.insert(15);
    ft::set<int>::iterator    iter_my_tree1 = my_tree1.begin();

    std::set<int>   std_tree1;
    std_tree1.insert(25);
    std_tree1.insert(15);
    std::set<int>::iterator   iter_std_tree1 = std_tree1.begin();

    ft::set<int>   my_tree2;
    my_tree2.insert(5);
    ft::set<int>::iterator    iter_my_tree2 = my_tree2.begin();

    std::set<int>   std_tree2;
    std_tree2.insert(5);
    std::set<int>::iterator   iter_std_tree2 = std_tree2.begin();

    std::cout << "\n\033[36m" << "\t\t befor swap: " << "\033[0m"  << std::endl;

    std::cout << std::setw(11) << std::left << "my_tree1" << std::setw(11) << "std_tree1" 
              << std::setw(11) << "my_tree2" << std::setw(11) << "std_tree2 " << std::endl;
    while ( iter_my_tree1 != my_tree1.end() ||
            iter_std_tree1 != std_tree1.end() ||
            iter_my_tree2 != my_tree2.end() ||
            iter_std_tree2 != std_tree2.end() ) {
        if ( iter_my_tree1 != my_tree1.end() ) {
            std::cout << std::setw(11) << *iter_my_tree1;
            ++iter_my_tree1;
        } else {
            std::cout << std::setw(11) << "";
        }
        if ( iter_std_tree1 != std_tree1.end() ) {
            std::cout << std::setw(11) << *iter_std_tree1;
            ++iter_std_tree1;
        } else {
            std::cout << std::setw(11) << "";
        }
        if ( iter_my_tree2 != my_tree2.end() ) {
            std::cout << std::setw(11) << *iter_my_tree2;
            ++iter_my_tree2;
        } else {
            std::cout << std::setw(11) << "";
        }
        if ( iter_std_tree2 != std_tree2.end() ) {
            std::cout << *iter_std_tree2 ;
            ++iter_std_tree2;
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
    
    my_tree1.swap(my_tree2);
    std_tree1.swap(std_tree2);
    iter_my_tree1 = my_tree1.begin();
    iter_std_tree1 = std_tree1.begin();
    iter_my_tree2 = my_tree2.begin();
    iter_std_tree2 = std_tree2.begin();

    std::cout << "\n\033[36m" << "\t\t after swap: " << "\033[0m"  << std::endl;

    std::cout << std::setw(11) << std::left << "my_tree1" << std::setw(11) << "std_tree1" 
              << std::setw(11) << "my_tree2" << std::setw(11) << "std_tree2 " << std::endl;
    while ( iter_my_tree1 != my_tree1.end() ||
            iter_std_tree1 != std_tree1.end() ||
            iter_my_tree2 != my_tree2.end() ||
            iter_std_tree2 != std_tree2.end() ) {
        if ( iter_my_tree1 != my_tree1.end() ) {
            std::cout << std::setw(11) << *iter_my_tree1;
            ++iter_my_tree1;
        } else {
            std::cout << std::setw(11) << "";
        }
        if ( iter_std_tree1 != std_tree1.end() ) {
            std::cout << std::setw(11) << *iter_std_tree1;
            ++iter_std_tree1;
        } else {
            std::cout << std::setw(11) << "";
        }
        if ( iter_my_tree2 != my_tree2.end() ) {
            std::cout << std::setw(11) << *iter_my_tree2;
            ++iter_my_tree2;
        } else {
            std::cout << std::setw(11) << "";
        }
        if ( iter_std_tree2 != std_tree2.end() ) {
            std::cout << *iter_std_tree2;
            ++iter_std_tree2;
        }
        std::cout << std::endl;
    }

    std::cout << std::endl << "\033[33m" << "__1.3)___3_____" << "\033[0m" << std::endl;
    std::cout << "\033[34m" << "\t 3) operator=; "
              << "\033[0m" << std::endl;

    ft::set<int>   my_tree3(my_tree1);
    std::cout << "ft::set<int>   my_tree3(my_tree1);" << std::endl;
    std::cout << "\n\033[36m" << "\t\t cout: " << "\033[0m"  << std::endl;
    for ( iter_my_tree1 = my_tree3.begin() ; iter_my_tree1 != my_tree3.end(); ++iter_my_tree1 ) {
        std::cout << *iter_my_tree1 << std::endl;
    }

    std::cout << std::endl << "\033[33m" << "_____15.3_____" << "\033[0m" << std::endl;
    std::cout << "\033[34m" << "\t 15.3) insert(InIter first, InIter last); "
              << "\033[0m" << std::endl;
    my_tree3.insert(my_tree2.begin(), my_tree2.end());
    std::cout << "my_tree3.insert(my_tree2.begin(), my_tree2.end());" << std::endl;
    std::cout << "\n\033[36m" << "\t\t cout: " << "\033[0m"  << std::endl;
    for ( iter_my_tree1 = my_tree3.begin() ; iter_my_tree1 != my_tree3.end(); ++iter_my_tree1 ) {
        std::cout << *iter_my_tree1 << std::endl;
    }
}

void    testSet_erase_for_destructor() {
    std::cout << "\n\033[36m" << "\t\t additional test: testSet_erase_for_destructor " << "\033[0m"  << std::endl;
    std::cout << "\n\033[36m" << " tree for 5 lvls " << "\033[0m"  << std::endl;
    ft::set<int>   my_tree;
    ft::set<int>::iterator    iter_my_tree;
    fill_set(&my_tree, NULL);

    my_tree.erase(my_tree.find(-10) ); // test
    my_tree.erase(my_tree.find(  0) ); // test
    my_tree.erase(my_tree.find( 10) ); // test
    my_tree.erase(my_tree.find( 20) ); // test
    my_tree.erase(my_tree.find( 40) ); // test
    my_tree.erase(my_tree.find( 60) ); // test
    my_tree.erase(my_tree.find( 80) ); // test
    my_tree.erase(my_tree.find( 85) ); // test
    my_tree.erase(my_tree.find( 90) ); // test
    my_tree.erase(my_tree.find( 100) ); // test
    my_tree.erase(my_tree.find( 110) ); // test
    my_tree.erase(my_tree.find( 120) ); // test
    my_tree.erase(my_tree.find( 122) ); // test
    my_tree.erase(my_tree.find( 130) ); // test
    my_tree.erase(my_tree.find( 140) ); // test
    my_tree.erase(my_tree.find( 150) ); // test
    my_tree.erase(my_tree.find( 170) ); // test

    tree_picture(my_tree);
}

void    testSet_clear() {
    std::cout << std::endl << "\033[35m" << "CHECK testSet Modifiers " << "\033[0m" << std::endl;
    std::cout << std::endl << "\033[33m" << "_____14_____" << "\033[0m" << std::endl;
    std::cout << "\033[34m" << "\t 14) void clear(); "
              << "\033[0m" << std::endl;
    ft::set<int>   my_tree;
    std::set<int>   std_tree;
    ft::set<int>::iterator    iter_my_tree;
    std::set<int>::iterator   iter_std_tree;
    fill_set(&my_tree, &std_tree);
    std::cout << "\n\033[36m" << "\t\t befor clear: " << "\033[0m"  << std::endl;
    std::cout << "my_tree.size() = " << my_tree.size() << "; std_tree.size() = " << std_tree.size() << std::endl;
    std::cout << "\n\033[36m" << "\t\t after clear: " << "\033[0m"  << std::endl;
    my_tree.clear();
    std_tree.clear();
    std::cout << "my_tree.size() = " << my_tree.size() << "; std_tree.size() = " << std_tree.size() << std::endl;
    if ( my_tree.begin() == my_tree.end() &&
         std_tree.begin() == std_tree.end() ) {
        std::cout << "begin and end - good!!! " << std::endl;
    }

}

void    testSet_erase() {
    std::cout << std::endl << "\033[35m" << "CHECK testSet Modifiers " << "\033[0m" << std::endl;
    std::cout << std::endl << "\033[33m" << "_____16_____" << "\033[0m" << std::endl;
    ft::set<int>   my_tree;
    std::set<int>   std_tree;
    ft::set<int>::iterator    iter_my_tree;
    std::set<int>::iterator   iter_std_tree;
    fill_set(&my_tree, &std_tree);
    std_tree.insert( 112 );
    my_tree.insert( 112 );
    std::cout << "my_tree.size() = " << my_tree.size() << "; std_tree.size() = " << std_tree.size() << std::endl;
    std::cout << "\033[34m" << "\t 16.1) void      erase( iterator pos ); \n"
              << "\033[0m" << std::endl;
    std::cout << "\n\033[36m" << "\t\t 1st case. Delete (D) without childs (begin, 110): " << "\033[0m"  << std::endl;
    std_tree.erase( std_tree.begin() );
    std_tree.erase( std_tree.find(110) );
    my_tree.erase( my_tree.begin() );
    my_tree.erase( my_tree.find(110) );

    std::cout << "\n\033[36m" << "\t\t 2st case. Delete (D) with one child (0 with child -10): " << "\033[0m"  << std::endl;
    std_tree.insert( -10 );
    my_tree.insert( -10 );
    std_tree.erase( std_tree.find(0) );
    my_tree.erase( my_tree.find(0) );

    std::cout << "\n\033[36m" << "\t\t 1st case. Delete (D) with both childs: " << "\033[0m"  << std::endl;
    std_tree.insert( 91 );
    my_tree.insert( 91 );
    std_tree.erase( std_tree.find(120) );
    my_tree.erase( my_tree.find(120) );
    std_tree.erase( std_tree.find(91) );
    my_tree.erase( my_tree.find(91) );

    std::cout << " std      | my " << std::endl;
    iter_my_tree = my_tree.begin();
    for (iter_std_tree = std_tree.begin(); iter_std_tree != std_tree.end(); ++iter_std_tree, ++iter_my_tree) {
        std::cout << *iter_std_tree << "\t\t"
                  << *iter_my_tree 
                  << std::endl;
    }
    std::cout << std::endl;

    std::cout << "\033[34m" << "\t 16.2) size_type erase( const Key& key ); \n"
              << "\033[0m" << std::endl;

    std::cout << "                \t std | my " << std::endl;
    std::cout << "tree.erase( 60 ) \t = " << std_tree.erase( 60 ) << " | " << my_tree.erase( 60 ) << std::endl;
    std::cout << "tree.erase( 122 ) \t = " << std_tree.erase( 122 ) << " | " << my_tree.erase( 122 ) << std::endl;
    std::cout << "tree.erase( 61 ) \t = " << std_tree.erase( 61 ) << " | " << my_tree.erase( 61 ) << std::endl;
    std::cout << "tree.erase( 6100 ) \t = " << std_tree.erase( 6100 ) << " | " << my_tree.erase( 6100 ) << std::endl;
    std::cout << "tree.erase( 170 ) \t = " << std_tree.erase( 170 ) << " | " << my_tree.erase( 170 ) << std::endl;

    std::cout << std::endl;
    std::cout << " std      | my " << std::endl;
    iter_my_tree = my_tree.begin();
    for (iter_std_tree = std_tree.begin(); iter_std_tree != std_tree.end(); ++iter_std_tree, ++iter_my_tree) {
        std::cout << *iter_std_tree << "\t\t"
                  << *iter_my_tree 
                  << std::endl;
    }
    std::cout << std::endl;

    std::cout << "\033[34m" << "\t 16.3) void      erase( iterator first, iterator last ); \n"
              << "\033[0m" << std::endl;
    std::cout << "tree.erase( find(40), find(90) ) " << std::endl;
    std_tree.erase( std_tree.find(40), std_tree.find(90) );
    my_tree.erase( my_tree.find(40), my_tree.find(90) );
    std::cout << "my_tree.size() = " << my_tree.size() << "; std_tree.size() = " << std_tree.size() << std::endl;
    
    std::cout << " std      | my " << std::endl;
    iter_my_tree = my_tree.begin();
    for (iter_std_tree = std_tree.begin(); iter_std_tree != std_tree.end(); ++iter_std_tree, ++iter_my_tree) {
        std::cout << *iter_std_tree << "\t\t"
                  << *iter_my_tree 
                  << std::endl;
    }
    std::cout << std::endl;

}

void    erase_additional_little_test() {
    std::cout << "\n\033[36m" << "\t\t erase_additional_little_test " << "\033[0m"  << std::endl;
    std::cout << "\n\033[36m" << " tree for 5 lvls " << "\033[0m"  << std::endl;
    ft::set<int>   my_tree;
    ft::set<int>::iterator    iter_my_tree;
    fill_set(&my_tree, NULL);
    iter_my_tree = my_tree.find(170);
    my_tree.erase( iter_my_tree );
    iter_my_tree = my_tree.find(122);
    my_tree.erase( iter_my_tree );
    iter_my_tree = my_tree.find(60);
    my_tree.erase( iter_my_tree );

    tree_picture(my_tree);

}

void    testSet_lookup() {
    std::cout << std::endl << "\033[35m" << "CHECK testSet lookup " << "\033[0m" << std::endl;
    std::cout << std::endl << "\033[33m" << "_____19_____" << "\033[0m" << std::endl;
    std::cout << "\033[34m" << "\t 19) iterator       find( const Key& key ); \n"
                               "\t     const_iterator find( const Key& key ) const; \n\n"
                               "\t     size_type      count( const Key& key ) const; "
              << "\033[0m" << std::endl;

    ft::set<int>   my_tree;
    std::set<int>   std_tree;
    fill_set(&my_tree, &std_tree);
    std::cout << "my_tree.size() = " << my_tree.size() << "; std_tree.size() = " << std_tree.size() << std::endl;

    ft::set<int>::iterator   iter_my_tree1;
    std::set<int>::iterator  iter_std_tree1;

    iter_my_tree1 = my_tree.find(80);
    iter_std_tree1 = std_tree.find(80);

    if (iter_std_tree1 == std_tree.end()) {
        std::cout << "STD_SET: Fix find() parametres for std::set. " << std::endl;
    } else {
        std::cout << "STD_SET find: Very good: " << *iter_std_tree1 
                  << " |  std_tree.count(80) = " << std_tree.count(80)
                  << " | *std_tree.lower_bound(80) = " << *std_tree.lower_bound(80)
                  << " | *std_tree.upper_bound(80) = " << *std_tree.upper_bound(80)
                  << std::endl;
    }

    if (iter_my_tree1 == my_tree.end()) {
        std::cout << " FT_SET: Fix your find() in ft::set. " << std::endl;
    } else {
        std::cout << " FT_SET find: Very good: " << *iter_my_tree1 
                  << " |   my_tree.count(80) = " << my_tree.count(80)
                  << " |  *my_tree.lower_bound(80) = " << *my_tree.lower_bound(80)
                  << " |  *my_tree.upper_bound(80) = " << *my_tree.upper_bound(80)
                  << std::endl;
    }
    std::cout << std::endl;

    iter_my_tree1 = my_tree.find(11280);
    iter_std_tree1 = std_tree.find(11280);

    if (iter_std_tree1 == std_tree.end() && 
        std_tree.lower_bound(11280) == std_tree.end() &&
        std_tree.upper_bound(11280) == std_tree.end()) {
        std::cout << "STD_SET find: Very good!!! "
                  << "std_tree.count(11280) = " << std_tree.count(11280)
                  << std::endl;

    } else {
        std::cout << "STD_SET: Fix find() parametres for std::set. " << std::endl;
    }

    if (iter_my_tree1 == my_tree.end() && 
        my_tree.lower_bound(11280) == my_tree.end() &&
        my_tree.upper_bound(11280) == my_tree.end()) {
        std::cout << " FT_SET find: Very good!!! "
                  << " my_tree.count(11280) = " << my_tree.count(11280)
                  << std::endl;
    } else {
        std::cout << " FT_SET: Fix your find() in ft::set. " << std::endl;
    }
    std::cout << std::endl;

    std::cout << "std_tree.equal_range(80): "
              << *std_tree.equal_range(80).first
              << std::endl;

    std::cout << " my_tree.equal_range(80): "
              << *my_tree.equal_range(80).first
              << std::endl;
}

void    testSet_capacity() {
    std::cout << std::endl << "\033[35m" << "CHECK testSet capacity " << "\033[0m" << std::endl;
    std::cout << std::endl << "\033[33m" << "_____11-13_____     iterators map" << "\033[0m" << std::endl;
    std::cout << "\033[34m" << "\t 10) bool        empty() const;"
                               "\t 11) size_type   size()  const;"
              << "\033[0m" << std::endl;
    ft::set<int>   my_tree;
    std::set<int>   std_tree;
    std::cout << " ft::set<int>    my_tree;  my_tree.empty(): " << std::boolalpha << my_tree.empty() << std::endl;
    std::cout << "std::set<int>   std_tree; std_tree.empty(): " << std::boolalpha << std_tree.empty() << std::endl;
    std::cout << "( my_tree.begin() ==  my_tree.end()): " << std::boolalpha << (my_tree.begin() == my_tree.end()) << std::endl;
    std::cout << "(std_tree.begin() == std_tree.end()): " << std::boolalpha << (std_tree.begin() == std_tree.end()) << std::endl;
    std::cout << "my_tree.size() = " << my_tree.size() << "; std_tree.size() = " << std_tree.size() << std::endl;

    my_tree.insert(80);
    std_tree.insert(80);
    std::cout << "\n after insert: " << std::boolalpha << (std_tree.begin() == std_tree.end()) << std::endl;
    std::cout << " ft::map<int, std::string>    my_tree;  my_tree.empty(): " << std::boolalpha << my_tree.empty() << std::endl;
    std::cout << "std::map<int, std::string>   std_tree; std_tree.empty(): " << std::boolalpha << std_tree.empty() << std::endl;
    std::cout << "( my_tree.begin() ==  my_tree.end()): " << std::boolalpha << (my_tree.begin() == my_tree.end()) << std::endl;
    std::cout << "(std_tree.begin() == std_tree.end()): " << std::boolalpha << (std_tree.begin() == std_tree.end()) << std::endl;
    std::cout << "my_tree.size() = " << my_tree.size() << "; std_tree.size() = " << std_tree.size() << std::endl;

    std::cout << "\033[34m" << "\t 12) size_type max_size() const;"
              << "\033[0m" << std::endl;

    std::cout << "my_tree.max_size() = " << my_tree.max_size() << "; std_tree.max_size() = " << std_tree.max_size() << std::endl;

}

void    testSet_iterator_reverse() {
    std::cout << std::endl << "\033[35m" << "CHECK testSet_iterator reverse " << "\033[0m" << std::endl;
    std::cout << std::endl << "\033[35m" << "check ITERATORS reverse " << "\033[0m" << std::endl;
    std::cout << "\033[34m" << "\t iter reverse."
                 "\t\t operator-> "
                 "\t\t operator*  " << "\033[0m" << std::endl;
    std::cout << std::endl << "\033[33m" << "_____9-10_____     iterators set" << "\033[0m" << std::endl;

    ft::set<int>    my_tree;
    std::set<int>   std_tree;
    fill_set(&my_tree, &std_tree);

    // std::cout << "my_tree.size() = " << my_tree.size() << "; std_tree.size() = " << std_tree.size() << std::endl;

    ft::set<int>::reverse_iterator   iter_my_tree1;
    std::set<int>::reverse_iterator  iter_std_tree1;

    ft::set<int>::reverse_iterator   iter_my_tree2;
    std::set<int>::reverse_iterator  iter_std_tree2;

    iter_my_tree1 = my_tree.rbegin();
    iter_my_tree2 = my_tree.rend();

    iter_std_tree1 = std_tree.rbegin();
    iter_std_tree2 = std_tree.rend();

    std::cout << "\033[34m" << "\t9) rbegin " << "\033[0m" << std::endl;
    std::cout << "*my_tree.rbegin() = " << *my_tree.rbegin() << std::endl;
    std::cout << "*iter_my_tree1 = " << *iter_my_tree1 << std::endl;
    std::cout << std::endl;
    std::cout << "*std_tree.rbegin() = " << *std_tree.rbegin() << std::endl;
    std::cout << "*iter_std_tree2 = " << *iter_std_tree1 << std::endl;

    std::cout << "\033[34m" << "\t10) rend " << "\033[0m" << std::endl;
    std::cout << "*(--( my_tree.rend())) = " << *(--(my_tree.rend())) << std::endl;
    std::cout << "*(--(std_tree.rend())) = " << *(--(std_tree.rend())) << std::endl;

    std::cout << "\033[34m" << "\t iter reverse.\n"
                 "\t\t operator++ \n"
                 "\t\t ++operator \n"
                 "\t\t --operator \n"
                 "\t\t operator-- \n"
                 "\t\t operator-> \n"
                 "\t\t operator*  \n"
              << "\033[0m" << std::endl;

    {
        std::cout << "\033[36m" << "\t\tcout iter_reverse operator++" << "\033[0m"  << std::endl;
        std::cout << "\033[36m" << "\t\tfrom rbegin to root (80)" << "\033[0m"  << std::endl;
        iter_my_tree2  =  my_tree.root();
        std::set<int>::reverse_iterator   iter_std_tree3(std_tree.find(*my_tree.root()));
        while (iter_my_tree1 != iter_my_tree2) {
            std::cout <<       "(*iter_my_tree1) = " <<  (*iter_my_tree1++)
                      << " \t\t (*iter_std_tree1) = " << (*iter_std_tree1++) 
                      << std::endl;
        }
        std::cout << std::endl;

        std::cout << "\033[36m" << "\t\tcout iter_reverse ++operator" << "\033[0m"  << std::endl;
        std::cout << "\033[36m" << "\t\tfrom root (80) to rend" << "\033[0m"  << std::endl;
        iter_my_tree2  =  --my_tree.rend();
        while (iter_my_tree1 != iter_my_tree2) {
            std::cout << "     (*++iter_my_tree1) = " <<  (*++iter_my_tree1) 
                      << "\t\t (*++iter_std_tree1) = " << (*++iter_std_tree1) 
                      << std::endl;
        }
    }

    {
        std::cout << "\033[36m" << "\t\tcout iter_reverse operator--" << "\033[0m"  << std::endl;
        std::cout << "\033[36m" << "\t\tfrom rend to root" << "\033[0m"  << std::endl;
        iter_my_tree1  =  my_tree.rend();
        --iter_my_tree1;
        iter_std_tree1 = std_tree.rend();
        --iter_std_tree1;

        iter_my_tree2  =  my_tree.root();
        std::set<int>::reverse_iterator   iter_std_tree3(std_tree.find(*my_tree.root()));
        while (iter_my_tree1 != iter_my_tree2) {
            std::cout <<      "(*iter_my_tree1) = " <<  (*iter_my_tree1--) 
                      << "\t\t (*iter_std_tree1) = " << (*iter_std_tree1--) 
                      << std::endl;
        }
        std::cout << std::endl;

        std::cout << "\033[36m" << "\t\tcout iter_reverse --operator" << "\033[0m"  << std::endl;
        std::cout << "\033[36m" << "\t\tfrom root (80) to rbegin" << "\033[0m"  << std::endl;
        iter_my_tree2  =  my_tree.rbegin();
        iter_std_tree2  =  std_tree.rbegin();
        while (--iter_my_tree1 != iter_my_tree2) {
            std::cout <<      "(*iter_my_tree1) = " << (*iter_my_tree1) 
                      << "\t\t (*iter_std_tree1) = " << (*--iter_std_tree1) 
                      << std::endl;
        }
        std::cout << std::endl;
    }
}

void    testSet_iterator() {
    std::cout << std::endl << "\033[35m" << "CHECK testSet_iterator normal " << "\033[0m" << std::endl;
    std::cout << std::endl << "\033[35m" << "check ITERATORS normal " << "\033[0m" << std::endl;
    std::cout << std::endl << "\033[33m" << "_____7-8_____     iterators" << "\033[0m" << std::endl;
    ft::set<int>   my_tree;
    std::set<int>   std_tree;
    fill_set(&my_tree, NULL);

    std::cout << "\033[34m" << "\t7) begin " << "\033[0m" << std::endl;
    std::cout << "my_tree.begin() = " << *my_tree.begin() << std::endl;

    std::cout << "\033[34m" << "\t8) end " << "\033[0m" << std::endl;
    std::cout << "--my_tree.end() = " << *(--my_tree.end() ) << std::endl;

    ft::set<int>::iterator iter1;
    ft::set<int>::iterator iter2;
    std::cout << "\033[34m" << "\t test iter1 = iter2 " << "\033[0m" << std::endl;
    iter1 = my_tree.root();
    iter2 = static_cast<ft::set<int>::iterator >(my_tree.root().base()->left);
    std::cout << "(*iter1) = " << (*iter1) << std::endl;
    std::cout << "(*iter2) = " << (*iter2) << std::endl;
    std::cout << "(*(iter1 = iter2)).first = " << (*(iter1 = iter2)) << std::endl;

    std::cout << "\033[34m" << "\t test ++iter " << "\033[0m" << std::endl;
    iter1 = my_tree.begin();
    std::cout << "iter1 = my_tree.begin() = " << (*iter1) << std::endl;
    iter2 = static_cast<ft::set<int>::iterator >(my_tree.end().base()->parent);
    std::cout << "iter2 = my_tree.end().base()->parent " << std::endl;
    while (iter1 != iter2) {
        std::cout << "\t (*++iter1): " << (*++iter1) << std::endl;
    }

    std::cout << "\033[34m" << "\t test iter++ " << "\033[0m" << std::endl;
    iter1 = my_tree.begin();
    std::cout << "iter1 = my_tree.begin() = " << (*iter1) << std::endl;
    iter2 = my_tree.end();
    std::cout << "iter2 = my_tree.end() " << std::endl;
    while (iter1 != iter2) {
        std::cout << (*iter1++) << "\t (*iter1): " << (*iter1) << std::endl;
    }

    std::cout << "\033[34m" << "\t test ++iter " << "\033[0m" << std::endl;
    iter1 = my_tree.root();
    std::cout << "iter1 = my_tree.root() = " << (*iter1) << std::endl;
    iter2 = my_tree.end();
    std::cout << "iter2 = my_tree.end() " << std::endl;
    while (iter1 != iter2) {
        std::cout << (*iter1++) << std::endl;
    }

    std::cout << "\033[34m" << "\t test --iter " << "\033[0m" << std::endl;
    iter1 = my_tree.begin();
    std::cout << "iter1 = my_tree.begin() = " << (*iter1) << std::endl;
    iter2 = my_tree.end();
    std::cout << "iter2 = my_tree.end() " << std::endl;
    while (iter1 != iter2) {
        std::cout << "\t (*iter1): " << (*--iter2) << std::endl;
    }

    std::cout << "\033[34m" << "\t test iter-- " << "\033[0m" << std::endl;
    iter1 = my_tree.begin();
    ++iter1;
    std::cout << "iter1 = my_tree.begin(); ++iter1; iter1: " << (*iter1) << std::endl;
    iter2 = my_tree.end();
    --iter2;
    std::cout << "iter2 = my_tree.end(); --iter2; iter2: " << (*iter2) << std::endl;
    while (iter1 != iter2) {
        std::cout << (*iter2--) << "\t (*iter2): " << (*iter2) << std::endl;
    }

    std::cout << "\033[34m" << "\t test --iter " << "\033[0m" << std::endl;
    iter1 = my_tree.root();
    std::cout << "iter1 = my_tree.root(); iter1 : " << (*iter1) << std::endl;
    iter2 = my_tree.end();
    --iter2;
    std::cout << "iter2 = my_tree.end(); --iter2; iter2: " << (*iter2) << std::endl;
    while (iter1 != iter2) {
        std::cout << "\t (*iter2--): " << (*iter2--) << std::endl;
    }


    // test const
    std::set<int>::const_iterator iter3;
    iter3 = (std_tree.begin() );

    ft::set<int>::const_iterator iter4;
    iter4 = (my_tree.begin() );
    std::cout << "\033[34m" "\n\t test const_iterator: \n" "\033[0m"
                 "    ft::set<int>::const_iterator iter4;\n"
                 "    iter4 = (my_tree.begin() ); " "\033[34m" "  (*iter4) = " << "\033[0m"
              << (*iter4) << std::endl;
}

void    testSet_insert() {
    std::cout << std::endl << "\033[35m" << "CHECK SET: modifiers" << "\033[0m" << std::endl;
    std::cout << std::endl << "\033[33m" << "_____15_____" << "\033[0m" << std::endl;
    std::cout << "\033[34m" << "\t15.1) std::pair<iterator, bool> insert( const value_type& value ); " << "\033[0m" << std::endl;
    std::cout << "\033[34m" << "\t15.2) iterator insert( iterator hint, const value_type& value ); " << "\033[0m" << std::endl;

    ft::set<int>   my_tree;
    ft::pair<ft::set<int>::iterator, bool> insert_pair;
    insert_pair = my_tree.insert(80);
    std::cout << "\n\033[36m" << "\t\t 1st insert. (80) \033[0m\n"
              << "\t insert_pair.first = (iter to: (\033[33m"
              << *(insert_pair.first)
              << "\033[0m), bool: \033[33m" << std::boolalpha << insert_pair.second << "\033[0m) "
              << std::endl;

    // std::set<int>   std_tree;
    // std::pair<std::set<int>::iterator, bool> insert_pair_std;
    // insert_pair_std = std_tree.insert(80);
    // std::cout << "\n\033[36m" << "\t\t 1st insert. (80) \033[0m\n"
    //           << "\t insert_pair_std.first = (iter to: (\033[33m"
    //           << *(insert_pair_std.first)
    //           << "\033[0m), bool: \033[33m" << std::boolalpha << insert_pair_std.second << "\033[0m) "
    //           << std::endl;

    insert_pair = my_tree.insert(40);
    std::cout << "\n\033[36m" << "\t\t     insert. (40) \033[0m\n"
              << "\t insert_pair.first = (iter to: (\033[33m"
              << *(insert_pair.first)
              << "\033[0m), bool: \033[33m" << std::boolalpha << insert_pair.second << "\033[0m) "
              << std::endl;

    ft::set<int>::iterator iter_insert = 
    my_tree.insert(insert_pair.first, 150);
    std::cout << "\n\033[36m" << "\t\t     insert. (iterator, 150) \033[0m\n"
              << "\t iter_insert = (\033[33m"
              << *(iter_insert)
              << "\033[0m) "
              << std::endl;

    my_tree.insert(60);
    my_tree.insert(20);
    insert_pair = my_tree.insert(10);
    std::cout << "\n\033[36m" << "\t\t     insert. (10) \033[0m\n"
              << "\t insert_pair.first = (iter to: (\033[33m"
              << *(insert_pair.first)
              << "\033[0m), bool: \033[33m" << std::boolalpha << insert_pair.second << "\033[0m) "
              << std::endl;
}

void    testSet_copy_insert() {
    std::cout << std::endl << "\033[35m" << "CHECK SET copy " << "\033[0m" << std::endl;

    ft::set<int> my_tree;
    std::set<int> std_tree;

    fill_set(&my_tree, &std_tree);
    ft::set<int> my_tree_copy = my_tree;
    std::set<int> std_tree_copy = std_tree;

    // tree_picture(my_tree);
    tree_picture(my_tree_copy);

}
