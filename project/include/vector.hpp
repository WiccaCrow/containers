#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <memory>
#include <iterator.hpp>
#include <stdexcept>
#include <lexicographical_compare.hpp>

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

    typedef ft::normal_iterator< ::std::random_access_iterator_tag, T>       iterator;
    typedef ft::normal_iterator< ::std::random_access_iterator_tag, const T> const_iterator;
    typedef ft::reverse_iterator<iterator>                           reverse_iterator;
    typedef ft::reverse_iterator<const_iterator>                     const_reverse_iterator;

    private:
    size_t    _size;
    size_t    _capacity;
    pointer   _arr;
    pointer   _arr_end;

    template< class InputIt >
        void    construct_base( iterator pos, InputIt first, InputIt last, ::std::input_iterator_tag );
    template< class InputIt >
        void    construct_base( iterator pos, InputIt first, InputIt last, int_iterator_tag );
    void vector_val(size_type count, const value_type& val);

    template< class InputIt >
        void    insert( iterator pos, InputIt first, InputIt last, ::std::input_iterator_tag );
    template< class InputIt >
        void    insert_base( iterator pos, InputIt first, InputIt last, ::std::input_iterator_tag );
    template< class InputIt >
        void    insert( iterator pos, InputIt first, InputIt last, int_iterator_tag );
    template< class InputIt >
        void    insert_base( iterator pos, InputIt first, InputIt last, int_iterator_tag );
    void    insert_not_iterator( iterator pos, size_type count, const T& value );
    void    increase_capacity(size_type & count);
    void    insert_too_small_capacity(iterator & pos, size_type & count, const T& value);
    template< class InputIt >
        void    insert_too_small_capacity(iterator & pos, size_type & count, InputIt first);
    void    insert_count_more_than_end_to_pos(iterator & pos, size_type & count, const T& value);
    template< class InputIt >
        void    insert_count_more_than_end_to_pos(iterator & pos, size_type & count, InputIt first, std::input_iterator_tag);
    void    insert_count_less_than_end_to_pos(iterator & pos, size_type & count, const T& value);
    template< class InputIt >
        void    insert_count_less_than_end_to_pos(iterator & pos, size_type & count, InputIt first, std::input_iterator_tag);
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
    ~vector();
    vector<T, Allocator>& operator=(const vector<T, Allocator>& other);
    void assign( size_type count, const T& value );
    template< class InputIt >
        void assign( InputIt first, InputIt last );
    allocator_type get_allocator() const;

    // Element access
    reference at( size_type pos );
    const_reference at( size_type pos ) const;
    reference       operator[]( size_type i );
    const_reference operator[]( size_type pos ) const;
    reference       front();
    const_reference front() const;
    reference       back();
    const_reference back() const;
    T*              data();

    // Iterators
    iterator       begin();
    const_iterator begin() const;
    iterator       end();
    const_iterator end() const;
    reverse_iterator rbegin();
    const_reverse_iterator rbegin() const;
    reverse_iterator rend();
    const_reverse_iterator rend() const;

    // Capacity
    bool           empty() const;
    size_t         size() const;
    size_type      max_size() const;
    void           reserve( size_type new_cap );
    size_t         capacity() const;
    
    // Modifiers
    void     clear();
    iterator insert( iterator pos, const T& value );
    void     insert( iterator pos, size_type count, const T& value );
    template< class InputIt >
        void    insert( iterator pos, InputIt first, InputIt last );
    iterator erase( iterator pos );
    iterator erase( iterator first, iterator last );
    void     push_back( const T& value );
    void     pop_back( );
    void     resize( size_type count, T value = T() );
    void     swap( vector& other );
};

    //////////////////////////
    // Non-member functions //
    //////////////////////////

template< class T, class Alloc >
bool operator==( const ::ft::vector<T,Alloc>& lhs,
                 const ::ft::vector<T,Alloc>& rhs );

