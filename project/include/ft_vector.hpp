#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <ft_iterator.hpp>
#include <memory>

// убрать
// #include <vector>

namespace ft {

template <
    class T,
    class Allocator = std::allocator<T> >

class vector {
    public:
    typedef Allocator                                allocator_type;
    typedef typename allocator_type::size_type       size_type;
    typedef typename allocator_type::reference       reference;
    typedef typename allocator_type::const_reference const_reference;
    typedef typename allocator_type::difference_type difference_type;
    typedef typename allocator_type::pointer         pointer;
    typedef typename allocator_type::const_pointer   const_pointer;
    // переделать std
    // typedef typename std::vector<T>::iterator iterator; // typedef implementation-defined    iterator;
    typedef ft::normal_iterator<pointer, vector> iterator;

    protected:
    typedef T value_type;

    public:
    /* Constructs and destructs*/
    explicit vector(const allocator_type& alloc = allocator_type());
    explicit vector(size_type n, const value_type& val = value_type(),
                    const allocator_type& alloc = allocator_type());
    ~vector(void) {}

    /* operators */
    vector<T, Allocator>& operator=(const vector<T, Allocator>& obj);
    // T &         operator[](int i);
    /* Set atributs */
    /* Get and show atributs */
    size_t         size() const;
    size_t         capacity() const;
    allocator_type alloc() const;
    iterator       begin() const;

    /* other methods */
    void clear();
    void push_back(const T& x);
    void memoryIncrease();

    private:
    T*        _arr;
    size_t    _size;
    size_t    _capacity;
    Allocator _allocator;
};

/******************************************************************************/
/* Constructors */

template <class T, class Allocator>
vector<T, Allocator>::vector(const allocator_type& alloc) : _size(0),
                                                            _capacity(0),
                                                            _allocator(alloc) {
    std::cout << "test void\n";
    _arr = 0;
}

template <class T, class Allocator>
vector<T, Allocator>::vector(size_type n, const value_type& val,
                             const allocator_type& alloc) : _size(n),
                                                            _capacity(n),
                                                            _allocator(alloc) {
    std::cout << "test 01\n";
    _arr = _allocator.allocate(n);
    for (size_type i = 0; i < n; ++i) {
        _allocator.construct(_arr + (int)i, val);
    }
    // std::cout << "test 3 i = " << i << "\n";
    std::cout << "test 02\n";
}

/* operators */
template <class T, class Allocator>
vector<T, Allocator>& vector<T, Allocator>::operator=(const vector<T, Allocator>& obj) {
    if (this == &obj) {
        return (*this);
    }
    clear();
    if (_capacity) {
        _allocator.deallocate(_arr, _capacity);
    }
    _size = obj.size();
    _capacity = obj.capacity();
    _allocator = obj.alloc();
    for (int i = 0; i < _size; ++i) {
        _allocator.construct(_arr[i], obj._arr[i]);
    }
    return (*this);
}

/* Get and show atributs */

template <class T, class Allocator>
size_t vector<T, Allocator>::size() const {
    return (_size);
}

template <class T, class Allocator>
size_t vector<T, Allocator>::capacity() const {
    return (_capacity);
}

template <class T, class Allocator>
typename vector<T, Allocator>::allocator_type vector<T, Allocator>::alloc() const {
    return (_allocator);
}

template <class T, class Allocator>
typename vector<T, Allocator>::iterator vector<T, Allocator>::begin() const {
    return (iterator(_arr));
}

/* other methods */

template <class T, class Allocator>
void vector<T, Allocator>::clear() {
    for (int i = 0; i < _size; ++i) {
        // _arr.destroy(_arr[i]);
    }
    _size = 0;
}

template <class T, class Allocator>
void vector<T, Allocator>::push_back(const T& x) {
    std::cout << "test push_back _size = " << _size << ", _capacity = " << _capacity << "\n";
    if (_size == _capacity) {
        memoryIncrease();
    }
    _arr[_size++] = x;
    // std::cout << "test _arr[_size - 1] = " << _arr[_size - 1] << std::endl;
}

template <class T, class Allocator>
void vector<T, Allocator>::memoryIncrease() {
    T* tmp = _arr;
    if (_capacity) {
        _capacity *= 2;
    } else {
        ++_capacity;
    }
    std::cout << _size << std::endl;
    std::cout << "test 1\n";
    _arr = _allocator.allocate(_capacity);
    std::cout << "test 2\n";
    for (int i = 0; i < (int)_size; ++i) {
        std::cout << "test 3 i = " << i << "\n";
        std::cout << "test 3 tmp[i] = " << tmp[i] << "\n";
        std::cout << "test 3 _arr[i].capacity() = " << _arr[i].capacity() << "\n";
        std::cout << "test 3 _arr[i] befor "
                  << "\n";
        _arr[i] = tmp[i];
    }

    _allocator.clear();
    _allocator.deallocate(tmp, _size);
}

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
//     typedef implementation-defined                   iterator;
//     typedef implementation-defined                   const_iterator;
//     typedef std::reverse_iterator<iterator>          reverse_iterator;
//     typedef std::reverse_iterator<const_iterator>    const_reverse_iterator;
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