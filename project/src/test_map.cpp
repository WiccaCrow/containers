#include <iostream>
#include <utility.hpp>
// #include <ft_vector.hpp>
#include <RBTree.hpp>
#include <iterator_binTree_normal.hpp>
#include <map.hpp>

void    testTree_insert();
void    testTree_iterator();


// At the Mountains of Madness
int main() {
    // testTree_insert();
    testTree_iterator();
    return (0);
}

void    testTree_iterator() {
    // ft::map<int, std::string>                  my_tree;
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
    ft::binTree_iterator< ft::Node<ft::pair<int, std::string> > > iter;
    iter = my_tree.root;
    std::cout << (*iter).data.first << std::endl;

    // ft::RBTree<ft::pair<int, std::string> >::iterator iter = my_tree.root();
}

void    testTree_insert() {
    // std::cout << std::boolalpha;
    ft::RBTree<ft::pair<int, std::string> >    my_tree(ft::make_pair(80, "Hello"));
    {
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
