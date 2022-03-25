#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <memory>
#include <ft_iterator.hpp>
#include <stdexcept>

// убрать
// #include <vector>

namespace ft {

template<typename _Tp, typename _Alloc>
class _Vector_base {
    protected:
    typedef typename _Alloc::template
	rebind<_Tp>::other _Tp_alloc_type;
    _Tp_alloc_type _alloc;
    _Vector_base(_Alloc alloc = _Alloc()) : _alloc(alloc) {}
};

template <
    class T,
    class Allocator = ::std::allocator<T> >

class vector : public _Vector_base<T, Allocator> {
    public:

    typedef T value_type;
    typedef typename ::ft::_Vector_base<T, Allocator>::_Tp_alloc_type    allocator_type;
    // typedef Allocator                                   allocator_type;
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

    void    insert_too_small_capacity(iterator & pos, size_type & count, const T& value);
    void    insert_count_more_than_end_to_pos(iterator & pos, size_type & count, const T& value);
    pointer copy(iterator first, iterator last, pointer copy_to);

    public:
    /* Constructs and destructs*/
    explicit vector();
    explicit vector(const allocator_type& alloc);
    explicit vector(size_type count, const value_type& val = value_type(),
                    const allocator_type& alloc = allocator_type());
    template <class InputIt>
        vector(InputIt first, InputIt last, const Allocator& alloc = Allocator()) :
                            ::ft::_Vector_base<T, Allocator>::_Vector_base(alloc),
                                _size(0),
                                _capacity(0),
                                _arr(NULL),
                                _arr_end(NULL) {
            Construct(first, last, Iter_cat(first));
        }
    template <class InputIt>
        void    Construct(InputIt first, InputIt last, int_iterator_tag) {
            size_type _size = (size_type)first;
            if (_size != 0) {
                _capacity = _size;
                _arr = ::ft::_Vector_base<T, Allocator>::_alloc.allocate(_size);
                _arr_end = _arr + _size;
                size_type i = 0;
                try {
                    for (; i < _size; ++i) {
                        ::ft::_Vector_base<T, Allocator>::_alloc.construct(_arr + (int)i, (value_type)last);
                    }
                    } catch (...) {
                        for (; i--;) {
                            ::ft::_Vector_base<T, Allocator>::_alloc.destroy(_arr + (int)i);
                        }
                        throw;
                    }
            }
    }

    template <class InputIt>
        void    Construct(InputIt first, InputIt last, input_iterator_tag) {
            insert(begin(), first, last);
    }

    ~vector(void) {}

    /* operators */
    vector<T, Allocator>& operator=(const vector<T, Allocator>& obj);
    T &         operator[](int i);
    /* Set atributs */
    /* Get and show atributs */
    size_t         size() const;
    size_type      max_size() const;
    size_t         capacity() const;
    allocator_type alloc() const;
    iterator       begin() const;
    iterator       end() const;

