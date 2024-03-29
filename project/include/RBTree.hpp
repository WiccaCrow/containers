#ifndef RBTREE_HPP
# define RBTREE_HPP

#include <memory>
#include <node.hpp>
#include <utility.hpp>
#include <cstddef>
// #include <iostream> // for test

namespace ft {

template <
    typename T,
    typename Tree >
class binTree_iterator;

template <
    typename T,
    typename Tree >
class binTree_iterator_const;

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
    typedef std::size_t                     size_type;

    typedef typename Allocator::template
            rebind<Node<T_node> >::other    allocator_type;

    typedef binTree_iterator<T_node, RBTree<T_node> >               iterator;
    typedef binTree_iterator_const<T_node, RBTree<T_node> >         const_iterator;

    typedef binTree_iterator_reverse<iterator >                       reverse_iterator;
    typedef binTree_iterator_reverse<const_iterator >                 const_reverse_iterator;

    protected:

    // Members

    Node<T_node> *       _root;
    Node<T_node> *       _begin;
    #define NIL &_empty_node
    Node<T_node>         _empty_node;
    Node<T_node>         _end_node;
    size_type            _size;
    allocator_type       _alloc;
    isLineXPG            _isLine;

    // Member functions

    iterator         find_element( const T_node& key );
    const_iterator   find_element( const T_node& key ) const;

    Node<T_node> *   find_insert_place(const T_node& data);
    Node<T_node> *   create_node(T_node data);
    void             check_balance_1(Node<T_node> *check_node);
    Node<T_node> *   check_balance_2(Node<T_node> *new_node, Node<T_node> *uncle, Node<T_node> *parent);
    void             checkLineXPG(Node<T_node> *new_node);
    void             rotate_lineXPG_straight(Node<T_node> *parent);
    void             rotate_lineXPG_angle(Node<T_node> *new_node, Node<T_node> *parent);

    void            erase_without_childs(iterator pos);
    void            erase_with_left_child(iterator pos);
    void            erase_with_right_child(iterator pos);
    void            erase_with_both_childs(iterator pos, iterator iter_next);
    void            erase_check_balance(int iter_prev_color_start, Node<T_node> *ch_prev,  Node<T_node> *Parent);
    int             balance_black_sibling_and_nephews(Node<T_node> **ch_prev, Node<T_node> **Parent);
    int             balance_black_sibling_red_nephews_line(Node<T_node> *ch_prev, Node<T_node> *Parent);
    int             balance_black_sibling_red_nephews_angle(Node<T_node> *ch_prev, Node<T_node> *Parent);
    void            balance_red_sibling(Node<T_node> *ch_prev, Node<T_node> *Parent);

    public:
    //////////////////////
    // Member functions //
    //////////////////////

    RBTree(allocator_type alloc = Allocator());
    RBTree(T_node data, allocator_type alloc = Allocator());
    RBTree(RBTree & other);
    template< class InputIt >
        RBTree( InputIt first, InputIt last,
            const Allocator& alloc = Allocator() );
    ~RBTree();
    RBTree &   operator=(const RBTree & other);
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

    void                    clear();
    pair<iterator, bool>    insert(const T_node& value);
    iterator                insert( iterator hint, const T_node& value );
    iterator                erase( iterator pos );
    // size_type               erase( const Key& key );
    void                    erase( iterator first, iterator last );
    void                    swap( RBTree& other );

