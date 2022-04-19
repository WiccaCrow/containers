#ifndef RBTREE_HPP
# define RBTREE_HPP

#include <memory>
#include <node.hpp>
#include <utility.hpp>

namespace ft {

template <
    typename T,
    typename Tree >
class binTree_iterator;

template <
    typename Iter >
class binTree_iterator_reverse;

template< 
    class T_node, 
    class Allocator = std::allocator<Node<T_node> > 
        >
class RBTree {
    public:

    // Member types
    typedef enum { lineLeft, lineRight, angleLeft, angleRight } isLineXPG; // Are the child, parent, grandparent on the same line?
    typedef std::size_t                                     size_type;
    typedef typename Allocator::template
            rebind<Node<T_node> >::other                         allocator_type;
    typedef binTree_iterator<Node<T_node>, RBTree<T_node> >           iterator;
    typedef binTree_iterator<const Node<T_node>, RBTree<T_node> >     const_iterator;
    typedef binTree_iterator_reverse<iterator >             reverse_iterator;
    typedef binTree_iterator_reverse<const_iterator >       const_reverse_iterator;

    protected:

    // Members

    Node<T_node> *       _root;
    Node<T_node> *       _begin;
    #define NIL &_empty_node
    Node<T_node>         _empty_node;
    Node<T_node>         _end_node;
    size_type       _size;
    allocator_type  _alloc;
    isLineXPG       _isLine;

    // Member functions

    iterator        find_element( const T_node& key );
    const_iterator  find_element( const T_node& key ) const;

    Node<T_node> *   find_insert_place(const T_node& data);
    Node<T_node> *   create_node(T_node data);
    void        check_balance_1(Node<T_node> *check_node);
    Node<T_node> *   check_balance_2(Node<T_node> *new_node, Node<T_node> *uncle, Node<T_node> *parent);
    void        checkLineXPG(Node<T_node> *new_node, Node<T_node> *parent);
    void        rotate_lineXPG_straight(Node<T_node> *parent);
    void        rotate_lineXPG_angle(Node<T_node> *new_node, Node<T_node> *parent);

    public:
    //////////////////////
    // Member functions //
    //////////////////////

    RBTree(allocator_type alloc = Allocator());
    RBTree(T_node data, allocator_type alloc = Allocator());
    allocator_type get_allocator() const;

    // Element access
    // Iterators

    iterator                root();
    iterator                begin();
    const_iterator          begin() const;
    iterator                end();
    const_iterator          end() const;
    reverse_iterator        rbegin();
    const_reverse_iterator  rbegin() const;
    reverse_iterator        rend();
    const_reverse_iterator  rend() const;

    // Capacity

    bool        empty() const;
    size_type   size() const;
    size_type   max_size() const;

    // Modifiers

    pair<iterator, bool>    insert(const T_node& value);
    iterator                insert( iterator hint, const T_node& value );

    // Lookup in private find_element


    // Observers

};

// public:

    //////////////////////
    // Member functions //
    //////////////////////

template< 
    class T_node, 
    class Allocator >
RBTree<T_node, Allocator>::
    RBTree(allocator_type alloc) : 
                _empty_node(),
                _root(NULL),
                _begin(_root),
                _end_node(),
                _size(0),
                _alloc(alloc) {
    _empty_node._is_empty = true;
    _end_node._is_empty = true;
    _end_node.right = _end_node.left = &_end_node;
}

template< 
    class T_node, 
    class Allocator >
RBTree<T_node, Allocator>::
    RBTree(T_node data, allocator_type alloc) : 
                _empty_node(),
                _end_node(),
                _size(1),
                _alloc(alloc) {
    _empty_node._is_empty = true;
    _end_node._is_empty = true;
    _root = create_node(data);
    _root->color = BLACK;
    _root->left = NIL;
    _root->right = &_end_node;
    _end_node.parent = _root;
    _end_node.right = _end_node.left = &_end_node;
    _begin = _root;
}

template< 
    class T_node, 
    class Allocator >
typename RBTree<T_node, Allocator>::allocator_type 
    RBTree<T_node, Allocator>::
    get_allocator() const {
        return (_alloc);
}

    // Element access

