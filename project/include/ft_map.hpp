#ifndef FT_MAP_HPP
# define FT_MAP_HPP

#include <functional>
#include <memory>
#include <ft_utility.hpp>

namespace ft {

template<
    class Key,
    class T,
    class Compare = std::less<Key>,
    class Allocator = std::allocator<std::pair<const Key, T> > > 
class map {

    public:

    typedef Key                         key_type;
    typedef T                           mapped_type;
    typedef ft::pair<const Key, T>      value_type;
    typedef std::size_t                 size_type;
    typedef std::ptrdiff_t              difference_type;
    typedef Compare                     key_compare;
    typedef Allocator                   allocator_type;
    typedef value_type&                 reference;
    typedef const value_type&           const_reference;

    typedef typename Allocator::pointer          pointer;
    typedef typename Allocator::const_pointer    const_pointer;

    // typedef ft::normal_iterator< ::std::bidirectional_iterator_tag, std::pair<const Key, T> >       iterator;
    // typedef ft::normal_iterator< ::std::bidirectional_iterator_tag, const std::pair<const Key, T> > const_iterator;
    // iterator	LegacyBidirectionalIterator to value_type
    // const_iterator	LegacyBidirectionalIterator to const value_type
    typedef ft::reverse_iterator<iterator>              reverse_iterator;
    typedef ft::reverse_iterator<const_iterator>        const_reverse_iterator;
    // typedef 
    // typedef 
    // typedef 
    // typedef 

    // private:

    // key_compare comp;

    // public:

    // explicit map( const Compare& comp = key_compare(),
    //             const Allocator& alloc = Allocator() );

};

} // namespace ft

#endif