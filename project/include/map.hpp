#ifndef MAP_HPP
# define MAP_HPP

#include <functional>
#include <memory>
#include <utility.hpp>
#include <iterator_binTree_normal.hpp>
#include <iterator_binTree_normal_const.hpp>
#include <iterator_binTree_reverse.hpp>
#include <RBTree.hpp>
#include <less.hpp>
#include <lexicographical_compare.hpp>

namespace ft {

template<
    class Key,
    class T,
    class Compare = ::ft::less<Key>,
    class Allocator = std::allocator< ::ft::pair<const Key, T> > > 
class map : public RBTree< ::ft::pair<const Key, T> > {
    public:

    typedef Key                     key_type;
    typedef T                       mapped_type;
    typedef pair<const Key, T>      value_type;
    typedef typename RBTree<value_type>::size_type
                                    size_type;
    typedef std::ptrdiff_t          difference_type;
    typedef Compare                 key_compare;
    typedef Allocator               allocator_type;
    typedef Node<value_type>&             reference;
    typedef const Node<value_type>&       const_reference;

    typedef typename Allocator::pointer          pointer;
    typedef typename Allocator::const_pointer    const_pointer;

    typedef typename RBTree<value_type>::iterator               iterator;
    typedef typename RBTree<value_type>::const_iterator         const_iterator;
    typedef typename RBTree<value_type>::reverse_iterator       reverse_iterator;
    typedef typename RBTree<value_type>::const_reverse_iterator const_reverse_iterator;

    private:
    key_compare _comp;

    public:

    //////////////////////
    // Member functions //
    //////////////////////

    explicit map( const Compare& comp = key_compare(),
                const Allocator& alloc = Allocator() );
    map( const map& other );
    template< class InputIt >
        map( InputIt first, InputIt last,
            const Compare& comp = Compare(),
            const Allocator& alloc = Allocator() );
    ~map();

    allocator_type  get_allocator();
    map &           operator=(const map & other);

    // Element access

    T&          operator[]( const Key& key );
    T&          at( const Key& key );
    const T&    at( const Key& key ) const;

    // Modifiers

    void        erase( iterator pos );
    void        erase( iterator first, iterator last );
    size_type   erase( const Key& key );

    // Lookup

    size_type       count( const Key& key );
    iterator        find( const Key& key );
    const_iterator  find( const Key& key ) const;
    iterator        lower_bound( const Key& key );
    const_iterator  lower_bound( const Key& key ) const;
    iterator        upper_bound( const Key& key );
    const_iterator  upper_bound( const Key& key ) const;
    ::ft::pair<iterator,iterator>               equal_range( const Key& key );
    ::ft::pair<const_iterator,const_iterator>   equal_range( const Key& key ) const;

    // Observers

    key_compare key_comp() const;
    class value_compare;
    value_compare   value_comp() const;

    class value_compare : public ::ft::binary_function<value_type, value_type, bool> {
        friend class ::ft::map<Key, T, Compare, Allocator>;
        protected:
        Compare comp;

        value_compare(Compare c) : 
                comp(c) { }

        public:

        bool operator()(const value_type& x, const value_type& y) const
        { return comp(x.first, y.first); }
    };

};

