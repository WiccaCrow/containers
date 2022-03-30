#include <iostream>
#include <vector>
#include <ft_vector.hpp>

void    check_constructor();
void    check_asisgn();
void    check_Element_access_and_iterators();
void    check_insert();


int main() {
    check_constructor(); // 1, 2, 3
    check_insert();
    check_asisgn(); // 4,      21.3
    // check_Element_access_and_iterators(); // 6
}

void    check_constructor() {
    std::cout << std::endl << "\033[35m" << "CHECK CONSTRUCTORS " << "\033[0m" << std::endl;
    std::cout << "\t\033[35m" << "with capacity, size " << "\033[0m" << std::endl;
    {
        std::cout << std::endl << "\033[33m" << "_____1.1_____" << "\033[0m" << std::endl;
        std::cout << "\033[34m" << "\t1) vector(); " << "\033[0m" << std::endl;
        std::vector<int> std_vec_int();
        ft::vector<int>  ft_vec_int();

        // does not compile
        // std::cout << "capacity: " << std_vec_int.capacity() << std::endl;
        // std::cout << "size: " << std_vec_int.size() << std::endl;

        // std::cout << "capacity: " << ft_vec_int.capacity() << std::endl;
        // std::cout << "size: " << ft_vec_int.size() << std::endl;
    }
    {
        std::cout << std::endl << "\033[33m" << "_____1.2_____" << "\033[0m" << std::endl;
        std::cout << "\033[34m" << "\t2) explicit vector( const Allocator& alloc ); " << "\033[0m" << std::endl;
        std::allocator<int> alloc;
        std::vector<int> std_vec_int(alloc);
        std::allocator<int> alloc1;
        ft::vector<int>  ft_vec_int(alloc1);
        std_vec_int.push_back(5);
        // ft_vec_int.push_back(5);
        std::cout << "\n\033[36m" << "\t\tpush_back(5) " << "\033[0m"  << std::endl;
        std::cout << "std  |  ft " << std::endl;
        std::cout << std_vec_int[0] << "  |  " << std::endl;
        // std::cout << std_vec_int[0] << "  |  " << ft_vec_int[0] << std::endl;
    }
    {
        std::cout << std::endl << "\033[33m" << "_____1.3_____" << "\033[0m" << std::endl;
        std::cout << "\n\033[34m" << "\t3) explicit vector( size_type count,\n"
                 "\t\t\t    const T& value = T(),\n"
                 "\t\t\t    const Allocator& alloc = Allocator());" 
                 "\n\t5 elements " << "\033[0m" << std::endl;
        std::vector<int> std_vec_int(5);
        ft::vector<int>  ft_vec_int(5);

        std::cout << "         std  |  ft " << std::endl;
        std::cout << "capacity: " << std_vec_int.capacity() << "   |   " << ft_vec_int.capacity() << std::endl;
        std::cout << "size:     " << std_vec_int.size() << "   |   " << ft_vec_int.size() << std::endl;
        std::cout << std::endl;
    }
    {
        std::cout << "\n\033[34m" << "\t5 elements, std::string \"hello \" " << "\033[0m" << std::endl;
        int size = 5;
        std::vector<std::string> std_vec_str(size, "hello ");
        ft::vector<std::string>  ft_vec_str(size, "hello ");

        std::cout << "         std  |  ft " << std::endl;
        std::cout << "capacity: " << std_vec_str.capacity() << "   |   " << ft_vec_str.capacity() << std::endl;
        std::cout << "size:     " << std_vec_str.size() << "   |   " << ft_vec_str.size() << std::endl;
        std::cout << "\n\033[36m" << "\t\tcout " << "\033[0m"  << std::endl;
        std::cout << "   std  |  ft " << std::endl;
        for (int i = 0; i < size; ++i) {
            std::cout << std_vec_str[i] << "  |  " << ft_vec_str[i] << std::endl;

        }
        std::cout << std::endl;
    }
    {
        std::cout << "\n\033[34m" << "\t5 elements, std::string \"hello \", allocator " << "\033[0m" << std::endl;
        int size = 5;
        std::allocator<std::string> alloc;
        std::vector<std::string> std_vec_str(size, "hello ", alloc);
        ft::vector<std::string>  ft_vec_str(size, "hello ", alloc);

        std::cout << "         std  |  ft " << std::endl;
        std::cout << "capacity: " << std_vec_str.capacity() << "   |   " << ft_vec_str.capacity() << std::endl;
        std::cout << "size:     " << std_vec_str.size() << "   |   " << ft_vec_str.size() << std::endl;
        std::cout << "\n\033[36m" << "\t\tcout " << "\033[0m"  << std::endl;
        std::cout << "   std  |  ft " << std::endl;
        for (int i = 0; i < size; ++i) {
            std::cout << std_vec_str[i] << "  |  " << ft_vec_str[i] << std::endl;
        }
        std::cout << std::endl;
    }

    {
        std::cout << std::endl << "\033[33m" << "_____1.5_____" << "\033[0m" << std::endl;
        std::cout << "\n\033[34m" << "\t5) template< class InputIt >\n"
                                     "\t   vector( InputIt first, InputIt last,\n"
                                     "\t\t   const Allocator& alloc = Allocator() ); "
                                     << "\033[0m" << std::endl;
        std::vector<std::string>    vect_for_iter;
        vect_for_iter.push_back("Hello ");
        vect_for_iter.push_back("my ");
        vect_for_iter.push_back("very ");
        vect_for_iter.push_back("beautiful ");
        vect_for_iter.push_back("world ");
        vect_for_iter.push_back("!!!\n");
        std::vector<std::string>::iterator  iter = vect_for_iter.begin();
        for (;iter < vect_for_iter.end(); ++iter) {
            std::cout << *iter;
        }
        iter = vect_for_iter.begin();

        std::cout << "test ft_vect\n";

        ft::vector<std::string>    ft_vect(vect_for_iter.data(), vect_for_iter.data() + vect_for_iter.size());
        ft::vector<std::string>::iterator  ft_iter = ft_vect.begin();
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
        std::vector<std::string>    vect_for_iter;
        vect_for_iter.push_back("Hello ");
        vect_for_iter.push_back("my ");
        vect_for_iter.push_back("very ");
        vect_for_iter.push_back("beautiful ");
        vect_for_iter.push_back("world ");
        vect_for_iter.push_back("!!!\n");
        ft::vector<std::string>    ft_vect(vect_for_iter.data(), vect_for_iter.data() + vect_for_iter.size());
        ft::vector<std::string>    ft_vect_copy = ft_vect;
        ft::vector<std::string>::iterator ft_iter = ft_vect_copy.begin();
        for (;ft_iter < ft_vect_copy.end(); ++ft_iter) {
            std::cout << *ft_iter;
        }
        std::cout << "capacity: " << ft_vect_copy.capacity() << std::endl;
        std::cout << "size:     " << ft_vect_copy.size() << std::endl;
    }
}

