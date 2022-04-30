#ifndef STACK_HPP
# define STACK_HPP

#include <vector.hpp>

namespace ft {

template<
    class T,
    class Container = ft::vector<T> > 
class stack {
    public:

    // Member types

    typedef Container                           container_type;
    typedef typename Container::value_type      value_type;
    typedef typename Container::size_type       size_type;
    typedef typename Container::reference       reference;
    typedef typename Container::const_reference const_reference;

    protected:

    container_type c;

    public:

    //////////////////////
    // Member functions //
    //////////////////////

    explicit stack( const Container& cont = Container() ) :
            c(cont) { }

    explicit stack( const stack& other ) : 
            c(other.c) { }

    ~stack() { }

    stack& operator=( const stack& other ) {
        c = other.c;
    }

    // Element access

    reference top() {
    	return ( c.back() );
    }

    const_reference top() const {
    	return ( c.back() );
    }

    // Capacity

    bool empty() const {
        return ( c.empty() );
    }

    size_type size() const {
        return ( c.size() );
    }

    // Modifiers

    void push( const value_type& value ) {
        c.push_back(value);
    }

    void pop() {
        c.pop_back();
    }

    // for Non-member functions 

    template<typename _Tp1, typename _Seq1>
	friend bool
	operator==(const stack<_Tp1, _Seq1>&, const stack<_Tp1, _Seq1>&);

      template<typename _Tp1, typename _Seq1>
	friend bool
	operator<(const stack<_Tp1, _Seq1>&, const stack<_Tp1, _Seq1>&);

};

    //////////////////////////
    // Non-member functions //
    //////////////////////////

template< class T, class Container >
bool operator==( const stack<T,Container>& lhs, const stack<T,Container>& rhs ) {
    return ( lhs.c == rhs.c );
}

template< class T, class Container >
bool operator!=( const stack<T,Container>& lhs, const stack<T,Container>& rhs ) {
    return ( !(lhs == rhs) );
}

template< class T, class Container >
bool operator<( const stack<T,Container>& lhs, const stack<T,Container>& rhs ) {
    return ( lhs.c < rhs.c );

}

template< class T, class Container >
bool operator<=( const stack<T,Container>& lhs, const stack<T,Container>& rhs ) {
    return ( !(rhs < lhs) );
}

template< class T, class Container >
bool operator>( const stack<T,Container>& lhs, const stack<T,Container>& rhs ) {
    return ( rhs < lhs );
}

template< class T, class Container >
bool operator>=( const stack<T,Container>& lhs, const stack<T,Container>& rhs ) {
    return ( !(lhs < rhs) );
}

}

#endif
