#ifndef FT_ITERATOR_HPP
#define FT_ITERATOR_HPP

namespace ft {

//
//
// Теги итератора
// iterator tag
struct input_iterator_tag {};
struct output_iterator_tag {};
struct forward_iterator_tag : public input_iterator_tag {};
struct bidirectional_iterator_tag : public forward_iterator_tag {};
struct random_access_iterator_tag : public bidirectional_iterator_tag {};

// template <typename _Iterator, typename _Container> // pointer, vector; typedef typename allocator_type::pointer         pointer;
// class normal_iterator {
//     protected:
//     _Iterator _M_current;
//
// typedef std::iterator_traits<_Iterator> __traits_type;
//
//     public:
//     typedef _Iterator                                 iterator_type;
//     typedef typename __traits_type::iterator_category iterator_category;
//     typedef typename __traits_type::value_type        value_type;
//     typedef typename __traits_type::difference_type   difference_type;
//     typedef typename __traits_type::reference         reference;
//     typedef typename __traits_type::pointer           pointer;
//
//     normal_iterator() : _M_current(_Iterator()) {}
//     normal_iterator(const _Iterator& i) : _M_current(i) {}
//
//     // Forward iterator requirements
//
//     reference operator*() const {
//         return *_M_current;
//     }
//
//     pointer operator->() const {
//         return _M_current;
//     }
//
//     normal_iterator& operator++() {
//         ++_M_current;
//         return *this;
//     }
//
//     normal_iterator operator++(int) {
//         return normal_iterator(_M_current++);
//     }
// };
//
// template <class _Iterator>
// struct __iterator_traits {
//     typedef typename _Iterator::iterator_category iterator_category;
//     typedef typename _Iterator::value_type        value_type;
//     typedef typename _Iterator::difference_type   difference_type;
//     typedef typename _Iterator::pointer           pointer;
//     typedef typename _Iterator::reference         reference;
// };

//
//
// шаблонный класс итератор (для наследования)
template <
    typename _iterTag,
    typename _Container,
    typename _Dist = ptrdiff_t,
    typename _Pt = _Container*,
    typename _Rt = _Container&>
struct iterator {
    public:
    typedef _iterTag   iterator_category;
    typedef _Container value_type;
    typedef _Dist      difference_type;
    typedef _Rt        reference;
    typedef _Pt        pointer;
};

struct OutIt : public iterator<output_iterator_tag, void, void, void, void> {};

template <
    typename _iterTag,
    typename _Container,
    typename _Dist = ptrdiff_t,
    typename _Pt = _Container*,
    typename _Rt = _Container&>
struct bidirIt : public iterator<bidirectional_iterator_tag, _Container, _Dist, _Pt, _Rt> {};

template <
    typename _iterTag,
    typename _Container,
    typename _Dist = ptrdiff_t,
    typename _Pt = _Container*,
    typename _Rt = _Container&>
struct RandomIt : public iterator<random_access_iterator_tag, _Container, _Dist, _Pt, _Rt> {};
//
//
// iterator_traits
template <class _Iterator>
struct iterators_traits {
    typedef typename _Iterator::iterator_category iterator_category;
    typedef typename _Iterator::value_type        value_type;
    typedef typename _Iterator::difference_type   difference_type;
    typedef typename _Iterator::pointer           pointer;
    typedef typename _Iterator::reference         reference;
};

template <class _T> // _T был выше _Container
struct iterators_traits<_T*> {
    typedef random_access_iterator_tag iterator_category;
    typedef _T                         value_type;
    typedef ptrdiff_t                  difference_type;
    typedef _T*                        pointer;
    typedef _T&                        reference;
};

//////////////////////////////////////////////
//
// Итераторы как указатели для контейнеров
//
//
// normal_iterator
template <
    typename _iterTag,
    typename _Container,
    typename _Dist = ptrdiff_t,
    typename _Pt = _Container*,
    typename _Rt = _Container&>
class normal_iterator : public iterator<
                            random_access_iterator_tag,
                            _Container,
                            _Dist,
                            _Pt,
                            _Rt> {
    protected:
    _Pt _M_current;

    public:
    // declarations
    /* Constructs and destructs */
    normal_iterator();
    explicit normal_iterator(_Pt Ptr);
    normal_iterator(const normal_iterator<_iterTag, _Container, _Dist, _Pt, _Rt>& obj);
    // getters
    _Pt base() const;

    // Forward iterator requirements and getters
    _Rt operator*() const;
}; // typename не скомпилится

// definitions
// Constructs and destructs
template <
    typename _iterTag,
    typename _Container,
    typename _Dist,
    typename _Pt,
    typename _Rt>
normal_iterator<_iterTag, _Container, _Dist, _Pt, _Rt>::
    normal_iterator() {}

template <
    typename _iterTag,
    typename _Container,
    typename _Dist,
    typename _Pt,
    typename _Rt>
normal_iterator<_iterTag, _Container, _Dist, _Pt, _Rt>::
    normal_iterator(_Pt Ptr) : _M_current(Ptr) {}

template <
    typename _iterTag,
    typename _Container,
    typename _Dist,
    typename _Pt,
    typename _Rt>
normal_iterator<_iterTag, _Container, _Dist, _Pt, _Rt>::
    normal_iterator(const normal_iterator<_iterTag, _Container, _Dist, _Pt, _Rt>& obj) : _M_current(obj.base()) {}

// getters
template <
    typename _iterTag,
    typename _Container,
    typename _Dist,
    typename _Pt,
    typename _Rt>
_Pt normal_iterator<_iterTag, _Container, _Dist, _Pt, _Rt>::
    base() const {
    return (_M_current);
}

//     // Forward iterator requirements
template <
    typename _iterTag,
    typename _Container,
    typename _Dist,
    typename _Pt,
    typename _Rt>
_Rt normal_iterator<_iterTag, _Container, _Dist, _Pt, _Rt>::
    operator*() const {
    return (*_M_current);
}

//     pointer operator->() const {
//         return _M_current;
//     }
//
//     normal_iterator& operator++() {
//         ++_M_current;
//         return *this;
//     }
//
//     normal_iterator operator++(int) {
//         return normal_iterator(_M_current++);
//     }

}; // namespace ft

#endif