    // Iterators

template< 
    class T_node, 
    class Allocator >
typename RBTree<T_node, Allocator>::iterator                
RBTree<T_node, Allocator>::
    root() {
    return (iterator(_root));
}

template< 
    class T_node, 
    class Allocator >
typename RBTree<T_node, Allocator>::iterator                
RBTree<T_node, Allocator>::
    begin() {
    return (iterator(_begin));
}

template< 
    class T_node, 
    class Allocator >
typename RBTree<T_node, Allocator>::const_iterator                
RBTree<T_node, Allocator>::
    begin() const {
        return (const_iterator(_begin));
}

template< 
    class T_node, 
    class Allocator >
typename RBTree<T_node, Allocator>::iterator                
RBTree<T_node, Allocator>::
    end() {
    if (_root == NULL) {
        return iterator(_root);
    }
    return (iterator(&_end_node));
}

template< 
    class T_node, 
    class Allocator >
typename RBTree<T_node, Allocator>::const_iterator                
RBTree<T_node, Allocator>::
    end() const {
    if (_root == NULL) {
        return const_iterator(_root);
    }
    return (const_iterator(&_end_node));
}

template< 
    class T_node, 
    class Allocator >
typename RBTree<T_node, Allocator>::reverse_iterator 
RBTree<T_node, Allocator>::
    rbegin() {
    return (reverse_iterator(end()));
}

template< 
    class T_node, 
    class Allocator >
typename RBTree<T_node, Allocator>::const_reverse_iterator 
RBTree<T_node, Allocator>::
    rbegin() const {
    return (const_reverse_iterator(end()));
}

template< 
    class T_node, 
    class Allocator >
typename RBTree<T_node, Allocator>::reverse_iterator 
RBTree<T_node, Allocator>::
    rend() {
    return (reverse_iterator(begin()));
}

template< 
    class T_node, 
    class Allocator >
typename RBTree<T_node, Allocator>::const_reverse_iterator 
RBTree<T_node, Allocator>::
    rend() const {
    return (const_reverse_iterator(begin()));
}

    // Capacity

template< 
    class T_node, 
    class Allocator >
bool
RBTree<T_node, Allocator>::
    empty() const {
    return (_root == NULL);
}

template< 
    class T_node, 
    class Allocator >
typename RBTree<T_node, Allocator>::size_type   
RBTree<T_node, Allocator>::
    size() const {
    return (_size);
}

template< 
    class T_node, 
    class Allocator >
typename RBTree<T_node, Allocator>::size_type   
RBTree<T_node, Allocator>::
max_size() const {
    return (_alloc.max_size());
}

    // Modifiers

template< 
    class T_node, 
    class Allocator >
pair<typename RBTree<T_node, Allocator>::iterator, bool>
RBTree<T_node, Allocator>::
    insert(const T_node& value) {
    if (_root == NULL) {
        _root = create_node(value);
        if (_root == NIL) {
            _root = NULL;
            return pair<iterator, bool>(iterator(_root), false);
        }
        _size = 1;
        _root->color = BLACK;
        _root->left = _root->parent = NIL;
        _root->right = &_end_node;
        _end_node.parent = _root;
        _begin = _root;
        return pair<iterator, bool>(iterator(_root), true);
    }
    Node<T_node> *insert_place = find_insert_place(value);
    if (*insert_place == value) {
        Node<T_node> *new_node = create_node(value);
        if (new_node == NIL) {
            return pair<iterator, bool>(iterator(insert_place), false);
        }
        new_node->color = insert_place->color;
        new_node->left = insert_place->left;
        new_node->right = insert_place->right;
        new_node->parent = insert_place->parent;
        if (new_node->left != NIL) {
            new_node->left->parent = new_node;
        }
        if (new_node->right != NIL && new_node->right != &_end_node) {
            new_node->right->parent = new_node;
        }
        if (new_node->parent != NULL && new_node->parent != NIL && new_node->parent->left == insert_place) {
            new_node->parent->left = new_node;
        } else if (new_node->parent != NULL && new_node->parent != NIL && new_node->parent->right == insert_place) {
            new_node->parent->right = new_node;
        }
        if (_root == insert_place) {
            _root = new_node;
        }
        _alloc.destroy(insert_place);
        _alloc.deallocate(insert_place, 1);
        return pair<iterator, bool>(iterator(new_node), true);
    } else {
        Node<T_node> *new_node = create_node(value);
        if (new_node == NIL) {
            return pair<iterator, bool>(iterator(insert_place), false);
        }
        ++_size;
        if (new_node->data < _begin->data) {
            _begin = new_node;
        }
        new_node->color = RED;
        new_node->parent = insert_place;
        new_node->left = new_node->right = NIL;
        if (value < *insert_place) {
            insert_place->left = new_node;
        } else if (*insert_place < value) {
            if (insert_place->right == &_end_node) {
                new_node->right = &_end_node;
                _end_node.parent = new_node;
            }
            insert_place->right = new_node;
        }
        check_balance_1(new_node);
        return pair<iterator, bool>(iterator(new_node), true);
    }
}

template< 
    class T_node, 
    class Allocator >
typename RBTree<T_node, Allocator>::iterator                
RBTree<T_node, Allocator>::
insert( iterator hint, const T_node& value ) {
    return insert(value).first;
}

    // Lookup

template< 
    class T_node, 
    class Allocator >
typename RBTree<T_node, Allocator>::iterator                
RBTree<T_node, Allocator>::
    find_element( const T_node& key ) {
    Node<T_node> *node = _root;
    while (node != NIL && node != &_end_node) {
        if (key < *node) {
            node = node->left;
        } else if (*node < key) {
            node = node->right;
        } else {
            return (iterator(node));
        }
    }
    return (end());
}

template< 
    class T_node, 
    class Allocator >
typename RBTree<T_node, Allocator>::const_iterator                
RBTree<T_node, Allocator>::    
    find_element( const T_node& key ) const {
    Node<T_node> *node = _root;
    while (node != NIL && node != &_end_node) {
        if (key < *node) {
            node = node->left;
        } else if (*node < key) {
            node = node->right;
        } else {
            return (const_iterator(node));
        }
    }
    return (end());
}

