#include <iostream>
#include <utility.hpp>
// #include <ft_vector.hpp>
#include <RBTree.hpp>
#include <iterator_binTree_normal.hpp>
#include <map.hpp>

void    testTree_insert();
void    testTree_iterator();
void    testMap_iterator();
void    testMap_insert();


// At the Mountains of Madness
int main() {
    // testTree_insert();
    // testTree_iterator();
    testMap_iterator();
    // testMap_insert(); // 15

    return (0);
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
              << (insert_pair.first)->data.first << ", \033[33m"
              << (insert_pair.first)->data.second
              << "\033[0m), bool: \033[33m" << std::boolalpha << insert_pair.second << "\033[0m) "
              << std::endl;

    insert_pair = my_tree.insert(ft::make_pair(40, "the "));
    std::cout << "\n\033[36m" << "\t\t     insert. pair(40, \"the \") \033[0m\n"
              << "\t insert_pair.first = (iter to: (\033[33m"
              << (insert_pair.first)->data.first << ", \033[33m"
              << (insert_pair.first)->data.second
              << "\033[0m), bool: \033[33m" << std::boolalpha << insert_pair.second << "\033[0m) "
              << std::endl;

    ft::map<int, std::string>::iterator iter_insert = 
    my_tree.insert(insert_pair.first, ft::make_pair(150, "Mountains "));
    std::cout << "\n\033[36m" << "\t\t     insert. pair(iterator, 150, \"Mountains \") \033[0m\n"
              << "\t iter_insert = (\033[33m"
              << (iter_insert)->data.first << ", \033[33m"
              << (iter_insert)->data.second
              << "\033[0m) "
              << std::endl;

    my_tree.insert(ft::make_pair(60, "of "));
    my_tree.insert(ft::make_pair(20, "Madness "));
    insert_pair = my_tree.insert(ft::make_pair(10, "... "));
    std::cout << "\n\033[36m" << "\t\t     insert. pair(10, \"... \") \033[0m\n"
              << "\t insert_pair.first = (iter to: (\033[33m"
              << (insert_pair.first)->data.first << ", \033[33m"
              << (insert_pair.first)->data.second
              << "\033[0m), bool: \033[33m" << std::boolalpha << insert_pair.second << "\033[0m) "
              << std::endl;
}

