#include <iostream>
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

// At the Mountains of Madness
int main() {
    // testTree_insert();
    // testTree_iterator();
    // testMap_insert(); // 15
    // testMap_iterator(); // 7, 8
    // testMap_iterator_reverse(); // 9, 10
    testMap_capacity(); // 11, 12, 13

    return (0);
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

    std::map<int, std::string>   std_tree;
    std_tree.insert(std::make_pair(80, "At "));
    std_tree.insert(std::make_pair(40, "the "));
    std_tree.insert(std::make_pair(150, "Mountains "));
    std_tree.insert(std::make_pair(60, "of "));
    std_tree.insert(std::make_pair(20, "Madness "));
    std_tree.insert(std::make_pair(10, "... "));
    std_tree.insert(std::make_pair(170, "..170.. "));
    std_tree.insert(std::make_pair(140, "..140.. "));
    std_tree.insert(std::make_pair(120, "..120.. "));
    std_tree.insert(std::make_pair(0, "..0.. "));
    std_tree.insert(std::make_pair(-10, "..-10.. "));
    std_tree.insert(std::make_pair(130, "..130.. "));
    std_tree.insert(std::make_pair(110, "..110.. "));
    std_tree.insert(std::make_pair(122, "..122.. "));
    std_tree.insert(std::make_pair(100, "..100.. "));
    std_tree.insert(std::make_pair(90, "..90.. "));
    std_tree.insert(std::make_pair(85, "..85.. "));

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
