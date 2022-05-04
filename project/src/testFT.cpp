#include <iostream>
#include <iomanip>
#include <string>
#include <deque>
#include <sys/time.h>
#include <cstddef>
#include <is_integral.hpp>

#include <enable_if.hpp>
#include <vector.hpp>
#include <map.hpp>
#include <stack.hpp>
#include <set.hpp>
#include <utility.hpp>

using namespace ft;

void    vector_test();
template <class T>
    void    print_vector(T & characters);

void    stack_test();

void    map_test();
void    fill_map(map<int, ::std::string> &my_tree);
void    print_pair(pair<const int, char>& n);
void    print_int(int n);
template<class Iter >
    void    for_each_ft(Iter begin, Iter end, void(*op)(pair<const int, char>& ));
template<class Iter >
    void    for_each_set(Iter begin, Iter end, void(*op)(int ));

void    set_test();
void    fill_set(set<int> * my_tree);

int main( ) {

    // start time
	long int		timestap_in_mcs;
	struct timeval	tv;
	if (!gettimeofday(&tv, NULL))
	{
		timestap_in_mcs = tv.tv_sec * 1000000 + tv.tv_usec;
	} else {
		std::cerr << "Error: gettimeofday error " << std::endl;
		return (1);
	}
	std::cout << std::endl;

    vector_test();
	std::cout << std::endl;

    long int vector_time;
	if (!gettimeofday(&tv, NULL))
	{
        vector_time = (tv.tv_sec * 1000000 + tv.tv_usec) - timestap_in_mcs;
	} else {
		std::cerr << "Error: gettimeofday error " << std::endl;
		return (1);
	}
	std::cout << std::endl;

    stack_test();
	std::cout << std::endl;

    long int stack_time;
	if (!gettimeofday(&tv, NULL))
	{
        stack_time = (tv.tv_sec * 1000000 + tv.tv_usec) - timestap_in_mcs - vector_time;
	} else {
		std::cerr << "Error: gettimeofday error " << std::endl;
		return (1);
	}
	std::cout << std::endl;

    map_test();
	std::cout << std::endl;

    long int map_time;
	if (!gettimeofday(&tv, NULL))
	{
        map_time = (tv.tv_sec * 1000000 + tv.tv_usec) - timestap_in_mcs - vector_time - stack_time;
	} else {
		std::cerr << "Error: gettimeofday error " << std::endl;
		return (1);
	}
	std::cout << std::endl;

    set_test();
	std::cout << std::endl;

    long int set_time;
	if (!gettimeofday(&tv, NULL))
	{
        set_time = (tv.tv_sec * 1000000 + tv.tv_usec) - timestap_in_mcs 
                    - map_time - vector_time - stack_time;
	} else {
		std::cerr << "Error: gettimeofday error " << std::endl;
		return (1);
	}
	std::cout << std::endl;
    
    if (!gettimeofday(&tv, NULL))
	{
		std::cout << "The program was completed for: " 
			      << ( (tv.tv_sec * 1000000 + tv.tv_usec) - timestap_in_mcs ) 
				  << " microseconds " << std::endl;
	} else {
		std::cerr << "Error: gettimeofday error " << std::endl;
		return (1);
	}

    std::cout << ::std::setw(40) << "The vector was completed for: " 
            << vector_time
            << " microseconds " << std::endl;

    std::cout << ::std::setw(40) << "The stack was completed for: " 
            << stack_time
            << " microseconds " << std::endl;

    std::cout << ::std::setw(40) << "The map was completed for: " 
            << map_time
            << " microseconds " << std::endl;

    std::cout << ::std::setw(40) << "The set was completed for: " 
            << set_time
            << " microseconds " << std::endl;
    return (0);
}