void    testMap_iterator() {
    std::cout << std::endl << "\033[35m" << "CHECK testMap_iterator " << "\033[0m" << std::endl;
    ft::map<int, std::string>   my_tree;

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


    ft::map<int, std::string>::iterator iter1;
    ft::map<int, std::string>::iterator iter2;
    std::cout << "\033[34m" << "\t test iter1 = iter2 " << "\033[0m" << std::endl;
    iter1 = my_tree.root();
    iter2 = my_tree.root()->left;
    std::cout << "(*iter1).data.first = " << (*iter1).data.first << std::endl;
    std::cout << "(*iter2).data.first = " << (*iter2).data.first << std::endl;
    std::cout << "(*(iter1 = iter2)).data.first = " << (*(iter1 = iter2)).data.first << std::endl;

    std::cout << "\033[34m" << "\t test ++iter " << "\033[0m" << std::endl;
    iter1 = my_tree.begin();
    std::cout << "iter1 = my_tree.begin() = " << (*iter1).data.first << std::endl;
    iter2 = my_tree.end()->parent;
    std::cout << "iter2 = my_tree.end()->parent " << std::endl;
    while (iter1 != iter2) {
        std::cout << "\t (*iter1).data.first: " << (*++iter1).data.first << std::endl;
    }

    std::cout << "\033[34m" << "\t test iter++ " << "\033[0m" << std::endl;
    iter1 = my_tree.begin();
    std::cout << "iter1 = my_tree.begin() = " << (*iter1).data.first << std::endl;
    iter2 = my_tree.end();
    std::cout << "iter2 = my_tree.end() " << std::endl;
    while (iter1 != iter2) {
        std::cout << (*iter1++).data.first << "\t (*iter1).data.first: " << (*iter1).data.first << std::endl;
    }

    std::cout << "\033[34m" << "\t test ++iter " << "\033[0m" << std::endl;
    iter1 = my_tree.root();
    std::cout << "iter1 = my_tree.root() = " << (*iter1).data.first << std::endl;
    iter2 = my_tree.end();
    std::cout << "iter2 = my_tree.end() " << std::endl;
    while (iter1 != iter2) {
        std::cout << (*iter1++).data.first << std::endl;
    }

    std::cout << "\033[34m" << "\t test --iter " << "\033[0m" << std::endl;
    iter1 = my_tree.begin();
    std::cout << "iter1 = my_tree.begin() = " << (*iter1).data.first << std::endl;
    iter2 = my_tree.end();
    std::cout << "iter2 = my_tree.end() " << std::endl;
    while (iter1 != iter2) {
        std::cout << "\t (*iter1).data.first: " << (*--iter2).data.first << std::endl;
    }

    std::cout << "\033[34m" << "\t test iter-- " << "\033[0m" << std::endl;
    iter1 = my_tree.begin();
    ++iter1;
    std::cout << "iter1 = my_tree.begin(); ++iter1; iter1: " << (*iter1).data.first << std::endl;
    iter2 = my_tree.end();
    --iter2;
    std::cout << "iter2 = my_tree.end(); --iter2; iter2: " << (*iter2).data.first << std::endl;
    while (iter1 != iter2) {
        std::cout << (*iter2--).data.first << "\t (*iter2).data.first: " << (*iter2).data.first << std::endl;
    }

    std::cout << "\033[34m" << "\t test --iter " << "\033[0m" << std::endl;
    iter1 = my_tree.root();
    std::cout << "iter1 = my_tree.root(); iter1 : " << (*iter1).data.first << std::endl;
    iter2 = my_tree.end();
    --iter2;
    std::cout << "iter2 = my_tree.end(); --iter2; iter2: " << (*iter2).data.first << std::endl;
    while (iter1 != iter2) {
        std::cout << "\t (*iter2--).data.first: " << (*iter2--).data.first << std::endl;
    }
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
    std::cout << "(*iter1).data.first = " << (*iter1).data.first << std::endl;
    ft::RBTree<ft::pair<int, std::string> >::iterator iter2;
    iter2 = my_tree.root()->left;
    std::cout << "(*iter2).data.first = " << (*iter2).data.first << std::endl;
    std::cout << "(*(iter1 = iter2)).data.first = " << (*(iter1 = iter2)).data.first << std::endl;

    std::cout << "\033[34m" << "\t test ++iter and iter++ " << "\033[0m" << std::endl;
    iter1 = my_tree.root();
    std::cout << "iter1 = my_tree.root() = " << (*iter1).data.first << std::endl;
    std::cout << "++iter1: " << std::endl;
    std::cout << (*++iter1).data.first << std::endl;
    std::cout << (*++iter1).data.first << std::endl;
    std::cout << (*++iter1).data.first << std::endl;
    std::cout << (*++iter1).data.first << std::endl;
    std::cout << (*++iter1).data.first << std::endl;

    iter1 = my_tree.root();
    std::cout << "iter1 = my_tree.root() = " << (*iter1).data.first << std::endl;
    std::cout << "iter1++: " << std::endl;
    std::cout << (*iter1++).data.first << "\t (*iter1).data.first: " << (*iter1).data.first << std::endl;
    std::cout << (*iter1++).data.first << "\t (*iter1).data.first: " << (*iter1).data.first << std::endl;
    std::cout << (*iter1++).data.first << "\t (*iter1).data.first: " << (*iter1).data.first << std::endl;
    std::cout << (*iter1++).data.first << "\t (*iter1).data.first: " << (*iter1).data.first << std::endl;
    std::cout << (*iter1++).data.first << "\t (*iter1).data.first: " << (*iter1).data.first << std::endl;
}

