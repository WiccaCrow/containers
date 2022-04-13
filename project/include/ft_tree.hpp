#ifndef FT_TREE_HPP
# define FT_TREE_HPP

#include <memory>
#include <ft_node.hpp>

namespace ft {

template< class T, class Allocator = std::allocator<Node<T> > >
class Tree {
    public:
    typedef Allocator                   allocator_type;
    typedef enum { lineLeft, lineRight, Not_lineLeft, Not_lineRight } isLineXPG; // Are the child, parent, grandparent on the same line?

        #define NIL &empty_node
        Node<T>     empty_node;
        Node<T> *   root;
        isLineXPG   isLine;
        Tree() : 
                empty_node(),
                root(NIL) {
                     std::cout << "constructor empy\n";
        }

        Tree(T data) : 
                empty_node() {
                     std::cout << "constructor data\n";
            root = create_node(data);
            root->color = BLACK;
            root->left = NIL;
            root->right = NIL;
        }

		Node<T> *create_node(T data, allocator_type alloc = Allocator() ) {
			Node<T> *new_node = alloc.allocate(1);
			alloc.construct(new_node, data); // data, RED, NULL, NULL, NULL
			return new_node;
		}

        void    insert_node(const T& data) {
            Node<T> *insert_place = find_insert_place(data);
            if (root == NIL) {
                std::cout << "insert_node NIL\n";
                root->data = data;
                root->left = root->right = root->parent = NIL;
                return ;
            } else if (*insert_place == data) {
                insert_place->data = data;
                return ;
            } else {
                Node<T> *new_node = create_node(data);
                new_node->color = RED;
                new_node->parent = insert_place;
                new_node->left = new_node->right = NIL;
                if (data < *insert_place) {
                    insert_place->left = new_node;
                } else if (*insert_place < data) {
                    // if (data.first == 6) {
                    //     std::cout << "test\n";
                    // }
                    insert_place->right = new_node;
                }
                check_balance_1(new_node);
            }
        }

        void    check_balance_1(Node<T> *check_node) {
            Node<T> *uncle;
            Node<T> *parent;
            while (check_node != root) {
                // std::cout << "test 0 \n";
                parent = check_node->parent;
                if (parent->color == BLACK) {
                    return ;
                }
                uncle = (parent->parent->left == parent ? parent->parent->right : parent->parent->left);
// if (check_node->data.first == 6) {
//     std::cout << "test 1: parent: " << parent->data.first << " uncle color: " << uncle->data.first << "\n";
    
// }
                check_node = check_balance_2(check_node, uncle, parent);
        // std::cout << "test 1: end \n";
            }
                // std::cout << "test 0: end \n";

        }

        Node<T> *    check_balance_2(Node<T> *new_node, Node<T> *uncle, Node<T> *parent) {
            // 1. change color
            if (uncle->color == RED) {
// if (new_node->data.first == 6) {
//     std::cout << "test 2.1\n";
// }
                uncle->color = parent->color = BLACK;
// if (new_node->data.first == 6) {
//     std::cout << "test 2.2\n";
// }
                parent->parent->color = (parent->parent == root ? BLACK : RED);
// if (new_node->data.first == 6) {
//     std::cout << "test 2.3\n";
//     if (parent->parent == root)
//     {
//         std::cout << "test 2.4\n";
//     } else {
//         std::cout << "test 2.5\n";
//     }
// }
//         std::cout << "test 2.6\n";

                return (parent->parent);
            }
            std::cout << "rotate\n";
            checkLineXPG(new_node, parent);
                    if (isLine == lineLeft) {
                        parent->parent->left = parent->right;//+
                        parent->parent->left->parent = parent->parent;//+
                        parent->right = parent->parent;//+
                        parent->parent = parent->parent->parent;//+
                        parent->right->parent = parent;//+
                        if (parent->parent != NIL && parent->parent->right == parent->right) {
                            parent->parent->right = parent;
                        } else if (parent->parent != NIL) {
                            parent->parent->left = parent;
                        }//+
                        parent->right->color = RED;
                        parent->color = BLACK;
                    } else if (isLine == lineRight) {
                        parent->parent->right = parent->left;//+
                        parent->parent->right->parent = parent->parent;//+
                        parent->left = parent->parent;//+
                        parent->parent = parent->parent->parent;//+
                        parent->left->parent = parent;//+
                        if (parent->parent != NIL && parent->parent->left == parent->left) {
                            parent->parent->left = parent;
                        } else if (parent->parent != NIL) {
                            parent->parent->right = parent;
                        }//+
                        parent->left->color = RED;
                        parent->color = BLACK;
                    }

            return (root);
        }

        void    checkLineXPG(Node<T> *new_node, Node<T> *parent) {
            if (new_node->parent->left == new_node &&
                (new_node->parent->parent == NIL ||
                 new_node->parent->parent->left == new_node->parent)) {
                    isLine = lineLeft;
            } else if (
                new_node->parent->right == new_node &&
                (new_node->parent->parent == NIL ||
                 new_node->parent->parent->right == new_node->parent)) {
                     isLine = lineRight;
            }
        }

        Node<T> *    find_insert_place(const T& data) {
            Node<T> *node = root;
            while (node != NIL) {
                if (data < *node && node->left != NIL) {
                    node = node->left;
                } else if ( *node < data && node->right != NIL) {
                    node = node->right;
                } else {
                    break ;
                }
            }
            return (node);
        }
};

} // namespace ft

#endif