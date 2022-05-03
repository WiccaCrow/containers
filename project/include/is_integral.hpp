#ifndef IS_INTEGRAL_HPP
# define IS_INTEGRAL_HPP

#include  <uchar.h>
#include  <true_false_type.hpp>

namespace ft {

    template<typename>
    struct is_integral
    : public false_type { };

    template<>
    struct is_integral<bool>
    : public true_type { };

    template<>
    struct is_integral<char>
    : public true_type { };

    template<>
    struct is_integral<char16_t>
    : public true_type { };

      template<>
    struct is_integral<char32_t>
    : public true_type { };

    template<>
    struct is_integral<wchar_t>
    : public true_type { };

    template<>
    struct is_integral<signed char>
    : public true_type { };

    template<>
    struct is_integral<short>
    : public true_type { };

    template<>
    struct is_integral<int>
    : public true_type { };

    template<>
    struct is_integral<long>
    : public true_type { };

    template<>
    struct is_integral<unsigned char>
    : public true_type { };

    template<>
    struct is_integral<unsigned long>
    : public true_type { };

// const

    template<>
    struct is_integral<const bool>
    : public true_type { };

    template<>
    struct is_integral<const char>
    : public true_type { };

    template<>
    struct is_integral<const char16_t>
    : public true_type { };

      template<>
    struct is_integral<const char32_t>
    : public true_type { };

    template<>
    struct is_integral<const wchar_t>
    : public true_type { };

    template<>
    struct is_integral<const signed char>
    : public true_type { };
    
    template<>
    struct is_integral<const short>
    : public true_type { };

    template<>
    struct is_integral<const int>
    : public true_type { };

    template<>
    struct is_integral<const long>
    : public true_type { };

    template<>
    struct is_integral<const unsigned char>
    : public true_type { };

    template<>
    struct is_integral<const unsigned long>
    : public true_type { };
}
#endif
