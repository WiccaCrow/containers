#ifndef ITERATOR_BINTREE_NORMAL_CONST_HPP
#define ITERATOR_BINTREE_NORMAL_CONST_HPP

#include <RBTree.hpp>
#include <iterator_traits.hpp>
#include <iterator_tag_structs.hpp>
#include <cstddef>

namespace ft {
// binTree_iterator

template <
    typename T,
    typename Tree >
class binTree_iterator;


template <
    typename _T,
    typename Tree = RBTree<_T> >
class binTree_iterator_const {
    public:
    typedef typename std::bidirectional_iterator_tag iterator_category;
    typedef _T                                  value_type;
    typedef const _T&                           reference;
    typedef const _T*                           pointer;
    typedef ptrdiff_t			                difference_type;
    typedef binTree_iterator<_T>                iterator;
    typedef binTree_iterator_const<_T>		    _Self;
    typedef typename Node<_T>::_Const_Node_ptr  _Node_ptr;

    // typedef typename iterator_traits<const typename Node<T>::data_type *>::reference const_reference;

    // typedef const _Rb_tree_node<_Tp>*			_Link_type;


    protected:
    _Node_ptr     _M_current;

    public:
    /* Constructs and destructs, operator= */
    binTree_iterator_const();
    explicit binTree_iterator_const(_Node_ptr TPtr);
    binTree_iterator_const(const iterator & obj);
    iterator        _M_const_cast() const;
    // iterator &      operator=(const iterator & obj);

    // getters
    _Node_ptr base() const;

    // Forward iterator requirements and getters
    reference                     operator*() const;
    pointer                       operator->() const;
    binTree_iterator_const &      operator++();
    binTree_iterator_const        operator++(int);

    // Bidirectional iterator requirements and getters
    binTree_iterator_const &   operator--();
    binTree_iterator_const     operator--(int);

    // bool
    bool    operator==(const binTree_iterator_const & itSecond) const;
    bool    operator==(int & adrrdInt) const;
    bool    operator!=(const binTree_iterator_const & itSecond) const;
    bool    operator!=(int & adrrdInt) const;

};

// definitions
// Constructs and destructs, operator=
template <
    class T, 
    class Tree >
binTree_iterator_const<T, Tree>::
    binTree_iterator_const() :
            _M_current(NULL) {}

template <
    class T, 
    class Tree >
binTree_iterator_const<T, Tree>::
    binTree_iterator_const(_Node_ptr TPtr) :
            _M_current(TPtr) {}

template <
    class T, 
    class Tree >
binTree_iterator_const<T, Tree>::
    binTree_iterator_const(const iterator & obj) :
            _M_current(obj.base()) {}

template <
    class T, 
    class Tree >
typename binTree_iterator_const<T, Tree>::iterator
binTree_iterator_const<T, Tree>::
_M_const_cast() const {
    return iterator(const_cast<typename iterator::_Node_ptr>(_M_current));
}

// template <
//     class T, 
//     class Tree >
// binTree_iterator_const<T, Tree>&
// binTree_iterator_const<T, Tree>::
//     operator=(const binTree_iterator<T, Tree>& obj) {
//     if (this != &obj) {
//         _M_current = obj.base();
//     }
//     return (*this);
// }

// getters
template <
    class T, 
    class Tree >
typename binTree_iterator_const<T, Tree>::_Node_ptr
    binTree_iterator_const<T, Tree>::
    base() const {
    return (_M_current);
}

    // Forward iterator requirements

template <
    class T, 
    class Tree >
typename binTree_iterator_const<T, Tree>::reference 
binTree_iterator_const<T, Tree>::
    operator*() const {
    // return (**_M_current);
    // return *static_cast<_Node_ptr>(_M_current)->_M_valptr();
    // return *static_cast<_Node_ptr>(_M_current);
    return (*(_M_const_cast()));
}

template <
    class T, 
    class Tree >
typename binTree_iterator_const<T, Tree>::pointer 
 binTree_iterator_const<T, Tree>::
    operator->() const {
    return (*_M_current);
}

template <
    class T, 
    class Tree >
binTree_iterator_const<T, Tree>& 
binTree_iterator_const<T, Tree>::
    operator++() {
    // check end
    if (_M_current->right->right == _M_current->right) {
        _M_current =  _M_current->right;
    // check right child/root
    } else if ((_M_current->right != NULL && 
        _M_current->right->is_empty() == false) ||
        (_M_current->is_empty() == false && 
        _M_current->parent->is_empty() == true)) {
        _M_current = _M_current->right;
        while (_M_current->left != NULL && 
                _M_current->left->is_empty() == false) {
            _M_current = _M_current->left;
        }
    // not end, not root, without right child
    } else {
        while (_M_current->parent->right == _M_current) {
            _M_current = _M_current->parent;
        }
        if (_M_current->parent->left == _M_current) {
            _M_current = _M_current->parent;
        }
    }
    return (*this);
}

template <
    class T, 
    class Tree >
binTree_iterator_const<T, Tree> 
binTree_iterator_const<T, Tree>::
    operator++(int) {
    binTree_iterator_const<T, Tree> tmp = *this;
    ++(*this);
    return (tmp);
}

    // Bidirectional iterator requirements

template <
    class T, 
    class Tree >
binTree_iterator_const<T, Tree>& 
binTree_iterator_const<T, Tree>::
    operator--() {
    // check end
    if (_M_current->right == _M_current) {
        _M_current =  _M_current->parent;
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
        while (_M_current->parent->left == _M_current) {
            _M_current = _M_current->parent;
        }
        if (_M_current->parent->right == _M_current) {
            _M_current = _M_current->parent;
        }
    }
    return *this;
}

template <
    class T, 
    class Tree >
binTree_iterator_const<T, Tree> 
binTree_iterator_const<T, Tree>::
    operator--(int) {
    binTree_iterator_const<T, Tree> tmp = *this;
    --(*this);
    return (tmp);
}

    // bool

template <
    class T, 
    class Tree >
bool 
binTree_iterator_const<T, Tree>::
    operator==(const binTree_iterator_const<T, Tree> & itSecond) const {
    return (_M_current == itSecond._M_current);
}

template <
    class T, 
    class Tree >
bool 
binTree_iterator_const<T, Tree>::
    operator==(int & adrrdInt) const {
    return (_M_current == static_cast<T*>(adrrdInt));
}

template <
    class T, 
    class Tree >
bool 
binTree_iterator_const<T, Tree>::
    operator!=(const binTree_iterator_const<T, Tree> & itSecond) const {
    return (!(operator==(itSecond)));
}

template <
    class T, 
    class Tree >
bool 
binTree_iterator_const<T, Tree>::
    operator!=(int & adrrdInt) const {
    return (!(operator==(static_cast<T*>(adrrdInt))));
}

} // namespace ft

#endif