    /* other methods */
    void    clear();
    void    push_back(const T& x);
    void    memoryIncrease();
    void    insert( iterator pos, size_type count, const T& value );
    template <class InputIt>
        void    insert(iterator pos, InputIt first, InputIt last) {
            insert(pos, first, last, Iter_cat(first));
        }
    template <class InputIt>
        void    insert(iterator pos, InputIt first, InputIt last, int_iterator_tag) {
            insert(pos, (size_type)first, (value_type)last);
        }
};

/******************************************************************************/
/* Constructors */

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

/* operators */
// template <class T, class Allocator>
// vector<T, Allocator>& vector<T, Allocator>::operator=(const vector<T, Allocator>& obj) {
//     if (this == &obj) {
//         return (*this);
//     }
//     clear();
//     if (_capacity) {
//         _allocator.deallocate(_arr, _capacity);
//     }
//     _size = obj.size();
//     _capacity = obj.capacity();
//     _allocator = obj.alloc();
//     for (int i = 0; i < _size; ++i) {
//         _allocator.construct(_arr[i], obj._arr[i]);
//     }
//     return (*this);
// }

template <class T, class Allocator>
T &         vector<T, Allocator>::operator[](int i) {
    return (_arr[i]);
}

/* Get and show atributs */

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

// template <class T, class Allocator>
// typename vector<T, Allocator>::allocator_type vector<T, Allocator>::alloc() const {
//     return (_allocator);
// }

template <class T, class Allocator>
typename vector<T, Allocator>::iterator 
    vector<T, Allocator>::begin() const {
    return (iterator(_arr));
}

template <class T, class Allocator>
typename vector<T, Allocator>::iterator 
    vector<T, Allocator>::end() const {
    return (iterator(&_arr[_size]));
}

/* other methods */

template <class T, class Allocator>
void 
    vector<T, Allocator>::insert(iterator pos, size_type count, const T& value) {
    if (!count) {
        return ;
    }
    // T   T_value = value;
    // size_type count_capacity = capacity();
    // size_type maxSize = max_size();
    if (max_size() - _size < count) {
        throw std::length_error("length_error: Oops...exception. vector is too long.\n");
    } else if (_capacity - _size < count) {
        insert_too_small_capacity(pos, count, value);
    } else if ((size_type)(end() - pos) < count) {
        insert_count_more_than_end_to_pos();
    } else {
        
    }
}

template <class T, class Allocator>
void 
    vector<T, Allocator>::insert_too_small_capacity(iterator & pos, size_type & count, const T& value) {
    size_type count_capacity = _capacity;
    if (_capacity * 2 < max_size()) {
        _capacity *= 2;
    } else {
        _capacity = max_size();
    }
    pointer tmp_capacity = ::ft::_Vector_base<T, Allocator>::_alloc.allocate(_capacity);
    pointer tmp_current;
    try {
        // copy part befor insert/pasting
        tmp_current = copy(_arr, pos, tmp_capacity);
        // copy pasted part
        int i = 0; 
        try {
            for (; i < count; ++i) {
                ::ft::_Vector_base<T, Allocator>::_alloc.construct(tmp_current + i, value);
            }
        } catch (...) {
            for (; i--;) {
                ::ft::_Vector_base<T, Allocator>::_alloc.destroy(tmp_current++);
                }
            throw;
        }
        // copy part after insert/pasting
        copy(pos, end(), tmp_capacity);
    } catch (...) {
        for (; tmp_current-- != tmp_capacity;) {
            ::ft::_Vector_base<T, Allocator>::_alloc.destroy(tmp_current);
        }
        ::ft::_Vector_base<T, Allocator>::_alloc.deallocate(tmp_capacity, _capacity);
        throw;
    }
    // freeing the old array
    if (_arr != 0) {
        for (pointer start = begin(); start != end(); ++start) {
            ::ft::_Vector_base<T, Allocator>::_alloc.destroy(start);
        }
        ::ft::_Vector_base<T, Allocator>::_alloc.deallocate(_arr, count_capacity);
    }
    _arr = tmp_capacity;
    _size += count;
}

template <class T, class Allocator>
void 
    vector<T, Allocator>::insert_count_more_than_end_to_pos(iterator & pos, size_type & count, const T& value) {
    // 1) transfer values from pos to pos + count (not previously initialized)
    copy(pos, end(), pos.base() + count);
    // 2) insert value in a place where there was no construct before (only allocate)
    size_type i = 0;
    try {
        pointer tmp_current = end();
        try {
            size_type to_construct = count - (end() - pos);
            for (;i < to_construct; ++i) {
                ::ft::_Vector_base<T, Allocator>::_alloc.construct(tmp_current + i, value);
            }
        } catch (...) {
            for (; i--;) {
                ::ft::_Vector_base<T, Allocator>::_alloc.destroy(tmp_current + i);
            }            
            throw;
        }
    } catch (...) {
        for (i = 0; i < count; ++i) {
            ::ft::_Vector_base<T, Allocator>::_alloc.destroy(end() + i);
        }
        throw;
    }
    _size += count;
    std::fill(pos, pos + count, value);
}

template <class T, class Allocator>
typename vector<T, Allocator>::pointer 
    vector<T, Allocator>::copy(iterator first, iterator last, pointer for_copy) {
    int i = 0; 
    try {
        for (; first != last; ++first, ++i) {
            ::ft::_Vector_base<T, Allocator>::_alloc.construct(for_copy + i, *first);
        }
    } catch (...) {
        for (; i--;) {
            ::ft::_Vector_base<T, Allocator>::_alloc.destroy(for_copy++);
            }
        throw;
    }
    return (for_copy);
}


// template <class T, class Allocator>
// void vector<T, Allocator>::clear() {
//     for (int i = 0; i < _size; ++i) {
//         // _arr.destroy(_arr[i]);
//     }
//     _size = 0;
// }

// template <class T, class Allocator>
// void vector<T, Allocator>::push_back(const T& x) {
//     // std::cout << "test push_back _size = " << _size << ", _capacity = " << _capacity << "\n";
//     if (_size == _capacity) {
//         memoryIncrease();
//     }
//     _arr[_size++] = x;
//     // std::cout << "test _arr[_size - 1] = " << _arr[_size - 1] << std::endl;
// }

// template <class T, class Allocator>
// void vector<T, Allocator>::memoryIncrease() {
//     T* tmp = _arr;
//     if (_capacity) {
//         _capacity *= 2;
//     } else {
//         ++_capacity;
//     }
//     // std::cout << _size << std::endl;
//     // std::cout << "test 1\n";
//     _arr = _allocator.allocate(_capacity);
//     // std::cout << "test 2\n";
//     for (int i = 0; i < (int)_size; ++i) {
//     //     std::cout << "test 3 i = " << i << "\n";
//     //     std::cout << "test 3 tmp[i] = " << tmp[i] << "\n";
//     //     std::cout << "test 3 _arr[i].capacity() = " << _arr[i].capacity() << "\n";
//     //     std::cout << "test 3 _arr[i] befor "
//     //               << "\n";
//         _arr[i] = tmp[i];
//     }

//     _allocator.clear();
//     _allocator.deallocate(tmp, _size);
// }

}; // namespace ft

