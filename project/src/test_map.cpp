#include <iostream>
#include <utility.hpp>
// #include <ft_vector.hpp>
#include <RBTree.hpp>
#include <iterator_binTree_normal.hpp>
#include <map.hpp>

void    testTree_insert();
void    testTree_iterator();
void    testMap_iterator();


// At the Mountains of Madness
int main() {
    // testTree_insert();
    testTree_iterator();
    // testMap_iterator();

    return (0);
}

void    testMap_iterator() {
    std::cout << std::endl << "\033[35m" << "CHECK testMap_iterator " << "\033[0m" << std::endl;
    ft::map<int, std::string>   my_tree;

    my_tree.insert_node(ft::make_pair(80, "At "));
    my_tree.insert_node(ft::make_pair(40, "the "));
    my_tree.insert_node(ft::make_pair(150, "Mountains "));
    my_tree.insert_node(ft::make_pair(60, "of "));
    my_tree.insert_node(ft::make_pair(20, "Madness "));
    my_tree.insert_node(ft::make_pair(10, "... "));
    my_tree.insert_node(ft::make_pair(170, "..170.. "));
    my_tree.insert_node(ft::make_pair(140, "..140.. "));
    my_tree.insert_node(ft::make_pair(120, "..120.. "));
    my_tree.insert_node(ft::make_pair(0, "..0.. "));
    my_tree.insert_node(ft::make_pair(-10, "..-10.. "));
    my_tree.insert_node(ft::make_pair(130, "..130.. "));

    ft::map<int, std::string>::iterator iter1;
    ft::map<int, std::string>::iterator iter2;
    std::cout << "\033[34m" << "\t test iter1 = iter2 " << "\033[0m" << std::endl;
    iter1 = my_tree.root;
    iter2 = my_tree.root->left;
    std::cout << "(*iter1).data.first = " << (*iter1).data.first << std::endl;
    std::cout << "(*iter2).data.first = " << (*iter2).data.first << std::endl;
    std::cout << "(*(iter1 = iter2)).data.first = " << (*(iter1 = iter2)).data.first << std::endl;

}


