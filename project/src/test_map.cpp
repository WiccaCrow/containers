#include <iostream>
#include <iomanip>
#include <utility.hpp>
// #include <vector.hpp>
#include <RBTree.hpp>
#include <iterator_binTree_normal.hpp>
// #include <iterator_binTree_reverse.hpp>
#include <map.hpp>
#include <map>

void    testTree_insert();
void    testTree_iterator();
void    testMap_insert();
void    testMap_iterator();
void    testMap_iterator_reverse();
void    testMap_capacity();
void    testMap_lookup();
void    fill_map(ft::map<int, std::string> &my_map, std::map<int, std::string>* std_map);
void    testMap_ElementAccess();
void    erase_additional_little_test();
void    testMap_erase();
void    testMap_clear();
void    testMap_swap();

// At the Mountains of Madness

 /*------------------START-------------------*/

int main() {
    // testTree_insert();
    // testTree_iterator();
    // testMap_insert(); // 15
    // testMap_iterator(); // 7, 8
    // testMap_iterator_reverse(); // 9, 10
    // testMap_capacity(); // 11, 12, 13
    // testMap_lookup(); // 19
    // testMap_ElementAccess(); // 5, 6
    // erase_additional_little_test(); // 16
    // testMap_erase(); // 16
    // testMap_clear(); // 14
    testMap_swap(); // 17
    return (0);
}

 /*------------------UTILITY-------------------*/

void    fill_map(ft::map<int, std::string> &my_tree, std::map<int, std::string>* std_tree) {
    my_tree.insert(ft::make_pair(80, "At "));
    my_tree.insert(ft::make_pair(40, "the "));
    my_tree.insert(ft::make_pair(150, "Mountains "));
    my_tree.insert(ft::make_pair(60, "of "));
    my_tree.insert(ft::make_pair(20, "Madness "));
    my_tree.insert(ft::make_pair(10, "... "));
    my_tree.insert(ft::make_pair(170, "..170.. "));
    my_tree.insert(ft::make_pair(140, "..140.. "));
    my_tree.insert(ft::make_pair(120, "..120.. "));
    my_tree.insert(ft::make_pair(0, "..0.. "));
    my_tree.insert(ft::make_pair(-10, "..-10.. "));
    my_tree.insert(ft::make_pair(130, "..130.. "));
    my_tree.insert(ft::make_pair(110, "..110.. "));
    my_tree.insert(ft::make_pair(122, "..122.. "));
    my_tree.insert(ft::make_pair(100, "..100.. "));
    my_tree.insert(ft::make_pair(90, "..90.. "));
    my_tree.insert(ft::make_pair(85, "..85.. "));

    if (std_tree != NULL) {
        std_tree->insert(std::make_pair(80, "At "));
        std_tree->insert(std::make_pair(40, "the "));
        std_tree->insert(std::make_pair(150, "Mountains "));
        std_tree->insert(std::make_pair(60, "of "));
        std_tree->insert(std::make_pair(20, "Madness "));
        std_tree->insert(std::make_pair(10, "... "));
        std_tree->insert(std::make_pair(170, "..170.. "));
        std_tree->insert(std::make_pair(140, "..140.. "));
        std_tree->insert(std::make_pair(120, "..120.. "));
        std_tree->insert(std::make_pair(0, "..0.. "));
        std_tree->insert(std::make_pair(-10, "..-10.. "));
        std_tree->insert(std::make_pair(130, "..130.. "));
        std_tree->insert(std::make_pair(110, "..110.. "));
        std_tree->insert(std::make_pair(122, "..122.. "));
        std_tree->insert(std::make_pair(100, "..100.. "));
        std_tree->insert(std::make_pair(90, "..90.. "));
        std_tree->insert(std::make_pair(85, "..85.. "));
    }
}


template <typename T>
void print_int_key_node(ft::Node<ft::pair<const int, T> > *node) {
    if ( node->_is_empty == false ) {
        if ( node->color == 1 ) {
            std::cout << "\033[30;41m" << std::setw(5) << node->data.first << "\033[0m";
        } else {
            std::cout << "\033[37;40m" << std::setw(5) << node->data.first << "\033[0m";
        }
    } else {
        std::cout << "\033[37;40m" " NIL " "\033[0m" ;
    }
}

//  /*------------------TESTS-------------------*/

