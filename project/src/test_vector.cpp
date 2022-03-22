#include <iostream>
#include <vector>
#include <ft_vector.hpp>

void    check_constructor();

int main() {
    check_constructor();


}

void    check_constructor() {
    std::cout << std::endl << "\033[35m" << "CHECK CONSTRUCTORS " << "\033[0m" << std::endl;
    std::cout << "\t\033[35m" << "with capacity, size " << "\033[0m" << std::endl;
    {
        std::cout << "\033[34m" << "\tvoid " << "\033[0m" << std::endl;
        std::vector<int> std_vec_int();
        ft::vector<int>  ft_vec_int();

        // does not compile
        // std::cout << "capacity: " << std_vec_int.capacity() << std::endl;
        // std::cout << "size: " << std_vec_int.size() << std::endl;

        // std::cout << "capacity: " << ft_vec_int.capacity() << std::endl;
        // std::cout << "size: " << ft_vec_int.size() << std::endl;
    }
    {
        std::cout << "\033[34m" << "\tallocator " << "\033[0m" << std::endl;
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
        std::cout << "\n\033[34m" << "\t5 elements " << "\033[0m" << std::endl;
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
}