void vector_test() {
    { // constr destr op= assign get_alloc
        std::cout << std::endl << "\033[35m" << "CHECK CONSTRUCTORS " << "\033[0m" << std::endl;
        std::cout << "\033[35m" << "with capacity, size \n"
                    "\t(constructor)\n"
                    "\t(destructor)\n" 
                    "\toperator=\n" 
                    "\tassign\n" 
                    "\tget_allocator\n" 
                    "\033[0m" << std::endl;
        {
            std::cout << std::endl << "\033[33m" << "_____1.1_____" << "\033[0m" << std::endl;
            std::cout << "\033[34m" << "\t1) vector(); " << "\033[0m" << std::endl;
            vector<int> std_vec_int;
        }
        {
            std::cout << std::endl << "\033[33m" << "_____1.2_____" << "\033[0m" << std::endl;
            std::cout << "\033[34m" << "\t2) explicit vector( const Allocator& alloc ); " << "\033[0m" << std::endl;
            ::std::allocator<int> alloc;
            vector<int> std_vec_int(alloc);
            std::cout << "\n\033[36m" << "\t\tpush_back(5) " << "\033[0m"  << std::endl;
            std_vec_int.push_back(5);
            std::cout << "cout [0]  " << std::endl;
            std::cout << std_vec_int[0] << std::endl;
        }

        {
            std::cout << std::endl << "\033[33m" << "_____1.3_____" << "\033[0m" << std::endl;
            std::cout << "\n\033[34m" << "\t3) explicit vector( size_type count,\n"
                    "\t\t\t    const T& value = T(),\n"
                    "\t\t\t    const Allocator& alloc = Allocator());" 
                    "\n\t5 elements " << "\033[0m" << std::endl;
            vector<int> std_vec_int(5);
            std::cout << "capacity: " << std_vec_int.capacity() << std::endl;
            std::cout << "size:     " << std_vec_int.size() << std::endl;
            std::cout << std::endl;
        }

        {
            std::cout << "\n\033[34m" << "\t3) for int\n"
                    "\n\t        vector<int> data(5, 5); " << "\033[0m" << std::endl;
            std::cout << "\n\033[36m" << "\t\tcout " << "\033[0m"  << std::endl;
        
            vector<int> data(5, 5);
            for (int i = 0; i < 5; ++i) {
                std::cout << data[i];
            }
            std::cout << std::endl;
        }

        {
            std::cout << "\n\033[34m" << "\t5 elements, std::string \"hello \" " << "\033[0m" << std::endl;
            int size = 5;
            vector<std::string> std_vec_str(size, "hello ");
        
            std::cout << "capacity: " << std_vec_str.capacity() << std::endl;
            std::cout << "size:     " << std_vec_str.size() << std::endl;
            std::cout << "\n\033[36m" << "\t\tcout " << "\033[0m"  << std::endl;
            for (int i = 0; i < size; ++i) {
                std::cout << std_vec_str[i] << std::endl;
        
            }
            std::cout << std::endl;
        }

        {
            std::cout << "\n\033[34m" << "\t5 elements, std::string \"hello \", allocator " << "\033[0m" << std::endl;
            int size = 5;
            std::allocator<std::string> alloc;
            vector<std::string> std_vec_str(size, "hello ", alloc);
        
            std::cout << "capacity: " << std_vec_str.capacity() << std::endl;
            std::cout << "size:     " << std_vec_str.size() << std::endl;
            std::cout << "\n\033[36m" << "\t\tcout " << "\033[0m"  << std::endl;
            for (int i = 0; i < size; ++i) {
                std::cout << std_vec_str[i] << std::endl;
            }
            std::cout << std::endl;
        }

        {
            std::cout << std::endl << "\033[33m" << "_____1.5_____" << "\033[0m" << std::endl;
            std::cout << "\n\033[34m" << "\t5) template< class InputIt >\n"
                                        "\t   vector( InputIt first, InputIt last,\n"
                                        "\t\t   const Allocator& alloc = Allocator() ); "
                                        << "\033[0m" << std::endl;
            vector<std::string>    vect_for_iter;
            vect_for_iter.push_back("Hello ");
            vect_for_iter.push_back("my ");
            vect_for_iter.push_back("very ");
            vect_for_iter.push_back("beautiful ");
            vect_for_iter.push_back("world ");
            vect_for_iter.push_back("!!!\n");
            std::cout << "\n\033[36m" << "\t\tcout :" << "\033[0m"  << std::endl;
            vector<std::string>::iterator  iter = vect_for_iter.begin();
            for (;iter < vect_for_iter.end(); ++iter) {
                std::cout << *iter;
            }
        
            std::cout << "\n\033[36m" << "\t\tcout :" << "\033[0m"  << std::endl;
            iter = vect_for_iter.begin();
            vector<std::string>::iterator  iter_end = vect_for_iter.end();
            vector<std::string>    ft_vect(iter, iter_end);
            vector<std::string>::iterator  ft_iter = ft_vect.begin();
            for (;ft_iter < ft_vect.end(); ++ft_iter) {
                std::cout << *ft_iter;
            }
            std::cout << "capacity: " << ft_vect.capacity() << std::endl;
            std::cout << "size:     " << ft_vect.size() << std::endl;
        }
        
        {
            std::cout << std::endl << "\033[33m" << "_____1.6_____      _____3_____" << "\033[0m" << std::endl;
            std::cout << "\n\033[34m" << "\t6) vector( const vector& other );"
                                        << "\033[0m" << std::endl;
            std::cout << "\n\033[34m" << "\toperator=\n"
                                    << "\033[0m" << std::endl;
            vector<std::string>    vect_for_iter;
            vect_for_iter.push_back("Hello ");
            vect_for_iter.push_back("my ");
            vect_for_iter.push_back("very ");
            vect_for_iter.push_back("beautiful ");
            vect_for_iter.push_back("world ");
            vect_for_iter.push_back("!!!\n");
            vector<std::string>    ft_vect(vect_for_iter.begin(), vect_for_iter.begin() + vect_for_iter.size());
            vector<std::string>    ft_vect_copy = ft_vect;
            vector<std::string>::iterator ft_iter = ft_vect_copy.begin();
            for (;ft_iter < ft_vect_copy.end(); ++ft_iter) {
                std::cout << *ft_iter;
            }
            std::cout << "capacity: " << ft_vect_copy.capacity() << std::endl;
            std::cout << "size:     " << ft_vect_copy.size() << std::endl;

            vector<std::string>    ft_ft_vect(vect_for_iter.data(), vect_for_iter.data() + vect_for_iter.size());
            vector<std::string>    ft_ft_ft_vect(vect_for_iter.data(), vect_for_iter.data() + vect_for_iter.size());
        }

    }

    { // assign access iterators
        {
            vector<char> characters;

            std::cout << std::endl << "\033[33m" << "_____4.1_____ characters" << "\033[0m" << std::endl;
            std::cout << "\033[34m" << "\t4.1) void assign( size_type count, const T& value );  " << "\033[0m" << std::endl;

            characters.assign(5, 'a');
                for (vector<char>::iterator iter = characters.begin();
                iter != characters.end(); ++iter) {
                std::cout << *iter << ' ';
            }
            std::cout << std::endl; 
            std::cout << "capacity: " << characters.capacity() << std::endl;
            std::cout << "size: " << characters.size() << std::endl;

            std::cout << std::endl << "\033[33m" << "_____4.2_____ characters" << "\033[0m" << std::endl;
            std::cout << "\033[34m" << "\t4.2) template< class InputIt >\n"
                                    "\t     void assign( InputIt first, InputIt last );  " << "\033[0m" << std::endl;

            const std::string extra(6, 'b');
            characters.assign(extra.begin(), extra.end());
                for (vector<char>::iterator iter = characters.begin();
                iter != characters.end(); ++iter) {
                std::cout << *iter << ' ';
            }
            std::cout << std::endl;
            std::cout << "capacity: " << characters.capacity() << std::endl;
            std::cout << "size: " << characters.size() << std::endl;
        }
        {
            vector<int> integers;

            std::cout << std::endl << "\033[33m" << "_____4.1_____ integers" << "\033[0m" << std::endl;
            std::cout << "\033[34m" << "\t4.1) void assign( size_type count, const T& value );  " << "\033[0m" << std::endl;

            integers.assign(5, 0);
                for (vector<int>::iterator iter = integers.begin();
                iter != integers.end(); ++iter) {
                std::cout << *iter << ' ';
            }
            std::cout << std::endl;
            std::cout << "capacity: " << integers.capacity() << std::endl;
            std::cout << "size: " << integers.size() << std::endl;

            std::cout << std::endl << "\033[33m" << "_____4.2_____ integers" << "\033[0m" << std::endl;
            std::cout << "\033[34m" << "\t4.2) template< class InputIt >\n"
                                    "\t     void assign( InputIt first, InputIt last );  " << "\033[0m" << std::endl;

            const std::string extra_integers(6, 6);
            integers.assign(extra_integers.begin(), extra_integers.end());
                for (vector<int>::iterator iter = integers.begin();
                iter != integers.end(); ++iter) {
                std::cout << *iter << ' ';
            }
            std::cout << std::endl;
            std::cout << "capacity: " << integers.capacity() << std::endl;
            std::cout << "size: " << integers.size() << std::endl;
        }
    }

    { // access
        std::cout << std::endl << "\033[35m" << "check ELEMENT ACCESS " << "\033[0m" << std::endl;
        std::cout << "\033[35m" << 
                    "\tat\n"
                    "\toperator[]\n" 
                    "\tfront\n" 
                    "\tback\n" 
                    "\tdata\n" 
                    "\033[0m" << std::endl;

        std::cout << std::endl << "\033[33m" << "_____6 - 10_____     Element access" << "\033[0m" << std::endl;

        vector<int> data;
        data.insert(data.begin(), 1, 6);
        data.insert(data.begin(), 1, 5);
        data.insert(data.begin(), 1, 5);
        data.insert(data.begin(), 1, 4);
        data.insert(data.begin(), 1, 2);
        data.insert(data.begin(), 1, 1);

        for (int i = 0; static_cast<size_t>(i) < data.size(); ++i) {
            std::cout << data[i] << " ";
        }
        std::cout << std::endl;

        std::cout << "\033[34m" << "\t6) at " << "\033[0m" << std::endl;

        // Set element 1
        data.at(1) = 88;
        std::cout << "data.at(1) = 88, cout data[1]: " << data[1] << std::endl;
    
        // Read element 2
        std::cout << "Element at index 2 has value " << data.at(2) << '\n';
    
        std::cout << "data size = " << data.size() << '\n';

        std::cout << std::endl;
        try {
            // Set element 7
            std::cout << "try: data.at(7) = 666" << std::endl;

            data.at(7) = 666;
        } catch (std::out_of_range const& exc) {
            std::cout << exc.what() << '\n';
        }
        std::cout << std::endl;
    
        // Print final values
        std::cout << "Print final values. \ndata:";
        for (long unsigned int i = 0; i < data.size(); ++i)
            std::cout << " " << data[i];
        std::cout << "\n\n";

        std::cout << "\033[34m" << "\t7) operator[] " << "\033[0m" << std::endl;
        std::cout << "data[2] = " << data[2] << std::endl;

        std::cout << "\033[34m" << "\t8) front " << "\033[0m" << std::endl;
        std::cout << "front = " << data.front() << std::endl;

        std::cout << "\033[34m" << "\t9) back " << "\033[0m" << std::endl;
        std::cout << "back = " << data.back() << std::endl;

        std::cout << "\033[34m" << "\t10) data " << "\033[0m" << std::endl;
        std::cout << "*data.data() = " << *data.data() << std::endl;
        std::cout << " data.data() = " << data.data() << std::endl;

        std::cout << std::endl << "\033[35m" << "check ITERATORS " << "\033[0m" << std::endl;
        std::cout << "\033[35m" << 
                    "\tbegin\n"
                    "\tend\n" 
                    "\trbegin\n" 
                    "\trend\n"  
                    "\033[0m" << std::endl;
        std::cout << std::endl << "\033[33m" << "_____11-14_____     iterators" << "\033[0m" << std::endl;
        
        std::cout << "\033[34m" << "\t11) begin " << "\033[0m" << std::endl;
        std::cout << "*data.begin(); \n" << *data.begin() << std::endl;

        std::cout << "\033[34m" << "\t12) end " << "\033[0m" << std::endl;
        std::cout << "*(data.end() - 1); \n" << *(data.end() - 1) << std::endl;

        std::cout << "\033[34m" << "\t13) rbegin " << "\033[0m" << std::endl;
        std::cout << "*data.rbegin(); \n" << *data.rbegin() << std::endl;

        std::cout << "\033[34m" << "\t14) rend " << "\033[0m" << std::endl;
        std::cout << "*(data.rend() - 1); \n" << *(data.rend() - 1) << std::endl;   
    }

    { // capacity
        std::cout << std::endl << "\033[35m" << "check CAPACITY " << "\033[0m" << std::endl;
        std::cout << "\033[35m" << 
                    "\tempty\n"
                    "\tsize\n" 
                    "\tmax_size\n" 
                    "\treserve\n"
                    "\tcapacity\n"
                    "\033[0m" << std::endl;
        std::cout << std::endl << "\033[33m" << "_____15-19_____     " << "\033[0m" << std::endl;
        
        std::cout << "\033[34m" << "\t15) empty " << "\033[0m" << std::endl;
            std::cout << std::boolalpha;
        vector<int> numbers;
        std::cout << "Initially, numbers.empty():            " << numbers.empty() << "\n\n";
        numbers.assign(5, 5);
        std::cout << "After adding elements\nnumbers.assign(5, 5); numbers.empty(): " << numbers.empty() << '\n';

        std::cout << "\033[34m" << "\t16) size " << "\033[0m" << std::endl;
        std::cout << "numbers.size(); \n" << numbers.size() << std::endl;

        std::cout << "\033[34m" << "\t17) max_size " << "\033[0m" << std::endl;
        std::cout << "numbers.max_size(); \n" << numbers.max_size() << std::endl;

        std::cout << "\033[34m" << "\t18) reserve " << "\033[0m" << std::endl;
        numbers.reserve(2);
        std::cout << "numbers.reserve(2);  capacity: " << numbers.capacity() << std::endl;
        numbers.reserve(5);
        std::cout << "numbers.reserve(5);  capacity: " << numbers.capacity() << std::endl;
        numbers.reserve(10);
        std::cout << "numbers.reserve(10); capacity: " << numbers.capacity() << std::endl;
        std::cout << "print_vector(numbers): ";
        print_vector(numbers);

        std::cout << "\033[34m" << "\t19) capacity " << "\033[0m" << std::endl;
        std::cout << "numbers.capacity(); \n" << numbers.capacity() << std::endl;
    }

    std::cout << std::endl << "\033[35m" << "CHECK MODIFIERS " << "\033[0m" << std::endl;

    { // clear
        std::cout << std::endl << "\033[33m" << "_____20_____     " << "\033[0m" << std::endl;
        
        std::cout << "\033[34m" << "\t20) clear " << "\033[0m" << std::endl;
        vector<std::string>    vect_clear(5);
        vect_clear[0] = "Hello, ";
        vect_clear[1] = "my ";
        vect_clear[2] = "beautiful ";
        vect_clear[3] = "world ";
        vect_clear[4] = "!!!";
        std::cout << "\n\033[36m" << "\t\tcout vect_clear" << "\033[0m"  << std::endl;
        print_vector(vect_clear);
        std::cout << "capacity: " << vect_clear.capacity() << std::endl;
        std::cout << "size: " << vect_clear.size() << std::endl;
        std::cout << std::endl;
        vect_clear.clear();
        std::cout << "vect_clear.clear();" << std::endl;
        print_vector(vect_clear);
        std::cout << "capacity: " << vect_clear.capacity() << std::endl;
        std::cout << "size: " << vect_clear.size() << std::endl;   
    }

    { // insert erase

        std::cout << std::endl << "\033[33m" << "_____21_____     4" << "\033[0m" << std::endl;
    
        {
            std::cout << "\n\033[34m" << "\t21.4) template< class InputIt >\n"
                                        "\t   void insert( iterator pos, InputIt first, InputIt last ); "
                                        << "\033[0m" << std::endl;
            vector<std::string>    vect_for_iter;
            vect_for_iter.push_back("Hello ");
            vect_for_iter.push_back("my ");
            vect_for_iter.push_back("very ");
            vect_for_iter.push_back("beautiful ");
            vect_for_iter.push_back("world ");
            vect_for_iter.push_back("!!!\n");
            vector<std::string>::iterator  iter = vect_for_iter.begin();
            for (;iter < vect_for_iter.end(); ++iter) {
                std::cout << *iter;
            }
            iter = vect_for_iter.begin();

            vector<std::string>    ft_vect(vect_for_iter.begin(), vect_for_iter.end());
            vector<std::string>::iterator  ft_iter = ft_vect.begin();
            for (;ft_iter < ft_vect.end(); ++ft_iter) {
                std::cout << *ft_iter;
            }
            std::cout << "capacity: " << ft_vect.capacity() << std::endl;
            std::cout << "size:     " << ft_vect.size() << std::endl;

            ft_vect.insert(ft_vect.begin() + ft_vect.size()/3*2, vect_for_iter.begin(), vect_for_iter.end() - 1);
            ft_iter = ft_vect.begin();
            for (;ft_iter < ft_vect.end(); ++ft_iter) {
                std::cout << *ft_iter;
            }
            std::cout << "capacity: " << ft_vect.capacity() << std::endl;
            std::cout << "size:     " << ft_vect.size() << std::endl;

            ft_vect.insert(ft_vect.begin() + ft_vect.size()/3*2, vect_for_iter.begin().base(), vect_for_iter.begin().base() + 4);
            ft_iter = ft_vect.begin();
            for (;ft_iter < ft_vect.end(); ++ft_iter) {
                std::cout << *ft_iter;
            }
            std::cout << "capacity: " << ft_vect.capacity() << std::endl;
            std::cout << "size:     " << ft_vect.size() << std::endl;

            ft_vect.insert(ft_vect.begin() + ft_vect.size()/3*2, vect_for_iter.begin(), vect_for_iter.begin() + 1);
            ft_iter = ft_vect.begin();
            for (;ft_iter < ft_vect.end(); ++ft_iter) {
                std::cout << *ft_iter;
            }
            std::cout << "capacity: " << ft_vect.capacity() << std::endl;
            std::cout << "size:     " << ft_vect.size() << std::endl;

            ft_vect.insert(ft_vect.begin() + ft_vect.size()/3*2, vect_for_iter.begin().base(), vect_for_iter.begin().base() + 1);
            ft_iter = ft_vect.begin();
            for (;ft_iter < ft_vect.end(); ++ft_iter) {
                std::cout << *ft_iter;
            }
            std::cout << "capacity: " << ft_vect.capacity() << std::endl;
            std::cout << "size:     " << ft_vect.size() << std::endl;
            std::cout << std::endl << "\033[33m" << "_____22_____     2" << "\033[0m" << std::endl;
            std::cout << "\n\033[34m" << "\t22.2) iterator erase( iterator first, iterator last );"
                                    << "\033[0m" << std::endl;
            ft_vect.erase(ft_vect.begin() + 4, ft_vect.begin() + 6);
            ft_iter = ft_vect.begin();
            for (;ft_iter < ft_vect.end(); ++ft_iter) {
                std::cout << *ft_iter;
            }
            std::cout << "capacity: " << ft_vect.capacity() << std::endl;
            std::cout << "size:     " << ft_vect.size() << std::endl;

            std::cout << std::endl << "\033[33m" << "_____20_____     " << "\033[0m" << std::endl;
            std::cout << "\n\033[34m" << "\t20) void clear();"
                                    << "\033[0m" << std::endl;
            ft_vect.clear();
            std::cout << "capacity: " << ft_vect.capacity() << std::endl;
            std::cout << "size:     " << ft_vect.size() << std::endl;   
        }

    }

    { // push pop
        std::cout << std::endl << "\033[33m" << "_____23_____" << "\033[0m" << std::endl;
        std::cout << "\n\033[34m" << "\t23) "
                                        "void push_back( const T& value ); "
                                        << "\033[0m" << std::endl;
        vector<int> vect_int;
        vect_int.push_back(0);
        vect_int.push_back(1);
        vect_int.push_back(2);
        vect_int.push_back(3);
        vect_int.push_back(4);
        vect_int.push_back(5);
        vector<int>::iterator vect_int_iter = vect_int.begin();
        for (; vect_int_iter != vect_int.end(); ++vect_int_iter) {
            std::cout << *vect_int_iter << " ";
        }
        std::cout << std::endl;
        std::cout << "capacity: " << vect_int.capacity() << std::endl;
        std::cout << "size:     " << vect_int.size() << std::endl;

        {
            std::cout << std::endl << "\033[33m" << "_____24_____" << "\033[0m" << std::endl;
            std::cout << "\n\033[34m" << "\t24) "
                                        "void pop_back( ); "
                                        << "\033[0m" << std::endl;
            vect_int.pop_back();
            // vect_int.pop_back();
            // vect_int.pop_back();
            // vect_int.pop_back();
            // vect_int.pop_back();
            // vect_int.pop_back(); for 0
            // vect_int.pop_back(); for empty
            vect_int_iter = vect_int.begin();
            for (; vect_int_iter != vect_int.end(); ++vect_int_iter) {
                std::cout << *vect_int_iter << " ";
            }
            std::cout << std::endl;
            std::cout << "capacity: " << vect_int.capacity() << std::endl;
            std::cout << "size:     " << vect_int.size() << std::endl;
        }
    }

    { // resize
        std::cout << std::endl << "\033[33m" << "_____25_____" << "\033[0m" << std::endl;
        std::cout << "\n\033[34m" << "\t25) "
                                    "void resize( size_type count, T value = T() ); "
                                << "\033[0m" << std::endl;
        vector<int> c;
        c.push_back(1);
        c.push_back(2);
        c.push_back(3);
        std::cout << "The vector holds: ";
        print_vector(c);
        c.resize(5);
        std::cout << "After resize up to 5: ";
        print_vector(c);
        c.resize(2);
        std::cout << "After resize down to 2: ";
        print_vector(c);
        c.resize(6, 4);
        std::cout << "After resize up to 6 (initializer = 4): ";
        print_vector(c);
    }

    { // swap
            std::cout << std::endl << "\033[33m" << "_____26_____" << "\033[0m" << std::endl;
        std::cout << "\n\033[34m" << "\t26) "
                                    "void swap( vector& other ); "
                                << "\033[0m" << std::endl;
        vector<int> a1, a2;
        a1.push_back(1);
        a1.push_back(2);
        a1.push_back(3);
        a2.push_back(4);
        a2.push_back(5);

    
        vector<int>::iterator it1 = a1.begin() + 1;
        vector<int>::iterator it2 = a2.begin() + 1;
    
        int& ref1 = a1.front();
        int& ref2 = a2.front();

        std::cout << "\n\033[36m" << "\t\tbefor swap: " << "\033[0m"  << std::endl;
        std::cout << "\t vectors: "  << std::endl;
        print_vector(a1);
        print_vector(a2);
        std::cout << "\t *it1: " << *it1 << std::endl;
        std::cout << "\t *it2: " << *it2 << std::endl;
        std::cout << "\t ref1: " << ref1 << std::endl;
        std::cout << "\t ref2: " << ref2 << std::endl;
        std::cout << "a1 capacity: " << a1.capacity() << std::endl;
        std::cout << "a1 size:     " << a1.size() << std::endl;
        std::cout << "a2 capacity: " << a2.capacity() << std::endl;
        std::cout << "a2 size:     " << a2.size() << std::endl;

        std::cout << "\n\033[36m" << "\t\tafter swap: " << "\033[0m"  << std::endl;
        a1.swap(a2);
        std::cout << "\t vectors: "  << std::endl;
        print_vector(a1);
        print_vector(a2);
        std::cout << "\t *it1: " << *it1 << std::endl;
        std::cout << "\t *it2: " << *it2 << std::endl;
        std::cout << "\t ref1: " << ref1 << std::endl;
        std::cout << "\t ref2: " << ref2 << std::endl;
        std::cout << "a1 capacity: " << a1.capacity() << std::endl;
        std::cout << "a1 size:     " << a1.size() << std::endl;
        std::cout << "a2 capacity: " << a2.capacity() << std::endl;
        std::cout << "a2 size:     " << a2.size() << std::endl;
    }

    { // non-members
        std::cout << std::endl << "\033[35m" << "check NON-MEMBER FUNCTIONS " << "\033[0m" << std::endl;
        std::cout << "\033[35m" << 
                    "\t operator== \n"
                    "\t operator!= \n" 
                    "\t operator< \n" 
                    "\t operator<= \n"
                    "\t operator> \n"
                    "\t operator>= \n"
                    "\t swap \n"
                    "\033[0m" << std::endl;
        vector<std::string>    vect1;
        vect1.push_back("It's ");
        vect1.push_back("a ");
        vect1.push_back("beautiful ");
        vect1.push_back("life, ");
        vect1.push_back("oh ");
        vect1.push_back("oh ");
        vect1.push_back("oh ");
        vect1.push_back("oh ");
        vector<std::string>    vect2(vect1);
        std::cout << std::boolalpha;
        vect2.reserve(vect2.capacity() + 10);

        std::cout << std::endl << "\033[33m" << "_____27-32_____" << "\033[0m" << std::endl;
        std::cout << "\n\033[34m" << "\t27) template< class T, class Alloc >\n"
                                    "\t\tbool operator==( const vector<T,Alloc>& lhs,\n"
                                    "\t\t                 const vector<T,Alloc>& rhs ); \n"
                                << "\033[0m" << std::endl;
        std::cout << "\n\033[34m" << "\t28) template< class T, class Alloc >\n"
                                    "\t\tbool operator!=( const vector<T,Alloc>& lhs,\n"
                                    "\t\t                 const vector<T,Alloc>& rhs ); \n"
                                << "\033[0m" << std::endl;
        std::cout << "operator== equal:     " << (vect1 == vect2) << std::endl;
        std::cout << "operator!= equal:     " << (vect1 != vect2) << std::endl;
        vect1.push_back("oh\n");
        std::cout << "operator== not equal: " << (vect1 == vect2) << std::endl;
        std::cout << "operator!= not equal: " << (vect1 != vect2) << std::endl;

        std::cout << "\n\033[34m" << "\t29) template< class T, class Alloc >\n"
                                    "\t\tbool operator<( const vector<T,Alloc>& lhs,\n"
                                    "\t\t                 const vector<T,Alloc>& rhs ); \n"
                                << "\033[0m" << std::endl;
        std::cout << "\n\033[34m" << "\t30) template< class T, class Alloc >\n"
                                    "\t\tbool operator<=( const vector<T,Alloc>& lhs,\n"
                                    "\t\t                 const vector<T,Alloc>& rhs ); \n"
                                << "\033[0m" << std::endl;
        std::cout << "\n\033[34m" << "\t31) template< class T, class Alloc >\n"
                                    "\t\tbool operator>( const vector<T,Alloc>& lhs,\n"
                                    "\t\t                 const vector<T,Alloc>& rhs ); \n"
                                << "\033[0m" << std::endl;
        std::cout << "\n\033[34m" << "\t32) template< class T, class Alloc >\n"
                                    "\t\tbool operator>=( const vector<T,Alloc>& lhs,\n"
                                    "\t\t                 const vector<T,Alloc>& rhs ); \n"
                                << "\033[0m" << std::endl;
        vect1.pop_back();
        std::cout << "equal:     " << std::endl;
        print_vector(vect1);
        print_vector(vect2);

        std::cout << "operator== equal:     " << (vect1 == vect2) << std::endl;
        std::cout << "\t operator<     " << (vect1 < vect2) << std::endl;
        std::cout << "\t operator<=    " << (vect1 <= vect2) << std::endl;
        std::cout << "\t operator>     " << (vect1 > vect2) << std::endl;
        std::cout << "\t operator>=    " << (vect1 >= vect2) << std::endl;
        vect1[2] = 'a';
        print_vector(vect1);
        print_vector(vect2);
        std::cout << "not equal: " << std::endl;
        std::cout << "\t operator<     " << (vect1 < vect2) << std::endl;
        std::cout << "\t operator<=    " << (vect1 <= vect2) << std::endl;
        std::cout << "\t operator>     " << (vect1 > vect2) << std::endl;
        std::cout << "\t operator>=    " << (vect1 >= vect2) << std::endl;


        std::cout << "\n\033[34m" << "\t33) template< class T, class Alloc >\n"
                                    "\t\t void swap( vector<T,Alloc>& lhs,\n"
                                    "\t\t vector<T,Alloc>& rhs );"
                                << "\033[0m" << std::endl;
        vector<int> alice;
        alice.push_back(1);
        alice.push_back(2);
        alice.push_back(3);
        vector<int> bob;
        bob.push_back(7);
        bob.push_back(8);
        bob.push_back(9);
        bob.push_back(10);

        std::cout << "\n\033[36m" << "befor SWAP " << "\033[0m"  << std::endl;
        std::cout << "alice: ";
        print_vector(alice);
        std::cout << "bob:   ";
        print_vector(bob);
        
        std::swap(alice, bob);
        std::cout << "\n\033[36m" << "after SWAP " << "\033[0m"  << std::endl;
        std::cout << "alice: ";
        print_vector(alice);
        std::cout << "bob:   ";
        print_vector(bob);
        std::cout << '\n';
    }
}

