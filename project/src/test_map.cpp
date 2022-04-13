#include <iostream>
#include <ft_utility.hpp>
// #include <ft_vector.hpp>
// #include <ft_map.hpp>
#include <ft_tree.hpp>

void    testTree();

// At the Mountains of Madness
int main() {
    testTree();
    return (0);
}

void    testTree() {
    // std::cout << std::boolalpha;
    ft::Tree<ft::pair<int, std::string> >    my_tree(ft::make_pair(8, "Hello"));
    {
        // test without rotate
        std::cout << my_tree.root->data.first << " " << my_tree.root->data.second << std::endl;

        my_tree.insert_node(ft::make_pair(8, "At "));
        std::cout << my_tree.root->data.first << " " << my_tree.root->data.second << std::endl;

        my_tree.insert_node(ft::make_pair(4, "the "));
        std::cout << my_tree.root->data.first << " " << my_tree.root->data.second << " " << my_tree.root->color << std::endl;
        std::cout << my_tree.root->left->data.first << " " << my_tree.root->left->data.second << " " << my_tree.root->left->color << std::endl;
        std::cout << std::endl;
        my_tree.insert_node(ft::make_pair(15, "Mountains "));
        std::cout << my_tree.root->data.first << " " << my_tree.root->data.second << " " << my_tree.root->color << std::endl;
        std::cout << my_tree.root->left->data.first << " " << my_tree.root->left->data.second << " " << my_tree.root->left->color << std::endl;
        std::cout << my_tree.root->right->data.first << " " << my_tree.root->right->data.second << " " << my_tree.root->right->color << std::endl;
        std::cout << std::endl;
        my_tree.insert_node(ft::make_pair(6, "of "));
        std::cout << my_tree.root->data.first << " " << my_tree.root->data.second << " " << my_tree.root->color << std::endl;
        std::cout << my_tree.root->left->data.first << " " << my_tree.root->left->data.second << " " << my_tree.root->left->color << std::endl;
        std::cout << my_tree.root->right->data.first << " " << my_tree.root->right->data.second << " " << my_tree.root->right->color << std::endl;
        std::cout << my_tree.root->left->right->data.first << " " << my_tree.root->left->right->data.second << " " << my_tree.root->left->right->color << std::endl;
        std::cout << std::endl;
        my_tree.insert_node(ft::make_pair(2, "Madness "));
        std::cout << my_tree.root->data.first << " " << my_tree.root->data.second << " " << my_tree.root->color << std::endl;
        std::cout << my_tree.root->left->data.first << " " << my_tree.root->left->data.second << " " << my_tree.root->left->color << std::endl;
        std::cout << my_tree.root->right->data.first << " " << my_tree.root->right->data.second << " " << my_tree.root->right->color << std::endl;
        std::cout << my_tree.root->left->right->data.first << " " << my_tree.root->left->right->data.second << " " << my_tree.root->left->right->color << std::endl;
        std::cout << my_tree.root->left->left->data.first << " " << my_tree.root->left->left->data.second << " " << my_tree.root->left->left->color << std::endl;
        std::cout << std::endl;
        my_tree.insert_node(ft::make_pair(1, "... "));
        // my_tree.insert_node(ft::make_pair(0, "... "));
        std::cout << my_tree.root->data.first << " " << my_tree.root->data.second << " " << my_tree.root->color << std::endl;
        std::cout << my_tree.root->left->data.first << " " << my_tree.root->left->data.second << " " << my_tree.root->left->color << std::endl;
        std::cout << my_tree.root->right->data.first << " " << my_tree.root->right->data.second << " " << my_tree.root->right->color << std::endl;
        std::cout << my_tree.root->left->right->data.first << " " << my_tree.root->left->right->data.second << " " << my_tree.root->left->right->color << std::endl;
        std::cout << my_tree.root->left->left->data.first << " " << my_tree.root->left->left->data.second << " " << my_tree.root->left->left->color << std::endl;
        std::cout << my_tree.root->left->left->left->data.first << " " << my_tree.root->left->left->left->data.second << " " << my_tree.root->left->left->left->color << std::endl;
        std::cout << std::endl;

        my_tree.insert_node(ft::make_pair(17, "..17.. "));
        my_tree.insert_node(ft::make_pair(14, "..14.. "));
        my_tree.insert_node(ft::make_pair(12, "..12.. "));
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
        // my_tree.insert_node(ft::make_pair(0, "..0.. "));
        // std::cout << my_tree.root->data.first << " " << my_tree.root->data.second << " " << my_tree.root->color << std::endl;
        // std::cout << my_tree.root->left->data.first << " " << my_tree.root->left->data.second << " " << my_tree.root->left->color << std::endl;
        // std::cout << my_tree.root->left->right->data.first << " " << my_tree.root->left->right->data.second << " " << my_tree.root->left->right->color << std::endl;
        // std::cout << my_tree.root->left->left->data.first << " " << my_tree.root->left->left->data.second << " " << my_tree.root->left->left->color << std::endl;
        // std::cout << my_tree.root->left->left->left->data.first << " " << my_tree.root->left->left->left->data.second << " " << my_tree.root->left->left->left->color << std::endl;
        // std::cout << my_tree.root->left->left->right->data.first << " " << my_tree.root->left->left->right->data.second << " " << my_tree.root->left->left->right->color << std::endl;
        // std::cout << my_tree.root->right->data.first << " " << my_tree.root->right->data.second << " " << my_tree.root->right->color << std::endl;
        // std::cout << my_tree.root->right->left->data.first << " " << my_tree.root->right->left->data.second << " " << my_tree.root->right->left->color << std::endl;
        // std::cout << my_tree.root->right->right->data.first << " " << my_tree.root->right->right->data.second << " " << my_tree.root->right->right->color << std::endl;
        // std::cout << my_tree.root->right->left->left->data.first << " " << my_tree.root->right->left->left->data.second << " " << my_tree.root->right->left->left->color << std::endl;
        // std::cout << std::endl;

        // my_tree.insert_node(ft::make_pair(-1, "..-1.. "));
        // std::cout << my_tree.root->data.first << " " << my_tree.root->data.second << " " << my_tree.root->color << std::endl;
        // std::cout << my_tree.root->left->data.first << " " << my_tree.root->left->data.second << " " << my_tree.root->left->color << std::endl;
        // std::cout << my_tree.root->left->right->data.first << " " << my_tree.root->left->right->data.second << " " << my_tree.root->left->right->color << std::endl;
        // std::cout << my_tree.root->left->left->data.first << " " << my_tree.root->left->left->data.second << " " << my_tree.root->left->left->color << std::endl;
        // std::cout << my_tree.root->left->left->left->data.first << " " << my_tree.root->left->left->left->data.second << " " << my_tree.root->left->left->left->color << std::endl;
        // std::cout << my_tree.root->left->left->left->left->data.first << " " << my_tree.root->left->left->left->left->data.second << " " << my_tree.root->left->left->left->left->color << std::endl;
        // std::cout << my_tree.root->left->left->right->data.first << " " << my_tree.root->left->left->right->data.second << " " << my_tree.root->left->left->right->color << std::endl;
        // std::cout << my_tree.root->right->data.first << " " << my_tree.root->right->data.second << " " << my_tree.root->right->color << std::endl;
        // std::cout << my_tree.root->right->left->data.first << " " << my_tree.root->right->left->data.second << " " << my_tree.root->right->left->color << std::endl;
        // std::cout << my_tree.root->right->right->data.first << " " << my_tree.root->right->right->data.second << " " << my_tree.root->right->right->color << std::endl;
        // std::cout << my_tree.root->right->left->left->data.first << " " << my_tree.root->right->left->left->data.second << " " << my_tree.root->right->left->left->color << std::endl;
        // std::cout << std::endl;
    }
    {
        // test with rotate (angle)
        my_tree.insert_node(ft::make_pair(13, "..13.. "));
        std::cout << my_tree.root->data.first << " " << my_tree.root->data.second << " " << my_tree.root->color << std::endl;
        std::cout << my_tree.root->left->data.first << " " << my_tree.root->left->data.second << " " << my_tree.root->left->color << std::endl;
        std::cout << my_tree.root->left->right->data.first << " " << my_tree.root->left->right->data.second << " " << my_tree.root->left->right->color << std::endl;
        std::cout << my_tree.root->left->left->data.first << " " << my_tree.root->left->left->data.second << " " << my_tree.root->left->left->color << std::endl;
        std::cout << my_tree.root->left->left->left->data.first << " " << my_tree.root->left->left->left->data.second << " " << my_tree.root->left->left->left->color << std::endl;
        std::cout << my_tree.root->right->data.first << " " << my_tree.root->right->data.second << " " << my_tree.root->right->color << std::endl;
        std::cout << my_tree.root->right->left->data.first << " " << my_tree.root->right->left->data.second << " " << my_tree.root->right->left->color << std::endl;
        std::cout << my_tree.root->right->right->data.first << " " << my_tree.root->right->right->data.second << " " << my_tree.root->right->right->color << std::endl;
        std::cout << my_tree.root->right->left->left->data.first << " " << my_tree.root->right->left->left->data.second << " " << my_tree.root->right->left->left->color << std::endl;
        std::cout << my_tree.root->right->left->right->data.first << " " << my_tree.root->right->left->right->data.second << " " << my_tree.root->right->left->right->color << std::endl;
        std::cout << std::endl;

        // my_tree.insert_node(ft::make_pair(-1, "..-1.. "));
        // std::cout << my_tree.root->data.first << " " << my_tree.root->data.second << " " << my_tree.root->color << std::endl;
        // std::cout << my_tree.root->left->data.first << " " << my_tree.root->left->data.second << " " << my_tree.root->left->color << std::endl;
        // std::cout << my_tree.root->left->right->data.first << " " << my_tree.root->left->right->data.second << " " << my_tree.root->left->right->color << std::endl;
        // std::cout << my_tree.root->left->left->data.first << " " << my_tree.root->left->left->data.second << " " << my_tree.root->left->left->color << std::endl;
        // std::cout << my_tree.root->left->left->left->data.first << " " << my_tree.root->left->left->left->data.second << " " << my_tree.root->left->left->left->color << std::endl;
        // std::cout << my_tree.root->left->left->left->left->data.first << " " << my_tree.root->left->left->left->left->data.second << " " << my_tree.root->left->left->left->left->color << std::endl;
        // std::cout << my_tree.root->left->left->right->data.first << " " << my_tree.root->left->left->right->data.second << " " << my_tree.root->left->left->right->color << std::endl;
        // std::cout << my_tree.root->right->data.first << " " << my_tree.root->right->data.second << " " << my_tree.root->right->color << std::endl;
        // std::cout << my_tree.root->right->left->data.first << " " << my_tree.root->right->left->data.second << " " << my_tree.root->right->left->color << std::endl;
        // std::cout << my_tree.root->right->right->data.first << " " << my_tree.root->right->right->data.second << " " << my_tree.root->right->right->color << std::endl;
        // std::cout << my_tree.root->right->left->left->data.first << " " << my_tree.root->right->left->left->data.second << " " << my_tree.root->right->left->left->color << std::endl;
        // std::cout << std::endl;
    }
}
