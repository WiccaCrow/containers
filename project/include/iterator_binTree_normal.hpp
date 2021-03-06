#ifndef ITERATOR_BINTREE_NORMAL_HPP
#define ITERATOR_BINTREE_NORMAL_HPP

#include <RBTree.hpp>
#include <iterator_traits.hpp>
#include <iterator_tag_structs.hpp>
#include <cstddef>

namespace ft {
// binTree_iterator

template <
    typename T,
    typename Tree = RBTree<T> >
class binTree_iterator {
    public:
    typedef typename std::bidirectional_iterator_tag iterator_category;
    typedef typename iterator_traits<typename Node<T>::data_type *>::value_type value_type;
    typedef typename iterator_traits<typename Node<T>::data_type *>::difference_type difference_type;
    typedef typename iterator_traits<typename Node<T>::data_type *>::reference reference;
    typedef typename iterator_traits<const typename Node<T>::data_type *>::reference const_reference;
    typedef typename iterator_traits<typename Node<T>::data_type *>::pointer pointer;
    typedef typename Node<T>::_Node_ptr  _Node_ptr;

    protected:
    _Node_ptr     _M_current;

    public:
    /* Constructs and destructs, operator= */
    binTree_iterator();
    // explicit binTree_iterator(const Node<T> * TPtr);
    explicit binTree_iterator(_Node_ptr TPtr);
    binTree_iterator(const binTree_iterator & obj);
    binTree_iterator & operator=(const binTree_iterator & obj);

    // getters
    _Node_ptr base() const;

    // Forward iterator requirements and getters
    reference               operator*() const;
    // const_reference               operator*() const {
    //     return (**_M_current);
    // }
    pointer                 operator->() const;
    binTree_iterator &      operator++();
    binTree_iterator        operator++(int);

    // Bidirectional iterator requirements and getters
    binTree_iterator &   operator--();
    binTree_iterator     operator--(int);

    // bool
    bool    operator==(const binTree_iterator & itSecond) const;
    bool    operator==(int & adrrdInt) const;
    bool    operator!=(const binTree_iterator & itSecond) const;
    bool    operator!=(int & adrrdInt) const;

};

// definitions
// Constructs and destructs, operator=
template <
    class T, 
    class Tree >
binTree_iterator<T, Tree>::
    binTree_iterator() :
            _M_current(NULL) {}

// template <
//     class T, 
//     class Tree >
// binTree_iterator<T, Tree>::
//     binTree_iterator(const Node<T> * TPtr) :
//             _M_current(TPtr) {}

template <
    class T, 
    class Tree >
binTree_iterator<T, Tree>::
    binTree_iterator(_Node_ptr TPtr) :
            _M_current(TPtr) {}

template <
    class T, 
    class Tree >
binTree_iterator<T, Tree>::
    binTree_iterator(const binTree_iterator<T, Tree>& obj) :
            _M_current(obj.base()) {}

template <
    class T, 
    class Tree >
binTree_iterator<T, Tree>&
binTree_iterator<T, Tree>::
    operator=(const binTree_iterator<T, Tree>& obj) {
    if (this != &obj) {
        _M_current = obj.base();
    }
    return (*this);
}

// getters
template <
    class T, 
    class Tree >
typename binTree_iterator<T, Tree>::_Node_ptr
    binTree_iterator<T, Tree>::
    base() const {
    return (_M_current);
}