void    stack_test() {
    std::cout << std::boolalpha;
 
    stack<int> container;
 
    std::cout << "Initially, container.empty(): " << container.empty() << std::endl;
    std::cout << "Initially, container.size(): " << container.size() << std::endl;

    std::cout << std::endl;

    container.push(42);
    std::cout << "After adding elements (int 42) , container.empty(): " << container.empty() << std::endl;
    std::cout << "Initially, container.size(): " << container.size() << std::endl;
    std::cout << "Initially, container.top(): " << container.top() << std::endl;

    std::cout << std::endl;

    stack<int> container2;
    container2.push(20);
    std::cout << "container2 with int 20: " << container2.top() << std::endl;
    std::cout << "container2 == contaiter: " << ( container2 == container ) << std::endl;
    std::cout << "container2 != contaiter: " << ( container2 != container ) << std::endl;
    std::cout << "container2 >  contaiter: " << ( container2 > container ) << std::endl;
    std::cout << "container2 >= contaiter: " << ( container2 >= container ) << std::endl;
    std::cout << "container2 <  contaiter: " << ( container2 < container ) << std::endl;
    std::cout << "container2 <= contaiter: " << ( container2 <= container ) << std::endl;

	stack<int> stack_int;
    // stack_int[5];
}

void    map_test() {
    { // insert copy
        std::cout << std::endl << "\033[35m" << "CHECK MAP insert copy " << "\033[0m" << std::endl;

        map<int, ::std::string> my_tree;
        fill_map(my_tree);

        map<int, ::std::string> my_tree_copy = my_tree;
    }

    { // reverse iterator
        std::cout << std::endl << "\033[35m" << "CHECK testMap_iterator reverse " << "\033[0m" << std::endl;
        std::cout << std::endl << "\033[35m" << "check ITERATORS reverse " << "\033[0m" << std::endl;
        std::cout << "\033[34m" << "\t iter reverse."
                    "\t\t operator-> "
                    "\t\t operator*  " << "\033[0m" << std::endl;
        std::cout << std::endl << "\033[33m" << "_____9-10_____     iterators map" << "\033[0m" << std::endl;

        map<int, ::std::string>    my_tree;
        fill_map(my_tree);

        map<int, ::std::string>::reverse_iterator   iter_my_tree1;
        map<int, ::std::string>::reverse_iterator   iter_my_tree2;

        iter_my_tree1 = my_tree.rbegin();
        iter_my_tree2 = my_tree.rend();

        std::cout << "\033[34m" << "\t9) rbegin " << "\033[0m" << std::endl;
        std::cout << "my_tree.rbegin()->first = " << my_tree.rbegin()->first << std::endl;
        std::cout << "iter_my_tree1->first = " << iter_my_tree1->first << std::endl;
        std::cout << "(*iter_my_tree1).first = " << (*iter_my_tree1).first << std::endl;
        std::cout << std::endl;

        std::cout << "\033[34m" << "\t10) rend " << "\033[0m" << std::endl;
        std::cout << "(--( my_tree.rend()))->first = " << (--(my_tree.rend()))->first << std::endl;

        std::cout << "\033[34m" << "\t iter reverse.\n"
                    "\t\t operator++ \n"
                    "\t\t ++operator \n"
                    "\t\t --operator \n"
                    "\t\t operator-- \n"
                    "\t\t operator-> \n"
                    "\t\t operator*  \n"
                << "\033[0m" << std::endl;

        {
            std::cout << "\033[36m" << "\t\tcout iter_reverse operator++" << "\033[0m"  << std::endl;
            std::cout << "\033[36m" << "\t\tfrom rbegin to root (80)" << "\033[0m"  << std::endl;
            iter_my_tree2  =  map<int, ::std::string>::reverse_iterator( my_tree.find(80) );
            while (iter_my_tree1 != iter_my_tree2) {
                std::cout << "iter_my_tree1->first = " << iter_my_tree1->first ;
                std::cout << "\t\t (*iter_my_tree1).first = " << (*iter_my_tree1++).first << std::endl;
            }
            std::cout << std::endl;

            std::cout << "\033[36m" << "\t\tcout iter_reverse ++operator" << "\033[0m"  << std::endl;
            std::cout << "\033[36m" << "\t\tfrom root (80) to rend" << "\033[0m"  << std::endl;
            iter_my_tree2  =  my_tree.rend();
            while (++iter_my_tree1 != iter_my_tree2) {
                std::cout << "iter_my_tree1->first = " << iter_my_tree1->first ;
                std::cout << "\t\t (*iter_my_tree1).first = " << (*iter_my_tree1).first << std::endl;
            }
            std::cout << std::endl;
        }

        {
            std::cout << "\033[36m" << "\t\tcout iter_reverse operator--" << "\033[0m"  << std::endl;
            std::cout << "\033[36m" << "\t\tfrom rend to root" << "\033[0m"  << std::endl;
            iter_my_tree1  =  my_tree.rend();
            --iter_my_tree1;
            iter_my_tree2  =  map<int, ::std::string>::reverse_iterator( my_tree.find(80) );
            while (iter_my_tree1 != iter_my_tree2) {
                std::cout << "iter_my_tree1->first = " << iter_my_tree1->first ;
                std::cout << "\t\t (*iter_my_tree1).first = " << (*iter_my_tree1--).first << std::endl;
            }
            std::cout << std::endl;

            std::cout << "\033[36m" << "\t\tcout iter_reverse --operator" << "\033[0m"  << std::endl;
            std::cout << "\033[36m" << "\t\tfrom root (80) to rbegin" << "\033[0m"  << std::endl;
            iter_my_tree2  =  my_tree.rbegin();
            while (--iter_my_tree1 != iter_my_tree2) {
                std::cout << "iter_my_tree1->first = " << iter_my_tree1->first ;
                std::cout << "\t\t (*iter_my_tree1).first = " << (*iter_my_tree1).first << std::endl;
            }
            std::cout << std::endl;
        }
    }

    { // non-members
        std::cout << std::endl << "\033[35m" << "CHECK testMap NON-MEMBER FUNCTIONS " << "\033[0m" << std::endl;
        std::cout << std::endl << "\033[33m" << "_____31_____" << "\033[0m" << std::endl;
        std::cout << "\033[34m" << "\t 31) template< class Key, class T, class Compare, class Alloc > \n"
                                "\t\t void swap( std::map<Key,T,Compare,Alloc>& lhs, \n"
                                "\t\t std::map<Key,T,Compare,Alloc>& rhs ); "
                << "\033[0m" << std::endl;
        map<int, char> alice;
        alice.insert( make_pair(1, 'a') );
        alice.insert( make_pair(2, 'b') );
        alice.insert( make_pair(3, 'c') );

        map<int, char> bob;
        bob.insert( make_pair(7, 'Z') );
        bob.insert( make_pair(8, 'Y') );
        bob.insert( make_pair(9, 'X') );
        bob.insert( make_pair(10, 'W') );
    
        // Print state before swap
        std::cout << "alice:";
        for_each_ft(alice.begin(), alice.end(), print_pair);
        std::cout << "\n" "bob  :";
        for_each_ft(bob.begin(), bob.end(), print_pair);
        std::cout << '\n';
    
        std::cout << "-- SWAP\n";
        swap(alice, bob);
    
        // Print state after swap
        std::cout << "alice:";
        for_each_ft(alice.begin(), alice.end(), print_pair);
        std::cout << "\n" "bob  :";
        for_each_ft(bob.begin(), bob.end(), print_pair);
        std::cout << std::endl;

        std::cout << std::endl << "\033[33m" << "_____25-30_____" << "\033[0m" << std::endl;
        std::cout << "\033[35m" << 
                    "\t operator== \n"
                    "\t operator!= \n" 
                    "\t operator< \n" 
                    "\t operator<= \n"
                    "\t operator> \n"
                    "\t operator>= "
                    "\033[0m" << std::endl;

        map<int, char> eve(alice);
    
        std::cout << std::boolalpha;
    
        // Compare non equal containers
        std::cout << "\n\033[36m" << "\t\t alice > bob " << "\033[0m"  << std::endl;
        std::cout << "alice == bob returns " << (alice == bob) << std::endl;
        std::cout << "alice != bob returns " << (alice != bob) << std::endl;
        std::cout << "alice <  bob returns " << (alice < bob) <<  std::endl;
        std::cout << "alice <= bob returns " << (alice <= bob) << std::endl;
        std::cout << "alice >  bob returns " << (alice > bob) <<  std::endl;
        std::cout << "alice >= bob returns " << (alice >= bob) << std::endl;

    
        // Compare equal containers
        std::cout << "\n\033[36m" << "\t\t alice == eve " << "\033[0m"  << std::endl;
        std::cout << "alice == eve returns " << (alice == eve) << std::endl;
        std::cout << "alice != eve returns " << (alice != eve) << std::endl;
        std::cout << "alice <  eve returns " << (alice < eve) <<  std::endl;
        std::cout << "alice <= eve returns " << (alice <= eve) << std::endl;
        std::cout << "alice >  eve returns " << (alice > eve) <<  std::endl;
        std::cout << "alice >= eve returns " << (alice >= eve) << std::endl;

        std::cout << std::endl;
    }
}