template< class T, class Alloc >
bool operator!=( const ::ft::vector<T,Alloc>& lhs,
                 const ::ft::vector<T,Alloc>& rhs );

template< class T, class Alloc >
bool operator<( const ::ft::vector<T,Alloc>& lhs,
                const ::ft::vector<T,Alloc>& rhs );

template< class T, class Alloc >
bool operator<=( const ::ft::vector<T,Alloc>& lhs,
                 const ::ft::vector<T,Alloc>& rhs );

template< class T, class Alloc >
bool operator>( const ::ft::vector<T,Alloc>& lhs,
                const ::ft::vector<T,Alloc>& rhs );

template< class T, class Alloc >
bool operator>=( const ::ft::vector<T,Alloc>& lhs,
                 const ::ft::vector<T,Alloc>& rhs );

template< class T, class Alloc >
void swap( ft::vector<T,Alloc>& lhs,
           ft::vector<T,Alloc>& rhs );

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
    vector_val(count, val);
}

template <class T, class Allocator>
template <class InputIt>
    vector<T, Allocator>::vector(InputIt first, InputIt last, const Allocator& alloc) :
                        ::ft::_Vector_base<T, Allocator>::_Vector_base(alloc),
                        _size(0),
                        _capacity(0),
                        _arr(NULL),
                        _arr_end(NULL) {
    construct_base(begin(), first, last, Iter_cat(first));
}

template <class T, class Allocator>
vector<T, Allocator>::vector( const vector<T, Allocator> & other ) :
                        ::ft::_Vector_base<T, Allocator>::_Vector_base(other._alloc),
                        _size(0),
                        _capacity(0),
                        _arr(NULL),
                        _arr_end(NULL) {
    operator=(other);
}

template <class T, class Allocator>
vector<T, Allocator>::~vector() {
    if (_size != 0) {
        for (; _arr_end-- != _arr;) {
            this->_alloc.destroy(_arr_end);
        }
    }

    _size = 0;
    if (_capacity != 0) {
        this->_alloc.deallocate(_arr, _capacity);
        _capacity = 0;
        _arr = _arr_end = NULL;
    }
}

template <class T, class Allocator>
vector<T, Allocator>& 
    vector<T, Allocator>::
    operator=(const vector<T, Allocator>& other) {
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
    _arr = ::ft::_Vector_base<T, Allocator>::_alloc.allocate(_capacity);
    for (int i = 0; static_cast<size_type>(i) < _size; ++i) {
        ::ft::_Vector_base<T, Allocator>::_alloc.construct(&_arr[i], other._arr[i]);
    }
    _arr_end = _arr + _size;
    return (*this);
}

template <class T, class Allocator>
void 
    vector<T, Allocator>::
    assign( size_type count, const T& value ) {
        erase(begin(), end());
        insert_not_iterator(begin(), count, value);
    }


template <class T, class Allocator>
template< class InputIt >
void
    vector<T, Allocator>::
    assign( InputIt first, InputIt last ) {
    erase(begin(), end());
    construct_base(begin(), first, last, Iter_cat(first));
}

template <class T, class Allocator>
typename vector<T, Allocator>::allocator_type 
    vector<T, Allocator>::
    get_allocator() const {
        return (::ft::_Vector_base<T, Allocator>::_alloc);
}

    // Element access

template <class T, class Allocator>
typename vector<T, Allocator>::reference 
    vector<T, Allocator>::
    at( size_type pos ) {
    if (_size < pos) {
        throw std::out_of_range("out_of_range: Oops...exception. pos value too high.\n");
    }
    return (_arr[pos]);
}

template <class T, class Allocator>
typename vector<T, Allocator>::const_reference 
    vector<T, Allocator>::
    at( size_type pos ) const {
    if (_size < pos) {
        throw std::out_of_range("out_of_range: Oops...exception. pos value too high.\n");
    }
    return (_arr[pos]);
}

