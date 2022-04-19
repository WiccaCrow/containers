#ifndef ITERATOR_BINTREE_NORMAL_HPP
#define ITERATOR_BINTREE_NORMAL_HPP

#include <RBTree.hpp>
#include <iterator_traits.hpp>
#include <iterator_tag_structs.hpp>

namespace ft {
// binTree_iterator

template <
    typename T,
    typename Tree = RBTree<T> >
class binTree_iterator {
    public:
    typedef typename std::bidirectional_iterator_tag iterator_category;
    typedef typename iterator_traits<typename T::data_type *>::value_type value_type;
    typedef typename iterator_traits<typename T::data_type *>::difference_type difference_type;
    typedef typename iterator_traits<typename T::data_type *>::reference reference;
    typedef typename iterator_traits<typename T::data_type *>::pointer pointer;

    protected:
    T *     _M_current;

    public:
    /* Constructs and destructs, operator= */
    binTree_iterator();
    explicit binTree_iterator(T * TPtr);
    binTree_iterator(const binTree_iterator & obj);
    binTree_iterator & operator=(const binTree_iterator & obj);
    binTree_iterator & operator=(T* obj);
    template < class Key, class Value >
        binTree_iterator<T, Tree>&  operator=(Node<pair<Key, Value> >* obj);

    // getters
    T * base() const;

    // Forward iterator requirements and getters
    reference               operator*() const;
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

template <
    class T, 
    class Tree >
binTree_iterator<T, Tree>::
    binTree_iterator(T * TPtr) :
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

template <
    class T, 
    class Tree >
binTree_iterator<T, Tree>&
binTree_iterator<T, Tree>::
    operator=(T* obj) {
    _M_current = obj;
    return (*this);
}

template <
    class T, 
    class Tree >
template < class Key, class Value >
binTree_iterator<T, Tree>&
binTree_iterator<T, Tree>::
    operator=(Node<pair<Key, Value> >* obj) {
    _M_current = obj;
    return (*this);
}

// getters
template <
    class T, 
    class Tree >
T *
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
