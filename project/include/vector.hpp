#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory>

// убрать
# include <vector>

namespace ft {

template    < 
    class _Tp, 
    class _Alloc = std::allocator<_Tp> 
            >

class vector {
    public:
        typedef _Alloc allocator_type;
        typedef size_t size_type;
        typedef _Tp value_type;

// переделать std
        typedef std::vector<_Tp>::iterator<T *>	iterator;

    public:
        /* Constructs and destructs*/
        explicit vector (const allocator_type& alloc = allocator_type());
        explicit vector (size_type n, const value_type& val = value_type(),
                 const allocator_type& alloc = allocator_type());
        ~vector(void) {}

        /* operators */
        vector<_Tp,_Alloc> &     operator=(const vector<_Tp,_Alloc> & obj);
// T &         operator[](int i);
        /* Set atributs */
        /* Get and show atributs */
        size_t          size() const;
        size_t          capacity() const;
        allocator_type  alloc() const;



        /* other methods */
        void clear();
        void push_back(const _Tp &x);
        void memoryIncrease();

    private:
        _Tp*    _arr;
        size_t  _size;
        size_t  _capacity;
        _Alloc  _alloc;

};

/******************************************************************************/
/* Constructors */

template<class _Tp, class _Alloc>
vector<_Tp,_Alloc>::vector(const allocator_type& alloc) :
        _alloc(alloc),
        _size (0),
        _capacity(0) {
    std::cout << "test void\n";
    _arr = 0;
}

template<class _Tp, class _Alloc>
vector<_Tp,_Alloc>::vector(size_type n, const value_type& val,
                 const allocator_type& alloc) :
        _size (n),
        _capacity(n) {
    std::cout << "test 01\n";
    _arr = _alloc.allocate(n);
    // std::cout << "test 3 i = " << i << "\n";
    
    std::cout << "test 02\n";

}

/* operators */
template<class _Tp, class _Alloc>
vector<_Tp,_Alloc> &     vector<_Tp,_Alloc>::operator=(const vector<_Tp,_Alloc> & obj) {
    if (this == &obj) {
        return (*this);
    }
    clear();
    if (_capacity) {
        _alloc.deallocate(_arr, _capacity);
    }
    _size = obj.size();
    _capacity = obj.capacity();
    _alloc = obj.alloc();
    for (int i = 0; i < _size; ++i) {
        _alloc.construct(_arr[i], obj._arr[i]);
    }
    return (*this);
}


/* Get and show atributs */

template<class _Tp, class _Alloc>
size_t  vector<_Tp,_Alloc>::size() const {
    return(_size);
}

template<class _Tp, class _Alloc>
size_t  vector<_Tp,_Alloc>::capacity() const {
    return(_capacity);
}

template<class _Tp, class _Alloc>
allocator_type  vector<_Tp,_Alloc>::alloc() const {
    return(_alloc);
}

/* other methods */

template<class _Tp, class _Alloc>
void vector<_Tp,_Alloc>::clear() {
    for (int i = 0; i < _size; ++i) {
        _arr.destroy(_arr[i]);
    }
    _size = 0;
}

template<class _Tp, class _Alloc>
void vector<_Tp,_Alloc>::push_back(const _Tp &x) {
    std::cout << "test push_back _size = " << _size << ", _capacity = " << _capacity << "\n";
    if (_size == _capacity) {
        memoryIncrease();
    }
    _arr[_size++] = x;
    // std::cout << "test _arr[_size - 1] = " << _arr[_size - 1] << std::endl;
}

template<class _Tp, class _Alloc>
void vector<_Tp,_Alloc>::memoryIncrease() {
    _Tp *tmp = _arr;
    if (_capacity) {
        _capacity *= 2;
    } else {
        ++_capacity;
    }
    std:: cout << _size << std::endl;
    std::cout << "test 1\n";
    _arr = _alloc.allocate(_capacity);
    std::cout << "test 2\n";
    for (int i = 0 ; i < (int)_size; ++i) {
    std::cout << "test 3 i = " << i << "\n";
    std::cout << "test 3 tmp[i] = " << tmp[i] << "\n";
    std::cout << "test 3 _arr[i].capacity() = " << _arr[i].capacity() << "\n";
    std::cout << "test 3 _arr[i] befor " << "\n";
        _arr[i] = tmp[i];
    }

    _alloc.clear();
    _alloc.deallocate(tmp, _size);
}

};


//      init

#endif