template <class T, class Allocator>
typename vector<T, Allocator>::reference
    vector<T, Allocator>::
    operator[](size_type i) {
    return (_arr[i]);
}

template <class T, class Allocator>
typename vector<T, Allocator>::const_reference
    vector<T, Allocator>::
    operator[](size_type i) const {
    return (_arr[i]);
}

template <class T, class Allocator>
typename vector<T, Allocator>::reference 
    vector<T, Allocator>::front() {
        return (_arr[0]);
}

template <class T, class Allocator>
typename vector<T, Allocator>::const_reference 
    vector<T, Allocator>::front() const {
        return (_arr[0]);
}

template <class T, class Allocator>
typename vector<T, Allocator>::reference 
    vector<T, Allocator>::back() {
        return (_arr[_size - 1]);
}

template <class T, class Allocator>
typename vector<T, Allocator>::const_reference 
    vector<T, Allocator>::back() const {
        return (_arr[_size - 1]);
}

template <class T, class Allocator>
T* 
    vector<T, Allocator>::
    data() {
        return (_arr);
}

    // Iterators

template <class T, class Allocator>
typename vector<T, Allocator>::iterator 
    vector<T, Allocator>::
    begin() {
    return (iterator(_arr));
}

template <class T, class Allocator>
typename vector<T, Allocator>::const_iterator 
    vector<T, Allocator>::
    begin() const {
    return (const_iterator(_arr));
}

template <class T, class Allocator>
typename vector<T, Allocator>::iterator 
    vector<T, Allocator>::
    end() {
    return (iterator(_arr_end));
}

template <class T, class Allocator>
typename vector<T, Allocator>::const_iterator 
    vector<T, Allocator>::
    end() const {
    return (const_iterator(_arr_end));
}

template <class T, class Allocator>
typename vector<T, Allocator>::reverse_iterator 
    vector<T, Allocator>::
    rbegin() {
    return (reverse_iterator(end()));
}

template <class T, class Allocator>
typename vector<T, Allocator>::const_reverse_iterator 
    vector<T, Allocator>::
    rbegin() const {
    return (const_reverse_iterator(end()));
}

template <class T, class Allocator>
typename vector<T, Allocator>::reverse_iterator 
    vector<T, Allocator>::
    rend() {
    return (reverse_iterator(begin()));
}

template <class T, class Allocator>
typename vector<T, Allocator>::const_reverse_iterator 
    vector<T, Allocator>::
    rend() const {
    return (const_reverse_iterator(begin()));
}

    // Capacity

template <class T, class Allocator>
bool
    vector<T, Allocator>::
    empty() const {
    return (!_size);
}


template <class T, class Allocator>
typename vector<T, Allocator>::size_type
    vector<T, Allocator>::
    size() const {
    return (_size);
}

template <class T, class Allocator>
typename vector<T, Allocator>::size_type
    vector<T, Allocator>::
    max_size() const {
        return (::ft::_Vector_base<T, Allocator>::_alloc.max_size());
    }

template <class T, class Allocator>
void
    vector<T, Allocator>::
    reserve( size_type new_cap ) {
    if (new_cap <= _capacity) {
        return ;
    }
    T* arr_new = get_allocator().allocate(new_cap);
    for (int i = 0; static_cast<size_type>(i) < _size ; ++i) {
        get_allocator().construct(arr_new + i, _arr[i]);
        get_allocator().destroy(_arr + i);
    }
    get_allocator().deallocate(_arr, _capacity);
    _arr = arr_new;
    _arr_end = _arr + _size;
    _capacity = new_cap;
}

template <class T, class Allocator>
typename vector<T, Allocator>::size_type
    vector<T, Allocator>::
    capacity() const {
    return (_capacity);
}

    // Modifiers

template <class T, class Allocator>
void 
    vector<T, Allocator>::
    clear() {
    erase(begin(), end());
}