    template< class InputIt >
        void    insert( InputIt first, InputIt last ) {
        while (first != last) {
            insert(*first);
            ++first;
        }
    }

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
    RBTree( allocator_type alloc ) : 
                _root(NULL),
                _begin(_root),
                _empty_node(),
                _end_node(),
                _size(0),
                _alloc(alloc) {
    _empty_node._is_empty = true;
    _end_node._is_empty = true;
    _end_node.right = &_end_node;
    _end_node.left = _begin;
}

template< 
    class T_node, 
    class Allocator >
RBTree<T_node, Allocator>::
    RBTree( T_node data, allocator_type alloc ) : 
                _empty_node(),
                _end_node(),
                _size(1),
                _alloc(alloc) {
    _empty_node._is_empty = true;
    _end_node._is_empty = true;
    _root = create_node(data);
    _root->color = BLACK;
    _root->left = &_end_node;
    _root->right = &_end_node;
    _end_node.parent = _root;
    _end_node.right = &_end_node;
    _begin = _root;
    _end_node.left = _begin;
}

template< 
    class T_node, 
    class Allocator >
RBTree<T_node, Allocator>::
    RBTree(RBTree & other) : 
                _root(NULL),
                _begin(_root),
                _empty_node(),
                _end_node(),
                _size(0) {
    _empty_node._is_empty = true;
    _end_node._is_empty = true;
    _end_node.right = _end_node.left = &_end_node;
    operator=(other);
}

template< 
    class T_node, 
    class Allocator >
template< class InputIt >
RBTree<T_node, Allocator>::
    RBTree( InputIt first, InputIt last,
        const Allocator& alloc ) : 
                _root(NULL),
                _begin(_root),
                _empty_node(),
                _end_node(),
                _size(0),
                _alloc(alloc) {
    _empty_node._is_empty = true;
    _end_node._is_empty = true;
    _end_node.right = _end_node.left = &_end_node;
    for ( ; first != last; ++first ) {
        this->insert( *first );
    }
}

template< 
    class T_node, 
    class Allocator >
RBTree<T_node, Allocator>::
    ~RBTree() {
    this->clear();
}

template< 
    class T_node, 
    class Allocator >
RBTree<T_node, Allocator> &   
RBTree<T_node, Allocator>::
    operator=(const RBTree & other) {
    if ( this == &other) {
        return (*this);
    }
    this->clear();
    _alloc = other.get_allocator();
    this->insert( other.begin(), other.end() );
    return (*this);
}

template< 
    class T_node, 
    class Allocator >
typename RBTree<T_node, Allocator>::allocator_type 
    RBTree<T_node, Allocator>::
    get_allocator(  ) const {
    return ( _alloc );
}

    // Element access

    // Iterators

template< 
    class T_node, 
    class Allocator >
typename RBTree<T_node, Allocator>::iterator                
RBTree<T_node, Allocator>::
    root(  ) {
    return ( iterator(_root) );
}

template< 
    class T_node, 
    class Allocator >
typename RBTree<T_node, Allocator>::iterator                
RBTree<T_node, Allocator>::
    begin(  ) {
    return ( iterator(_begin) );
}

template< 
    class T_node, 
    class Allocator >
typename RBTree<T_node, Allocator>::const_iterator                
RBTree<T_node, Allocator>::
    begin(  ) const {
        return ( const_iterator(_begin) );
}

template< 
    class T_node, 
    class Allocator >
typename RBTree<T_node, Allocator>::iterator                
RBTree<T_node, Allocator>::
    end(  ) {
    if ( _root == NULL ) {
        return ( iterator(_root) );
    }
    return ( iterator(&_end_node) );
}

template< 
    class T_node, 
    class Allocator >
typename RBTree<T_node, Allocator>::const_iterator                
RBTree<T_node, Allocator>::
    end(  ) const {
    if ( _root == NULL ) {
        return ( const_iterator(_root) );
    }
    return ( const_iterator(&_end_node) );
}

template< 
    class T_node, 
    class Allocator >
typename RBTree<T_node, Allocator>::reverse_iterator 
RBTree<T_node, Allocator>::
    rbegin( ) {
    return ( reverse_iterator(end()) );
}

template< 
    class T_node, 
    class Allocator >
typename RBTree<T_node, Allocator>::const_reverse_iterator 
RBTree<T_node, Allocator>::
    rbegin( ) const {
    return ( const_reverse_iterator(end()) );
}

template< 
    class T_node, 
    class Allocator >
typename RBTree<T_node, Allocator>::reverse_iterator 
RBTree<T_node, Allocator>::
    rend(  ) {
    return ( reverse_iterator(begin()) );
}

template< 
    class T_node, 
    class Allocator >
typename RBTree<T_node, Allocator>::const_reverse_iterator 
RBTree<T_node, Allocator>::
    rend(  ) const {
    return ( const_reverse_iterator(begin()) );
}

