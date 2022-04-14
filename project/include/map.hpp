#ifndef MAP_HPP
# define MAP_HPP

#include <functional>
#include <memory>
#include <utility.hpp>
#include <iterator_binTree_normal.hpp>
#include <RBTree.hpp>

namespace ft {

template<
    class Key,
    class T,
    class Compare = std::less<Key>,
    class Allocator = std::allocator<std::pair<const Key, T> > > 
// class map : protected RBTree<pair<const Key, T> > {
class map : public RBTree<pair<Key, T> > {
    public:

    typedef Key                         key_type;
    typedef T                           mapped_type;
    typedef pair<const Key, T>          value_type;
    typedef std::size_t                 size_type;
    typedef std::ptrdiff_t              difference_type;
    typedef Compare                     key_compare;
    typedef Allocator                   allocator_type;
    typedef value_type&                 reference;
    typedef const value_type&           const_reference;

    typedef typename Allocator::pointer          pointer;
    typedef typename Allocator::const_pointer    const_pointer;

    // typedef binTree_iterator<value_type>         iterator;
    // typedef binTree_iterator<const value_type>   const_iterator;
    // iterator	LegacyBidirectionalIterator to value_type
    // const_iterator	LegacyBidirectionalIterator to const value_type
    // typedef reverse_iterator<iterator>              reverse_iterator;
    // typedef reverse_iterator<const_iterator>        const_reverse_iterator;
    // typedef 
    // typedef 
    // typedef 
    // typedef 

    private:
    typedef typename Allocator::template
        rebind<value_type>::other alloc_type;
    alloc_type _alloc;

    key_compare _comp;

    public:

    explicit map( const Compare& comp = key_compare(),
                const Allocator& alloc = Allocator() ) :
                    _comp(comp), 
                    _alloc(alloc) { }

};

} // namespace ft

#endif