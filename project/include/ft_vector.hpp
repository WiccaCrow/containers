#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <memory>
#include <ft_iterator.hpp>
#include <stdexcept>

namespace ft {

template<typename _Tp, typename _Alloc>
class _Vector_base {
    protected:
    typedef typename _Alloc::template
	rebind<_Tp>::other _Tp_alloc_type;
    _Vector_base(_Alloc alloc = _Alloc()) : _alloc(alloc) {}
    public:
    _Tp_alloc_type _alloc;
};

template <
    class T,
    class Allocator = ::std::allocator<T> >

class vector : public _Vector_base<T, Allocator> {
    public:

    // Member types
    typedef T value_type;
    typedef typename ::ft::_Vector_base<T, Allocator>::_Tp_alloc_type    allocator_type;
    typedef typename ::std::size_t                      size_type;
    typedef typename ::std::ptrdiff_t                   difference_type;
    typedef value_type&                                 reference;
    typedef const value_type&                           const_reference;
    typedef typename ::std::allocator<T>::pointer       pointer;
    typedef typename ::std::allocator<T>::const_pointer const_pointer;

    typedef ft::normal_iterator<random_access_iterator_tag, T>       iterator;
    typedef ft::normal_iterator<random_access_iterator_tag, const T> const_iterator;
    typedef ft::reverse_iterator<iterator>                           reverse_iterator;
    typedef ft::reverse_iterator<const_iterator>                     const_reverse_iterator;

    private:
    size_t    _size;
    size_t    _capacity;
    pointer        _arr;
    pointer        _arr_end;

    void    insert_too_small_capacity(iterator & pos, size_type & count, iterator first);
    void    insert_count_more_than_end_to_pos(iterator & pos, size_type & count, iterator first);
    void    insert_count_less_than_end_to_pos(iterator & pos, size_type & count, iterator first);
    pointer copy(iterator first, iterator last, pointer copy_to);

    public:
    //////////////////////
    // Member functions //
    //////////////////////

    explicit vector();
    explicit vector(const allocator_type& alloc);
    explicit vector(size_type count, const value_type& val = value_type(),
                    const allocator_type& alloc = allocator_type());
    template <class InputIt>
        vector(InputIt first, InputIt last, const Allocator& alloc = Allocator());
    vector( const vector& other );
    ~vector() {}
    vector<T, Allocator>& operator=(const vector<T, Allocator>& other);

    // Element access
    T &     operator[](int i);
    T*      data();

    // Iterators
    iterator       begin() const;
    iterator       end() const;

    // Capacity
    size_t         size() const;
    size_type      max_size() const;
    size_t         capacity() const;
    
    // Modifiers
    void    clear();
    template< class InputIt >
        void    insert( iterator pos, InputIt first, InputIt last );
    iterator erase( iterator first, iterator last );

    /* operators */
    /* Set atributs */
    /* Get and show atributs */

    // allocator_type alloc() const;

    /* other methods */
    // void        push_back(const T& x);

};  // namespace ft

/******************************************************************************/
    //////////////////////
    // Member functions //
    //////////////////////

template <class T, class Allocator>
vector<T, Allocator>::vector() : 
                                ::ft::_Vector_base<T, Allocator>::_Vector_base(),
                                _size(0),
                                _capacity(0),
                                _arr(NULL),
                                _arr_end(NULL) {
}

template <class T, class Allocator>
vector<T, Allocator>::vector(const allocator_type& alloc) : 
                                ::ft::_Vector_base<T, Allocator>::_Vector_base(alloc),
                                _size(0),
                                _capacity(0),
                                _arr(NULL),
                                _arr_end(NULL) {
}

template <class T, class Allocator>
vector<T, Allocator>::vector(size_type count, const value_type& val,
                             const allocator_type& alloc) :
                                ::ft::_Vector_base<T, Allocator>::_Vector_base(alloc),
                                _size(count),
                                _capacity(count),
                                _arr(::ft::_Vector_base<T, Allocator>::_alloc.allocate(count)),
                                _arr_end(_arr + count) {
    size_type i = 0;
    try {
        for (; i < count; ++i) {
            ::ft::_Vector_base<T, Allocator>::_alloc.construct(_arr + (int)i, val);
        }
    } catch (...) {
        for (; i--;) {
            ::ft::_Vector_base<T, Allocator>::_alloc.destroy(_arr + i);
        }
        throw;
    }
}

template <class T, class Allocator>
template <class InputIt>
    vector<T, Allocator>::vector(InputIt first, InputIt last, const Allocator& alloc) :
                        ::ft::_Vector_base<T, Allocator>::_Vector_base(alloc),
                        _size(0),
                        _capacity(0),
                        _arr(NULL),
                        _arr_end(NULL) {
    insert(begin(), first, last);
}

template <class T, class Allocator>
vector<T, Allocator>::vector( const vector<T, Allocator> & other ) :
                        ::ft::_Vector_base<T, Allocator>::_Vector_base(other._alloc) {
    operator=(other);
}

template <class T, class Allocator>
vector<T, Allocator>& vector<T, Allocator>::operator=(const vector<T, Allocator>& other) {
    if (this == &other) {
        return (*this);
    }
    clear();
    if (_capacity) {
        ::ft::_Vector_base<T, Allocator>::_alloc.deallocate(_arr, _capacity);
    }
    _size = other.size();
    _capacity = other.capacity();
    ::ft::_Vector_base<T, Allocator>::_alloc = other._alloc;
    for (int i = 0; (size_type)i < _size; ++i) {
        ::ft::_Vector_base<T, Allocator>::_alloc.construct(&_arr[i], other._arr[i]);
    }
    _arr_end = _arr + _size;
    return (*this);
}