void    testTree_insert() {
    // std::cout << std::boolalpha;
    std::cout << std::endl << "\033[35m" << "CHECK RBTREE " << "\033[0m" << std::endl;
    
    ft::RBTree<ft::pair<int, std::string> >    my_tree(ft::make_pair(80, "Hello"));
    {
        std::cout << "\033[34m" << "\t test without rotate " << "\033[0m" << std::endl;
        // test without rotate

        std::cout << my_tree.root()->data.first << " " << my_tree.root()->data.second << std::endl;

        my_tree.insert(ft::make_pair(80, "At "));
        std::cout << my_tree.root()->data.first << " " << my_tree.root()->data.second << std::endl;

        my_tree.insert(ft::make_pair(40, "the "));
        std::cout << my_tree.root()->data.first << " " << my_tree.root()->data.second << " " << my_tree.root()->color << std::endl;
        std::cout << my_tree.root()->left->data.first << " " << my_tree.root()->left->data.second << " " << my_tree.root()->left->color << std::endl;
        std::cout << std::endl;
        my_tree.insert(ft::make_pair(150, "Mountains "));
        std::cout << my_tree.root()->data.first << " " << my_tree.root()->data.second << " " << my_tree.root()->color << std::endl;
        std::cout << my_tree.root()->left->data.first << " " << my_tree.root()->left->data.second << " " << my_tree.root()->left->color << std::endl;
        std::cout << my_tree.root()->right->data.first << " " << my_tree.root()->right->data.second << " " << my_tree.root()->right->color << std::endl;
        std::cout << std::endl;
        my_tree.insert(ft::make_pair(60, "of "));
        std::cout << my_tree.root()->data.first << " " << my_tree.root()->data.second << " " << my_tree.root()->color << std::endl;
        std::cout << my_tree.root()->left->data.first << " " << my_tree.root()->left->data.second << " " << my_tree.root()->left->color << std::endl;
        std::cout << my_tree.root()->right->data.first << " " << my_tree.root()->right->data.second << " " << my_tree.root()->right->color << std::endl;
        std::cout << my_tree.root()->left->right->data.first << " " << my_tree.root()->left->right->data.second << " " << my_tree.root()->left->right->color << std::endl;
        std::cout << std::endl;
        my_tree.insert(ft::make_pair(20, "Madness "));
        std::cout << my_tree.root()->data.first << " " << my_tree.root()->data.second << " " << my_tree.root()->color << std::endl;
        std::cout << my_tree.root()->left->data.first << " " << my_tree.root()->left->data.second << " " << my_tree.root()->left->color << std::endl;
        std::cout << my_tree.root()->right->data.first << " " << my_tree.root()->right->data.second << " " << my_tree.root()->right->color << std::endl;
        std::cout << my_tree.root()->left->right->data.first << " " << my_tree.root()->left->right->data.second << " " << my_tree.root()->left->right->color << std::endl;
        std::cout << my_tree.root()->left->left->data.first << " " << my_tree.root()->left->left->data.second << " " << my_tree.root()->left->left->color << std::endl;
        std::cout << std::endl;
        my_tree.insert(ft::make_pair(10, "... "));
        std::cout << my_tree.root()->data.first << " " << my_tree.root()->data.second << " " << my_tree.root()->color << std::endl;
        std::cout << my_tree.root()->left->data.first << " " << my_tree.root()->left->data.second << " " << my_tree.root()->left->color << std::endl;
        std::cout << my_tree.root()->right->data.first << " " << my_tree.root()->right->data.second << " " << my_tree.root()->right->color << std::endl;
        std::cout << my_tree.root()->left->right->data.first << " " << my_tree.root()->left->right->data.second << " " << my_tree.root()->left->right->color << std::endl;
        std::cout << my_tree.root()->left->left->data.first << " " << my_tree.root()->left->left->data.second << " " << my_tree.root()->left->left->color << std::endl;
        std::cout << my_tree.root()->left->left->left->data.first << " " << my_tree.root()->left->left->left->data.second << " " << my_tree.root()->left->left->left->color << std::endl;
        std::cout << std::endl;

        my_tree.insert(ft::make_pair(170, "..170.. "));
        my_tree.insert(ft::make_pair(140, "..140.. "));
        my_tree.insert(ft::make_pair(120, "..120.. "));
        std::cout << my_tree.root()->data.first << " " << my_tree.root()->data.second << " " << my_tree.root()->color << std::endl;
        std::cout << my_tree.root()->left->data.first << " " << my_tree.root()->left->data.second << " " << my_tree.root()->left->color << std::endl;
        std::cout << my_tree.root()->left->right->data.first << " " << my_tree.root()->left->right->data.second << " " << my_tree.root()->left->right->color << std::endl;
        std::cout << my_tree.root()->left->left->data.first << " " << my_tree.root()->left->left->data.second << " " << my_tree.root()->left->left->color << std::endl;
        std::cout << my_tree.root()->left->left->left->data.first << " " << my_tree.root()->left->left->left->data.second << " " << my_tree.root()->left->left->left->color << std::endl;
        std::cout << my_tree.root()->right->data.first << " " << my_tree.root()->right->data.second << " " << my_tree.root()->right->color << std::endl;
        std::cout << my_tree.root()->right->left->data.first << " " << my_tree.root()->right->left->data.second << " " << my_tree.root()->right->left->color << std::endl;
        std::cout << my_tree.root()->right->right->data.first << " " << my_tree.root()->right->right->data.second << " " << my_tree.root()->right->right->color << std::endl;
        std::cout << my_tree.root()->right->left->left->data.first << " " << my_tree.root()->right->left->left->data.second << " " << my_tree.root()->right->left->left->color << std::endl;
        std::cout << std::endl;
    }
    {
        std::cout << "\033[34m" << "\t test with rotate (one line) " << "\033[0m" << std::endl;
        // test with rotate (one line)

        my_tree.insert(ft::make_pair(0, "..0.. "));
        std::cout << my_tree.root()->data.first << " " << my_tree.root()->data.second << " " << my_tree.root()->color << std::endl;
        std::cout << my_tree.root()->left->data.first << " " << my_tree.root()->left->data.second << " " << my_tree.root()->left->color << std::endl;
        std::cout << my_tree.root()->left->right->data.first << " " << my_tree.root()->left->right->data.second << " " << my_tree.root()->left->right->color << std::endl;
        std::cout << my_tree.root()->left->left->data.first << " " << my_tree.root()->left->left->data.second << " " << my_tree.root()->left->left->color << std::endl;
        std::cout << my_tree.root()->left->left->left->data.first << " " << my_tree.root()->left->left->left->data.second << " " << my_tree.root()->left->left->left->color << std::endl;
        std::cout << my_tree.root()->left->left->right->data.first << " " << my_tree.root()->left->left->right->data.second << " " << my_tree.root()->left->left->right->color << std::endl;
        std::cout << my_tree.root()->right->data.first << " " << my_tree.root()->right->data.second << " " << my_tree.root()->right->color << std::endl;
        std::cout << my_tree.root()->right->left->data.first << " " << my_tree.root()->right->left->data.second << " " << my_tree.root()->right->left->color << std::endl;
        std::cout << my_tree.root()->right->right->data.first << " " << my_tree.root()->right->right->data.second << " " << my_tree.root()->right->right->color << std::endl;
        std::cout << my_tree.root()->right->left->left->data.first << " " << my_tree.root()->right->left->left->data.second << " " << my_tree.root()->right->left->left->color << std::endl;
        std::cout << std::endl;

        my_tree.insert(ft::make_pair(-10, "..-10.. "));
        std::cout << my_tree.root()->data.first << " " << my_tree.root()->data.second << " " << my_tree.root()->color << std::endl;
        std::cout << my_tree.root()->left->data.first << " " << my_tree.root()->left->data.second << " " << my_tree.root()->left->color << std::endl;
        std::cout << my_tree.root()->left->right->data.first << " " << my_tree.root()->left->right->data.second << " " << my_tree.root()->left->right->color << std::endl;
        std::cout << my_tree.root()->left->left->data.first << " " << my_tree.root()->left->left->data.second << " " << my_tree.root()->left->left->color << std::endl;
        std::cout << my_tree.root()->left->left->left->data.first << " " << my_tree.root()->left->left->left->data.second << " " << my_tree.root()->left->left->left->color << std::endl;
        std::cout << my_tree.root()->left->left->left->left->data.first << " " << my_tree.root()->left->left->left->left->data.second << " " << my_tree.root()->left->left->left->left->color << std::endl;
        std::cout << my_tree.root()->left->left->right->data.first << " " << my_tree.root()->left->left->right->data.second << " " << my_tree.root()->left->left->right->color << std::endl;
        std::cout << my_tree.root()->right->data.first << " " << my_tree.root()->right->data.second << " " << my_tree.root()->right->color << std::endl;
        std::cout << my_tree.root()->right->left->data.first << " " << my_tree.root()->right->left->data.second << " " << my_tree.root()->right->left->color << std::endl;
        std::cout << my_tree.root()->right->right->data.first << " " << my_tree.root()->right->right->data.second << " " << my_tree.root()->right->right->color << std::endl;
        std::cout << my_tree.root()->right->left->left->data.first << " " << my_tree.root()->right->left->left->data.second << " " << my_tree.root()->right->left->left->color << std::endl;
        std::cout << std::endl;
    }
    {
        std::cout << "\033[34m" << "\t test with rotate (angle) " << "\033[0m" << std::endl;
        // test with rotate (angle)

        my_tree.insert(ft::make_pair(130, "..130.. "));
        std::cout << my_tree.root()->data.first << " " << my_tree.root()->data.second << " " << my_tree.root()->color << std::endl;
        std::cout << my_tree.root()->left->data.first << " " << my_tree.root()->left->data.second << " " << my_tree.root()->left->color << std::endl;
        std::cout << my_tree.root()->left->left->data.first << " " << my_tree.root()->left->left->data.second << " " << my_tree.root()->left->left->color << std::endl;
        std::cout << my_tree.root()->left->right->data.first << " " << my_tree.root()->left->right->data.second << " " << my_tree.root()->left->right->color << std::endl;
        std::cout << my_tree.root()->left->left->left->data.first << " " << my_tree.root()->left->left->left->data.second << " " << my_tree.root()->left->left->left->color << std::endl;
        std::cout << my_tree.root()->left->left->right->data.first << " " << my_tree.root()->left->left->right->data.second << " " << my_tree.root()->left->left->right->color << std::endl;
        std::cout << my_tree.root()->left->left->left->left->data.first << " " << my_tree.root()->left->left->left->left->data.second << " " << my_tree.root()->left->left->left->left->color << std::endl;
        std::cout << my_tree.root()->right->data.first << " " << my_tree.root()->right->data.second << " " << my_tree.root()->right->color << std::endl;
        std::cout << my_tree.root()->right->right->data.first << " " << my_tree.root()->right->right->data.second << " " << my_tree.root()->right->right->color << std::endl;
        std::cout << my_tree.root()->right->left->data.first << " " << my_tree.root()->right->left->data.second << " " << my_tree.root()->right->left->color << std::endl;
        std::cout << my_tree.root()->right->left->left->data.first << " " << my_tree.root()->right->left->left->data.second << " " << my_tree.root()->right->left->left->color << std::endl;
        std::cout << my_tree.root()->right->left->right->data.first << " " << my_tree.root()->right->left->right->data.second << " " << my_tree.root()->right->left->right->color << std::endl;
        std::cout << std::endl;

    }
}