    //////////////////////////
    // Non-member functions //
    //////////////////////////

template< class Key, class T, class Compare, class Alloc >
void swap( map<Key,T,Compare,Alloc>& lhs,
           map<Key,T,Compare,Alloc>& rhs );

template< class Key, class T, class Compare, class Alloc >
bool operator==( const map<Key,T,Compare,Alloc>& lhs,
                 const map<Key,T,Compare,Alloc>& rhs );

template< class Key, class T, class Compare, class Alloc >
bool operator!=( const map<Key,T,Compare,Alloc>& lhs,
                 const map<Key,T,Compare,Alloc>& rhs );

template< class Key, class T, class Compare, class Alloc >
bool operator<( const map<Key,T,Compare,Alloc>& lhs,
                const map<Key,T,Compare,Alloc>& rhs );

template< class Key, class T, class Compare, class Alloc >
bool operator<=( const map<Key,T,Compare,Alloc>& lhs,
                 const map<Key,T,Compare,Alloc>& rhs );

template< class Key, class T, class Compare, class Alloc >
bool operator>( const map<Key,T,Compare,Alloc>& lhs,
                const map<Key,T,Compare,Alloc>& rhs );

template< class Key, class T, class Compare, class Alloc >
bool operator>=( const map<Key,T,Compare,Alloc>& lhs,
                 const map<Key,T,Compare,Alloc>& rhs );

/******************************************************************************/
    //////////////////////
    // Member functions //
    //////////////////////

template<
    class Key,
    class T,
    class Compare,
    class Allocator > 
map<Key, T, Compare, Allocator>::
    map( const Compare& comp , const Allocator& alloc ) :
            RBTree<pair<const Key, T> >(alloc),
            _comp(comp) { }

template<
    class Key,
    class T,
    class Compare,
    class Allocator > 
map<Key, T, Compare, Allocator>::
    map( const map& other ) :
            RBTree<pair<const Key, T> >() {
        operator=(other);
}

template<
    class Key,
    class T,
    class Compare,
    class Allocator > 
template< class InputIt >
map<Key, T, Compare, Allocator>::
    map( InputIt first, InputIt last,
        const Compare& comp,
        const Allocator& alloc ) :
                    RBTree<pair<const Key, T> >(first, last, alloc),
                    _comp(comp) { }

template<
    class Key,
    class T,
    class Compare,
    class Allocator > 
map<Key, T, Compare, Allocator>::
    ~map() {
    RBTree<pair<const Key, T> >::clear();
}

template<
    class Key,
    class T,
    class Compare,
    class Allocator > 
map<Key, T, Compare, Allocator> &
map<Key, T, Compare, Allocator>::
   operator=(const map & other) {
        _comp = other._comp;
        RBTree<pair<const Key, T> >::operator=(other);
        return ( *this );
}

template<
    class Key,
    class T,
    class Compare,
    class Allocator > 
T&
map<Key, T, Compare, Allocator>::
    operator[]( const Key& key ) {
        iterator iter = find(key);
        if ( iter == this->end() ) {
            return this->insert(::ft::make_pair(key, T())).first->second;
        }
        return iter->second;
} 

template<
    class Key,
    class T,
    class Compare,
    class Allocator > 
T&
map<Key, T, Compare, Allocator>::
    at( const Key& key ) {
    iterator iter = find(key);
    if ( iter == this->end() ) {
        throw std::out_of_range("out_of_range: Oops...exception. pos key out of range.\n");
    }
    return iter->second;
}

template<
    class Key,
    class T,
    class Compare,
    class Allocator > 
const T&
map<Key, T, Compare, Allocator>::
    at( const Key& key ) const {
    iterator iter = find(key);
    if ( iter == this->end() ) {
        throw std::out_of_range("out_of_range: Oops...exception. pos key out of range.\n");
    }
    return iter->second;
}

    // Modifiers

template<
    class Key,
    class T,
    class Compare,
    class Allocator > 
void
map<Key, T, Compare, Allocator>::
    erase( iterator pos ) {
    RBTree<pair<const Key, T> >::erase(pos);
}

template<
    class Key,
    class T,
    class Compare,
    class Allocator > 
void
map<Key, T, Compare, Allocator>::
    erase( iterator first, iterator last ) {
    RBTree<pair<const Key, T> >::erase(first, last);
}

template<
    class Key,
    class T,
    class Compare,
    class Allocator > 
typename map<Key, T, Compare, Allocator>::size_type
map<Key, T, Compare, Allocator>::
   erase( const Key& key ) {
    iterator pos = find(key);
    if ( pos == this->end() ) {
        return (0);
    }
    RBTree<pair<const Key, T> >::erase(pos);
    return (1);
}