//      init

#endif

// public:
//  +   typedef T                                        value_type;
//  +   typedef Allocator                                allocator_type;
//  +   typedef typename allocator_type::size_type       size_type;
//  +   typedef typename allocator_type::reference       reference;
//  +   typedef typename allocator_type::const_reference const_reference;
//  +   typedef typename allocator_type::difference_type difference_type;
//  +   typedef typename allocator_type::pointer         pointer;
//  +   typedef typename allocator_type::const_pointer   const_pointer;
//  +   typedef implementation-defined                   iterator;
//  +   typedef implementation-defined                   const_iterator;
//  +   typedef std::reverse_iterator<iterator>          reverse_iterator;
//  +   typedef std::reverse_iterator<const_iterator>    const_reverse_iterator;
//
//     vector()
//         noexcept(is_nothrow_default_constructible<allocator_type>::value);
//     explicit vector(const allocator_type&);
//     explicit vector(size_type n);
//     explicit vector(size_type n, const allocator_type&); // C++14
//     vector(size_type n, const value_type& value, const allocator_type& = allocator_type());
//     template <class InputIterator>
//         vector(InputIterator first, InputIterator last, const allocator_type& = allocator_type());
//     vector(const vector& x);
//     vector(vector&& x)
//         noexcept(is_nothrow_move_constructible<allocator_type>::value);
//     vector(initializer_list<value_type> il);
//     vector(initializer_list<value_type> il, const allocator_type& a);
//     ~vector();
//     vector& operator=(const vector& x);
//     vector& operator=(vector&& x)
//         noexcept(
//              allocator_type::propagate_on_container_move_assignment::value ||
//              allocator_type::is_always_equal::value); // C++17
//     vector& operator=(initializer_list<value_type> il);
//     template <class InputIterator>
//         void assign(InputIterator first, InputIterator last);
//     void assign(size_type n, const value_type& u);
//     void assign(initializer_list<value_type> il);
//
//     allocator_type get_allocator() const noexcept;
//
//     iterator               begin() noexcept;
//     const_iterator         begin()   const noexcept;
//     iterator               end() noexcept;
//     const_iterator         end()     const noexcept;
//
//     reverse_iterator       rbegin() noexcept;
//     const_reverse_iterator rbegin()  const noexcept;
//     reverse_iterator       rend() noexcept;
//     const_reverse_iterator rend()    const noexcept;
//
//     const_iterator         cbegin()  const noexcept;
//     const_iterator         cend()    const noexcept;
//     const_reverse_iterator crbegin() const noexcept;
//     const_reverse_iterator crend()   const noexcept;
//
//     size_type size() const noexcept;
//     size_type max_size() const noexcept;
//     size_type capacity() const noexcept;
//     bool empty() const noexcept;
//     void reserve(size_type n);
//     void shrink_to_fit() noexcept;
//
//     reference       operator[](size_type n);
//     const_reference operator[](size_type n) const;
//     reference       at(size_type n);
//     const_reference at(size_type n) const;
//
//     reference       front();
//     const_reference front() const;
//     reference       back();
//     const_reference back() const;
//
//     value_type*       data() noexcept;
//     const value_type* data() const noexcept;
//
//     void push_back(const value_type& x);
//     void push_back(value_type&& x);
//     template <class... Args>
//         reference emplace_back(Args&&... args); // reference in C++17
//     void pop_back();
//
//     template <class... Args> iterator emplace(const_iterator position, Args&&... args);
//     iterator insert(const_iterator position, const value_type& x);
//     iterator insert(const_iterator position, value_type&& x);
//     iterator insert(const_iterator position, size_type n, const value_type& x);
//     template <class InputIterator>
//         iterator insert(const_iterator position, InputIterator first, InputIterator last);
//     iterator insert(const_iterator position, initializer_list<value_type> il);
//
//     iterator erase(const_iterator position);
//     iterator erase(const_iterator first, const_iterator last);
//
//     void clear() noexcept;
//
//     void resize(size_type sz);
//     void resize(size_type sz, const value_type& c);
//
//     void swap(vector&)
//         noexcept(allocator_traits<allocator_type>::propagate_on_container_swap::value ||
//                  allocator_traits<allocator_type>::is_always_equal::value);  // C++17
//
//     bool __invariants() const;