    // Capacity

template< 
    class T_node, 
    class Allocator >
bool
RBTree<T_node, Allocator>::
    empty(  ) const {
    return ( _root == NULL );
}

template< 
    class T_node, 
    class Allocator >
typename RBTree<T_node, Allocator>::size_type   
RBTree<T_node, Allocator>::
    size(  ) const {
    return ( _size );
}

template< 
    class T_node, 
    class Allocator >
typename RBTree<T_node, Allocator>::size_type   
RBTree<T_node, Allocator>::
max_size(  ) const {
    return ( _alloc.max_size() );
}

    // Modifiers

template< 
    class T_node, 
    class Allocator >
void
RBTree<T_node, Allocator>::
    clear() {
    this->erase( this->begin(), this->end() );
    _begin = _root = NULL;
    _end_node.parent = _end_node.left = NULL;
}

template< 
    class T_node, 
    class Allocator >
pair<typename RBTree<T_node, Allocator>::iterator, bool>
RBTree<T_node, Allocator>::
    insert( const T_node& value ) {
    if ( _root == NULL ) {
        _root = create_node(value);
        if ( _root == NIL ) {
            _root = NULL;
            return ( pair<iterator, bool>(iterator(_root), false) );
        }
        _size = 1;
        _root->color = BLACK;
        _root->left = &_end_node;
        _root->parent = NIL;
        _root->right = &_end_node;
        _end_node.parent = _root;
        _begin = _root;
        _end_node.left = _begin;
        return ( pair<iterator, bool>(iterator(_root), true) );
    }
    Node<T_node> *insert_place = find_insert_place(value);
    if ( *insert_place == value ) {
        return ( pair<iterator, bool>(iterator(insert_place), false) );
    } else {
        Node<T_node> *new_node = create_node(value);
        if (new_node == NIL) {
            return ( pair<iterator, bool>(iterator(insert_place), false) );
        }
        ++_size;
        if ( new_node->data < _begin->data ) {
            _begin = new_node;
            new_node->left = &_end_node;
            _end_node.left = _begin;
        } else {
            new_node->left = NIL;
        }
        new_node->parent = insert_place;
        new_node->right = NIL;
        if ( value < *insert_place ) {
            insert_place->left = new_node;
        } else if ( *insert_place < value ) {
            if ( insert_place->right == &_end_node ) {
                new_node->right = &_end_node;
                _end_node.parent = new_node;
            }
            insert_place->right = new_node;
        }
        check_balance_1(new_node);
        return ( pair<iterator, bool>(iterator(new_node), true) );
    }
}

template< 
    class T_node, 
    class Allocator >
typename RBTree<T_node, Allocator>::iterator                
RBTree<T_node, Allocator>::
insert( iterator hint, const T_node& value ) {
    iterator addr_hint = hint;
    if ( addr_hint == hint ) {
        ;
    }
    return ( insert(value).first );
}

template< 
    class T_node, 
    class Allocator >
typename RBTree<T_node, Allocator>::iterator               
RBTree<T_node, Allocator>::
    erase( iterator pos ) {
    --_size;
    if ( 0 == _size ) {
        _root = _begin = _end_node.parent = _end_node.left = NULL;
        _alloc.destroy(pos.base());
        _alloc.deallocate(pos.base(), 1);
        return this->end();
    }
    iterator iter_prev = pos;
    --iter_prev;
    if ( pos.base()->left == NIL || pos.base()->left == &_end_node ) {
        if ( pos.base()->right == NIL || pos.base()->right == &_end_node ) {
            erase_without_childs(pos);
        } else {
            erase_with_right_child(pos);
        }
    } else if ( pos.base()->right == NIL || pos.base()->right == this->end().base() ) {
        erase_with_left_child(pos);
    } else {
        erase_with_both_childs(pos, iter_prev);
    }
    return ( iter_prev );
}

template< 
    class T_node, 
    class Allocator >
void              
RBTree<T_node, Allocator>::
    erase( iterator first, iterator last ) {
    iterator iter_for_erase;
    while ( first != last ) {
        iter_for_erase = first;
        ++first;
        erase(iter_for_erase);
    }

}

