#ifndef SET_HPP
# define SET_HPP

#include <functional>
#include <memory>
// #include <utility.hpp>
#include <iterator_binTree_normal.hpp>
#include <iterator_binTree_normal_const.hpp>
#include <iterator_binTree_reverse.hpp>
#include <RBTree.hpp>
#include <less.hpp>
#include <lexicographical_compare.hpp>

namespace ft {
    
template<
    class Key,
    class Compare = ::ft::less<Key>,
    class Allocator = std::allocator<Key> > 
class set : public RBTree< Key >  {

    public:
    
    typedef Key         key_type;
    typedef Key         value_type;
    typedef typename RBTree<value_type>::size_type
                                    size_type;
    typedef std::ptrdiff_t          difference_type;
    typedef Compare                 key_compare;
    typedef Compare                 value_compare;
    typedef Allocator               allocator_type;
    typedef value_type&             reference;
    typedef const value_type&       const_reference;

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

    explicit set( const Compare& comp = key_compare(),
                const Allocator& alloc = Allocator() );
    set( const set& other );
    template< class InputIt >
        set( InputIt first, InputIt last,
            const Compare& comp = Compare(),
            const Allocator& alloc = Allocator() );
    ~set();

    allocator_type  get_allocator();
    set &           operator=(const set & other);

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

    key_compare     key_comp() const;
    value_compare   value_comp() const;

};

    //////////////////////////
    // Non-member functions //
    //////////////////////////

template< class Key, class Compare, class Alloc >
void swap( set<Key,Compare,Alloc>& lhs,
           set<Key,Compare,Alloc>& rhs );

template< class Key, class Compare, class Alloc >
bool operator==( const set<Key,Compare,Alloc>& lhs,
                 const set<Key,Compare,Alloc>& rhs );

template< class Key, class Compare, class Alloc >
bool operator!=( const set<Key,Compare,Alloc>& lhs,
                 const set<Key,Compare,Alloc>& rhs );

template< class Key, class Compare, class Alloc >
bool operator<( const set<Key,Compare,Alloc>& lhs,
                const set<Key,Compare,Alloc>& rhs );

template< class Key, class Compare, class Alloc >
bool operator<=( const set<Key,Compare,Alloc>& lhs,
                 const set<Key,Compare,Alloc>& rhs );

template< class Key, class Compare, class Alloc >
bool operator>( const set<Key,Compare,Alloc>& lhs,
                const set<Key,Compare,Alloc>& rhs );

template< class Key, class Compare, class Alloc >
bool operator>=( const set<Key,Compare,Alloc>& lhs,
                 const set<Key,Compare,Alloc>& rhs );

/******************************************************************************/
    //////////////////////
    // Member functions //
    //////////////////////

template<
    class Key,
    class Compare,
    class Allocator > 
set<Key, Compare, Allocator>::
    set( const Compare& comp , const Allocator& alloc ) :
            RBTree<Key >(alloc),
            _comp(comp) { }

template<
    class Key,
    class Compare,
    class Allocator > 
set<Key, Compare, Allocator>::
    set( const set& other ) :
            RBTree<Key >() {
        operator=(other);
}

template<
    class Key,
    class Compare,
    class Allocator > 
template< class InputIt >
set<Key, Compare, Allocator>::
    set( InputIt first, InputIt last,
        const Compare& comp,
        const Allocator& alloc ) :
                    RBTree<Key >(first, last, alloc),
                    _comp(comp) { }

template<
    class Key,
    class Compare,
    class Allocator > 
set<Key, Compare, Allocator>::
    ~set() {
    RBTree<Key >::clear();
}

template<
    class Key,
    class Compare,
    class Allocator > 
set<Key, Compare, Allocator> &
set<Key, Compare, Allocator>::
   operator=(const set & other) {
        // _comp = other._comp;
        RBTree<Key >::operator=(other);
        return ( *this );
}

    // Modifiers

template<
    class Key,
    class Compare,
    class Allocator > 
void
set<Key, Compare, Allocator>::
    erase( iterator pos ) {
    RBTree<Key >::erase(pos);
}

template<
    class Key,
    class Compare,
    class Allocator > 
void
set<Key, Compare, Allocator>::
    erase( iterator first, iterator last ) {
    RBTree<Key >::erase(first, last);
}

template<
    class Key,
    class Compare,
    class Allocator > 
typename set<Key, Compare, Allocator>::size_type
set<Key, Compare, Allocator>::
   erase( const Key& key ) {
    iterator pos = find(key);
    if ( pos == this->end() ) {
        return (0);
    }
    RBTree<Key >::erase(pos);
    return (1);
}

