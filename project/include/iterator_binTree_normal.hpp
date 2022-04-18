#ifndef ITERATOR_BINTREE_NORMAL_HPP
#define ITERATOR_BINTREE_NORMAL_HPP

#include <RBTree.hpp>
#include <cstddef>
#include <ft_iterator_base.hpp>
#include <ft_iterator_tag_structs.hpp>
#include <ft_vector.hpp>

namespace ft {
// Итераторы как указатели для контейнеров
// binTree_iterator

template <
    typename T,
    typename Tree = RBTree<T> >
class binTree_iterator {
    public:
    typedef typename std::bidirectional_iterator_tag iterator_category;
    typedef typename iterator_traits<T *>::value_type value_type;
    typedef typename iterator_traits<T *>::difference_type difference_type;
    typedef typename iterator_traits<T *>::reference reference;
    typedef typename iterator_traits<T *>::pointer pointer;

    protected:
    vector< T* >    _stack;
    T *             _M_current;

    void            op_plus();

    public:
    void            op_plus_test();
    /* Constructs and destructs, operator= */
    binTree_iterator();
    explicit binTree_iterator(T * TPtr);
    binTree_iterator(const binTree_iterator & obj);
    binTree_iterator & operator=(const binTree_iterator & obj);
    binTree_iterator & operator=(T* obj);
    template < class Key, class Value >
        binTree_iterator<T, Tree>&  operator=(Node<pair<Key, Value> >* obj);

    // getters
    pointer base() const;

    // Forward iterator requirements and getters
    reference               operator*() const;
    pointer                 operator->() const;
    binTree_iterator &      operator++();
    binTree_iterator        operator++(int);

    // Bidirectional iterator requirements and getters
    // binTree_iterator &   operator--();
    // binTree_iterator     operator--(int);

    // Random access iterator requirements and getters
    // _Rt                 operator[](const _Dist n);
    // binTree_iterator     operator+(const _Dist n) const;
    // binTree_iterator     operator-(const _Dist n) const;
    // binTree_iterator &   operator+=(const _Dist n);
    // binTree_iterator &   operator-=(const _Dist n);
    // _Dist               operator-(const binTree_iterator & itSecond) const;

    // bool
    bool    operator==(const binTree_iterator & itSecond) const;
    bool    operator==(int & adrrdInt) const;
    bool    operator!=(const binTree_iterator & itSecond) const;
    bool    operator!=(int & adrrdInt) const;

    // bool    operator>(const binTree_iterator & itSecond) const;
    // bool    operator<(const binTree_iterator & itSecond) const;
    // bool    operator>=(const binTree_iterator & itSecond) const;
    // bool    operator<=(const binTree_iterator & itSecond) const;

};

// definitions
// Constructs and destructs, operator=
template <
    class T, 
    class Tree >
binTree_iterator<T, Tree>::
    binTree_iterator() :
            _stack(),
            _M_current(NULL) {}

template <
    class T, 
    class Tree >
binTree_iterator<T, Tree>::
    binTree_iterator(T * TPtr) :
            _stack(),
            _M_current(TPtr) {}

template <
    class T, 
    class Tree >
binTree_iterator<T, Tree>::
    binTree_iterator(const binTree_iterator<T, Tree>& obj) :
            _stack(),
            _M_current(obj.base()) {}

template <
    class T, 
    class Tree >
binTree_iterator<T, Tree>&
binTree_iterator<T, Tree>::
    operator=(const binTree_iterator<T, Tree>& obj) {
    if (this != &obj) {
        _M_current = obj.base();
        _stack.clear();
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
    _stack.clear();
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
    _stack.clear();
    return (*this);
}

// getters
template <
    class T, 
    class Tree >
typename binTree_iterator<T, Tree>::pointer 
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
    return (*_M_current);
}

template <
    class T, 
    class Tree >
typename binTree_iterator<T, Tree>::pointer 
 binTree_iterator<T, Tree>::
    operator->() const {
    return (_M_current);
}

template <
    class T, 
    class Tree >
binTree_iterator<T, Tree>& 
binTree_iterator<T, Tree>::
    operator++() {
    op_plus();
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

template <
    class T, 
    class Tree >
void
binTree_iterator<T, Tree>::
    op_plus() {
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
}

//     // Bidirectional iterator requirements

// template <
//     class T, 
//     class Tree = RBTree<T> >
// binTree_iterator<T, Tree>& 
// binTree_iterator<T, Tree>::
//     operator--() {
//     --_M_current;
//     return *this;
// }

// template <
//     class T, 
//     class Tree = RBTree<T> >
// binTree_iterator<T, Tree> 
// binTree_iterator<T, Tree>::
//     operator--(int) {
//     binTree_iterator<T, Tree> tmp = *this;
//     --_M_current;
//     return (tmp);
// }

//     // Random access iterator requirements and getters
// template <
//     class T, 
//     class Tree = RBTree<T> >
// _Rt
// binTree_iterator<T, Tree>::
//     operator[](const _Dist n) {
//     return (*(*this + n));
// }

// template <
//     class T, 
//     class Tree = RBTree<T> >
// binTree_iterator<T, Tree> 
// binTree_iterator<T, Tree>::
//     operator+(const _Dist n) const {
//     binTree_iterator<T, Tree> tmp(_M_current + n);
//     return (tmp);
// }

// template <
//     class T, 
//     class Tree = RBTree<T> >
// binTree_iterator<T, Tree> 
// binTree_iterator<T, Tree>::
//     operator-(const _Dist n) const {
//     binTree_iterator<T, Tree> tmp(_M_current - n);
//     return (tmp);
// }

// template <
//     class T, 
//     class Tree = RBTree<T> >
// binTree_iterator<T, Tree> &
// binTree_iterator<T, Tree>::
//     operator+=(const _Dist n) {
//     _M_current+=n;
//     return (*this);
// }

// template <
//     class T, 
//     class Tree = RBTree<T> >
// binTree_iterator<T, Tree> &
// binTree_iterator<T, Tree>::
//     operator-=(const _Dist n) {
//     _M_current-=n;
//     return (*this);
// }

// template <
//     class T, 
//     class Tree = RBTree<T> >
// _Dist
// binTree_iterator<T, Tree>::
//     operator-(const binTree_iterator & itSecond) const {
//     return (_M_current - itSecond._M_current);
// }

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

// template <
//     class T, 
//     class Tree = RBTree<T> >
// bool 
// binTree_iterator<T, Tree>::
//     operator>(const binTree_iterator<T, Tree> & itSecond) const {
//     return (_M_current > itSecond._M_current);
// }

// template <
//     class T, 
//     class Tree = RBTree<T> >
// bool 
// binTree_iterator<T, Tree>::
//     operator<(const binTree_iterator<T, Tree> & itSecond) const {
//     return (itSecond > *this);
// }

// template <
//     class T, 
//     class Tree = RBTree<T> >
// bool 
// binTree_iterator<T, Tree>::
//     operator>=(const binTree_iterator<T, Tree> & itSecond) const {
//     return (!(itSecond > *this));
// }

// template <
//     class T, 
//     class Tree = RBTree<T> >
// bool 
// binTree_iterator<T, Tree>::
//     operator<=(const binTree_iterator<T, Tree> & itSecond) const {
//     return (!(*this > itSecond));
// }


} // namespace ft

#endif