    // size_type               erase( const Key& key );

template< 
    class T_node, 
    class Allocator >
void              
RBTree<T_node, Allocator>::
    swap( RBTree& other ) {
    // RBTree tmp(other);
    // other = *this;
    // *this = tmp;

        // tree tmp = *this;
    Node<T_node> * copy_root        = this->_root;
    Node<T_node> * copy_begin       = this->_begin;
    Node<T_node> * copy_end_parent  = this->_end_node.parent;
    Node<T_node> * copy_end_left    = this->_end_node.left;
    size_type      copy_size        = this->_size;
    allocator_type copy_alloc       = this->_alloc;
    // isLineXPG            _isLine;

        // *this = other;
    this->_root        = other._root;
    this->_begin       = other._begin;
    this->_begin->left = &(this->_end_node);
    // this->_end_node      = other._end_node;
    this->_end_node.parent  = other._end_node.parent;
    this->_end_node.left    = other._end_node.left;
    // this->_end_node.left    = _begin;
    this->_end_node.parent->right = &(this->_end_node);
    this->_size        = other._size;
    this->_alloc       = other._alloc;
    // this->_isLine      = other._isLine;
    // change NIL
    for (iterator iter = this->begin(); iter != this->end(); ) {
        iterator iter_copy = iter;
        ++iter;
        if ( iter_copy.base()->left == &(other._empty_node) ) {
            iter_copy.base()->left = &(this->_empty_node);
        }
        if ( iter_copy.base()->right == &(other._empty_node) ) {
            iter_copy.base()->right = &(this->_empty_node);
        }
        if ( iter_copy.base()->parent == &(other._empty_node) ) {
            iter_copy.base()->parent = &(this->_empty_node);
        } 
    }

        // other = tmp;
    other._root        = copy_root;
    other._begin       = copy_begin;
    other._begin->left = &(other._end_node);
    // other._end_node     = copy_end_node;
    other._end_node.parent  = copy_end_parent;
    other._end_node.left    = copy_end_left;
    other._end_node.parent->right = &(other._end_node);
    other._size        = copy_size;
    other._alloc       = copy_alloc;
    // other._isLine      = copy_isLine;
    // change NIL
    for (iterator iter = other.begin(); iter != other.end(); ) {
        iterator iter_copy = iter;
        ++iter;
        if (iter_copy.base()->left == &(this->_empty_node) ) {
            iter_copy.base()->left = &(other._empty_node);
        }
        if (iter_copy.base()->right == &(this->_empty_node)) {
            iter_copy.base()->right = &(other._empty_node);
        }
        if (iter_copy.base()->parent == &(this->_empty_node)) {
            iter_copy.base()->parent = &(other._empty_node);
        } 
    }
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
        if ( data < *node && node->left != NIL && node->left != &_end_node ) {
            node = node->left;
        } else if ( *node < data && node->right != NIL && node->right != &_end_node ) {
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
    checkLineXPG(new_node);
    rotate_lineXPG_straight(parent);
    rotate_lineXPG_angle(new_node, parent);
    return (_root);
}

template< 
    class T_node, 
    class Allocator >
void
RBTree<T_node, Allocator>::
    checkLineXPG(Node<T_node> *new_node) {
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
        parent->right = new_node->left;
        parent->right->parent = parent;
        new_node->left = parent;
    } else if (_isLine == angleRight) {
        new_node->parent = parent->parent;
        parent->parent->right = new_node;
        parent->parent = new_node;
        parent->left = new_node->right;
        parent->left->parent = parent;
        new_node->right = parent;
    }
    checkLineXPG(parent);
    rotate_lineXPG_straight(new_node);
}


template< 
    class T_node, 
    class Allocator >
void
RBTree<T_node, Allocator>::
    balance_red_sibling(Node<T_node> *ch_prev, Node<T_node> *Parent) {
    if ( Parent->right == ch_prev &&
         Parent->left->color == RED ) {
        Parent->left->color = BLACK;
        Parent->color = RED;
        if ( _root == Parent ) {
            _root = (Parent->left); // check root
        }
        (Parent->left->right)->parent = Parent; // BRC(p) = P
        (Parent->left)->parent = Parent->parent; // B(p) = G
        if ( Parent->parent != NULL && 
             Parent->parent != NIL ) {
            if ( Parent->parent->left == Parent ) { // G(l or r) = B
                Parent->parent->left = Parent->left;
            } else {
                Parent->parent->right = Parent->left;
            }
        }
        Parent->parent = Parent->left; // P(p) = B, 
        // B now is parent->parent
        Parent->left = (Parent->left->right); // P(l) = BRC
        (Parent->parent)->right = Parent; // B(r) = P
    } else if ( Parent->left == ch_prev &&
         Parent->right->color == RED ) {
        Parent->right->color = BLACK;
        Parent->color = RED;
        if ( _root == Parent ) {
            _root = (Parent->right); // check root
        }
        (Parent->right->left)->parent = Parent; // BLC(p) = P
        (Parent->right)->parent = Parent->parent; // B(p) = G
        if ( Parent->parent != NULL && 
             Parent->parent != NIL ) {
            if ( Parent->parent->left == Parent ) { // G(l or r) = B
                Parent->parent->left = Parent->right;
            } else {
                Parent->parent->right = Parent->right;
            }
        }
        Parent->parent = Parent->right; // P(p) = B, 
        // B now is parent->parent
        Parent->right = (Parent->right->left); // P(r) = BLC
        (Parent->parent)->left = Parent; // B(l) = P
    }
}

template< 
    class T_node, 
    class Allocator >
int
RBTree<T_node, Allocator>::
    balance_black_sibling_red_nephews_angle(Node<T_node> *ch_prev, Node<T_node> *Parent) {
    if ( Parent->right == ch_prev  &&
         Parent->left->color == BLACK &&
         Parent->left->left->color == BLACK &&
         Parent->left->right->color == RED ) {
        (Parent->left)->parent = (Parent->left->right); // B(p) = BRC
        // BRC now is (Parent->left)->parent
        (Parent->left->parent)->parent = Parent; // BRC(p) = P
        if ( (Parent->left->parent)->left != NIL ) {
            ((Parent->left->parent)->left)->parent = (Parent->left); // E(p) = B
        }
        (Parent->left)->right = (Parent->left->parent)->left; // B(r) = E
        (Parent->left->parent)->left = (Parent->left); // BRC(l) = B
        Parent->left = (Parent->left->parent); // P(r) = BLC
        // color
        Parent->left->color = BLACK; // BRC(color) = BLACK
        Parent->left->left->color = RED; // B(color) = RED
        return (1);
    } else if ( Parent->left == ch_prev  &&
         Parent->right->color == BLACK && // sibling
         Parent->right->right->color == BLACK &&
         Parent->right->left->color == RED ) { // nephew angle
        (Parent->right)->parent = (Parent->right->left); // B(p) = BLC
        // BLC now is (Parent->right)->parent
        (Parent->right->parent)->parent = Parent; // BLC(p) = P
        if ( (Parent->right->left)->right != NIL ) {
            ((Parent->right->left)->right)->parent = (Parent->right); // E(p) = B
        }
        (Parent->right)->left = (Parent->right->parent)->right; // B(l) = E
        (Parent->right->parent)->right = (Parent->right); // BLC(r) = B
        Parent->right = (Parent->right->parent); // P(r) = BLC
        // color
        Parent->right->color = BLACK; // BLC(color) = BLACK
        Parent->right->right->color = RED; // B(color) = RED
        return (1);
    }
    return (0);
}

template< 
    class T_node, 
    class Allocator >
int
RBTree<T_node, Allocator>::
    balance_black_sibling_red_nephews_line(Node<T_node> *ch_prev, Node<T_node> *Parent) {
    if ( Parent->right == ch_prev  &&
         Parent->left->color == BLACK &&
         Parent->left->left->color == RED ) {
        if ( _root == Parent) { // check root
            _root = Parent->left;
        }
        // родителем ч.брата станет родитель родителя: B(p) = P(p) 
        Parent->left->parent = Parent->parent;
        // ребенком деда вместо родителя станет брат: G(l or r) = B
        if (Parent->parent != NULL && Parent->parent != NIL) {
            if ( Parent->parent->left == Parent ) {
                Parent->parent->left = Parent->left;
            } else {
                Parent->parent->right = Parent->left;
            }
        }
        // родителем родителя становится брат: P(p) = B
        Parent->parent = Parent->left;
        // левым ребенком родителя становится вместо брата 
        // правый ребенок брата: P(l) = BRC
        Parent->left = Parent->parent->right;
        // родителем правого ребенка брата становится родитель: BRC(p)=  P
        if ( Parent->left != NIL) {
            Parent->left->parent = Parent;
        }
        // B(r) = P
        Parent->parent->right = Parent;
        // color
        if ( Parent->color == BLACK ) {
            Parent->parent->left->color = BLACK;
        } else {
            Parent->parent->left->color = Parent->color = BLACK;
            Parent->parent->color = RED;
        }
        return (1);
    } else if ( Parent->left == ch_prev  &&
         Parent->right->color == BLACK && // sibling
         Parent->right->right->color == RED ) { // nephew line
        if ( _root == Parent) { // check root
            _root = Parent->right;
        }
        Parent->right->parent = Parent->parent;
        if (Parent->parent != NULL && Parent->parent != NIL) {
            if ( Parent->parent->left == Parent ) {
                Parent->parent->left = Parent->right;
            } else {
                Parent->parent->right = Parent->right;
            }
        }
        Parent->parent = Parent->right;
        Parent->right = Parent->parent->left;
        if ( Parent->right != NIL) {
            Parent->right->parent = Parent;
        }
        Parent->parent->left = Parent;
        // color
        if ( Parent->color == BLACK ) {
            Parent->parent->right->color = BLACK;
        } else {
            Parent->parent->right->color = Parent->color = BLACK;
            Parent->parent->color = RED;
        }
        return (1);
    }
    return (0);
}

template< 
    class T_node, 
    class Allocator >
int
RBTree<T_node, Allocator>::
    balance_black_sibling_and_nephews(Node<T_node> **ch_prev, Node<T_node> **Parent) {
    if ( (*Parent)->left == (*ch_prev) &&
            (
            (*Parent)->right->color == BLACK &&
            (*Parent)->right->left->color == BLACK &&
            (*Parent)->right->right->color == BLACK
            ) 
        ) {
        (*Parent)->right->color = RED;
        *ch_prev = (*Parent);
        *Parent = (*Parent)->parent;
        if ( (*ch_prev)->color == BLACK && *ch_prev != _root) {
            return (1);
        }
        (*ch_prev)->color = BLACK;
        return (2);
    } else if ( (*Parent)->right == (*ch_prev) &&
            (
            (*Parent)->left->color == BLACK &&
            (*Parent)->left->left->color == BLACK &&
            (*Parent)->left->right->color == BLACK
            )  ) {
        (*Parent)->left->color = RED;
        *ch_prev = (*Parent);
        *Parent = (*Parent)->parent;
        if ( (*ch_prev)->color == BLACK ) {
            return (1);
        }
        (*ch_prev)->color = BLACK;
        return (2);
    }
    return (0);
}

template< 
    class T_node, 
    class Allocator >
void
RBTree<T_node, Allocator>::
    erase_check_balance(int iter_prev_color_start, Node<T_node> *ch_prev, Node<T_node> *Parent) {
    if ( iter_prev_color_start ==  BLACK ) {
        if ( ch_prev->color == RED ) {
            ch_prev->color = BLACK;
        } else {
            // rotate
            for ( int i = 1 ; i ; ) {
                balance_red_sibling(ch_prev, Parent);
                i = balance_black_sibling_and_nephews(&ch_prev, &Parent);
                if ( i == 2 ) {
                    return ;
                }
            }
            if ( balance_black_sibling_red_nephews_line(ch_prev, Parent) ) {
                return ;
            }
            if ( balance_black_sibling_red_nephews_angle(ch_prev, Parent) ) {
                if ( balance_black_sibling_red_nephews_line(ch_prev, Parent) )
                    return ;
            }
        }
    }
}

template< 
    class T_node, 
    class Allocator >
void
RBTree<T_node, Allocator>::
    erase_without_childs(iterator pos) {
    if ( _begin == pos.base() ) {
        _begin = pos.base()->parent;
        _end_node.left = _begin;
        pos.base()->left = NIL;
    }
    if ( pos.base()->parent->left == pos.base() ) {
        pos.base()->parent->left = NIL;
        erase_check_balance(pos.base()->color, pos.base()->parent->left, pos.base()->parent);
    } else {
        pos.base()->parent->right = pos.base()->right;
        erase_check_balance(pos.base()->color, pos.base()->parent->right, pos.base()->parent);
    }
    _begin->left = &_end_node;
    delete_node(pos.base(), _alloc);
}

template< 
    class T_node, 
    class Allocator >
void
RBTree<T_node, Allocator>::
    erase_with_right_child(iterator pos) {
    if ( pos.base() == _root ) {
        _begin = pos.base()->right;
        _begin->left = &_end_node;
        _begin->color = BLACK;
        _begin->parent = pos.base()->parent;
        _root = _begin;
        delete_node(pos.base(), _alloc);
        return ;
    }
    if ( pos.base()->parent->left == pos.base() ) {
        if ( _begin == pos.base() ) {
            _begin = pos.base()->right;
            _end_node.left = _begin;
            pos.base()->left = NIL;
        }
        pos.base()->parent->left = pos.base()->right;
    } else {
        pos.base()->parent->right = pos.base()->right;
    }
    pos.base()->right->parent = pos.base()->parent;
    erase_check_balance(pos.base()->color, pos.base()->right, pos.base()->parent);
    _begin->left = &_end_node;
    delete_node(pos.base(), _alloc);
}

template< 
    class T_node, 
    class Allocator >
void
RBTree<T_node, Allocator>::
    erase_with_left_child(iterator pos) {
    if ( pos.base() == _root ) {
        _root = pos.base()->left;
        pos.base()->left->right = &_end_node;
        pos.base()->left->color = BLACK;
        pos.base()->left->parent = pos.base()->parent;
        delete_node(pos.base(), _alloc);
        return ;
    }
    if ( pos.base()->parent->left == pos.base() ) {
        pos.base()->parent->left = pos.base()->left;
    } else {
        pos.base()->parent->right = pos.base()->left;
    }
    pos.base()->left->parent = pos.base()->parent;
    erase_check_balance(pos.base()->color, pos.base()->left, pos.base()->parent);
    delete_node(pos.base(), _alloc);
}

template< 
    class T_node, 
    class Allocator >
void
RBTree<T_node, Allocator>::
    erase_with_both_childs(iterator pos, iterator iter_prev) {
    if ( _root == pos.base() ) {
        _root = iter_prev.base(); // check root
    }
    int iter_prev_color_start = iter_prev.base()->color;
    Node<T_node> *ch_prev = iter_prev.base()->left; // for color
    Node<T_node> *parent_prev = iter_prev.base()->parent; // for color

    // 1
    iter_prev.base()->color = pos.base()->color;
    // 2 , 6.1, 6.2
    if ( iter_prev.base()->parent != pos.base() ) {
        iter_prev.base()->parent->right = iter_prev.base()->left;
        if ( iter_prev.base()->left != NIL && 
             iter_prev.base()->left != &_end_node ) {
            iter_prev.base()->left->parent = iter_prev.base()->parent;
        }
    }
    // 3
    iter_prev.base()->parent = pos.base()->parent;
    // 4
    if ( pos.base()->parent != NULL &&
         pos.base()->parent != NIL ) {
        if ( pos.base()->parent->left == pos.base() ) {
            pos.base()->parent->left = iter_prev.base();
        } else {
            pos.base()->parent->right = iter_prev.base();
        }
    }
    // 5
    iter_prev.base()->right = pos.base()->right;
    // 6
    pos.base()->right->parent = iter_prev.base();
    if ( pos.base()->left != iter_prev.base() ) {
        // 7
        iter_prev.base()->left = pos.base()->left;
        iter_prev.base()->left->parent = iter_prev.base();
    } else {
        parent_prev = iter_prev.base();
    }
    erase_check_balance(iter_prev_color_start, ch_prev, parent_prev);
    delete_node(pos.base(), _alloc);
}

//  double black node has black sibling and 2 black nephews. push up black level

} // namespace ft

#endif