    // Lookup
    
template<
    class Key,
    class Compare,
    class Allocator > 
typename set<Key, Compare, Allocator>::size_type
set<Key, Compare, Allocator>::
    count( const Key& key ) {
    return ( find(key) == this->end() ? 0 : 1 );
}

template<
    class Key,
    class Compare,
    class Allocator > 
typename set<Key, Compare, Allocator>::iterator
set<Key, Compare, Allocator>::
    find( const Key& key ) {
    iterator iter = this->find_element(key);
    return (iter);
}

template<
    class Key,
    class Compare,
    class Allocator > 
typename set<Key, Compare, Allocator>::const_iterator
set<Key, Compare, Allocator>::
    find( const Key& key ) const {
    const_iterator iter = this->find_element(key);
    return (iter);
}

template<
    class Key,
    class Compare,
    class Allocator > 
typename set<Key, Compare, Allocator>::iterator
set<Key, Compare, Allocator>::
    lower_bound( const Key& key ) {
    return (find(key));
}

template<
    class Key,
    class Compare,
    class Allocator > 
typename set<Key, Compare, Allocator>::const_iterator
set<Key, Compare, Allocator>::
    lower_bound( const Key& key ) const {
    return (find(key));
}

template<
    class Key,
    class Compare,
    class Allocator > 
typename set<Key, Compare, Allocator>::iterator
set<Key, Compare, Allocator>::
    upper_bound( const Key& key ) {
    iterator iter(find(key));
    return (iter == this->end() ? iter : ++iter);
}

template<
    class Key,
    class Compare,
    class Allocator > 
typename set<Key, Compare, Allocator>::const_iterator
set<Key, Compare, Allocator>::
    upper_bound( const Key& key ) const {
    const_iterator iter(find(key));
    return (iter == this->end() ? iter : ++iter);
}

template<
    class Key,
    class Compare,
    class Allocator > 
::ft::pair<typename set<Key, Compare, Allocator>::iterator, 
           typename set<Key, Compare, Allocator>::iterator>
set<Key, Compare, Allocator>::
    equal_range( const Key& key ) {
    ::ft::pair<iterator,iterator> pair_eq(lower_bound(key), upper_bound(key));
    return pair_eq;
}

template<
    class Key,
    class Compare,
    class Allocator > 
::ft::pair<typename set<Key, Compare, Allocator>::const_iterator, 
           typename set<Key, Compare, Allocator>::const_iterator>
set<Key, Compare, Allocator>::
    equal_range( const Key& key ) const {
    ::ft::pair<iterator,iterator> pair_eq(lower_bound(key), upper_bound(key));
    return pair_eq;
}

    // Observers

template<
    class Key,
    class Compare,
    class Allocator >
typename set<Key, Compare, Allocator>::key_compare
set<Key, Compare, Allocator>::
    key_comp() const {
    return ( Compare() );
}

template<
    class Key,
    class Compare,
    class Allocator >
typename set<Key, Compare, Allocator>::value_compare
set<Key, Compare, Allocator>::
    value_comp() const {
    return ( Compare() );
}

/******************************************************************************/
    //////////////////////////
    // Non-member functions //
    //////////////////////////

template< class Key, class Compare, class Alloc >
bool operator==( const set<Key,Compare,Alloc>& lhs,
                 const set<Key,Compare,Alloc>& rhs ) {
    if (lhs.size() != rhs.size()) {
        return (false);
    }
    typename set<Key,Compare,Alloc>::const_iterator iter_lhs( lhs.begin() );
    typename set<Key,Compare,Alloc>::const_iterator iter_rhs( rhs.begin() );

    for ( typename set<Key,Compare,Alloc>::size_type i = 0; i < lhs.size() ; ++i ) {
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

template< class Key, class Compare, class Alloc >
bool operator!=( const set<Key,Compare,Alloc>& lhs,
                 const set<Key,Compare,Alloc>& rhs ) {
    return (!(lhs == rhs));
}

template< class Key, class Compare, class Alloc >
bool operator<( const set<Key,Compare,Alloc>& lhs,
                const set<Key,Compare,Alloc>& rhs ) {
    return (::ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
}

template< class Key, class Compare, class Alloc >
bool operator<=( const set<Key,Compare,Alloc>& lhs,
                 const set<Key,Compare,Alloc>& rhs ) {
    return (!(rhs < lhs));
}

template< class Key, class Compare, class Alloc >
bool operator>( const set<Key,Compare,Alloc>& lhs,
                const set<Key,Compare,Alloc>& rhs ) {
    return (!(lhs <= rhs));
}

template< class Key, class Compare, class Alloc >
bool operator>=( const set<Key,Compare,Alloc>& lhs,
                 const set<Key,Compare,Alloc>& rhs ) {
    return (!(lhs < rhs));
}

template< class Key, class Compare, class Alloc >
void swap( set<Key,Compare,Alloc>& lhs,
           set<Key,Compare,Alloc>& rhs ) {
    lhs.swap(rhs);
}

} // namespace ft


#endif
