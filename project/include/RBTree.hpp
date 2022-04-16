#ifndef RBTREE_HPP
# define RBTREE_HPP

#include <memory>
#include <node.hpp>
#include <utility.hpp>
// #include <iterator_binTree_normal.hpp>

namespace ft {

template< class T, class Allocator = std::allocator<Node<T> > >
class RBTree {
    public:
    typedef enum { lineLeft, lineRight, angleLeft, angleRight } isLineXPG; // Are the child, parent, grandparent on the same line?
    typedef typename Allocator::template
        rebind<Node<T> >::other allocator_type;

    // typedef binTree_iterator< T >         iterator;

        #define NIL &empty_node
        Node<T>         empty_node;
        Node<T> *       root;
        allocator_type  _alloc;
        isLineXPG       isLine;
        RBTree() : 
                empty_node(),
                root(NIL),
                _alloc(Allocator()) {
                empty_node._is_empty = true;
                     std::cout << "constructor empy\n";
        }

        RBTree(T data) : 
                empty_node(),
                _alloc(Allocator()) {
                empty_node._is_empty = true;
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
                root = create_node(data);
                root->color = BLACK;
                root->left = root->right = root->parent = NIL;
                return ;
            } else if (*insert_place == data) {
                Node<T> *new_node = create_node(data);
                new_node->color = insert_place->color;
                new_node->left = insert_place->left;
                new_node->right = insert_place->right;
                new_node->parent = insert_place->parent;
                if (new_node->left != NIL) {
                    new_node->left->parent = new_node;
                }
                if (new_node->right != NIL) {
                    new_node->right->parent = new_node;
                }
                if (new_node->parent->left == insert_place) {
                    new_node->parent->left = new_node;
                } else if (new_node->parent->right == insert_place) {
                    new_node->parent->right = new_node;
                }
                _alloc.destroy(insert_place);
			    _alloc.deallocate(insert_place, 1);
                return ;
            } else {
                Node<T> *new_node = create_node(data);
                new_node->color = RED;
                new_node->parent = insert_place;
                new_node->left = new_node->right = NIL;
                if (data < *insert_place) {
                    insert_place->left = new_node;
                } else if (*insert_place < data) {
                    insert_place->right = new_node;
                }
                check_balance_1(new_node);
            }
        }

        void    check_balance_1(Node<T> *check_node) {
            Node<T> *uncle;
            Node<T> *parent;
            while (check_node != root) {
                parent = check_node->parent;
                if (parent->color == BLACK) {
                    return ;
                }
                uncle = (parent->parent->left == parent ? parent->parent->right : parent->parent->left);
                check_node = check_balance_2(check_node, uncle, parent);
            }
        }

        Node<T> *    check_balance_2(Node<T> *new_node, Node<T> *uncle, Node<T> *parent) {
            if (uncle->color == RED) {
                uncle->color = parent->color = BLACK;
                parent->parent->color = (parent->parent == root ? BLACK : RED);
                return (parent->parent);
            }
            checkLineXPG(new_node, parent);
            rotate_lineXPG_straight(parent);
            rotate_lineXPG_angle(new_node, parent);
            return (root);
        }

        void    rotate_lineXPG_angle(Node<T> *new_node, Node<T> *parent) {
            if (isLine != angleLeft && isLine != angleRight) {
                return ;
            }
            if (isLine == angleLeft) {
                new_node->parent = parent->parent;
                parent->parent->left = new_node;
                parent->parent = new_node;
                parent->right = NIL;
                new_node->left = parent;
            } else if (isLine == angleRight) {
                new_node->parent = parent->parent;
                parent->parent->right = new_node;
                parent->parent = new_node;
                parent->left = NIL;
                new_node->right = parent;
            }
            checkLineXPG(parent, new_node);
            rotate_lineXPG_straight(new_node);
        }

        void    rotate_lineXPG_straight(Node<T> *parent) {
            if (isLine == lineLeft) {
                parent->parent->left = parent->right;
                if (parent->parent->left != NIL) {
                    parent->parent->left->parent = parent->parent;
                }
                parent->right = parent->parent;
                parent->parent = parent->parent->parent;
                parent->right->parent = parent;
                if (parent->parent != NIL && parent->parent->right == parent->right) {
                    parent->parent->right = parent;
                } else if (parent->parent != NIL) {
                    parent->parent->left = parent;
                }
                parent->right->color = RED;
                parent->color = BLACK;
            } else if (isLine == lineRight) {
                parent->parent->right = parent->left;
                if (parent->parent->right != NIL) {
                    parent->parent->right->parent = parent->parent;
                }
                parent->left = parent->parent;
                parent->parent = parent->parent->parent;
                parent->left->parent = parent;
                if (parent->parent != NIL && parent->parent->left == parent->left) {
                    parent->parent->left = parent;
                } else if (parent->parent != NIL) {
                    parent->parent->right = parent;
                }
                parent->left->color = RED;
                parent->color = BLACK;
            }
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
            } else if (
                new_node->parent->right == new_node &&
                 new_node->parent->parent->left == new_node->parent) {
                    isLine = angleLeft;
            } else if (
                new_node->parent->left == new_node &&
                 new_node->parent->parent->right == new_node->parent) {
                    isLine = angleRight;
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

        // bool is_empty(Node<T> *node) {
        //     return (node == NIL);
        // }
};

} // namespace ft

#endif