void    set_test() {
    { // insert copy
        std::cout << std::endl << "\033[35m" << "CHECK SET insert copy " << "\033[0m" << std::endl;

        set<int> my_tree;
        fill_set(&my_tree);

        set<int> my_tree_copy = my_tree;
    }

    { // reverse iterator
        std::cout << std::endl << "\033[35m" << "CHECK testSET_iterator reverse " << "\033[0m" << std::endl;
        std::cout << std::endl << "\033[35m" << "check ITERATORS reverse " << "\033[0m" << std::endl;
        std::cout << "\033[34m" << "\t iter reverse."
                    "\t\t operator-> "
                    "\t\t operator*  " << "\033[0m" << std::endl;
        std::cout << std::endl << "\033[33m" << "_____9-10_____     iterators set" << "\033[0m" << std::endl;

        set<int>    my_tree;
        fill_set(&my_tree);

        set<int>::reverse_iterator   iter_my_tree1;
        set<int>::reverse_iterator   iter_my_tree2;

        iter_my_tree1 = my_tree.rbegin();
        iter_my_tree2 = my_tree.rend();

        std::cout << "\033[34m" << "\t9) rbegin " << "\033[0m" << std::endl;
        std::cout << "*my_tree.rbegin() = " << *my_tree.rbegin() << std::endl;
        std::cout << "*iter_my_tree1 = " << *iter_my_tree1 << std::endl;
        std::cout << std::endl;

        std::cout << "\033[34m" << "\t10) rend " << "\033[0m" << std::endl;
        std::cout << "*(--( my_tree.rend())) = " << *(--(my_tree.rend())) << std::endl;

        std::cout << "\033[34m" << "\t iter reverse.\n"
                    "\t\t operator++ \n"
                    "\t\t ++operator \n"
                    "\t\t --operator \n"
                    "\t\t operator-- \n"
                    "\t\t operator-> \n"
                    "\t\t operator*  \n"
                << "\033[0m" << std::endl;

        {
            std::cout << "\033[36m" << "\t\tcout iter_reverse operator++" << "\033[0m"  << std::endl;
            std::cout << "\033[36m" << "\t\tfrom rbegin to root (80)" << "\033[0m"  << std::endl;
            iter_my_tree2  =  set<int>::reverse_iterator( my_tree.find(80) );
            while (iter_my_tree1 != iter_my_tree2) {
                std::cout << "\t\t (*iter_my_tree1) = " << (*iter_my_tree1++) << std::endl;
            }
            std::cout << std::endl;

            std::cout << "\033[36m" << "\t\tcout iter_reverse ++operator" << "\033[0m"  << std::endl;
            std::cout << "\033[36m" << "\t\tfrom root (80) to rend" << "\033[0m"  << std::endl;
            iter_my_tree2  =  my_tree.rend();
            while (++iter_my_tree1 != iter_my_tree2) {
                std::cout << "\t\t (*iter_my_tree1) = " << (*iter_my_tree1) << std::endl;
            }
            std::cout << std::endl;
        }

        {
            std::cout << "\033[36m" << "\t\tcout iter_reverse operator--" << "\033[0m"  << std::endl;
            std::cout << "\033[36m" << "\t\tfrom rend to root" << "\033[0m"  << std::endl;
            iter_my_tree1  =  my_tree.rend();
            --iter_my_tree1;
            iter_my_tree2  =  set<int>::reverse_iterator( my_tree.find(80) );
            while (iter_my_tree1 != iter_my_tree2) {
                std::cout << "\t\t (*iter_my_tree1) = " << (*iter_my_tree1--) << std::endl;
            }
            std::cout << std::endl;

            std::cout << "\033[36m" << "\t\tcout iter_reverse --operator" << "\033[0m"  << std::endl;
            std::cout << "\033[36m" << "\t\tfrom root (80) to rbegin" << "\033[0m"  << std::endl;
            iter_my_tree2  =  my_tree.rbegin();
            while (--iter_my_tree1 != iter_my_tree2) {
                std::cout << "\t\t (*iter_my_tree1) = " << (*iter_my_tree1) << std::endl;
            }
            std::cout << std::endl;
        }
    }

    { // non-members
        std::cout << std::endl << "\033[35m" << "CHECK testSET NON-MEMBER FUNCTIONS " << "\033[0m" << std::endl;
        std::cout << std::endl << "\033[33m" << "_____31_____" << "\033[0m" << std::endl;
        std::cout << "\033[34m" << "\t 31) swap "
                << "\033[0m" << std::endl;
        set<int> alice;
        alice.insert( 1 );
        alice.insert( 2 );
        alice.insert( 3 );

        set<int> bob;
        bob.insert( 7  );
        bob.insert( 8  );
        bob.insert( 9  );
        bob.insert( 10 );
    
        // Print state before swap
        std::cout << "alice:";
        for_each_set(alice.begin(), alice.end(), print_int);
        std::cout << "\n" "bob  :";
        for_each_set(bob.begin(), bob.end(), print_int);
        std::cout << '\n';
    
        std::cout << "-- SWAP\n";
        swap(alice, bob);
    
        // Print state after swap
        std::cout << "alice:";
        for_each_set(alice.begin(), alice.end(), print_int);
        std::cout << "\n" "bob  :";
        for_each_set(bob.begin(), bob.end(), print_int);
        std::cout << std::endl;

        std::cout << std::endl << "\033[33m" << "_____25-30_____" << "\033[0m" << std::endl;
        std::cout << "\033[35m" << 
                    "\t operator== \n"
                    "\t operator!= \n" 
                    "\t operator< \n" 
                    "\t operator<= \n"
                    "\t operator> \n"
                    "\t operator>= "
                    "\033[0m" << std::endl;

        set<int> eve(alice);
    
        std::cout << std::boolalpha;
    
        // Compare non equal containers
        std::cout << "\n\033[36m" << "\t\t alice > bob " << "\033[0m"  << std::endl;
        std::cout << "alice == bob returns " << (alice == bob) << std::endl;
        std::cout << "alice != bob returns " << (alice != bob) << std::endl;
        std::cout << "alice <  bob returns " << (alice < bob) <<  std::endl;
        std::cout << "alice <= bob returns " << (alice <= bob) << std::endl;
        std::cout << "alice >  bob returns " << (alice > bob) <<  std::endl;
        std::cout << "alice >= bob returns " << (alice >= bob) << std::endl;

    
        // Compare equal containers
        std::cout << "\n\033[36m" << "\t\t alice == eve " << "\033[0m"  << std::endl;
        std::cout << "alice == eve returns " << (alice == eve) << std::endl;
        std::cout << "alice != eve returns " << (alice != eve) << std::endl;
        std::cout << "alice <  eve returns " << (alice < eve) <<  std::endl;
        std::cout << "alice <= eve returns " << (alice <= eve) << std::endl;
        std::cout << "alice >  eve returns " << (alice > eve) <<  std::endl;
        std::cout << "alice >= eve returns " << (alice >= eve) << std::endl;

        std::cout << std::endl;
    }
}