void    check_insert() {
    std::cout << std::endl << "\033[35m" << "CHECK MODIFIERS " << "\033[0m" << std::endl;
    {
        std::cout << "\n\033[34m" << "\t4) template< class InputIt >\n"
                                     "\t   void insert( iterator pos, InputIt first, InputIt last ); "
                                     << "\033[0m" << std::endl;
        std::vector<std::string>    vect_for_iter;
        vect_for_iter.push_back("Hello ");
        vect_for_iter.push_back("my ");
        vect_for_iter.push_back("very ");
        vect_for_iter.push_back("beautiful ");
        vect_for_iter.push_back("world ");
        vect_for_iter.push_back("!!!\n");
        std::vector<std::string>::iterator  iter = vect_for_iter.begin();
        for (;iter < vect_for_iter.end(); ++iter) {
            std::cout << *iter;
        }
        iter = vect_for_iter.begin();

        ft::vector<std::string>    ft_vect(vect_for_iter.data(), vect_for_iter.data() + vect_for_iter.size());
        ft::vector<std::string>::iterator  ft_iter = ft_vect.begin();
        for (;ft_iter < ft_vect.end(); ++ft_iter) {
            std::cout << *ft_iter;
        }
        std::cout << "capacity: " << ft_vect.capacity() << std::endl;
        std::cout << "size:     " << ft_vect.size() << std::endl;

        // vect_for_iter.insert(vect_for_iter.begin() + vect_for_iter.size()/3*2, ft_vect.begin().base(), ft_vect.end().base() - 1);
        // std::vector<std::string>::iterator  std_iter = vect_for_iter.begin();
        // for (;std_iter < vect_for_iter.end(); ++std_iter) {
        //     std::cout << *std_iter;
        // }
        // std::cout << "capacity: " << vect_for_iter.capacity() << std::endl;
        // std::cout << "size:     " << vect_for_iter.size() << std::endl;

        // ft_vect.insert(ft_vect.begin() + ft_vect.size()/3*2, vect_for_iter.begin().base(), vect_for_iter.end().base() - 1);
        ft_vect.insert(ft_vect.begin() + ft_vect.size()/3*2, vect_for_iter.begin().base(), vect_for_iter.begin().base() + 1);
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

        std::vector<std::string>::iterator  std_iter = vect_for_iter.begin();
        for (;std_iter < vect_for_iter.end(); ++std_iter) {
            std::cout << *std_iter;
        }
        std::cout << "capacity: " << vect_for_iter.capacity() << std::endl;
        std::cout << "size:     " << vect_for_iter.size() << std::endl;

        ft_vect.insert(ft_vect.begin() + ft_vect.size()/3*2, vect_for_iter.begin().base(), vect_for_iter.begin().base() + 1);
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

        std::cout << "\n\033[34m" << "\t2) iterator erase( iterator first, iterator last );"
                                  << "\033[0m" << std::endl;
        ft_vect.erase(ft_vect.begin() + 4, ft_vect.begin() + 6);
        ft_iter = ft_vect.begin();
        for (;ft_iter < ft_vect.end(); ++ft_iter) {
            std::cout << *ft_iter;
        }
        std::cout << "capacity: " << ft_vect.capacity() << std::endl;
        std::cout << "size:     " << ft_vect.size() << std::endl;

        std::cout << "\n\033[34m" << "\tvoid clear();"
                                  << "\033[0m" << std::endl;
        ft_vect.clear();
        std::cout << "capacity: " << ft_vect.capacity() << std::endl;
        std::cout << "size:     " << ft_vect.size() << std::endl;
    }
    {

    }
}

