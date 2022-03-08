#ifndef ITERATOR_HPP
#define ITERATOR_HPP

namespace ft {

template<typename _Iterator, typename _Container>
class normal_iterator {
    protected:
      _Iterator _M_current;

      typedef std::iterator_traits<_Iterator>		__traits_type;

    public:
      typedef _Iterator					iterator_type;
      typedef typename __traits_type::iterator_category iterator_category;
      typedef typename __traits_type::value_type  	value_type;
      typedef typename __traits_type::difference_type 	difference_type;
      typedef typename __traits_type::reference 	reference;
      typedef typename __traits_type::pointer   	pointer;

    normal_iterator() : _M_current(_Iterator()) { }
    normal_iterator(const _Iterator& i) : _M_current(i) { }

          // Forward iterator requirements

    reference           operator*() const {
        return *_M_current;
    }

    pointer             operator->() const {
        return _M_current;
    }

    normal_iterator&    operator++() {
    	++_M_current;
	    return *this;
    }

    normal_iterator     operator++(int) {
        return normal_iterator(_M_current++);
    }
};

template<class _Iterator>
struct __iterator_traits {
    typedef typename _Iterator::iterator_category iterator_category;
    typedef typename _Iterator::value_type        value_type;
    typedef typename _Iterator::difference_type   difference_type;
    typedef typename _Iterator::pointer           pointer;
    typedef typename _Iterator::reference         reference;
};
};

#endif
