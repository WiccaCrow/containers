#ifndef NODE_HPP
# define NODE_HPP

#include <memory>
#include <utility.hpp>

namespace ft {
    
typedef enum { BLACK, RED } nodeColor;

template <class T>
class Node {
    public:
        
        T data;
        nodeColor color;
        Node *parent;
        Node *left;
        Node *right;
        bool _is_empty;

        Node() : 
            data(),
            color(BLACK),
            parent(0),
            left(0),
            right(0),
            _is_empty(true) { }
        
        Node(T d, nodeColor clr, Node * prnt, Node * lft, Node * rht) : 
            data(d),
            color(clr),
            parent(prnt),
            left(lft),
            right(rht),
            _is_empty(false) { }
        
        Node(T d) : 
            data(d),
            color(RED),
            parent(NULL),
            left(NULL),
            right(NULL),
            _is_empty(false) { }

        ~Node() {}

        bool is_empty() {
            return (_is_empty);
        }
};

template< class T >
bool operator==( const Node<T> & lhs,
                 const Node<T> & rhs ) {
    return (lhs.data == rhs.data);
}

template< class T >
bool operator==( const Node<T> & lhs,
                 const T & data ) {
    return (lhs.data == data);
}

template< class T >
bool operator==( const T & data,
                 const Node<T> & rhs ) {
    return (rhs == data);
}

template< class T >
bool operator<( const Node<T>& lhs,
                 const Node<T>& rhs ) {
    return (lhs.data < rhs.data);
}

template< class T >
bool operator<( const Node<T> & lhs,
                 const T & data ) {
    return (lhs.data < data);
}

template< class T >
bool operator<( const T & data,
                 const Node<T> & rhs ) {
    return (rhs < data);
}

template< class T >
bool operator<=( const Node<T>& lhs,
                 const Node<T>& rhs ) {
    return (lhs.data <= rhs.data);
}

template< class T >
bool operator<=( const Node<T> & lhs,
                 const T & data ) {
    return (lhs.data <= data);
}

template< class T >
bool operator<=( const T & data,
                 const Node<T> & rhs ) {
    return (rhs <= data);
}

template< class T >
bool operator>( const Node<T>& lhs,
                 const Node<T>& rhs ) {
    return (lhs.data > rhs.data);
}

template< class T >
bool operator>( const Node<T> & lhs,
                 const T & data ) {
    return (lhs.data > data);
}

template< class T >
bool operator>( const T & data,
                 const Node<T> & rhs ) {
    return (rhs > data);
}

template< class T >
bool operator>=( const Node<T>& lhs,
                 const Node<T>& rhs ) {
    return (lhs.data >= rhs.data);
}

template< class T >
bool operator>=( const Node<T> & lhs,
                 const T & data ) {
    return (lhs.data >= data);
}

template< class T >
bool operator>=( const T & data,
                 const Node<T> & rhs ) {
    return (rhs >= data);
}

/////////////////////// pair

template< class T1, class T2 >
bool operator==( const Node<pair<T1, T2> > & lhs,
                 const Node<pair<T1, T2> > & rhs ) {
    return (lhs.data.first == rhs.data.first);
}

template< class T1, class T2 >
bool operator==( const Node<pair<T1, T2> > & lhs,
                 const pair<T1, T2> & data ) {
    return (lhs.data.first == data.first);
}

template< class T1, class T2 >
bool operator==( const pair<T1, T2> & data,
                 const Node<pair<T1, T2> > & rhs ) {
    return (data.first == rhs.data.first);
}

template< class T1, class T2 >
bool operator<( const Node<pair<T1, T2> >& lhs,
                 const Node<pair<T1, T2> >& rhs ) {
    return (lhs.data.first < rhs.data.first);
}

template< class T1, class T2 >
bool operator<( const Node<pair<T1, T2> > & lhs,
                 const pair<T1, T2> & data ) {
    return (lhs.data.first < data.first);
}

template< class T1, class T2 >
bool operator<( const pair<T1, T2> & data,
                 const Node<pair<T1, T2> > & rhs ) {
    return (data.first < rhs.data.first);
}

template< class T1, class T2 >
bool operator<=( const Node<pair<T1, T2> >& lhs,
                 const Node<pair<T1, T2> >& rhs ) {
    return (lhs.data.first <= rhs.data.first);
}

template< class T1, class T2 >
bool operator<=( const Node<pair<T1, T2> > & lhs,
                 const pair<T1, T2> & data ) {
    return (lhs.data.first <= data.first);
}

template< class T1, class T2 >
bool operator<=( const pair<T1, T2> & data,
                 const Node<pair<T1, T2> > & rhs ) {
    return (data.first <= rhs.data.first);
}

template< class T1, class T2 >
bool operator>( const Node<pair<T1, T2> >& lhs,
                 const Node<pair<T1, T2> >& rhs ) {
    return (lhs.data.first > rhs.data.first);
}

template< class T1, class T2 >
bool operator>( const Node<pair<T1, T2> > & lhs,
                 const pair<T1, T2> & data ) {
    return (lhs.data.first > data.first);
}

template< class T1, class T2 >
bool operator>( const pair<T1, T2> & data,
                 const Node<pair<T1, T2> > & rhs ) {
    return (data.first > rhs.data.first);
}

template< class T1, class T2 >
bool operator>=( const Node<pair<T1, T2> >& lhs,
                 const Node<pair<T1, T2> >& rhs ) {
    return (lhs.data.first >= rhs.data.first);
}

template< class T1, class T2 >
bool operator>=( const Node<pair<T1, T2> > & lhs,
                 const pair<T1, T2> & data ) {
    return (lhs.data.first >= data.first);
}

template< class T1, class T2 >
bool operator>=( const pair<T1, T2> & data,
                 const Node<pair<T1, T2> > & rhs ) {
    return (data.first >= rhs.data.first);
}

} // namespace ft

#endif