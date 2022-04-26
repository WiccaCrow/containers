#ifndef LESS_HPP
#define LESS_HPP

namespace ft {

template<typename _Arg1, typename _Arg2, typename _Result>
struct binary_function {

    typedef _Arg1 	    first_argument_type; 
    typedef _Arg2 	    second_argument_type;
    typedef _Result 	result_type;
};

template<typename _Tp>
struct less : public ::ft::binary_function<_Tp, _Tp, bool> {
bool    operator()(const _Tp& _x, const _Tp& _y) const { 
    return ( _x < _y ); 
}

};

}

#endif