void    testMap_swap() {
    std::cout << std::endl << "\033[35m" << "CHECK testMap Modifiers " << "\033[0m" << std::endl;
    std::cout << std::endl << "\033[33m" << "_____17_____" << "\033[0m" << std::endl;
    
    ft::map<int, std::string>   my_tree1;
    my_tree1.insert(ft::make_pair(25, "..25.. "));
    my_tree1.insert(ft::make_pair(15, "..15.. "));
    ft::map<int, std::string>::iterator    iter_my_tree1 = my_tree1.begin();

    std::map<int, std::string>   std_tree1;
    std_tree1.insert(std::make_pair(25, "..25.. "));
    std_tree1.insert(std::make_pair(15, "..15.. "));
    std::map<int, std::string>::iterator   iter_std_tree1 = std_tree1.begin();

    ft::map<int, std::string>   my_tree2;
    my_tree2.insert(ft::make_pair(5, "..5.. "));
    ft::map<int, std::string>::iterator    iter_my_tree2 = my_tree2.begin();

    std::map<int, std::string>   std_tree2;
    std_tree2.insert(std::make_pair(5, "..5.. "));
    std::map<int, std::string>::iterator   iter_std_tree2 = std_tree2.begin();

    // ft::map<int, std::string>   my_tree3;
    // my_tree3 = my_tree1;

    std::cout << "\n\033[36m" << "\t\t befor swap: " << "\033[0m"  << std::endl;

    std::cout << "my_tree1 \t  std_tree1 \t  my_tree2 \t  std_tree2 " << std::endl;
    while ( iter_my_tree1 != my_tree1.end() ||
            iter_std_tree1 != std_tree1.end() ||
            iter_my_tree2 != my_tree2.end() ||
            iter_std_tree2 != std_tree2.end() ) {
        if ( iter_my_tree1 != my_tree1.end() ) {
            std::cout << iter_my_tree1->first << " " << iter_my_tree1->second << "\t  ";
            ++iter_my_tree1;
        } else {
            std::cout << "         \t  ";
        }
        if ( iter_std_tree1 != std_tree1.end() ) {
            std::cout << iter_std_tree1->first << " " << iter_std_tree1->second << "\t  ";
            ++iter_std_tree1;
        } else {
            std::cout << "          \t  ";
        }
        if ( iter_my_tree2 != my_tree2.end() ) {
            std::cout << iter_my_tree2->first << " " << iter_my_tree2->second << "\t  ";
            ++iter_my_tree2;
        } else {
            std::cout << "         \t  ";
        }
        if ( iter_std_tree2 != std_tree2.end() ) {
            std::cout << iter_std_tree2->first << " " << iter_std_tree2->second;
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
    std::cout << "my_tree1 \t  std_tree1 \t  my_tree2 \t  std_tree2 " << std::endl;
    while ( iter_my_tree1 != my_tree1.end() ||
            iter_std_tree1 != std_tree1.end() ||
            iter_my_tree2 != my_tree2.end() ||
            iter_std_tree2 != std_tree2.end() ) {
        if ( iter_my_tree1 != my_tree1.end() ) {
            std::cout << iter_my_tree1->first << " " << iter_my_tree1->second << "\t  ";
            ++iter_my_tree1;
        } else {
            std::cout << "         \t  ";
        }
        if ( iter_std_tree1 != std_tree1.end() ) {
            std::cout << iter_std_tree1->first << " " << iter_std_tree1->second << "\t  ";
            ++iter_std_tree1;
        } else {
            std::cout << "          \t  ";
        }
        if ( iter_my_tree2 != my_tree2.end() ) {
            std::cout << iter_my_tree2->first << " " << iter_my_tree2->second << "\t  ";
            ++iter_my_tree2;
        } else {
            std::cout << "         \t  ";
        }
        if ( iter_std_tree2 != std_tree2.end() ) {
            std::cout << iter_std_tree2->first << " " << iter_std_tree2->second;
            ++iter_std_tree2;
        }
        std::cout << std::endl;
    }

}

void    testMap_clear() {
    std::cout << std::endl << "\033[35m" << "CHECK testMap Modifiers " << "\033[0m" << std::endl;
    std::cout << std::endl << "\033[33m" << "_____14_____" << "\033[0m" << std::endl;
    std::cout << "\033[34m" << "\t 14) void clear(); "
              << "\033[0m" << std::endl;
    ft::map<int, std::string>   my_tree;
    std::map<int, std::string>   std_tree;
    ft::map<int, std::string>::iterator    iter_my_tree;
    std::map<int, std::string>::iterator   iter_std_tree;
    fill_map(my_tree, &std_tree);
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

void    erase_additional_little_test() {
    std::cout << "\n\033[36m" << "\t\t erase_additional_little_test " << "\033[0m"  << std::endl;
    std::cout << "\n\033[36m" << " tree for 5 lvls " << "\033[0m"  << std::endl;
    ft::map<int, std::string>   my_tree;
    ft::map<int, std::string>::iterator    iter_my_tree;
    fill_map(my_tree, NULL);
    iter_my_tree = my_tree.find(170);
    my_tree.erase( iter_my_tree );
    iter_my_tree = my_tree.find(122);
    my_tree.erase( iter_my_tree );
    iter_my_tree = my_tree.find(60);
    my_tree.erase( iter_my_tree );

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
                     "     " // 3h-1w pos
                     "                    "
                     "     " // 3h-2w pos
                     "                        ";
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
        std::cout << "                         ";
    } else {
        if (my_tree.root().base()->left->left->_is_empty == false) {
            std::cout << "     ";
            print_int_key_node( my_tree.root().base()->left->left->left ); // 4h-1w pos // -10
            std::cout << "       ";
            print_int_key_node( my_tree.root().base()->left->left->right ); // 4h-2w pos // NIL
            std::cout << "          ";
        } else {
            std::cout << "                       ";
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

// /////////////////////////////////

void    testMap_erase() {
    std::cout << std::endl << "\033[35m" << "CHECK testMap Modifiers " << "\033[0m" << std::endl;
    std::cout << std::endl << "\033[33m" << "_____16_____" << "\033[0m" << std::endl;
    ft::map<int, std::string>   my_tree;
    std::map<int, std::string>   std_tree;
    ft::map<int, std::string>::iterator    iter_my_tree;
    std::map<int, std::string>::iterator   iter_std_tree;
    fill_map(my_tree, &std_tree);
    std_tree.insert( std::make_pair(112, "..112.. ") );
    my_tree.insert( ft::make_pair(112, "..112.. ") );
    std::cout << "my_tree.size() = " << my_tree.size() << "; std_tree.size() = " << std_tree.size() << std::endl;
    
    std::cout << "\033[34m" << "\t 16.1) void      erase( iterator pos ); \n"
              << "\033[0m" << std::endl;
    std::cout << "\n\033[36m" << "\t\t 1st case. Delete (D) without childs (begin, 110): " << "\033[0m"  << std::endl;
    std_tree.erase( std_tree.begin() );
    std_tree.erase( std_tree.find(110) );
    my_tree.erase( my_tree.begin() );
    my_tree.erase( my_tree.find(110) );

    std::cout << "\n\033[36m" << "\t\t 2st case. Delete (D) with one child (0 with child -10): " << "\033[0m"  << std::endl;
    std_tree.insert( std::make_pair(-10, "..-10.. ") );
    my_tree.insert( ft::make_pair(-10, "..-10.. ") );
    std_tree.erase( std_tree.find(0) );
    my_tree.erase( my_tree.find(0) );

    std::cout << "\n\033[36m" << "\t\t 1st case. Delete (D) with both childs: " << "\033[0m"  << std::endl;
    std_tree.insert( std::make_pair(91, "..91.. ") );
    my_tree.insert( ft::make_pair(91, "..91.. ") );
    std_tree.erase( std_tree.find(120) );
    my_tree.erase( my_tree.find(120) );
    std_tree.erase( std_tree.find(91) );
    my_tree.erase( my_tree.find(91) );

    std::cout << " std      | my " << std::endl;
    iter_my_tree = my_tree.begin();
    for (iter_std_tree = std_tree.begin(); iter_std_tree != std_tree.end(); ++iter_std_tree, ++iter_my_tree) {
        std::cout << iter_std_tree->first << "\t\t"
                  << iter_my_tree->first 
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
        std::cout << iter_std_tree->first << "\t\t"
                  << iter_my_tree->first 
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
        std::cout << iter_std_tree->first << "\t\t"
                  << iter_my_tree->first 
                  << std::endl;
    }
    std::cout << std::endl;

}

void    testMap_ElementAccess() {
    std::cout << std::endl << "\033[35m" << "CHECK testMap Element Access " << "\033[0m" << std::endl;
    std::cout << std::endl << "\033[33m" << "_____5-6_____" << "\033[0m" << std::endl;
    std::cout << "\033[34m" << "\t 5) iteT& operator[]( const Key& key ); \n"
                               "\t 6)       T& at( const Key& key ); \n"
                               "\t    const T& at( const Key& key ) const; "
              << "\033[0m" << std::endl;

    ft::map<int, std::string>   my_tree;
    std::map<int, std::string>   std_tree;
    fill_map(my_tree, &std_tree);
    std::cout << "my_tree.size() = " << my_tree.size() << "; std_tree.size() = " << std_tree.size() << std::endl;
    std::cout << "\n\033[36m" << "\t\t op[]" << "\033[0m"  << std::endl;
    std::cout << "std_tree[80] = " << std_tree[80] << std::endl;

    try {
        std_tree[80] = "At the Mountains of ";
        std_tree[80] += "Madness ";
        std::cout << "\033[36m" << "std_tree[80] = \"At the Mountains of \";" 
                  << "std_tree[80] += \"Madness \";" << "\033[0m" << std::endl;
        std::cout << "\033[36m" << "cout [80] = " << "\033[0m" <<  std_tree[80] << std::endl;

        std::cout << "\n\033[36m" << "std_tree[200] = \"..200.. \";" << "\033[0m" << std::endl;
        std_tree[200] = "..200.. ";
        std::cout << "\033[36m" << "cout [200] = " << "\033[0m"  << std_tree[200] << std::endl;

        std::cout << "\n\033[36m" << "\t\t at" << "\033[0m"  << std::endl;
        std_tree.at(80) += "!!!!!! ";
        std::cout << "\033[36m" << "std_tree.at(80) += \"!!!!!! \";" << std::endl
                  << "\033[36m" << "cout std_tree.at(80) = " << "\033[0m" << std_tree.at(80) << std::endl;
        std::cout << std::endl;
        std::cout << "\033[36m" << "try to std_tree.at(280) = \"!!!!!! \";" << "\033[0m" << std::endl;
        std_tree.at(280) = "!!!!!! ";
        std::cout << "\033[36m" << "cout std_tree.at(280) = " << "\033[0m" << std_tree.at(280) << std::endl;
        std::cout << "You will never see it... \n" << std::endl;
    } catch (...) {
        std::cout << "Attention: exception!!! \n" << std::endl;
    }

    std::cout << "\n\033[36m" << "--------------------------------" << "\033[0m"  << std::endl;
    std::cout << "\n\033[36m" << "\t\t op[]" << "\033[0m"  << std::endl;
    std::cout << "my_tree[80] = " << my_tree[80] << std::endl;
    try {
        my_tree[80] = "At the Mountains of ";
        my_tree[80] += "Madness ";
        std::cout << "\033[36m" << "my_tree[80] = \"At the Mountains of \";" 
                  << "my_tree[80] += \"Madness \";" << "\033[0m" << std::endl;
        std::cout << "\033[36m" << "cout [80] = " << "\033[0m" <<  my_tree[80] << std::endl;

        std::cout << "\n\033[36m" << "my_tree[200] = \"..200.. \";" << "\033[0m" << std::endl;
        my_tree[200] = "..200.. ";
        std::cout << "\033[36m" << "cout [200] = " << "\033[0m"  << my_tree[200] << std::endl;

        std::cout << "\n\033[36m" << "\t\t at" << "\033[0m"  << std::endl;
        my_tree.at(80) += "!!!!!! ";
        std::cout << "\033[36m" << "my_tree.at(80) += \"!!!!!! \";" << std::endl
                  << "\033[36m" << "cout my_tree.at(80) = " << "\033[0m" << my_tree.at(80) << std::endl;
        std::cout << std::endl;
        std::cout << "\033[36m" << "try to my_tree.at(280) = \"!!!!!! \";" << "\033[0m" << std::endl;
        my_tree.at(280) = "!!!!!! ";
        std::cout << "\033[36m" << "cout my_tree.at(280) = " << "\033[0m" << my_tree.at(280) << std::endl;
        std::cout << "You will never see it... \n" << std::endl;
    } catch (...) {
        std::cout << "Attention: exception!!! \n" << std::endl;
    }


}

void    testMap_lookup() {
    std::cout << std::endl << "\033[35m" << "CHECK testMap lookup " << "\033[0m" << std::endl;
    std::cout << std::endl << "\033[33m" << "_____19_____" << "\033[0m" << std::endl;
    std::cout << "\033[34m" << "\t 19) iterator       find( const Key& key ); \n"
                               "\t     const_iterator find( const Key& key ) const; \n\n"
                               "\t     size_type      count( const Key& key ) const; "
              << "\033[0m" << std::endl;

    ft::map<int, std::string>   my_tree;
    std::map<int, std::string>   std_tree;
    fill_map(my_tree, &std_tree);
    std::cout << "my_tree.size() = " << my_tree.size() << "; std_tree.size() = " << std_tree.size() << std::endl;

    ft::map<int, std::string>::iterator   iter_my_tree1;
    std::map<int, std::string>::iterator  iter_std_tree1;

    iter_my_tree1 = my_tree.find(80);
    iter_std_tree1 = std_tree.find(80);

    if (iter_std_tree1 == std_tree.end()) {
        std::cout << "STD_MAP: Fix find() parametres for std::map. " << std::endl;
    } else {
        std::cout << "STD_MAP find: Very good: " << iter_std_tree1->first << " " << iter_std_tree1->second 
                  << " | std_tree.count(80) = " << std_tree.count(80)
                  << " | std_tree.lower_bound(80)->first = " << std_tree.lower_bound(80)->first
                  << " | std_tree.upper_bound(80)->first = " << std_tree.upper_bound(80)->first
                  << std::endl;
    }

    if (iter_my_tree1 == my_tree.end()) {
        std::cout << " FT_MAP: Fix your find() in ft::map. " << std::endl;
    } else {
        std::cout << " FT_MAP find: Very good: " << iter_my_tree1->first << " " << iter_my_tree1->second 
                  << " |  my_tree.count(80) = " << my_tree.count(80)
                  << " |  my_tree.lower_bound(80)->first = " << my_tree.lower_bound(80)->first
                  << " |  my_tree.upper_bound(80)->first = " << my_tree.upper_bound(80)->first
                  << std::endl;
    }
    std::cout << std::endl;

    iter_my_tree1 = my_tree.find(11280);
    iter_std_tree1 = std_tree.find(11280);

    if (iter_std_tree1 == std_tree.end() && 
        std_tree.lower_bound(11280) == std_tree.end() &&
        std_tree.upper_bound(11280) == std_tree.end()) {
        std::cout << "STD_MAP find: Very good!!! "
                  << "std_tree.count(11280) = " << std_tree.count(11280)
                  << std::endl;

    } else {
        std::cout << "STD_MAP: Fix find() parametres for std::map. " << std::endl;
    }

    if (iter_my_tree1 == my_tree.end() && 
        my_tree.lower_bound(11280) == my_tree.end() &&
        my_tree.upper_bound(11280) == my_tree.end()) {
        std::cout << " FT_MAP find: Very good!!! "
                  << " my_tree.count(11280) = " << my_tree.count(11280)
                  << std::endl;
    } else {
        std::cout << " FT_MAP: Fix your find() in ft::map. " << std::endl;
    }
    std::cout << std::endl;

    std::cout << "std_tree.equal_range(80): "
              << "   first = " << std_tree.equal_range(80).first->first
              << " | second = " << std_tree.equal_range(80).second->first
              << std::endl;

    std::cout << " my_tree.equal_range(80): "
              << "   first = " << my_tree.equal_range(80).first->first
              << " | second = " << my_tree.equal_range(80).second->first
              << std::endl;
}

void    testMap_capacity() {
    std::cout << std::endl << "\033[35m" << "CHECK testMap capacity " << "\033[0m" << std::endl;
    std::cout << std::endl << "\033[33m" << "_____11-13_____     iterators map" << "\033[0m" << std::endl;
    std::cout << "\033[34m" << "\t 10) bool        empty() const;"
                               "\t 11) size_type   size()  const;"
              << "\033[0m" << std::endl;
    ft::map<int, std::string>   my_tree;
    std::map<int, std::string>   std_tree;
    std::cout << " ft::map<int, std::string>    my_tree;  my_tree.empty(): " << std::boolalpha << my_tree.empty() << std::endl;
    std::cout << "std::map<int, std::string>   std_tree; std_tree.empty(): " << std::boolalpha << std_tree.empty() << std::endl;
    std::cout << "( my_tree.begin() ==  my_tree.end()): " << std::boolalpha << (my_tree.begin() == my_tree.end()) << std::endl;
    std::cout << "(std_tree.begin() == std_tree.end()): " << std::boolalpha << (std_tree.begin() == std_tree.end()) << std::endl;
    std::cout << "my_tree.size() = " << my_tree.size() << "; std_tree.size() = " << std_tree.size() << std::endl;

    my_tree.insert(ft::make_pair(80, "At "));
    std_tree.insert(std::make_pair(80, "At "));
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

void    testMap_iterator_reverse() {
    std::cout << std::endl << "\033[35m" << "CHECK testMap_iterator reverse " << "\033[0m" << std::endl;
    std::cout << std::endl << "\033[35m" << "check ITERATORS reverse " << "\033[0m" << std::endl;
    std::cout << "\033[34m" << "\t iter reverse."
                 "\t\t operator-> "
                 "\t\t operator*  " << "\033[0m" << std::endl;
    std::cout << std::endl << "\033[33m" << "_____9-10_____     iterators map" << "\033[0m" << std::endl;

    ft::map<int, std::string>    my_tree;
    std::map<int, std::string>   std_tree;
    fill_map(my_tree, &std_tree);

    // std::cout << "my_tree.size() = " << my_tree.size() << "; std_tree.size() = " << std_tree.size() << std::endl;

    ft::map<int, std::string>::reverse_iterator   iter_my_tree1;
    std::map<int, std::string>::reverse_iterator  iter_std_tree1;

    ft::map<int, std::string>::reverse_iterator   iter_my_tree2;
    std::map<int, std::string>::reverse_iterator  iter_std_tree2;

    iter_my_tree1 = my_tree.rbegin();
    iter_my_tree2 = my_tree.rend();

    iter_std_tree1 = std_tree.rbegin();
    iter_std_tree2 = std_tree.rend();

    std::cout << "\033[34m" << "\t9) rbegin " << "\033[0m" << std::endl;
    std::cout << "my_tree.rbegin()->first = " << my_tree.rbegin()->first << std::endl;
    std::cout << "iter_my_tree1->first = " << iter_my_tree1->first << std::endl;
    std::cout << "(*iter_my_tree1).first = " << (*iter_my_tree1).first << std::endl;
    std::cout << std::endl;
    std::cout << "std_tree.rbegin()->first = " << std_tree.rbegin()->first << std::endl;
    std::cout << "iter_std_tree2->first = " << iter_std_tree1->first << std::endl;
    std::cout << "(*iter_std_tree2).first = " << (*iter_std_tree1).first << std::endl;

    std::cout << "\033[34m" << "\t10) rend " << "\033[0m" << std::endl;
    std::cout << "(--( my_tree.rend()))->first = " << (--(my_tree.rend()))->first << std::endl;
    std::cout << "(--(std_tree.rend()))->first = " << (--(std_tree.rend()))->first << std::endl;

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
        iter_my_tree2  =  my_tree.root().base();
        std::map<int, std::string>::reverse_iterator   iter_std_tree3(std_tree.find(my_tree.root()->first));
        while (iter_my_tree1 != iter_my_tree2) {
            std::cout << "iter_my_tree1->first = " << iter_my_tree1->first ;
            std::cout << "\t\t (*iter_my_tree1).first = " << (*iter_my_tree1++).first << std::endl;
        }
        std::cout << std::endl;
        while (iter_std_tree1 != iter_std_tree3) {
            std::cout << "iter_std_tree1->first = " << iter_std_tree1->first ;
            std::cout << "\t\t (*iter_std_tree1).first = " << (*iter_std_tree1++).first << std::endl;
        }

        std::cout << "\033[36m" << "\t\tcout iter_reverse ++operator" << "\033[0m"  << std::endl;
        std::cout << "\033[36m" << "\t\tfrom root (80) to rend" << "\033[0m"  << std::endl;
        iter_my_tree2  =  my_tree.rend();
        while (++iter_my_tree1 != iter_my_tree2) {
            std::cout << "iter_my_tree1->first = " << iter_my_tree1->first ;
            std::cout << "\t\t (*iter_my_tree1).first = " << (*iter_my_tree1).first << std::endl;
        }
        std::cout << std::endl;
        while (++iter_std_tree1 != iter_std_tree2) {
            std::cout << "iter_std_tree1->first = " << iter_std_tree1->first ;
            std::cout << "\t\t (*iter_std_tree1).first = " << (*iter_std_tree1).first << std::endl;
        }
    }

    {
        std::cout << "\033[36m" << "\t\tcout iter_reverse operator--" << "\033[0m"  << std::endl;
        std::cout << "\033[36m" << "\t\tfrom rend to root" << "\033[0m"  << std::endl;
        iter_my_tree1  =  my_tree.rend();
        --iter_my_tree1;
        iter_my_tree2  =  my_tree.root().base();
        std::map<int, std::string>::reverse_iterator   iter_std_tree3(std_tree.find(my_tree.root()->first));
        while (iter_my_tree1 != iter_my_tree2) {
            std::cout << "iter_my_tree1->first = " << iter_my_tree1->first ;
            std::cout << "\t\t (*iter_my_tree1).first = " << (*iter_my_tree1--).first << std::endl;
        }
        std::cout << std::endl;
        iter_std_tree1  =  std_tree.rend();
        --iter_std_tree1;
        while (iter_std_tree1 != iter_std_tree3) {
            std::cout << "iter_std_tree1->first = " << iter_std_tree1->first ;
            std::cout << "\t\t (*iter_std_tree1).first = " << (*iter_std_tree1--).first << std::endl;
        }

        std::cout << "\033[36m" << "\t\tcout iter_reverse --operator" << "\033[0m"  << std::endl;
        std::cout << "\033[36m" << "\t\tfrom root (80) to rbegin" << "\033[0m"  << std::endl;
        iter_my_tree2  =  my_tree.rbegin();
        while (--iter_my_tree1 != iter_my_tree2) {
            std::cout << "iter_my_tree1->first = " << iter_my_tree1->first ;
            std::cout << "\t\t (*iter_my_tree1).first = " << (*iter_my_tree1).first << std::endl;
        }
        std::cout << std::endl;
        iter_std_tree2  =  std_tree.rbegin();
        while (--iter_std_tree1 != iter_std_tree2) {
            std::cout << "iter_std_tree1->first = " << iter_std_tree1->first ;
            std::cout << "\t\t (*iter_std_tree1).first = " << (*iter_std_tree1).first << std::endl;
        }
    }
}

void    testMap_iterator() {
    std::cout << std::endl << "\033[35m" << "CHECK testMap_iterator normal " << "\033[0m" << std::endl;
    std::cout << std::endl << "\033[35m" << "check ITERATORS normal " << "\033[0m" << std::endl;
    std::cout << std::endl << "\033[33m" << "_____7-8_____     iterators" << "\033[0m" << std::endl;
    ft::map<int, std::string>   my_tree;
    std::map<int, std::string>   std_tree;
    fill_map(my_tree, NULL);

    std::cout << "\033[34m" << "\t7) begin " << "\033[0m" << std::endl;
    std::cout << "my_tree.begin()->first = " << my_tree.begin()->first << std::endl;

    std::cout << "\033[34m" << "\t8) end " << "\033[0m" << std::endl;
    std::cout << "my_tree.end().base()->parent->data.first = " << my_tree.end().base()->parent->data.first << std::endl;

    ft::map<int, std::string>::iterator iter1;
    ft::map<int, std::string>::iterator iter2;
    std::cout << "\033[34m" << "\t test iter1 = iter2 " << "\033[0m" << std::endl;
    iter1 = my_tree.root();
    iter2 = my_tree.root().base()->left;
    std::cout << "(*iter1).first = " << (*iter1).first << std::endl;
    std::cout << "(*iter2).first = " << (*iter2).first << std::endl;
    std::cout << "(*(iter1 = iter2)).first = " << (*(iter1 = iter2)).first << std::endl;

    std::cout << "\033[34m" << "\t test ++iter " << "\033[0m" << std::endl;
    iter1 = my_tree.begin();
    std::cout << "iter1 = my_tree.begin() = " << (*iter1).first << std::endl;
    iter2 = my_tree.end().base()->parent;
    std::cout << "iter2 = my_tree.end().base()->parent " << std::endl;
    while (iter1 != iter2) {
        std::cout << "\t (*++iter1).first: " << (*++iter1).first << std::endl;
    }

    std::cout << "\033[34m" << "\t test iter++ " << "\033[0m" << std::endl;
    iter1 = my_tree.begin();
    std::cout << "iter1 = my_tree.begin() = " << (*iter1).first << std::endl;
    iter2 = my_tree.end();
    std::cout << "iter2 = my_tree.end() " << std::endl;
    while (iter1 != iter2) {
        std::cout << (*iter1++).first << "\t (*iter1).first: " << (*iter1).first << std::endl;
    }

    std::cout << "\033[34m" << "\t test ++iter " << "\033[0m" << std::endl;
    iter1 = my_tree.root();
    std::cout << "iter1 = my_tree.root() = " << (*iter1).first << std::endl;
    iter2 = my_tree.end();
    std::cout << "iter2 = my_tree.end() " << std::endl;
    while (iter1 != iter2) {
        std::cout << (*iter1++).first << std::endl;
    }

    std::cout << "\033[34m" << "\t test --iter " << "\033[0m" << std::endl;
    iter1 = my_tree.begin();
    std::cout << "iter1 = my_tree.begin() = " << (*iter1).first << std::endl;
    iter2 = my_tree.end();
    std::cout << "iter2 = my_tree.end() " << std::endl;
    while (iter1 != iter2) {
        std::cout << "\t (*iter1).first: " << (*--iter2).first << std::endl;
    }

    std::cout << "\033[34m" << "\t test iter-- " << "\033[0m" << std::endl;
    iter1 = my_tree.begin();
    ++iter1;
    std::cout << "iter1 = my_tree.begin(); ++iter1; iter1: " << (*iter1).first << std::endl;
    iter2 = my_tree.end();
    --iter2;
    std::cout << "iter2 = my_tree.end(); --iter2; iter2: " << (*iter2).first << std::endl;
    while (iter1 != iter2) {
        std::cout << (*iter2--).first << "\t (*iter2).first: " << (*iter2).first << std::endl;
    }

    std::cout << "\033[34m" << "\t test --iter " << "\033[0m" << std::endl;
    iter1 = my_tree.root();
    std::cout << "iter1 = my_tree.root(); iter1 : " << (*iter1).first << std::endl;
    iter2 = my_tree.end();
    --iter2;
    std::cout << "iter2 = my_tree.end(); --iter2; iter2: " << (*iter2).first << std::endl;
    while (iter1 != iter2) {
        std::cout << "\t (*iter2--).first: " << (*iter2--).first << std::endl;
    }
}

void    testMap_insert() {
    std::cout << std::endl << "\033[35m" << "CHECK Map: modifiers" << "\033[0m" << std::endl;
    std::cout << std::endl << "\033[33m" << "_____15_____" << "\033[0m" << std::endl;
    std::cout << "\033[34m" << "\t15.1) std::pair<iterator, bool> insert( const value_type& value ); " << "\033[0m" << std::endl;
    std::cout << "\033[34m" << "\t15.2) iterator insert( iterator hint, const value_type& value ); " << "\033[0m" << std::endl;

    ft::map<int, std::string>   my_tree;
    ft::pair<ft::map<int, std::string>::iterator, bool> insert_pair;
    insert_pair = my_tree.insert(ft::make_pair(80, "At "));
    std::cout << "\n\033[36m" << "\t\t 1st insert. pair(80, \"At \") \033[0m\n"
              << "\t insert_pair.first = (iter to: (\033[33m"
              << (insert_pair.first)->first << ", \033[33m"
              << (insert_pair.first)->second
              << "\033[0m), bool: \033[33m" << std::boolalpha << insert_pair.second << "\033[0m) "
              << std::endl;

    insert_pair = my_tree.insert(ft::make_pair(40, "the "));
    std::cout << "\n\033[36m" << "\t\t     insert. pair(40, \"the \") \033[0m\n"
              << "\t insert_pair.first = (iter to: (\033[33m"
              << (insert_pair.first)->first << ", \033[33m"
              << (insert_pair.first)->second
              << "\033[0m), bool: \033[33m" << std::boolalpha << insert_pair.second << "\033[0m) "
              << std::endl;

    ft::map<int, std::string>::iterator iter_insert = 
    my_tree.insert(insert_pair.first, ft::make_pair(150, "Mountains "));
    std::cout << "\n\033[36m" << "\t\t     insert. pair(iterator, 150, \"Mountains \") \033[0m\n"
              << "\t iter_insert = (\033[33m"
              << (iter_insert)->first << ", \033[33m"
              << (iter_insert)->second
              << "\033[0m) "
              << std::endl;

    my_tree.insert(ft::make_pair(60, "of "));
    my_tree.insert(ft::make_pair(20, "Madness "));
    insert_pair = my_tree.insert(ft::make_pair(10, "... "));
    std::cout << "\n\033[36m" << "\t\t     insert. pair(10, \"... \") \033[0m\n"
              << "\t insert_pair.first = (iter to: (\033[33m"
              << (insert_pair.first)->first << ", \033[33m"
              << (insert_pair.first)->second
              << "\033[0m), bool: \033[33m" << std::boolalpha << insert_pair.second << "\033[0m) "
              << std::endl;
}

void    testTree_iterator() {
    std::cout << std::endl << "\033[35m" << "CHECK testTree_iterator " << "\033[0m" << std::endl;
    ft::RBTree<ft::pair<int, std::string> >    my_tree;

    my_tree.insert(ft::make_pair(80, "At "));
    my_tree.insert(ft::make_pair(40, "the "));
    my_tree.insert(ft::make_pair(150, "Mountains "));
    my_tree.insert(ft::make_pair(60, "of "));
    my_tree.insert(ft::make_pair(20, "Madness "));
    my_tree.insert(ft::make_pair(10, "... "));
    my_tree.insert(ft::make_pair(170, "..170.. "));
    my_tree.insert(ft::make_pair(140, "..140.. "));
    my_tree.insert(ft::make_pair(120, "..120.. "));
    my_tree.insert(ft::make_pair(0, "..0.. "));
    my_tree.insert(ft::make_pair(-10, "..-10.. "));
    my_tree.insert(ft::make_pair(130, "..130.. "));

    std::cout << "\033[34m" << "\t test iter1 = iter2 " << "\033[0m" << std::endl;
    ft::RBTree<ft::pair<int, std::string> >::iterator iter1;
    iter1 = my_tree.root();
    std::cout << "(*iter1).data.first = " << (*iter1).first << std::endl;
    ft::RBTree<ft::pair<int, std::string> >::iterator iter2;
    iter2 = my_tree.root().base()->left;
    std::cout << "(*iter2).data.first = " << (*iter2).first << std::endl;
    std::cout << "(*(iter1 = iter2)).data.first = " << (*(iter1 = iter2)).first << std::endl;

    std::cout << "\033[34m" << "\t test ++iter and iter++ " << "\033[0m" << std::endl;
    iter1 = my_tree.root();
    std::cout << "iter1 = my_tree.root() = " << (*iter1).first << std::endl;
    std::cout << "++iter1: " << std::endl;
    std::cout << (*++iter1).first << std::endl;
    std::cout << (*++iter1).first << std::endl;
    std::cout << (*++iter1).first << std::endl;
    std::cout << (*++iter1).first << std::endl;
    std::cout << (*++iter1).first << std::endl;

    iter1 = my_tree.root();
    std::cout << "iter1 = my_tree.root() = " << (*iter1).first << std::endl;
    std::cout << "iter1++: " << std::endl;
    std::cout << (*iter1++).first << "\t (*iter1).data.first: " << (*iter1).first << std::endl;
    std::cout << (*iter1++).first << "\t (*iter1).data.first: " << (*iter1).first << std::endl;
    std::cout << (*iter1++).first << "\t (*iter1).data.first: " << (*iter1).first << std::endl;
    std::cout << (*iter1++).first << "\t (*iter1).data.first: " << (*iter1).first << std::endl;
    std::cout << (*iter1++).first << "\t (*iter1).data.first: " << (*iter1).first << std::endl;
}

void    testTree_insert() {
    // std::cout << std::boolalpha;
    std::cout << std::endl << "\033[35m" << "CHECK RBTREE " << "\033[0m" << std::endl;
    
    ft::RBTree<ft::pair<int, std::string> >    my_tree(ft::make_pair(80, "Hello"));
    {
        std::cout << "\033[34m" << "\t test without rotate " << "\033[0m" << std::endl;
        // test without rotate

        std::cout << (*my_tree.root()).first << " " << std::endl;
        std::cout << (my_tree.root())->first << " " << (my_tree.root())->second << std::endl;

        my_tree.insert(ft::make_pair(80, "At "));
        std::cout << (my_tree.root())->first << " " << (my_tree.root())->second << std::endl;

        my_tree.insert(ft::make_pair(40, "the "));
        std::cout << my_tree.root()->first << " " << my_tree.root()->second << " " << my_tree.root().base()->color << std::endl;
        std::cout << my_tree.root().base()->left->data.first << " " << my_tree.root().base()->left->data.second << " " << my_tree.root().base()->left->color << std::endl;
        std::cout << std::endl;
        my_tree.insert(ft::make_pair(150, "Mountains "));
        std::cout << my_tree.root()->first << " " << my_tree.root()->second << " " << my_tree.root().base()->color << std::endl;
        std::cout << my_tree.root().base()->left->data.first << " " << my_tree.root().base()->left->data.second << " " << my_tree.root().base()->left->color << std::endl;
        std::cout << my_tree.root().base()->right->data.first << " " << my_tree.root().base()->right->data.second << " " << my_tree.root().base()->right->color << std::endl;
        std::cout << std::endl;
        my_tree.insert(ft::make_pair(60, "of "));
        std::cout << my_tree.root()->first << " " << my_tree.root()->second << " " << my_tree.root().base()->color << std::endl;
        std::cout << my_tree.root().base()->left->data.first << " " << my_tree.root().base()->left->data.second << " " << my_tree.root().base()->left->color << std::endl;
        std::cout << my_tree.root().base()->right->data.first << " " << my_tree.root().base()->right->data.second << " " << my_tree.root().base()->right->color << std::endl;
        std::cout << my_tree.root().base()->left->right->data.first << " " << my_tree.root().base()->left->right->data.second << " " << my_tree.root().base()->left->right->color << std::endl;
        std::cout << std::endl;
        my_tree.insert(ft::make_pair(20, "Madness "));
        std::cout << my_tree.root()->first << " " << my_tree.root()->second << " " << my_tree.root().base()->color << std::endl;
        std::cout << my_tree.root().base()->left->data.first << " " << my_tree.root().base()->left->data.second << " " << my_tree.root().base()->left->color << std::endl;
        std::cout << my_tree.root().base()->right->data.first << " " << my_tree.root().base()->right->data.second << " " << my_tree.root().base()->right->color << std::endl;
        std::cout << my_tree.root().base()->left->right->data.first << " " << my_tree.root().base()->left->right->data.second << " " << my_tree.root().base()->left->right->color << std::endl;
        std::cout << my_tree.root().base()->left->left->data.first << " " << my_tree.root().base()->left->left->data.second << " " << my_tree.root().base()->left->left->color << std::endl;
        std::cout << std::endl;
        my_tree.insert(ft::make_pair(10, "... "));
        std::cout << my_tree.root()->first << " " << my_tree.root()->second << " " << my_tree.root().base()->color << std::endl;
        std::cout << my_tree.root().base()->left->data.first << " " << my_tree.root().base()->left->data.second << " " << my_tree.root().base()->left->color << std::endl;
        std::cout << my_tree.root().base()->right->data.first << " " << my_tree.root().base()->right->data.second << " " << my_tree.root().base()->right->color << std::endl;
        std::cout << my_tree.root().base()->left->right->data.first << " " << my_tree.root().base()->left->right->data.second << " " << my_tree.root().base()->left->right->color << std::endl;
        std::cout << my_tree.root().base()->left->left->data.first << " " << my_tree.root().base()->left->left->data.second << " " << my_tree.root().base()->left->left->color << std::endl;
        std::cout << my_tree.root().base()->left->left->left->data.first << " " << my_tree.root().base()->left->left->left->data.second << " " << my_tree.root().base()->left->left->left->color << std::endl;
        std::cout << std::endl;

        my_tree.insert(ft::make_pair(170, "..170.. "));
        my_tree.insert(ft::make_pair(140, "..140.. "));
        my_tree.insert(ft::make_pair(120, "..120.. "));
        std::cout << my_tree.root()->first << " " << my_tree.root()->second << " " << my_tree.root().base()->color << std::endl;
        std::cout << my_tree.root().base()->left->data.first << " " << my_tree.root().base()->left->data.second << " " << my_tree.root().base()->left->color << std::endl;
        std::cout << my_tree.root().base()->left->right->data.first << " " << my_tree.root().base()->left->right->data.second << " " << my_tree.root().base()->left->right->color << std::endl;
        std::cout << my_tree.root().base()->left->left->data.first << " " << my_tree.root().base()->left->left->data.second << " " << my_tree.root().base()->left->left->color << std::endl;
        std::cout << my_tree.root().base()->left->left->left->data.first << " " << my_tree.root().base()->left->left->left->data.second << " " << my_tree.root().base()->left->left->left->color << std::endl;
        std::cout << my_tree.root().base()->right->data.first << " " << my_tree.root().base()->right->data.second << " " << my_tree.root().base()->right->color << std::endl;
        std::cout << my_tree.root().base()->right->left->data.first << " " << my_tree.root().base()->right->left->data.second << " " << my_tree.root().base()->right->left->color << std::endl;
        std::cout << my_tree.root().base()->right->right->data.first << " " << my_tree.root().base()->right->right->data.second << " " << my_tree.root().base()->right->right->color << std::endl;
        std::cout << my_tree.root().base()->right->left->left->data.first << " " << my_tree.root().base()->right->left->left->data.second << " " << my_tree.root().base()->right->left->left->color << std::endl;
        std::cout << std::endl;
    }
    {
        std::cout << "\033[34m" << "\t test with rotate (one line) " << "\033[0m" << std::endl;
        // test with rotate (one line)

        my_tree.insert(ft::make_pair(0, "..0.. "));
        std::cout << my_tree.root()->first << " " << my_tree.root()->second << " " << my_tree.root().base()->color << std::endl;
        std::cout << my_tree.root().base()->left->data.first << " " << my_tree.root().base()->left->data.second << " " << my_tree.root().base()->left->color << std::endl;
        std::cout << my_tree.root().base()->left->right->data.first << " " << my_tree.root().base()->left->right->data.second << " " << my_tree.root().base()->left->right->color << std::endl;
        std::cout << my_tree.root().base()->left->left->data.first << " " << my_tree.root().base()->left->left->data.second << " " << my_tree.root().base()->left->left->color << std::endl;
        std::cout << my_tree.root().base()->left->left->left->data.first << " " << my_tree.root().base()->left->left->left->data.second << " " << my_tree.root().base()->left->left->left->color << std::endl;
        std::cout << my_tree.root().base()->left->left->right->data.first << " " << my_tree.root().base()->left->left->right->data.second << " " << my_tree.root().base()->left->left->right->color << std::endl;
        std::cout << my_tree.root().base()->right->data.first << " " << my_tree.root().base()->right->data.second << " " << my_tree.root().base()->right->color << std::endl;
        std::cout << my_tree.root().base()->right->left->data.first << " " << my_tree.root().base()->right->left->data.second << " " << my_tree.root().base()->right->left->color << std::endl;
        std::cout << my_tree.root().base()->right->right->data.first << " " << my_tree.root().base()->right->right->data.second << " " << my_tree.root().base()->right->right->color << std::endl;
        std::cout << my_tree.root().base()->right->left->left->data.first << " " << my_tree.root().base()->right->left->left->data.second << " " << my_tree.root().base()->right->left->left->color << std::endl;
        std::cout << std::endl;

        my_tree.insert(ft::make_pair(-10, "..-10.. "));
        std::cout << my_tree.root()->first << " " << my_tree.root()->second << " " << my_tree.root().base()->color << std::endl;
        std::cout << my_tree.root().base()->left->data.first << " " << my_tree.root().base()->left->data.second << " " << my_tree.root().base()->left->color << std::endl;
        std::cout << my_tree.root().base()->left->right->data.first << " " << my_tree.root().base()->left->right->data.second << " " << my_tree.root().base()->left->right->color << std::endl;
        std::cout << my_tree.root().base()->left->left->data.first << " " << my_tree.root().base()->left->left->data.second << " " << my_tree.root().base()->left->left->color << std::endl;
        std::cout << my_tree.root().base()->left->left->left->data.first << " " << my_tree.root().base()->left->left->left->data.second << " " << my_tree.root().base()->left->left->left->color << std::endl;
        std::cout << my_tree.root().base()->left->left->left->left->data.first << " " << my_tree.root().base()->left->left->left->left->data.second << " " << my_tree.root().base()->left->left->left->left->color << std::endl;
        std::cout << my_tree.root().base()->left->left->right->data.first << " " << my_tree.root().base()->left->left->right->data.second << " " << my_tree.root().base()->left->left->right->color << std::endl;
        std::cout << my_tree.root().base()->right->data.first << " " << my_tree.root().base()->right->data.second << " " << my_tree.root().base()->right->color << std::endl;
        std::cout << my_tree.root().base()->right->left->data.first << " " << my_tree.root().base()->right->left->data.second << " " << my_tree.root().base()->right->left->color << std::endl;
        std::cout << my_tree.root().base()->right->right->data.first << " " << my_tree.root().base()->right->right->data.second << " " << my_tree.root().base()->right->right->color << std::endl;
        std::cout << my_tree.root().base()->right->left->left->data.first << " " << my_tree.root().base()->right->left->left->data.second << " " << my_tree.root().base()->right->left->left->color << std::endl;
        std::cout << std::endl;
    }
    {
        std::cout << "\033[34m" << "\t test with rotate (angle) " << "\033[0m" << std::endl;
        // test with rotate (angle)

        my_tree.insert(ft::make_pair(130, "..130.. "));
        std::cout << my_tree.root()->first << " " << my_tree.root()->second << " " << my_tree.root().base()->color << std::endl;
        std::cout << my_tree.root().base()->left->data.first << " " << my_tree.root().base()->left->data.second << " " << my_tree.root().base()->left->color << std::endl;
        std::cout << my_tree.root().base()->left->left->data.first << " " << my_tree.root().base()->left->left->data.second << " " << my_tree.root().base()->left->left->color << std::endl;
        std::cout << my_tree.root().base()->left->right->data.first << " " << my_tree.root().base()->left->right->data.second << " " << my_tree.root().base()->left->right->color << std::endl;
        std::cout << my_tree.root().base()->left->left->left->data.first << " " << my_tree.root().base()->left->left->left->data.second << " " << my_tree.root().base()->left->left->left->color << std::endl;
        std::cout << my_tree.root().base()->left->left->right->data.first << " " << my_tree.root().base()->left->left->right->data.second << " " << my_tree.root().base()->left->left->right->color << std::endl;
        std::cout << my_tree.root().base()->left->left->left->left->data.first << " " << my_tree.root().base()->left->left->left->left->data.second << " " << my_tree.root().base()->left->left->left->left->color << std::endl;
        std::cout << my_tree.root().base()->right->data.first << " " << my_tree.root().base()->right->data.second << " " << my_tree.root().base()->right->color << std::endl;
        std::cout << my_tree.root().base()->right->right->data.first << " " << my_tree.root().base()->right->right->data.second << " " << my_tree.root().base()->right->right->color << std::endl;
        std::cout << my_tree.root().base()->right->left->data.first << " " << my_tree.root().base()->right->left->data.second << " " << my_tree.root().base()->right->left->color << std::endl;
        std::cout << my_tree.root().base()->right->left->left->data.first << " " << my_tree.root().base()->right->left->left->data.second << " " << my_tree.root().base()->right->left->left->color << std::endl;
        std::cout << my_tree.root().base()->right->left->right->data.first << " " << my_tree.root().base()->right->left->right->data.second << " " << my_tree.root().base()->right->left->right->color << std::endl;
        std::cout << std::endl;

    }
}