    // Element access

template <class T, class Allocator>
T &         vector<T, Allocator>::operator[](int i) {
    return (_arr[i]);
}

template <class T, class Allocator>
T* 
    vector<T, Allocator>::data() {
        return (_arr);
    }

    // Iterators

template <class T, class Allocator>
typename vector<T, Allocator>::iterator 
    vector<T, Allocator>::begin() const {
    return (iterator(_arr));
}

template <class T, class Allocator>
typename vector<T, Allocator>::iterator 
    vector<T, Allocator>::end() const {
    return (iterator(_arr_end));
}

    // Capacity

template <class T, class Allocator>
typename vector<T, Allocator>::size_type
vector<T, Allocator>::size() const {
    return (_size);
}

template <class T, class Allocator>
typename vector<T, Allocator>::size_type
    vector<T, Allocator>::max_size() const {
        return (::ft::_Vector_base<T, Allocator>::_alloc.max_size());
    }

template <class T, class Allocator>
typename vector<T, Allocator>::size_type
    vector<T, Allocator>::capacity() const {
    return (_capacity);
}

    // Modifiers

template <class T, class Allocator>
void vector<T, Allocator>::clear() {
    erase(begin(), end());
}

template <class T, class Allocator>
    template< class InputIt >
    void vector<T, Allocator>::insert( iterator pos, InputIt first, InputIt last ) {
        size_type count = static_cast<size_type>(::ft::distance(first, last));
        if (!count) {
            return ;
        }
        if (max_size() - _size < count) {
            throw std::length_error("length_error: Oops...exception. vector is too long.\n");
        } else if (_capacity - _size < count) {
            insert_too_small_capacity(pos, count, (iterator)first);
        } else if ((size_type)(end() - pos) < count) {
            insert_count_more_than_end_to_pos(pos, count, (iterator)first);
        } else {
            insert_count_less_than_end_to_pos(pos, count, (iterator)first);
        }
    }

template <class T, class Allocator>
typename vector<T, Allocator>::iterator
    vector<T, Allocator>::erase( vector<T, Allocator>::iterator first, 
                                 vector<T, Allocator>::iterator last ) {
    iterator first_copy = first;
    for (; last != end(); ++first_copy, ++last) {
        *first_copy = *last;
    }
    for ( ; first_copy != end(); ++first_copy) {
        ::ft::_Vector_base<T, Allocator>::_alloc.destroy(first_copy.base());
        --_size;
    }
    _arr_end = _arr + _size;
    return (first);
}

/* operators */

// /* Get and show atributs */

// // template <class T, class Allocator>
// // typename vector<T, Allocator>::allocator_type vector<T, Allocator>::alloc() const {
// //     return (_allocator);
// // }

// // template <class T, class Allocator>
// // void vector<T, Allocator>::push_back(const T& x) {
// //     // std::cout << "test push_back _size = " << _size << ", _capacity = " << _capacity << "\n";
// //     if (_size == _capacity) {
// //         memoryIncrease();
// //     }
// //     _arr[_size++] = x;
// //     // std::cout << "test _arr[_size - 1] = " << _arr[_size - 1] << std::endl;
// // }

// // template <class T, class Allocator>
// // void vector<T, Allocator>::memoryIncrease() {
// //     T* tmp = _arr;
// //     if (_capacity) {
// //         _capacity *= 2;
// //     } else {
// //         ++_capacity;
// //     }
// //     // std::cout << _size << std::endl;
// //     // std::cout << "test 1\n";
// //     _arr = _allocator.allocate(_capacity);
// //     // std::cout << "test 2\n";
// //     for (int i = 0; i < (int)_size; ++i) {
// //     //     std::cout << "test 3 i = " << i << "\n";
// //     //     std::cout << "test 3 tmp[i] = " << tmp[i] << "\n";
// //     //     std::cout << "test 3 _arr[i].capacity() = " << _arr[i].capacity() << "\n";
// //     //     std::cout << "test 3 _arr[i] befor "
// //     //               << "\n";
// //         _arr[i] = tmp[i];
// //     }

// //     _allocator.clear();
// //     _allocator.deallocate(tmp, _size);
// // }

