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
    typedef typename iterator_traits<typename T::data_type *>::value_type value_type;
    typedef typename iterator_traits<typename T::data_type *>::difference_type difference_type;
    typedef typename iterator_traits<T *>::reference reference;
    typedef typename iterator_traits< T *>::pointer pointer;



    protected:
    vector< T* >    _stack;
    T *             _M_current_node;
    T *             _M_current;

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
    pointer base() const;

    // Forward iterator requirements and getters
    reference               operator*() const;
    pointer                 operator->() const;
    binTree_iterator &      operator++();
    binTree_iterator        operator++(int);
    void                    op_plus();

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
    // bool    operator==(const binTree_iterator & itSecond) const;
    // bool    operator==(int & adrrdInt) const;
    // bool    operator!=(const binTree_iterator & itSecond) const;
    // bool    operator!=(int & adrrdInt) const;

    // bool    operator>(const binTree_iterator & itSecond) const;
    // bool    operator<(const binTree_iterator & itSecond) const;
    // bool    operator>=(const binTree_iterator & itSecond) const;
    // bool    operator<=(const binTree_iterator & itSecond) const;

}; // typename не скомпилится

// definitions
// Constructs and destructs, operator=
template <
    class T, 
    class Tree >
binTree_iterator<T, Tree>::
    binTree_iterator() :
            _stack(),
            _M_current_node(NULL),
            _M_current(NULL) {}

template <
    class T, 
    class Tree >
binTree_iterator<T, Tree>::
    binTree_iterator(T * TPtr) :
            _stack(),
            _M_current_node(NULL),
            _M_current(TPtr) {}

template <
    class T, 
    class Tree >
binTree_iterator<T, Tree>::
    binTree_iterator(const binTree_iterator<T, Tree>& obj) :
            _stack(),
            _M_current_node(obj._M_current_node), 
            _M_current(obj.base()) {}

template <
    class T, 
    class Tree >
binTree_iterator<T, Tree>&
binTree_iterator<T, Tree>::
    operator=(const binTree_iterator<T, Tree>& obj) {
    if (this != &obj) {
        _M_current_node = obj._M_current_node;
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
    _M_current_node = _M_current;
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
    _M_current_node = _M_current;
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

// template <
//     class T, 
//     class Tree >
// void
// binTree_iterator<T, Tree>::
//     op_plus() {
//     if (_stack.empty() == false || (_M_current_node != NULL && _M_current_node->is_empty() == false)) {
//         if (_M_current_node != NULL && _M_current_node->is_empty() == false) {
//             while (_M_current_node != NULL && _M_current_node->is_empty() == false) {
//                 _stack.push_back(_M_current_node);
//                 _M_current_node = _M_current_node->left;
//             }
//         } else {
//             _M_current_node = _stack[_stack.size() - 1];
//             _stack.pop_back();
//         }
//         _M_current = _M_current_node;
//         // std::cout << _M_current_node->data.first << std::endl;
//         // std::cout << _M_current->data.first << std::endl;
//             _M_current_node = _M_current_node->right;
//     }
// }

template <
    class T, 
    class Tree >
binTree_iterator<T, Tree>& 
binTree_iterator<T, Tree>::
    operator++() {
    Node<T> tmpNode = *_M_current;
    op_plus();
    while (_M_current->_is_empty || *_M_current == tmpNode) {
        op_plus();
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

template <
    class T, 
    class Tree >
void
binTree_iterator<T, Tree>::
    op_plus() {
    if (_stack.empty() == false || (_M_current_node != NULL && _M_current_node->is_empty() == false)) {
        if (_M_current_node != NULL && _M_current_node->is_empty() == false) {
            while (_M_current_node != NULL && 
                   _M_current_node->is_empty() == false && 
                   *_M_current_node > *_M_current) {
                _stack.push_back(_M_current_node);
                _M_current_node = _M_current_node->left;
            }
        } else {
            _M_current_node = _stack[_stack.size() - 1];
            _stack.pop_back();
        }
        _M_current = _M_current_node;
        _M_current_node = _M_current_node->right;
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

//     // bool

// template <
//     class T, 
//     class Tree = RBTree<T> >
// bool 
// binTree_iterator<T, Tree>::
//     operator==(const binTree_iterator<T, Tree> & itSecond) const {
//     return (_M_current == itSecond._M_current);
// }

// template <
//     class T, 
//     class Tree = RBTree<T> >
// bool 
// binTree_iterator<T, Tree>::
//     operator==(int & adrrdInt) const {
//     return (_M_current == static_cast<_Pt>(adrrdInt));
// }

// template <
//     class T, 
//     class Tree = RBTree<T> >
// bool 
// binTree_iterator<T, Tree>::
//     operator!=(const binTree_iterator<T, Tree> & itSecond) const {
//     return (!(operator==(itSecond)));
// }

// template <
//     class T, 
//     class Tree = RBTree<T> >
// bool 
// binTree_iterator<T, Tree>::
//     operator!=(int & adrrdInt) const {
//     return (!(operator==(static_cast<_Pt>(adrrdInt))));
// }

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