template < class T>
void print_vector(ft::vector<T> & characters) {
    for (typename ft::vector<T>::iterator iter = characters.begin();
         iter != characters.end(); ++iter) {
        std::cout << *iter << ' ';
    }
    std::cout << std::endl;  
}

void    check_asisgn() {
    ft::vector<char> characters;

    std::cout << std::endl << "\033[33m" << "_____4.1_____" << "\033[0m" << std::endl;
    std::cout << "\033[34m" << "\t4.1) void assign( size_type count, const T& value );  " << "\033[0m" << std::endl;

    characters.assign(5, 'a');
        for (typename ft::vector<char>::iterator iter = characters.begin();
         iter != characters.end(); ++iter) {
        std::cout << *iter << ' ';
    }
    std::cout << std::endl; 

    std::cout << std::endl << "\033[33m" << "_____4.2_____" << "\033[0m" << std::endl;
    std::cout << "\033[34m" << "\t4.2) template< class InputIt >\n"
                               "\t     void assign( InputIt first, InputIt last );  " << "\033[0m" << std::endl;

    const std::string extra(6, 'b');
    characters.assign(extra.begin(), extra.end());
        for (typename ft::vector<char>::iterator iter = characters.begin();
         iter != characters.end(); ++iter) {
        std::cout << *iter << ' ';
    }
    std::cout << std::endl;
}


void    check_Element_access_and_iterators() {
    // https://en.cppreference.com/w/cpp/container/vector/at


    // std::cout << std::endl << "\033[33m" << "_____6 - 10_____     Element access" << "\033[0m" << std::endl;
    // std::cout << "\033[34m" << "\t6) at " << "\033[0m" << std::endl;

    // ft::vector<int> data;
    // // data.push_back(1);
    // // data.push_back(2);
    // // data.push_back(4);
    // // data.push_back(5);
    // // data.push_back(5);
    // // data.push_back(6);
    // data.insert(data.begin(), 1, 6);
    // // data.insert(data.begin(), 1, 5);
    // // data.insert(data.begin(), 1, 5);
    // // data.insert(data.begin(), 1, 4);
    // // data.insert(data.begin(), 1, 2);
    // // data.insert(data.begin(), 1, 1);



    // // // Set element 1
    // // data.at(1) = 88;
 
    // // // Read element 2
    // // std::cout << "Element at index 2 has value " << data.at(2) << '\n';
 
    // // std::cout << "data size = " << data.size() << '\n';
 
    // // try {
    // //     // Set element 6
    // //     data.at(6) = 666;
    // // } catch (std::out_of_range const& exc) {
    // //     std::cout << exc.what() << '\n';
    // // }
 
    // // // Print final values
    // // std::cout << "data:";
    // // for (long unsigned int i = 0; i < data.size(); ++i)
    // //     std::cout << " " << data[i];
    // // std::cout << '\n';

    // // std::cout << "\033[34m" << "\t7) operator[] " << "\033[0m" << std::endl;
    // // std::cout << "data[2] = " << data[2] << std::endl;

    // // std::cout << "\033[34m" << "\t8) front " << "\033[0m" << std::endl;
    // // std::cout << "front = " << data.front() << std::endl;

    // // std::cout << "\033[34m" << "\t9) back " << "\033[0m" << std::endl;
    // // std::cout << "back = " << data.back() << std::endl;

    // // std::cout << "\033[34m" << "\t10) data " << "\033[0m" << std::endl;
    // // std::cout << "*data.data() = " << *data.data() << std::endl;
    // // std::cout << " data.data() = " << data.data() << std::endl;


    // // std::cout << std::endl << "\033[33m" << "_____11-14_____     iterators" << "\033[0m" << std::endl;
    
    // // std::cout << "\033[34m" << "\t11) begin " << "\033[0m" << std::endl;
    // // std::cout << "*data.begin(); \n" << *data.begin() << std::endl;

    // // std::cout << "\033[34m" << "\t12) end " << "\033[0m" << std::endl;
    // // std::cout << "*(data.end() - 1); \n" << *(data.end() - 1) << std::endl;

    // // std::cout << "\033[34m" << "\t13) rbegin " << "\033[0m" << std::endl;
    // // std::cout << "*data.rbegin(); \n" << *data.rbegin() << std::endl;

    // // std::cout << "\033[34m" << "\t14) rend " << "\033[0m" << std::endl;
    // // std::cout << "*(data.rend() - 1); \n" << *(data.rend() - 1) << std::endl;


}