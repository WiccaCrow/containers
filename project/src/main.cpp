#include <deque>
#include <iostream>
#include <string>

void    check_iterators();
void    check_iterators_normal();
void    check_iterators_reverse();

// #if 1 //CREATE A REAL STL EXAMPLE
// 	#include <map>
#include <stack>
#include <vector>
// namespace ft = std;
// #else
// #include <map.hpp>
// #include <stack.hpp>
#include <ft_vector.hpp>
// #endif

#include <stdlib.h>

#define MAX_RAM     4294967296
#define BUFFER_SIZE 4096
struct Buffer {
    int  idx;
    char buff[BUFFER_SIZE];
};

#define COUNT (MAX_RAM / (int)sizeof(Buffer))

template <typename T>
// class MutantStack : public ft::stack<T>
class MutantStack : public std::stack<T> {
    public:
    MutantStack() {}
    MutantStack(const MutantStack<T>& src) { *this = src; }
    MutantStack<T>& operator=(const MutantStack<T>& rhs) {
        this->c = rhs.c;
        return *this;
    }
    ~MutantStack() {}

    // typedef typename ft::stack<T>::container_type::iterator iterator;
    typedef typename std::stack<T>::container_type::iterator iterator;

    iterator begin() { return this->c.begin(); }
    iterator end() { return this->c.end(); }
};

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cerr << "Usage: ./test seed" << std::endl;
        std::cerr << "Provide a seed please" << std::endl;
        std::cerr << "Count value:" << COUNT << std::endl;
        return 1;
    }
    const int seed = atoi(argv[1]);
    srand(seed);

    std::cout << "test main 1\n";
    std::string str;
    std::cout << "str.capacity() = " << str.capacity() << std::endl;

    std::vector<std::string> vector_str_real1(5);
    std::cout << "vector_str_real1.capacity() = " << vector_str_real1.capacity() << std::endl;
    std::cout << "vector_str_real1[0].capacity() = " << vector_str_real1[0].capacity() << std::endl;

    std::cout << "test main 2\n";
check_iterators();
    ft::vector<std::string> vector_str(5, "Hello ");
    // std::cout << "test\n";

    // vector_str.push_back("hello");

    // ft::vector<std::string>::iterator it_v_ft = vector_str.begin();
    // vector_str.insert(it, "hello");
    // it = vector_str.begin();
    // vector_str.insert(it, "hello");
    // it = vector_str.begin();
    // vector_str.insert(it, "hello");
    // it = vector_str.begin();
    // vector_str.insert(it, "hello");

    // it = vector_str.begin();
    // vector_str.insert(it, "hello");

    // ft::vector<int> vector_int;
    // ft::stack<int> stack_int;
    // ft::vector<Buffer> vector_buffer;
    // ft::stack<Buffer, std::deque<Buffer> > stack_deq_buffer;
    // ft::map<int, int> map_int;

    std::cout << "\nft::vector<std::string> vector_str size:     " << vector_str.size() << std::endl;
    std::cout << "ft::vector<std::string> vector_str capacity: " << vector_str.capacity() << std::endl;

    std::vector<std::string> vector_str_real(0);
    vector_str_real.push_back("hello");

    std::vector<std::string>::iterator it = vector_str_real.begin();
    vector_str_real.insert(it, "hello");
    // it = vector_str_real.begin();
    // vector_str_real.insert(it, "hello");
    // it = vector_str_real.begin();
    // vector_str_real.insert(it, "hello");
    // it = vector_str_real.begin();
    // vector_str_real.insert(it, "hello");
    std::cout << "\nstd vector_str_real size:     " << vector_str_real.size() << std::endl;
    std::cout << "std vector_str_real capacity: " << vector_str_real.capacity() << std::endl;

    // for (int i = 0; i < COUNT; i++)
    // {
    // 	vector_buffer.push_back(Buffer());
    // }

    // for (int i = 0; i < COUNT; i++)
    // {
    // 	const int idx = rand() % COUNT;
    // 	vector_buffer[idx].idx = 5;
    // }
    // ft::vector<Buffer>().swap(vector_buffer);

    // try
    // {
    // 	for (int i = 0; i < COUNT; i++)
    // 	{
    // 		const int idx = rand() % COUNT;
    // 		vector_buffer.at(idx);
    // 		std::cerr << "Error: THIS VECTOR SHOULD BE EMPTY!!" <<std::endl;
    // 	}
    // }
    // catch(const std::exception& e)
    // {
    // 	//NORMAL ! :P
    // }

    // for (int i = 0; i < COUNT; ++i)
    // {
    // 	map_int.insert(ft::make_pair(rand(), rand()));
    // }

    // int sum = 0;
    // for (int i = 0; i < 10000; i++)
    // {
    // 	int access = rand();
    // 	sum += map_int[access];
    // }
    // std::cout << "should be constant with the same seed: " << sum << std::endl;

    // {
    // 	ft::map<int, int> copy = map_int;
    // }
    // MutantStack<char> iterable_stack;
    // for (char letter = 'a'; letter <= 'z'; letter++)
    // 	iterable_stack.push(letter);
    // for (MutantStack<char>::iterator it = iterable_stack.begin(); it != iterable_stack.end(); it++)
    // {
    // 	std::cout << *it;
    // }
    // std::cout << std::endl;
    return (0);
}