// -------------- UTILITY -------------- //

template < class T>
void print_vector(T & characters) {
    for (typename T::iterator iter = characters.begin();
         iter != characters.end(); ++iter) {
        std::cout << *iter << ' ';
    }
    std::cout << std::endl;  
}

void    fill_map(map<int, ::std::string> &my_tree) {
    my_tree.insert(make_pair(80, "At "));
    my_tree.insert(make_pair(40, "the "));
    my_tree.insert(make_pair(150, "Mountains "));
    my_tree.insert(make_pair(60, "of "));
    my_tree.insert(make_pair(20, "Madness "));
    my_tree.insert(make_pair(10, "... "));
    my_tree.insert(make_pair(170, "..170.. "));
    my_tree.insert(make_pair(140, "..140.. "));
    my_tree.insert(make_pair(120, "..120.. "));
    my_tree.insert(make_pair(0, "..0.. "));
    my_tree.insert(make_pair(-10, "..-10.. "));
    my_tree.insert(make_pair(130, "..130.. "));
    my_tree.insert(make_pair(110, "..110.. "));
    my_tree.insert(make_pair(122, "..122.. "));
    my_tree.insert(make_pair(100, "..100.. "));
    my_tree.insert(make_pair(90, "..90.. "));
    my_tree.insert(make_pair(85, "..85.. "));

}

template<class Iter >
void
for_each_ft(Iter begin, Iter end, void(*op)(pair<const int, char>& )) {
    for ( ; begin != end ; ++begin ) {
        op(*begin);
    }
}

template<class Iter >
void
for_each_set(Iter begin, Iter end, void(*op)(int)) {
    for ( ; begin != end ; ++begin ) {
        op(*begin);
    }
}

void    print_pair(pair<const int, char>& n) { 
    std::cout << " " << n.first << '(' << n.second << ')'; 
}

void    print_int(int n) { 
    std::cout << " " << n ; 
}

void    fill_set(set<int> * my_tree) {
    if (my_tree != NULL) {
        my_tree->insert(80  );
        my_tree->insert(40  );
        my_tree->insert(150 );
        my_tree->insert(60  );
        my_tree->insert(20  );
        my_tree->insert(10  );
        my_tree->insert(170 );
        my_tree->insert(140 );
        my_tree->insert(120 );
        my_tree->insert(0   );
        my_tree->insert(-10 );
        my_tree->insert(130 );
        my_tree->insert(110 );
        my_tree->insert(122 );
        my_tree->insert(100 );
        my_tree->insert(90  );
        my_tree->insert(85  );
    }
}
