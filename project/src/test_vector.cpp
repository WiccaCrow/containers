#include <iostream>
#include <vector>
#include <ft_vector.hpp>

void    check_constructor();
void    check_insert();


int main() {
    check_constructor();
    check_insert();
}

void    check_constructor() {
    std::cout << std::endl << "\033[35m" << "CHECK CONSTRUCTORS " << "\033[0m" << std::endl;
    std::cout << "\t\033[35m" << "with capacity, size " << "\033[0m" << std::endl;
    {
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
        std::cout << "\n\033[34m" << "\t4) template< class InputIt >\n"
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
}

void    check_insert() {
    std::cout << std::endl << "\033[35m" << "CHECK INSERT " << "\033[0m" << std::endl;
    {
        std::cout << "\n\033[34m" << "\t4) template< class InputIt >\n"
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
    }
}