template <class T, class Allocator>
typename vector<T, Allocator>::iterator 
    vector<T, Allocator>::
    insert( iterator pos, const T& value ) {
    size_type dist_pos = ::std::distance(begin(), pos);
    insert_not_iterator(pos, 1, value );
    return (begin() + dist_pos);
}

template <class T, class Allocator>
void 
    vector<T, Allocator>::
    insert( iterator pos, 
            size_type count, 
            const T& value ) {
    insert_not_iterator(pos, count, value );
}

template <class T, class Allocator>
    template< class InputIt >
    void 
        vector<T, Allocator>::
        insert( iterator pos, InputIt first, InputIt last ) {
            insert(pos, first, last, Iter_cat(first));
}

template <class T, class Allocator>
typename vector<T, Allocator>::iterator
    vector<T, Allocator>::
    erase( iterator pos ) {
    return (erase(pos, pos + 1));
}

template <class T, class Allocator>
typename vector<T, Allocator>::iterator
    vector<T, Allocator>::
    erase( vector<T, Allocator>::iterator first, 
           vector<T, Allocator>::iterator last ) {
    if (first == last || _arr == NULL || _size == 0) {
        return (first);
    }
    iterator first_copy = first;
    for (; last != end(); ++first_copy, ++last) {
        *first_copy = *last;
    }
    for ( ; _size != 0 && first_copy != end(); ++first_copy) {
        ::ft::_Vector_base<T, Allocator>::_alloc.destroy(first_copy.base());
        --_size;
    }
    _arr_end = _arr + _size;
    return (first);
}

template <class T, class Allocator>
void
    vector<T, Allocator>::
    push_back( const T& value ) {
    insert(end(), value);
}

template <class T, class Allocator>
void
    vector<T, Allocator>::
    pop_back( ) {
    if (_arr == NULL) {
        return ;
    }
    erase(end() - 1, end());
}

template <class T, class Allocator>
void
    vector<T, Allocator>::
    resize( size_type count, T value ) {
    if (_size < count) {
        insert(end(), count - _size, value);
    } else if (count < _size) {
        erase(iterator(_arr + count), end());
    }
}

template <class T, class Allocator>
void
    vector<T, Allocator>::
    swap( vector& other ) {
        vector tmp = *this;
        *this = other;
        other = tmp;
}

    // private

////// for constructors

template <class T, class Allocator>
void
vector<T, Allocator>::vector_val(size_type count, const value_type& val) {
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
    _arr_end = _arr + _size;
}

template <class T, class Allocator>
    template< class InputIt >
    void 
        vector<T, Allocator>::
        construct_base( iterator pos, InputIt first, InputIt last, ::std::input_iterator_tag ) {
        size_type count = static_cast<size_type>(::std::distance(first, last));
        if (!count) {
            return ;
        }
        if (max_size() - _size < count) {
            throw std::length_error("length_error: Oops...exception. vector is too long.\n");
        } else if (_capacity - _size < count) {
            insert_too_small_capacity(pos, count, first);
        }
}

template <class T, class Allocator>
template< class InputIt >
void 
    vector<T, Allocator>::
    construct_base( iterator pos, InputIt first, InputIt last, int_iterator_tag ) {
    size_type count = (size_type)first;
    T value = (T)last;
    if (!count) {
        return ;
    }
    if (max_size() - _size < count) {
        throw std::length_error("length_error: Oops...exception. vector is too long.\n");
    } else {
        insert_too_small_capacity(pos, count, value);
    }
}

////// for insert

template <class T, class Allocator>
void
    vector<T, Allocator>::
    insert_not_iterator( iterator pos, 
                         size_type count, 
                         const T& value ) {
    if (!count) {
        return ;
    }    
    if (max_size() - _size < count) {
        throw std::length_error("length_error: Oops...exception. vector is too long.\n");
    } else if (_capacity - _size < count) {
        insert_too_small_capacity(pos, count, value);
    } else if ((size_type)(end() - pos) < count) {
        insert_count_more_than_end_to_pos(pos, count, value);
    } else {
        insert_count_less_than_end_to_pos(pos, count, value);
    }
}

