#ifndef MAP_HPP
# define MAP_HPP

#include <functional>
#include <memory>
#include <utility.hpp>
#include <iterator_binTree_normal.hpp>
#include <iterator_binTree_normal_const.hpp>
#include <iterator_binTree_reverse.hpp>
#include <RBTree.hpp>

namespace ft {

template<
    class Key,
    class T,
    class Compare = std::less<Key>,
    class Allocator = std::allocator<std::pair<const Key, T> > > 
class map : public RBTree<pair<const Key, T> > {
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

    explicit map( const Compare& comp = key_compare(),
                const Allocator& alloc = Allocator() ) :
                    RBTree<pair<const Key, T> >(alloc),
                    _comp(comp) { }

    map( const map& other ) {
        operator=(other);
    }

    template< class InputIt >
    map( InputIt first, InputIt last,
        const Compare& comp = Compare(),
        const Allocator& alloc = Allocator() ) :
                    RBTree<pair<const Key, T> >(first, last, alloc),
                    _comp(comp) { }

    allocator_type get_allocator();

    map &   operator=(const map & other) {
        _comp = other._comp;
        RBTree<pair<const Key, T> >::operator=(other);
        return ( *this );
    }

    // Element access

    T&    operator[]( const Key& key ) {
        iterator iter = find(key);
        if ( iter == this->end() ) {
            return this->insert(::ft::make_pair(key, T())).first->second;
        }
        return iter->second;
    }    

    T& at( const Key& key ) {
        iterator iter = find(key);
        if ( iter == this->end() ) {
            throw std::out_of_range("out_of_range: Oops...exception. pos key out of range.\n");
        }
        return iter->second;
    }

    const T& at( const Key& key ) const {
        iterator iter = find(key);
        if ( iter == this->end() ) {
            throw std::out_of_range("out_of_range: Oops...exception. pos key out of range.\n");
        }
        return iter->second;
    }

    // Modifiers

    void    erase( iterator pos ) {
        RBTree<pair<const Key, T> >::erase(pos);
    }

    void erase( iterator first, iterator last ) {
        RBTree<pair<const Key, T> >::erase(first, last);
    }
    size_type   erase( const Key& key ) {
        iterator pos = find(key);
        if ( pos == this->end() ) {
            return (0);
        }
        RBTree<pair<const Key, T> >::erase(pos);
        return (1);
    }

    // Lookup

    size_type count( const Key& key ) {
        return ( find(key) == this->end() ? 0 : 1 );
    }

    iterator        find( const Key& key ) {
        T   second_type;
        pair<const Key, T> pair_for_node(key, second_type);
        iterator iter = this->find_element(pair_for_node);
        return (iter);
    }

    const_iterator  find( const Key& key ) const {
        T   second_type;
        pair<const Key, T> pair_for_node(key, second_type);
        const_iterator iter = this->find_element(pair_for_node);
        return (iter);
    }

    iterator lower_bound( const Key& key ) {
        return (find(key));
    }

    const_iterator lower_bound( const Key& key ) const {
        return (find(key));
    }

    iterator upper_bound( const Key& key ) {
        iterator iter(find(key));
        return (iter == this->end() ? iter : ++iter);
    }

    const_iterator upper_bound( const Key& key ) const {
        const_iterator iter(find(key));
        return (iter == this->end() ? iter : ++iter);
    }

    ::ft::pair<iterator,iterator> equal_range( const Key& key ) {
        ::ft::pair<iterator,iterator> pair_eq(lower_bound(key), upper_bound(key));
        return pair_eq;
    }

    ::ft::pair<const_iterator,const_iterator> equal_range( const Key& key ) const {
        ::ft::pair<iterator,iterator> pair_eq(lower_bound(key), upper_bound(key));
        return pair_eq;
    }

};

} // namespace ft

#endif