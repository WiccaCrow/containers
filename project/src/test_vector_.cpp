#include <iostream>
#include <vector>
#include <ft_vector.hpp>

void    check_insert();
void    check_insert_iter();

template < class T>
void print_vector(ft::vector<T> & characters);

int main() {
    std::cout << std::endl << "\033[35m" << "CHECK MODIFIERS " << "\033[0m" << std::endl; 
    check_insert();
    check_insert_iter();
}

template < class T>
void print_vector(ft::vector<T> & characters) {
    for (typename ft::vector<T>::iterator iter = characters.begin();
         iter != characters.end(); ++iter) {
        std::cout << *iter << ' ';
    }
    std::cout << std::endl;  
}

void    check_insert() {
    std::cout << std::endl << "\033[33m" << "_____20_____     " << "\033[0m" << std::endl;
    
    {
        std::cout << "\n\033[34m" << "\t20.4) template< class InputIt >\n"
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

        ft::vector<std::string>    ft_vect(vect_for_iter.begin(), vect_for_iter.end());
        ft::vector<std::string>::iterator  ft_iter = ft_vect.begin();
        for (;ft_iter < ft_vect.end(); ++ft_iter) {
            std::cout << *ft_iter;
        }
        std::cout << "capacity: " << ft_vect.capacity() << std::endl;
        std::cout << "size:     " << ft_vect.size() << std::endl;

        // // vect_for_iter.insert(vect_for_iter.begin() + vect_for_iter.size()/3*2, ft_vect.begin().base(), ft_vect.end().base() - 1);
        // // std::vector<std::string>::iterator  std_iter = vect_for_iter.begin();
        // // for (;std_iter < vect_for_iter.end(); ++std_iter) {
        // //     std::cout << *std_iter;
        // // }
        // // std::cout << "capacity: " << vect_for_iter.capacity() << std::endl;
        // // std::cout << "size:     " << vect_for_iter.size() << std::endl;

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

        // // std::vector<std::string>::iterator  std_iter = vect_for_iter.begin();
        // // for (;std_iter < vect_for_iter.end(); ++std_iter) {
        // //     std::cout << *std_iter;
        // // }
        // // std::cout << "capacity: " << vect_for_iter.capacity() << std::endl;
        // // std::cout << "size:     " << vect_for_iter.size() << std::endl;

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
}

void    check_insert_iter() {
    std::cout << std::endl << "\033[35m" << "CHECK MODIFIERS " << "\033[0m" << std::endl;
    {
        std::cout << "\n\033[34m" << "\t4) template< class InputIt >\n"
                                     "\t   void insert( iterator pos, InputIt first, InputIt last ); "
                                     << "\033[0m" << std::endl;
        std::vector<int>    vect_for_iter(5);

        std::vector<int>::iterator  iter = vect_for_iter.begin();
        for (int i = 0;iter < vect_for_iter.end(); ++iter, ++i) {
            *iter = i;
            std::cout << *iter;
        }
        std::cout << std::endl;

        ft::vector<int>    vect_for_iter_copy;
        iter = vect_for_iter.begin();
        vect_for_iter_copy.insert(vect_for_iter_copy.begin(), vect_for_iter.data(), vect_for_iter.data() + vect_for_iter.size());
        ft::vector<int>::iterator  ft_iter = vect_for_iter_copy.begin();
        for (int i = 0; ft_iter < vect_for_iter_copy.end(); ++ft_iter, ++i) {
            *ft_iter = i;
            std::cout << *ft_iter;
        }
        std::cout << std::endl;
    }
}