template <class T, class Allocator>
template< class InputIt >
void 
    vector<T, Allocator>::
    insert( iterator pos, InputIt first, InputIt last, int_iterator_tag ) {
    size_type count = (size_type)first;
    T value = (T)last;
    if (!count) {
        return ;
    }
    if (max_size() - _size < count) {
        throw std::length_error("length_error: Oops...exception. vector is too long.\n");
    } else {
        insert_too_small_capacity(pos, count, value);
    }
}

template <class T, class Allocator>
    template< class InputIt >
    void 
        vector<T, Allocator>::
        insert_base( iterator pos, InputIt first, InputIt last, int_iterator_tag obj) {
        insert( pos, first, last, obj );
}

template <class T, class Allocator>
    template< class InputIt >
    void 
        vector<T, Allocator>::
        insert_base( iterator pos, InputIt first, InputIt last, ::std::input_iterator_tag ) {
        insert( pos, first, last, Iter_cat(first) );
}

template <class T, class Allocator>
    template< class InputIt >
    void 
        vector<T, Allocator>::
        insert( iterator pos, InputIt first, InputIt last, ::std::input_iterator_tag tag_obj) {
        size_type count = static_cast<size_type>(::std::distance(first, last));
        if (!count) {
            return ;
        }
        if (max_size() - _size < count) {
            throw std::length_error("length_error: Oops...exception. vector is too long.\n");
        } else if (_capacity - _size < count) {
            insert_too_small_capacity(pos, count, first);
        } else if ((size_type)(end() - pos) < count) {
            insert_count_more_than_end_to_pos(pos, count, first, tag_obj);
        } else {
            insert_count_less_than_end_to_pos(pos, count, first, tag_obj);
        }
}

template <class T, class Allocator>
void 
    vector<T, Allocator>::
    increase_capacity(size_type & count) {
    if (!_capacity) {
        _capacity = count;
    } else if (_capacity * 2 < max_size()) {
        _capacity *= 2;
    } else {
        _capacity = max_size();
    }
}

