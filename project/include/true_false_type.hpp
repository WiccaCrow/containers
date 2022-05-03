#ifndef TRUE_FALSE_TYPE_HPP
# define TRUE_FALSE_TYPE_HPP

namespace ft {

  /// integral_constant
  template<typename _Tp, _Tp __v>
    struct integral_constant
    {
        static const _Tp                      value = __v;
        typedef _Tp                           value_type;
        typedef integral_constant<_Tp, __v>   type;
        operator _Tp() const { 
            return value; 
            }

    };


///////////////////////////


  /// The type used as a compile-time boolean with true value.
  typedef integral_constant<bool, true>     true_type;

  /// The type used as a compile-time boolean with false value.
  typedef integral_constant<bool, false>    false_type;

}

#endif