    // Observers

// private

template< 
    class T_node, 
    class Allocator >
Node<T_node> *
RBTree<T_node, Allocator>::
    find_insert_place(const T_node& data) {
    Node<T_node> *node = _root;
    while (node != NIL && node != &_end_node) {
        if (data < *node && node->left != NIL) {
            node = node->left;
        } else if ( *node < data && node->right != NIL && node->right != &_end_node) {
            node = node->right;
        } else {
            break ;
        }
    }
    return (node);
}

template< 
    class T_node,
    class Allocator >
Node<T_node> *
RBTree<T_node, Allocator>::create_node(T_node data) {
    try {
        Node<T_node> *new_node = _alloc.allocate(1);
        _alloc.construct(new_node, data); // data, RED, NULL, NULL, NULL
        return new_node;
    } catch (const std::bad_alloc& e) {
        return NIL;
    }
}

template< 
    class T_node, 
    class Allocator >
void
RBTree<T_node, Allocator>::
    check_balance_1(Node<T_node> *check_node) {
    Node<T_node> *uncle;
    Node<T_node> *parent;
    while (check_node != _root) {
        parent = check_node->parent;
        if (parent->color == BLACK) {
            return ;
        }
        uncle = (parent->parent->left == parent ? parent->parent->right : parent->parent->left);
        check_node = check_balance_2(check_node, uncle, parent);
    }
}

template< 
    class T_node, 
    class Allocator >
Node<T_node> *
RBTree<T_node, Allocator>::
    check_balance_2(Node<T_node> *new_node, Node<T_node> *uncle, Node<T_node> *parent) {
    if (uncle->color == RED) {
        uncle->color = parent->color = BLACK;
        parent->parent->color = (parent->parent == _root ? BLACK : RED);
        return (parent->parent);
    }
    checkLineXPG(new_node, parent);
    rotate_lineXPG_straight(parent);
    rotate_lineXPG_angle(new_node, parent);
    return (_root);
}

template< 
    class T_node, 
    class Allocator >
void
RBTree<T_node, Allocator>::
    checkLineXPG(Node<T_node> *new_node, Node<T_node> *parent) {
    if (new_node->parent->left == new_node &&
        (new_node->parent->parent == NIL ||
            new_node->parent->parent->left == new_node->parent)) {
            _isLine = lineLeft;
    } else if (
        new_node->parent->right == new_node &&
        (new_node->parent->parent == NIL ||
            new_node->parent->parent->right == new_node->parent)) {
            _isLine = lineRight;
    } else if (
        new_node->parent->right == new_node &&
            new_node->parent->parent->left == new_node->parent) {
            _isLine = angleLeft;
    } else if (
        new_node->parent->left == new_node &&
            new_node->parent->parent->right == new_node->parent) {
            _isLine = angleRight;
    }
}

template< 
    class T_node, 
    class Allocator >
void
RBTree<T_node, Allocator>::
    rotate_lineXPG_straight(Node<T_node> *parent) {
    if (_isLine == lineLeft) {
        parent->parent->left = parent->right;
        if (parent->parent->left != NIL) {
            parent->parent->left->parent = parent->parent;
        }
        parent->right = parent->parent;
        parent->parent = parent->parent->parent;
        parent->right->parent = parent;
        if (parent->parent != NULL && parent->parent != NIL && parent->parent->right == parent->right) {
            parent->parent->right = parent;
        } else if (parent->parent != NIL) {
            parent->parent->left = parent;
        }
        parent->right->color = RED;
        parent->color = BLACK;
        if (_root == parent->right) {
            _root = parent;
        }
    } else if (_isLine == lineRight) {
        parent->parent->right = parent->left;
        if (parent->parent->right != NIL && parent->parent->right != &_end_node) {
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
        if (_root == parent->left) {
            _root = parent;
        }
    }
}

template< 
    class T_node, 
    class Allocator >
void
RBTree<T_node, Allocator>::
    rotate_lineXPG_angle(Node<T_node> *new_node, Node<T_node> *parent) {
    if (_isLine != angleLeft && _isLine != angleRight) {
        return ;
    }
    if (_isLine == angleLeft) {
        new_node->parent = parent->parent;
        parent->parent->left = new_node;
        parent->parent = new_node;
        parent->right = NIL;
        new_node->left = parent;
    } else if (_isLine == angleRight) {
        new_node->parent = parent->parent;
        parent->parent->right = new_node;
        parent->parent = new_node;
        parent->left = NIL;
        new_node->right = parent;
    }
    checkLineXPG(parent, new_node);
    rotate_lineXPG_straight(new_node);
}

} // namespace ft

#endif