    // private

template <class T, class Allocator>
void
    vector<T, Allocator>::insert_too_small_capacity(iterator & pos, size_type & count, iterator first) {
    size_type count_capacity = _capacity;
    // increase _capacity
    if (!_capacity) {
        _capacity = count;
    } else if (_capacity * 2 < max_size()) {
        _capacity *= 2;
    } else {
        _capacity = max_size();
    }
    pointer tmp_capacity = ::ft::_Vector_base<T, Allocator>::_alloc.allocate(_capacity);
    pointer tmp_current;
    try {
        // copy part befor insert/pasting
        tmp_current = _arr == 0 ? tmp_capacity : copy(static_cast<iterator>(_arr), pos, tmp_capacity);
        // copying the part that is located after pasting (after pos).
        int i = 0;
        try {
            for (; (size_type)i < count; ++i, ++first) {
                ::ft::_Vector_base<T, Allocator>::_alloc.construct(tmp_current++, *first);
            }

        } catch (...) {
            for (; i--;) {
                ::ft::_Vector_base<T, Allocator>::_alloc.destroy(--tmp_current);
                }
            throw;
        }
        // copy part after insert/pasting
        copy(pos, end(), tmp_current);
    } catch (...) {
        for (; tmp_current-- != tmp_capacity;) {
            ::ft::_Vector_base<T, Allocator>::_alloc.destroy(tmp_current);
        }
        ::ft::_Vector_base<T, Allocator>::_alloc.deallocate(tmp_capacity, _capacity);
        throw;
    }
    // freeing the old array
    if (_arr != 0) {
        for (iterator start = begin(); start != end(); ++start) {
            ::ft::_Vector_base<T, Allocator>::_alloc.destroy(start.base());
        }
        ::ft::_Vector_base<T, Allocator>::_alloc.deallocate(_arr, count_capacity);
    }
    // new private values
    _size += count;
    _arr = tmp_capacity;
    _arr_end = _arr + _size;
}

template <class T, class Allocator>
void 
    vector<T, Allocator>::
    insert_count_more_than_end_to_pos(iterator & pos, size_type & count, iterator first) {
    // 1) transfer values from pos to pos + count (not previously initialized)
    copy(pos, end(), pos.base() + count);
    // 2) insert value in a place befor old end() (was construct)
    size_type i = 0;
    size_type count_with_init = ::ft::distance(pos, end());
    for (; i <= count_with_init; ++first) {
        pos[(int)i++] = *first;
    }
    // 3) insert value in a place where there was no construct before (only allocate)
    try {
        size_type to_construct = count - count_with_init;
        for (;i < to_construct; ++i, ++first) {
            ::ft::_Vector_base<T, Allocator>::_alloc.construct(pos.base() + i, *first);
        }
    } catch (...) {
        for (; i--;) {
            ::ft::_Vector_base<T, Allocator>::_alloc.destroy(pos.base() + i);
        }            
        throw;
    }
    _size += count;
    _arr_end += count;
}

template <class T, class Allocator>
void 
    vector<T, Allocator>::
    insert_count_less_than_end_to_pos(iterator & pos, size_type & count, iterator first) {
    // move "count" positions before end() to position after end() (with construct)
    copy(end() - count, end(), end().base());
    // move the remaining values in the range from "pos" to "end() - count" 
    // by "count" positions to the right (near the end)
    std::copy_backward(pos, end() - count, end());
    // fill in insert positions
    for (size_type i = 0; i < count; ++first) {
        pos[(int)i++] = *first;
    }
    _size += count;
    _arr_end += count;
}

template <class T, class Allocator>
typename vector<T, Allocator>::pointer 
    vector<T, Allocator>::copy(iterator first, iterator last, pointer for_copy) {
    int i = 0;
    try {
        for (; first != last;) {
            ::ft::_Vector_base<T, Allocator>::_alloc.construct(for_copy++, *first++);
        }
    } catch (...) {
        for (; i--;) {
            ::ft::_Vector_base<T, Allocator>::_alloc.destroy(for_copy--);
            }
        throw;
    }
    return (for_copy);
}

} // namespace ft

#endif