void    check_iterators() {
    std::cout << std::endl << "CHECK ITERATORS " << std::endl;
    check_iterators_normal();
    check_iterators_reverse();
}

void    check_iterators_normal() {
    std::cout << "\tnormal " << std::endl;
    ft::vector<std::string> vector_str(5, "Hello ");
    ft::vector<std::string>::iterator it_v_ft = vector_str.begin();

    // vector: check normal (forward) iterator
    for (it_v_ft = vector_str.begin(); it_v_ft != vector_str.end(); it_v_ft++) {
        std::cout << *it_v_ft;
    }

    // vector: check normal (random access) iterator
    char i = '0';
    for (it_v_ft = vector_str.begin(); it_v_ft != vector_str.end(); ++it_v_ft) {
        *it_v_ft += i++;
    }
    it_v_ft = vector_str.begin();
    std::cout << std::endl << *(it_v_ft + 2) << std::endl;

    for (it_v_ft = vector_str.end(); it_v_ft-- != vector_str.begin(); ) {
        std::cout << *it_v_ft << " ";
    }
    std::cout << std::endl;
    it_v_ft = vector_str.begin();
    std::cout << it_v_ft.operator->() << " ";    
    std::cout << std::endl;

}

void    check_iterators_reverse() {
    std::cout << "\treverse " << std::endl;

    int a[] = {0, 1, 2, 3};
    //             ↑  └───── x, y // ft
    //             └──────── z
 
    std::reverse_iterator<int*>
        x (&a[4]),
        y (&a[4]),
        z (&a[3]);

    ft::reverse_iterator<int*>
        x_ft (&a[4]),
        y_ft (&a[4]),
        z_ft (&a[3]);

    std::cout
        << std::boolalpha
        << "*x == " << *x << "        |  " << *x_ft << " == *x_ft" << '\n' // 3
        << "*y == " << *y << "        |  " << *y_ft << " == *x_ft" << '\n' // 3
        << "*z == " << *z << "        |  " << *z_ft << " == *x_ft" << '\n' // 2
        << "x == y ? " << (x == y) << "  | " << (x_ft == y_ft) << '\n' // true
        << "x != y ? " << (x != y) << " | " << (x_ft != y_ft) << '\n' // false
        << "x <  y ? " << (x <  y) << " | " << (x_ft <  y_ft) << '\n' // false
        << "x <= y ? " << (x <= y) << "  | " << (x_ft <= y_ft) << '\n' // true
        << "x == z ? " << (x == z) << " | " << (x_ft == z_ft) << '\n' // false
        << "x != z ? " << (x != z) << "  | " << (x_ft != z_ft) << '\n' // true
        << "x <  z ? " << (x <  z) << "  | " << (x_ft <  z_ft) << '\n' // true!
        << "x <= z ? " << (x <= z) << "  | " << (x_ft <= z_ft) << '\n' // true
        ;
}