void    testTree_iterator() {
    std::cout << std::endl << "\033[35m" << "CHECK testTree_iterator " << "\033[0m" << std::endl;
    ft::RBTree<ft::pair<int, std::string> >    my_tree;

    my_tree.insert_node(ft::make_pair(80, "At "));
    my_tree.insert_node(ft::make_pair(40, "the "));
    my_tree.insert_node(ft::make_pair(150, "Mountains "));
    my_tree.insert_node(ft::make_pair(60, "of "));
    my_tree.insert_node(ft::make_pair(20, "Madness "));
    my_tree.insert_node(ft::make_pair(10, "... "));
    my_tree.insert_node(ft::make_pair(170, "..170.. "));
    my_tree.insert_node(ft::make_pair(140, "..140.. "));
    my_tree.insert_node(ft::make_pair(120, "..120.. "));
    my_tree.insert_node(ft::make_pair(0, "..0.. "));
    my_tree.insert_node(ft::make_pair(-10, "..-10.. "));
    my_tree.insert_node(ft::make_pair(130, "..130.. "));

    std::cout << "\033[34m" << "\t test iter1 = iter2 " << "\033[0m" << std::endl;
    ft::binTree_iterator< ft::Node<ft::pair<int, std::string> > > iter1;
    iter1 = my_tree.root;
    std::cout << "(*iter1).data.first = " << (*iter1).data.first << std::endl;
    ft::binTree_iterator< ft::Node<ft::pair<int, std::string> > > iter2;
    iter2 = my_tree.root->left;
    std::cout << "(*iter2).data.first = " << (*iter2).data.first << std::endl;
    std::cout << "(*(iter1 = iter2)).data.first = " << (*(iter1 = iter2)).data.first << std::endl;

    iter1 = my_tree.root;
    std::cout << "iter1 = my_tree.root = " << (*iter1).data.first << std::endl;
    std::cout << "++iter1: " << std::endl;
    std::cout << (*++iter1).data.first << std::endl;
    std::cout << (*++iter1).data.first << std::endl;
    std::cout << (*++iter1).data.first << std::endl;
    std::cout << (*++iter1).data.first << std::endl;
    std::cout << (*++iter1).data.first << std::endl;

    iter1 = my_tree.root;
    std::cout << "iter1 = my_tree.root = " << (*iter1).data.first << std::endl;
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

        std::cout << my_tree.root->data.first << " " << my_tree.root->data.second << std::endl;

        my_tree.insert_node(ft::make_pair(80, "At "));
        std::cout << my_tree.root->data.first << " " << my_tree.root->data.second << std::endl;

        my_tree.insert_node(ft::make_pair(40, "the "));
        std::cout << my_tree.root->data.first << " " << my_tree.root->data.second << " " << my_tree.root->color << std::endl;
        std::cout << my_tree.root->left->data.first << " " << my_tree.root->left->data.second << " " << my_tree.root->left->color << std::endl;
        std::cout << std::endl;
        my_tree.insert_node(ft::make_pair(150, "Mountains "));
        std::cout << my_tree.root->data.first << " " << my_tree.root->data.second << " " << my_tree.root->color << std::endl;
        std::cout << my_tree.root->left->data.first << " " << my_tree.root->left->data.second << " " << my_tree.root->left->color << std::endl;
        std::cout << my_tree.root->right->data.first << " " << my_tree.root->right->data.second << " " << my_tree.root->right->color << std::endl;
        std::cout << std::endl;
        my_tree.insert_node(ft::make_pair(60, "of "));
        std::cout << my_tree.root->data.first << " " << my_tree.root->data.second << " " << my_tree.root->color << std::endl;
        std::cout << my_tree.root->left->data.first << " " << my_tree.root->left->data.second << " " << my_tree.root->left->color << std::endl;
        std::cout << my_tree.root->right->data.first << " " << my_tree.root->right->data.second << " " << my_tree.root->right->color << std::endl;
        std::cout << my_tree.root->left->right->data.first << " " << my_tree.root->left->right->data.second << " " << my_tree.root->left->right->color << std::endl;
        std::cout << std::endl;
        my_tree.insert_node(ft::make_pair(20, "Madness "));
        std::cout << my_tree.root->data.first << " " << my_tree.root->data.second << " " << my_tree.root->color << std::endl;
        std::cout << my_tree.root->left->data.first << " " << my_tree.root->left->data.second << " " << my_tree.root->left->color << std::endl;
        std::cout << my_tree.root->right->data.first << " " << my_tree.root->right->data.second << " " << my_tree.root->right->color << std::endl;
        std::cout << my_tree.root->left->right->data.first << " " << my_tree.root->left->right->data.second << " " << my_tree.root->left->right->color << std::endl;
        std::cout << my_tree.root->left->left->data.first << " " << my_tree.root->left->left->data.second << " " << my_tree.root->left->left->color << std::endl;
        std::cout << std::endl;
        my_tree.insert_node(ft::make_pair(10, "... "));
        std::cout << my_tree.root->data.first << " " << my_tree.root->data.second << " " << my_tree.root->color << std::endl;
        std::cout << my_tree.root->left->data.first << " " << my_tree.root->left->data.second << " " << my_tree.root->left->color << std::endl;
        std::cout << my_tree.root->right->data.first << " " << my_tree.root->right->data.second << " " << my_tree.root->right->color << std::endl;
        std::cout << my_tree.root->left->right->data.first << " " << my_tree.root->left->right->data.second << " " << my_tree.root->left->right->color << std::endl;
        std::cout << my_tree.root->left->left->data.first << " " << my_tree.root->left->left->data.second << " " << my_tree.root->left->left->color << std::endl;
        std::cout << my_tree.root->left->left->left->data.first << " " << my_tree.root->left->left->left->data.second << " " << my_tree.root->left->left->left->color << std::endl;
        std::cout << std::endl;

        my_tree.insert_node(ft::make_pair(170, "..170.. "));
        my_tree.insert_node(ft::make_pair(140, "..140.. "));
        my_tree.insert_node(ft::make_pair(120, "..120.. "));
        std::cout << my_tree.root->data.first << " " << my_tree.root->data.second << " " << my_tree.root->color << std::endl;
        std::cout << my_tree.root->left->data.first << " " << my_tree.root->left->data.second << " " << my_tree.root->left->color << std::endl;
        std::cout << my_tree.root->left->right->data.first << " " << my_tree.root->left->right->data.second << " " << my_tree.root->left->right->color << std::endl;
        std::cout << my_tree.root->left->left->data.first << " " << my_tree.root->left->left->data.second << " " << my_tree.root->left->left->color << std::endl;
        std::cout << my_tree.root->left->left->left->data.first << " " << my_tree.root->left->left->left->data.second << " " << my_tree.root->left->left->left->color << std::endl;
        std::cout << my_tree.root->right->data.first << " " << my_tree.root->right->data.second << " " << my_tree.root->right->color << std::endl;
        std::cout << my_tree.root->right->left->data.first << " " << my_tree.root->right->left->data.second << " " << my_tree.root->right->left->color << std::endl;
        std::cout << my_tree.root->right->right->data.first << " " << my_tree.root->right->right->data.second << " " << my_tree.root->right->right->color << std::endl;
        std::cout << my_tree.root->right->left->left->data.first << " " << my_tree.root->right->left->left->data.second << " " << my_tree.root->right->left->left->color << std::endl;
        std::cout << std::endl;
    }
    {
        std::cout << "\033[34m" << "\t test with rotate (one line) " << "\033[0m" << std::endl;
        // test with rotate (one line)

        my_tree.insert_node(ft::make_pair(0, "..0.. "));
        std::cout << my_tree.root->data.first << " " << my_tree.root->data.second << " " << my_tree.root->color << std::endl;
        std::cout << my_tree.root->left->data.first << " " << my_tree.root->left->data.second << " " << my_tree.root->left->color << std::endl;
        std::cout << my_tree.root->left->right->data.first << " " << my_tree.root->left->right->data.second << " " << my_tree.root->left->right->color << std::endl;
        std::cout << my_tree.root->left->left->data.first << " " << my_tree.root->left->left->data.second << " " << my_tree.root->left->left->color << std::endl;
        std::cout << my_tree.root->left->left->left->data.first << " " << my_tree.root->left->left->left->data.second << " " << my_tree.root->left->left->left->color << std::endl;
        std::cout << my_tree.root->left->left->right->data.first << " " << my_tree.root->left->left->right->data.second << " " << my_tree.root->left->left->right->color << std::endl;
        std::cout << my_tree.root->right->data.first << " " << my_tree.root->right->data.second << " " << my_tree.root->right->color << std::endl;
        std::cout << my_tree.root->right->left->data.first << " " << my_tree.root->right->left->data.second << " " << my_tree.root->right->left->color << std::endl;
        std::cout << my_tree.root->right->right->data.first << " " << my_tree.root->right->right->data.second << " " << my_tree.root->right->right->color << std::endl;
        std::cout << my_tree.root->right->left->left->data.first << " " << my_tree.root->right->left->left->data.second << " " << my_tree.root->right->left->left->color << std::endl;
        std::cout << std::endl;

        my_tree.insert_node(ft::make_pair(-10, "..-10.. "));
        std::cout << my_tree.root->data.first << " " << my_tree.root->data.second << " " << my_tree.root->color << std::endl;
        std::cout << my_tree.root->left->data.first << " " << my_tree.root->left->data.second << " " << my_tree.root->left->color << std::endl;
        std::cout << my_tree.root->left->right->data.first << " " << my_tree.root->left->right->data.second << " " << my_tree.root->left->right->color << std::endl;
        std::cout << my_tree.root->left->left->data.first << " " << my_tree.root->left->left->data.second << " " << my_tree.root->left->left->color << std::endl;
        std::cout << my_tree.root->left->left->left->data.first << " " << my_tree.root->left->left->left->data.second << " " << my_tree.root->left->left->left->color << std::endl;
        std::cout << my_tree.root->left->left->left->left->data.first << " " << my_tree.root->left->left->left->left->data.second << " " << my_tree.root->left->left->left->left->color << std::endl;
        std::cout << my_tree.root->left->left->right->data.first << " " << my_tree.root->left->left->right->data.second << " " << my_tree.root->left->left->right->color << std::endl;
        std::cout << my_tree.root->right->data.first << " " << my_tree.root->right->data.second << " " << my_tree.root->right->color << std::endl;
        std::cout << my_tree.root->right->left->data.first << " " << my_tree.root->right->left->data.second << " " << my_tree.root->right->left->color << std::endl;
        std::cout << my_tree.root->right->right->data.first << " " << my_tree.root->right->right->data.second << " " << my_tree.root->right->right->color << std::endl;
        std::cout << my_tree.root->right->left->left->data.first << " " << my_tree.root->right->left->left->data.second << " " << my_tree.root->right->left->left->color << std::endl;
        std::cout << std::endl;
    }
    {
        std::cout << "\033[34m" << "\t test with rotate (angle) " << "\033[0m" << std::endl;
        // test with rotate (angle)

        my_tree.insert_node(ft::make_pair(130, "..130.. "));
        std::cout << my_tree.root->data.first << " " << my_tree.root->data.second << " " << my_tree.root->color << std::endl;
        std::cout << my_tree.root->left->data.first << " " << my_tree.root->left->data.second << " " << my_tree.root->left->color << std::endl;
        std::cout << my_tree.root->left->left->data.first << " " << my_tree.root->left->left->data.second << " " << my_tree.root->left->left->color << std::endl;
        std::cout << my_tree.root->left->right->data.first << " " << my_tree.root->left->right->data.second << " " << my_tree.root->left->right->color << std::endl;
        std::cout << my_tree.root->left->left->left->data.first << " " << my_tree.root->left->left->left->data.second << " " << my_tree.root->left->left->left->color << std::endl;
        std::cout << my_tree.root->left->left->right->data.first << " " << my_tree.root->left->left->right->data.second << " " << my_tree.root->left->left->right->color << std::endl;
        std::cout << my_tree.root->left->left->left->left->data.first << " " << my_tree.root->left->left->left->left->data.second << " " << my_tree.root->left->left->left->left->color << std::endl;
        std::cout << my_tree.root->right->data.first << " " << my_tree.root->right->data.second << " " << my_tree.root->right->color << std::endl;
        std::cout << my_tree.root->right->right->data.first << " " << my_tree.root->right->right->data.second << " " << my_tree.root->right->right->color << std::endl;
        std::cout << my_tree.root->right->left->data.first << " " << my_tree.root->right->left->data.second << " " << my_tree.root->right->left->color << std::endl;
        std::cout << my_tree.root->right->left->left->data.first << " " << my_tree.root->right->left->left->data.second << " " << my_tree.root->right->left->left->color << std::endl;
        std::cout << my_tree.root->right->left->right->data.first << " " << my_tree.root->right->left->right->data.second << " " << my_tree.root->right->left->right->color << std::endl;
        std::cout << std::endl;

    }
}
