#ifndef FT_ITERATOR_TAG_STRUCTS_HPP
#define FT_ITERATOR_TAG_STRUCTS_HPP

namespace ft {

// Теги итератора
// iterator tag
struct input_iterator_tag {};
struct output_iterator_tag {};
struct forward_iterator_tag : public input_iterator_tag {};
struct bidirectional_iterator_tag : public forward_iterator_tag {};
struct random_access_iterator_tag : public bidirectional_iterator_tag {};
struct int_iterator_tag {};

}

#endif