    // Forward iterator requirements

template <
    class T, 
    class Tree >
typename binTree_iterator<T, Tree>::reference 
    binTree_iterator<T, Tree>::
    operator*() const {
    return (**_M_current);
}

template <
    class T, 
    class Tree >
typename binTree_iterator<T, Tree>::pointer 
 binTree_iterator<T, Tree>::
    operator->() const {
    return &(**_M_current);
}

template <
    class T, 
    class Tree >
binTree_iterator<T, Tree>& 
binTree_iterator<T, Tree>::
    operator++() {
    // check befor begin
    if ( _M_current->right == _M_current ) {
        _M_current = _M_current->left;
    // check end
    } else if (_M_current->right->right == _M_current->right) {
        _M_current =  _M_current->right;
    // check right child/root
    } else if ((_M_current->right != NULL && 
        _M_current->right->is_empty() == false) || // right node is not list and not end node
        (_M_current->is_empty() == false && 
        _M_current->parent->is_empty() == true)) { // is root
        _M_current = _M_current->right;
        while (_M_current->left != NULL && 
                _M_current->left->is_empty() == false) {
            _M_current = _M_current->left;
        }
    // not end, not root, without right child
    } else {
        // Find the parent to the right of the source node
        while ( (_M_current->parent != NULL && 
                 _M_current->parent->is_empty() == false) &&
                _M_current->parent->right == _M_current) {
                    // std::cout << " test 1 " << _M_current->data.first << std::endl; // test
            _M_current = _M_current->parent;
                    // std::cout << " test 2 " << _M_current->data.first << std::endl; // test
                    // std::cout << " test 2 " << _M_current->parent->data.first << std::endl; // test

        }

        // if (_M_current->data.first == 1350490027) {
            // if (_M_current->parent != NULL && _M_current->parent->is_empty() == false)
                // std::cout << " test 3 " << _M_current->parent->data.first << std::endl; // test
            // else
                // std::cout << " test 4 NIL________________ " << std::endl; // test
        // }

        if ( (_M_current->parent != NULL && 
              _M_current->parent->is_empty() == false) &&
             _M_current->parent->left == _M_current) {
                // std::cout << " test 5________________ " << std::endl; // test

            _M_current = _M_current->parent;
        }
    }
    return (*this);
}

template <
    class T, 
    class Tree >
binTree_iterator<T, Tree> 
binTree_iterator<T, Tree>::
    operator++(int) {
    binTree_iterator<T, Tree> tmp = *this;
    ++(*this);
    return (tmp);
}

    // Bidirectional iterator requirements

template <
    class T, 
    class Tree >
binTree_iterator<T, Tree>& 
binTree_iterator<T, Tree>::
    operator--() {
    // check begin : not list && does end_node (befor begin)
    if ( _M_current->left != NULL && _M_current->left->right == _M_current->left ) {
        _M_current = _M_current->left;
    // check end
    } else if (_M_current->right == _M_current) {
        _M_current = _M_current->parent;
    // check right child/root
    } else if ((_M_current->left != NULL && 
        _M_current->left->is_empty() == false) ||
        (_M_current->is_empty() == false && // check root
        _M_current->parent->is_empty() == true)) {
        _M_current = _M_current->left;
        while (_M_current->right != NULL && 
                _M_current->right->is_empty() == false) {
            _M_current = _M_current->right;
        }
    // not end, not root, without right child
    } else {
        while ( (_M_current->parent != NULL && 
                 _M_current->parent->is_empty() == false) &&
                _M_current->parent->left == _M_current) {
            _M_current = _M_current->parent;
        }
        if ( (_M_current->parent != NULL && 
              _M_current->parent->is_empty() == false) && 
             _M_current->parent->right == _M_current ) {
            _M_current = _M_current->parent;
        }
    }
    return *this;
}

template <
    class T, 
    class Tree >
binTree_iterator<T, Tree> 
binTree_iterator<T, Tree>::
    operator--(int) {
    binTree_iterator<T, Tree> tmp = *this;
    --(*this);
    return (tmp);
}

    // bool

template <
    class T, 
    class Tree >
bool 
binTree_iterator<T, Tree>::
    operator==(const binTree_iterator<T, Tree> & itSecond) const {
    return (_M_current == itSecond._M_current);
}

template <
    class T, 
    class Tree >
bool 
binTree_iterator<T, Tree>::
    operator==(int & adrrdInt) const {
    return (_M_current == static_cast<T*>(adrrdInt));
}

template <
    class T, 
    class Tree >
bool 
binTree_iterator<T, Tree>::
    operator!=(const binTree_iterator<T, Tree> & itSecond) const {
    return (!(operator==(itSecond)));
}

template <
    class T, 
    class Tree >
bool 
binTree_iterator<T, Tree>::
    operator!=(int & adrrdInt) const {
    return (!(operator==(static_cast<T*>(adrrdInt))));
}

} // namespace ft

#endif