template <class T, class Allocator>
void
    vector<T, Allocator>::
    insert_too_small_capacity(iterator & pos, 
                              size_type & count,
                              const T& value ) {
    size_type count_capacity = _capacity;
    increase_capacity(count);
    pointer tmp_capacity = ::ft::_Vector_base<T, Allocator>::_alloc.allocate(_capacity);
    pointer tmp_current;
    try {
        // copy part befor insert/pasting
        tmp_current = _arr == 0 ? tmp_capacity : copy(static_cast<iterator>(_arr), pos, tmp_capacity);
        // copying the part that is located after pasting (after pos).
        int i = 0;
        try {
            for (; (size_type)i < count; ++i) {
                ::ft::_Vector_base<T, Allocator>::_alloc.construct(tmp_current++, value);
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
    // new private/protected values
    _size += count;
    _arr = tmp_capacity;
    _arr_end = _arr + _size;
}

template <class T, class Allocator>
template < class InputIt >
void
    vector<T, Allocator>::
    insert_too_small_capacity(iterator & pos, 
                              size_type & count, 
                              InputIt first) {
    size_type count_capacity = _capacity;
    increase_capacity(count);
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
    insert_count_more_than_end_to_pos(iterator & pos, 
                                      size_type & count, 
                                      const T& value) {
    // 1) transfer values from pos to pos + count (not previously initialized)
    copy(pos, end(), pos.base() + count);
    // 2) insert value in a place befor old end() (was construct)
    iterator pos_copy = pos;
    for (; pos_copy != end() ; ++pos_copy) {
        *pos_copy = value;
    }
    // 3) insert value in a place where there was no construct before (only allocate)
    size_type i = 0;
    try {
        size_type to_construct = ::ft::distance(end(), pos + count);
        for (; i < to_construct; ++i) {
            ::ft::_Vector_base<T, Allocator>::
                _alloc.construct(end().base() + i, value);
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
template< class InputIt >
void
    vector<T, Allocator>::
    insert_count_more_than_end_to_pos(iterator & pos, 
                                      size_type & count, 
                                      InputIt first, 
                                      ::std::input_iterator_tag) {
    // 1) transfer values from pos to pos + count (not previously initialized)
    copy(pos, end(), pos.base() + count);
    // 2) insert value in a place befor old end() (was construct)
    iterator pos_copy = pos;
    for (; pos_copy != end() ; ++first, ++pos_copy) {
        *pos_copy = *first;
    }
    // 3) insert value in a place where there was no construct before (only allocate)
    size_type i = 0;
    try {
        size_type to_construct = ::std::distance(end().base(), pos.base() + count);
        for (; i < to_construct; ++i, ++first) {
            ::ft::_Vector_base<T, Allocator>::
                _alloc.construct(end().base() + i, *first);
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
    insert_count_less_than_end_to_pos(iterator & pos, 
                                      size_type & count, 
                                      const T& value) {
    // move "count" positions before end() to position after end() (with construct)
    copy(end() - count, end(), end().base());
    // move the remaining values in the range from "pos" to "end() - count" 
    // by "count" positions to the right (near the end)
    std::copy_backward(pos, end() - count, end());
    // fill in insert positions
    for (size_type i = 0; i < count; ) {
        pos[(int)i++] = value;
    }
    _size += count;
    _arr_end += count;
}

template <class T, class Allocator>
template< class InputIt >
void 
    vector<T, Allocator>::
    insert_count_less_than_end_to_pos(iterator & pos, 
                                      size_type & count, 
                                      InputIt first, 
                                      ::std::input_iterator_tag) {
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
    vector<T, Allocator>::
    copy(iterator first, iterator last, pointer for_copy) {
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


/******************************************************************************/
    //////////////////////////
    // Non-member functions //
    //////////////////////////

template< class T, class Alloc >
bool operator==( const ::ft::vector<T,Alloc>& lhs,
                 const ::ft::vector<T,Alloc>& rhs ) {
    if (lhs.size() != rhs.size()) {
        return (false);
    }
    for (int i = 0; static_cast<typename ::ft::vector<T,Alloc>::size_type>(i) < lhs.size() ; ++i) {
        if (lhs[i] != rhs[i]) {
            return (false);
        }
    }
    return (true);
}

template< class T, class Alloc >
bool operator!=( const ::ft::vector<T,Alloc>& lhs,
                 const ::ft::vector<T,Alloc>& rhs ) {
    return (!(lhs == rhs));
}

template< class T, class Alloc >
bool operator<( const ::ft::vector<T,Alloc>& lhs,
                const ::ft::vector<T,Alloc>& rhs ) {
    return (::ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
}

template< class T, class Alloc >
bool operator<=( const ::ft::vector<T,Alloc>& lhs,
                 const ::ft::vector<T,Alloc>& rhs ) {
    return (!(rhs < lhs));
}

template< class T, class Alloc >
bool operator>( const ::ft::vector<T,Alloc>& lhs,
                const ::ft::vector<T,Alloc>& rhs ) {
    return (!(lhs <= rhs));
}

template< class T, class Alloc >
bool operator>=( const ::ft::vector<T,Alloc>& lhs,
                 const ::ft::vector<T,Alloc>& rhs ) {
    return (!(lhs < rhs));
}

template< class T, class Alloc >
void swap( ::ft::vector<T,Alloc>& lhs,
           ::ft::vector<T,Alloc>& rhs ) {
    lhs.swap(rhs);
}

} // namespace ft

#endif