    // Lookup
    
template<
    class Key,
    class T,
    class Compare,
    class Allocator > 
typename map<Key, T, Compare, Allocator>::size_type
map<Key, T, Compare, Allocator>::
    count( const Key& key ) {
    return ( find(key) == this->end() ? 0 : 1 );
}

template<
    class Key,
    class T,
    class Compare,
    class Allocator > 
typename map<Key, T, Compare, Allocator>::iterator
map<Key, T, Compare, Allocator>::
    find( const Key& key ) {
    T   second_type;
    pair<const Key, T> pair_for_node(key, second_type);
    iterator iter = this->find_element(pair_for_node);
    return (iter);
}

template<
    class Key,
    class T,
    class Compare,
    class Allocator > 
typename map<Key, T, Compare, Allocator>::const_iterator
map<Key, T, Compare, Allocator>::
    find( const Key& key ) const {
    T   second_type;
    pair<const Key, T> pair_for_node(key, second_type);
    const_iterator iter = this->find_element(pair_for_node);
    return (iter);
}

template<
    class Key,
    class T,
    class Compare,
    class Allocator > 
typename map<Key, T, Compare, Allocator>::iterator
map<Key, T, Compare, Allocator>::
    lower_bound( const Key& key ) {
    return (find(key));
}

template<
    class Key,
    class T,
    class Compare,
    class Allocator > 
typename map<Key, T, Compare, Allocator>::const_iterator
map<Key, T, Compare, Allocator>::
    lower_bound( const Key& key ) const {
    return (find(key));
}

template<
    class Key,
    class T,
    class Compare,
    class Allocator > 
typename map<Key, T, Compare, Allocator>::iterator
map<Key, T, Compare, Allocator>::
    upper_bound( const Key& key ) {
    iterator iter(find(key));
    return (iter == this->end() ? iter : ++iter);
}

template<
    class Key,
    class T,
    class Compare,
    class Allocator > 
typename map<Key, T, Compare, Allocator>::const_iterator
map<Key, T, Compare, Allocator>::
    upper_bound( const Key& key ) const {
    const_iterator iter(find(key));
    return (iter == this->end() ? iter : ++iter);
}

template<
    class Key,
    class T,
    class Compare,
    class Allocator > 
::ft::pair<typename map<Key, T, Compare, Allocator>::iterator, 
           typename map<Key, T, Compare, Allocator>::iterator>
map<Key, T, Compare, Allocator>::
    equal_range( const Key& key ) {
    ::ft::pair<iterator,iterator> pair_eq(lower_bound(key), upper_bound(key));
    return pair_eq;
}

template<
    class Key,
    class T,
    class Compare,
    class Allocator > 
::ft::pair<typename map<Key, T, Compare, Allocator>::const_iterator, 
           typename map<Key, T, Compare, Allocator>::const_iterator>
map<Key, T, Compare, Allocator>::
    equal_range( const Key& key ) const {
    ::ft::pair<iterator,iterator> pair_eq(lower_bound(key), upper_bound(key));
    return pair_eq;
}

    // Observers

template<
    class Key,
    class T,
    class Compare,
    class Allocator >
typename map<Key, T, Compare, Allocator>::key_compare
map<Key, T, Compare, Allocator>::
    key_comp() const {
    return ( this->_comp );
}

template<
    class Key,
    class T,
    class Compare,
    class Allocator >
typename map<Key, T, Compare, Allocator>::value_compare
map<Key, T, Compare, Allocator>::
    value_comp() const {
    Compare less_obj;
    return value_compare(less_obj);
}

/******************************************************************************/
    //////////////////////////
    // Non-member functions //
    //////////////////////////

template< class Key, class T, class Compare, class Alloc >
bool operator==( const map<Key,T,Compare,Alloc>& lhs,
                 const map<Key,T,Compare,Alloc>& rhs ) {
    if (lhs.size() != rhs.size()) {
        return (false);
    }
    typename map<Key,T,Compare,Alloc>::const_iterator iter_lhs( lhs.begin() );
    typename map<Key,T,Compare,Alloc>::const_iterator iter_rhs( rhs.begin() );

    for ( typename map<Key,T,Compare,Alloc>::size_type i = 0; i < lhs.size() ; ++i ) {
        if ( *iter_lhs != *iter_rhs ) {
            return (false);
        }
        ++iter_lhs;
        ++iter_rhs;
    }
    if ( iter_rhs != rhs.end() ) {
        return ( false );
    }
    return (true);
}

template< class Key, class T, class Compare, class Alloc >
bool operator!=( const map<Key,T,Compare,Alloc>& lhs,
                 const map<Key,T,Compare,Alloc>& rhs ) {
    return (!(lhs == rhs));
}

template< class Key, class T, class Compare, class Alloc >
bool operator<( const map<Key,T,Compare,Alloc>& lhs,
                const map<Key,T,Compare,Alloc>& rhs ) {
    return (::ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
}

template< class Key, class T, class Compare, class Alloc >
bool operator<=( const map<Key,T,Compare,Alloc>& lhs,
                 const map<Key,T,Compare,Alloc>& rhs ) {
    return (!(rhs < lhs));
}

template< class Key, class T, class Compare, class Alloc >
bool operator>( const map<Key,T,Compare,Alloc>& lhs,
                const map<Key,T,Compare,Alloc>& rhs ) {
    return (!(lhs <= rhs));
}

template< class Key, class T, class Compare, class Alloc >
bool operator>=( const map<Key,T,Compare,Alloc>& lhs,
                 const map<Key,T,Compare,Alloc>& rhs ) {
    return (!(lhs < rhs));
}

template< class Key, class T, class Compare, class Alloc >
void swap( map<Key,T,Compare,Alloc>& lhs,
           map<Key,T,Compare,Alloc>& rhs ) {
    lhs.swap(rhs);
}

} // namespace ft

#endif
