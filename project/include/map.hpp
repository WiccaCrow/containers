#ifndef MAP_HPP
# define MAP_HPP

#include <functional>
#include <memory>
#include <utility.hpp>
#include <iterator_binTree_normal.hpp>
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
    typedef value_type&             reference;
    typedef const value_type&       const_reference;

    typedef typename Allocator::pointer          pointer;
    typedef typename Allocator::const_pointer    const_pointer;

    typedef typename RBTree<value_type>::iterator               iterator;
    typedef typename RBTree<value_type>::const_iterator         const_iterator;
    typedef typename RBTree<value_type>::reverse_iterator       reverse_iterator;
    typedef typename RBTree<value_type>::const_reverse_iterator const_reverse_iterator;

    // typedef 
    // typedef 
    // typedef 
    // typedef 

    private:
    key_compare _comp;

    public:

    explicit map( const Compare& comp = key_compare(),
                const Allocator& alloc = Allocator() ) :
                    RBTree<pair<const Key, T> >(alloc),
                    _comp(comp) { }

};

} // namespace ft

#endif