#include <iostream>
#include <string>
#include <deque>
// #if 1 //CREATE A REAL STL EXAMPLE
// 	#include <map>
// 	#include <stack>
// 	#include <vector>
// 	namespace ft = std;
// #else
	#include <map.hpp>
	#include <stack.hpp>
	#include <vector.hpp>
// #endif

#include <stdlib.h>

#define MAX_RAM 4294967296
#define BUFFER_SIZE 4096
struct Buffer
{
	int idx;
	char buff[BUFFER_SIZE];
};

template <typename T>
void tree_picture(ft::map<int, T> &my_tree);

#define COUNT (MAX_RAM / (int)sizeof(Buffer))
// #define COUNT 16


template<typename T>
class MutantStack : public ft::stack<T>
{
public:
	MutantStack() {}
	MutantStack(const MutantStack<T>& src) { *this = src; }
	MutantStack<T>& operator=(const MutantStack<T>& rhs) 
	{
		this->c = rhs.c;
		return *this;
	}
	~MutantStack() {}

	typedef typename ft::stack<T>::container_type::iterator iterator;

	iterator begin() { return this->c.begin(); }
	iterator end() { return this->c.end(); }
};

int main(int argc, char** argv) {
	if (argc != 2)
	{
		std::cerr << "Usage: ./test seed" << std::endl;
		std::cerr << "Provide a seed please" << std::endl;
		std::cerr << "Count value:" << COUNT << std::endl;
		return 1;
	}
	const int seed = atoi(argv[1]);
	srand(seed);
	std::cout << "test 1 " << std::endl;

	ft::vector<std::string> vector_str;
	ft::vector<int> vector_int;
	ft::stack<int> stack_int;
	ft::vector<Buffer> vector_buffer;
	ft::stack<Buffer, std::deque<Buffer> > stack_deq_buffer;
	ft::map<int, int> map_int;
	std::cout << "test 2 " << std::endl;

	for (int i = 0; i < COUNT; i++)
	{
		vector_buffer.push_back(Buffer());
	}
	std::cout << "test 3 " << std::endl;

	for (int i = 0; i < COUNT; i++)
	{
		const int idx = rand() % COUNT;
		vector_buffer[idx].idx = 5;
	}
	std::cout << "test 4 " << std::endl;

	ft::vector<Buffer>().swap(vector_buffer);
	std::cout << "test 5 " << std::endl;

	try
	{
		for (int i = 0; i < COUNT; i++)
		{
			const int idx = rand() % COUNT;
			vector_buffer.at(idx);
			std::cerr << "Error: THIS VECTOR SHOULD BE EMPTY!!" <<std::endl;
		}
	}
	catch(const std::exception& e)
	{
		//NORMAL ! :P
	}
	std::cout << "test 6 " << std::endl;
	
	for (int i = 0; i < COUNT; ++i)
	{
	std::cout << i << " = i test 6 size: " << map_int.size()  << std::endl;
		map_int.insert(ft::make_pair(rand(), rand()));
		// tree_picture(map_int);

	}
	std::cout << "test 7 " << std::endl;

	int sum = 0;
	std::cout << " map_int size: " << map_int.size() << std::endl;
	for (int i = 0; i < 10000; i++)
	// for (int i = 0; i < COUNT; i++)
	{
		int access = rand();
		sum += map_int[access];
	// std::cout << i << " = i test 7 sum: " << sum << std::endl;
	}
	std::cout << "should be constant with the same seed: " << sum << std::endl;

	{
		ft::map<int, int> copy = map_int;
	}
	MutantStack<char> iterable_stack;
	for (char letter = 'a'; letter <= 'z'; letter++)
		iterable_stack.push(letter);
	for (MutantStack<char>::iterator it = iterable_stack.begin(); it != iterable_stack.end(); it++)
	{
		std::cout << *it;
	}
	std::cout << std::endl;
	std::cout << "test 8 " << std::endl;

	// tree_picture(map_int);

	return (0);
}

#include <iomanip>

int nb_setw = 10;
std::string nb_str_space(nb_setw, ' ');

template <typename T>
void print_int_key_node(ft::Node<ft::pair<const int, T> > *node) {
    if ( node->_is_empty == false ) {
        if ( node->color == 1 ) {
            std::cout << "\033[30;41m" << std::setw(nb_setw) << node->data.first << "\033[0m";
        } else {
            std::cout << "\033[37;40m" << std::setw(nb_setw) << node->data.first << "\033[0m";
        }
    } else {
		if ( nb_setw > 3 ) {
			std::cout << "\033[37;40m";
			for ( int i = 0; i < (nb_setw - 3)/2; ++i) {
        		std::cout << nb_str_space[i] ;
			}
        	std::cout << "NIL" ;
			for ( int i = (nb_setw - 3)/2 + 3; i <= nb_setw; ++i) {
        		std::cout << nb_str_space[i] ;
			}
        	std::cout << "\033[0m" ;
		} else {
        	std::cout << "\033[37;40m" " NIL " "\033[0m" ;
		}
    }
}

template <typename T>
void tree_picture(ft::map<int, T> &my_tree) {
    if ( my_tree.empty() ) {
        std::cout << "Tree is empty. " << std::endl;
        return ;
    }
	std::string str_start(nb_setw/2, ' ');
	std::string str____(nb_setw + 2, '_');

    // 80
    std::cout << str_start << nb_str_space << nb_str_space << nb_str_space
    		  << nb_str_space << nb_str_space << nb_str_space << nb_str_space
			  << "              " ;
    print_int_key_node( my_tree.root().base() );
    std::cout << std::endl;

    std::cout << str_start << nb_str_space << nb_str_space << nb_str_space << nb_str_space << "      " 
	          << str____ << str____ << str____ << "_/" << nb_str_space << "\\_"
			  << str____ << str____ << str____ << std::endl;
    // 10 120 // 2h
    std::cout << str_start << nb_str_space << nb_str_space << nb_str_space << "      ";
    print_int_key_node( my_tree.root().base()->left ); // 2h-1w pos
    std::cout << nb_str_space << nb_str_space << nb_str_space << nb_str_space;
    std::cout << nb_str_space << nb_str_space << nb_str_space << "                ";

    print_int_key_node( my_tree.root().base()->right ); // 2h-2w pos
    if ( my_tree.root().base()->left->_is_empty == false && my_tree.root().base()->right->_is_empty == false) {
        std::cout << std::endl << str_start << nb_str_space << "  "<< nb_str_space << str____ << "_/" << nb_str_space << "\\_" << str____  
				  << nb_str_space << nb_str_space << nb_str_space << nb_str_space << "        " << nb_str_space 
				  << str____ << "_/" << nb_str_space << "\\_" << str____ << std::endl;  // 3h-1,2,3,4w pos
    } else if ( my_tree.root().base()->left->_is_empty == false && my_tree.root().base()->right->_is_empty == true ) {
        std::cout << std::endl << str_start << nb_str_space << "  "<< nb_str_space << str____ << "_/" << nb_str_space << "\\_" << str____ << std::endl;
    } else if (my_tree.root().base()->left->_is_empty == true && my_tree.root().base()->right->_is_empty == false) {
        std::cout << std::endl << str_start << nb_str_space << "  "<< nb_str_space << nb_str_space << "    " << nb_str_space << "    " << nb_str_space  
				  << nb_str_space << nb_str_space << nb_str_space << nb_str_space << "        " << nb_str_space 
				  << str____ << "_/" << nb_str_space << "\\_" << str____ << std::endl;  // 3h-1,2,3,4w pos
    } else {
        std::cout << std::endl;
        return ;
    }
    // 0 40 100 140 // 3h
    if ( my_tree.root().base()->left->_is_empty == false ) {
        std::cout << str_start << nb_str_space << " _";
        print_int_key_node( my_tree.root().base()->left->left ); // 3h-1w pos
        std::cout << "_" << "      " << nb_str_space << nb_str_space << nb_str_space << "_";
        print_int_key_node( my_tree.root().base()->left->right ); // 3h-2w pos
        std::cout << "_" << "      " << nb_str_space << nb_str_space << nb_str_space;
    } else {
        std::cout << str_start << nb_str_space << "   "
                  << nb_str_space // 3h-1w pos
                  << "          " << nb_str_space << nb_str_space << nb_str_space << " "
                  << nb_str_space // 3h-2w pos
                  << " " << "      " << nb_str_space << nb_str_space << nb_str_space;
    }
    if ( my_tree.root().base()->right->_is_empty == false ) {
        std::cout << "_";
        print_int_key_node( my_tree.root().base()->right->left ); // 3h-3w pos
        std::cout << "_" << "      " << nb_str_space << nb_str_space << nb_str_space << "_";
        print_int_key_node( my_tree.root().base()->right->right ); // 3h-4w pos
        std::cout << "_";
    }
    
    std::cout << std::endl;
    if ( my_tree.root().base()->left->_is_empty == false &&
         my_tree.root().base()->left->left->_is_empty == false ) {
        std::cout << str_start << nb_str_space << "/" << nb_str_space << "  \\    "; // 4h-1,2w pos
    } else {
        std::cout << str_start << nb_str_space << nb_str_space << "        "; // 4h-1,2w pos
    }
    if ( my_tree.root().base()->left->_is_empty == false &&
         my_tree.root().base()->left->right->_is_empty == false ) {
        std::cout << nb_str_space << nb_str_space << nb_str_space << "/" << nb_str_space << "  \\    "; // 4h-3,4w pos
    } else {
        std::cout << nb_str_space << nb_str_space << nb_str_space << nb_str_space << "        "; // 4h-3,4w pos
    }
    if ( my_tree.root().base()->right->_is_empty == false &&
         my_tree.root().base()->right->left->_is_empty == false ) {
        std::cout << nb_str_space << nb_str_space << nb_str_space << "/" << nb_str_space << "  \\    "; // 4h-5,6w pos
    } else {
        std::cout << nb_str_space << nb_str_space << nb_str_space << nb_str_space << "        "; // 4h-5,6w pos
    }
    if ( my_tree.root().base()->right->_is_empty == false &&
         my_tree.root().base()->right->right->_is_empty == false ) {
        std::cout << nb_str_space << nb_str_space << nb_str_space << "/" << nb_str_space << "  \\    "; // 4h-7,8w pos
    }
    std::cout << std::endl;
    // -10 NIL 20 NIL 90 110 130 150
    if ( ( my_tree.root().base()->left->_is_empty && 
           my_tree.root().base()->right->_is_empty ) ||
         ( my_tree.root().base()->left->_is_empty == false &&
           my_tree.root().base()->left->left->_is_empty && 
           my_tree.root().base()->left->right->_is_empty && 
           my_tree.root().base()->right->_is_empty ) ||
         ( my_tree.root().base()->right->_is_empty == false &&
           my_tree.root().base()->right->left->_is_empty && 
           my_tree.root().base()->right->right->_is_empty && 
           my_tree.root().base()->left->_is_empty )
       ) {
           return ;
    }

    if ( my_tree.root().base()->left->_is_empty ) {
        std::cout << str_start << nb_str_space << nb_str_space << "        ";
    } else {
        if (my_tree.root().base()->left->left->_is_empty == false) {
            std::cout << str_start;
            print_int_key_node( my_tree.root().base()->left->left->left ); // 4h-1w pos
            std::cout << nb_str_space << "    ";
            print_int_key_node( my_tree.root().base()->left->left->right ); // 4h-2w pos
            std::cout << nb_str_space << "    ";
        } else {
            std::cout << str_start << nb_str_space << nb_str_space << "    " << nb_str_space << nb_str_space << "    ";
        }
        if (my_tree.root().base()->left->right->_is_empty == false) {
            print_int_key_node( my_tree.root().base()->left->right->left ); // 4h-3w pos
            std::cout << nb_str_space << "    ";
            print_int_key_node( my_tree.root().base()->left->right->right ); // 4h-4w pos
            std::cout << nb_str_space << "    ";
        } else {
            std::cout << nb_str_space << nb_str_space << "    " << nb_str_space << nb_str_space << "    ";
        }
    }
    if ( my_tree.root().base()->right->_is_empty == false ) {
        if (my_tree.root().base()->right->left->_is_empty == false) {
            print_int_key_node( my_tree.root().base()->right->left->left ); // 4h-5w pos
            std::cout << nb_str_space << "    ";
            print_int_key_node( my_tree.root().base()->right->left->right ); // 4h-6w pos
            std::cout << nb_str_space << "    ";
        } else {
            std::cout << nb_str_space << nb_str_space << "    " << nb_str_space << nb_str_space << "    ";
        }
        if (my_tree.root().base()->right->right->_is_empty == false) {
            print_int_key_node( my_tree.root().base()->right->right->left ); // 4h-7w pos
            std::cout << nb_str_space << "    ";
            print_int_key_node( my_tree.root().base()->right->right->right ); // 4h-8w pos
        }
    }
    std::cout << std::endl;
    if ( my_tree.root().base()->left->_is_empty == false &&
         my_tree.root().base()->left->left->_is_empty == false &&
         my_tree.root().base()->left->left->left->_is_empty == false ) {
        std::cout << nb_str_space << "/\\  " << nb_str_space ; // 5h-1,2w pos
    } else {
        std::cout << nb_str_space << nb_str_space << "    " ; // 5h-1w pos

    }
    if ( my_tree.root().base()->left->_is_empty == false &&
         my_tree.root().base()->left->left->_is_empty == false &&
         my_tree.root().base()->left->left->right->_is_empty == false) {
        std::cout << nb_str_space << "/\\  " << nb_str_space ; // 5h-3,4w pos
    } else {
        std::cout << nb_str_space << nb_str_space << "    " ; // 5h-3,4w pos
    }
    if ( my_tree.root().base()->left->_is_empty == false &&
         my_tree.root().base()->left->right->_is_empty == false &&
         my_tree.root().base()->left->right->left->_is_empty == false) {
        std::cout << nb_str_space << "/\\  " << nb_str_space; // 5h-5,6w pos
    } else {
        std::cout << nb_str_space << nb_str_space << "    " ; // 5h-5,6w pos
    }
    if ( my_tree.root().base()->left->_is_empty == false &&
         my_tree.root().base()->left->right->_is_empty == false &&
         my_tree.root().base()->left->right->right->_is_empty == false) {
        std::cout << nb_str_space << "/\\  " << nb_str_space; // 5h-7,8w pos
    } else {
        std::cout << nb_str_space << nb_str_space << "    " ; // 5h-7,8w pos
    }


    if ( my_tree.root().base()->right->_is_empty == false &&
         my_tree.root().base()->right->left->_is_empty == false &&
         my_tree.root().base()->right->left->left->_is_empty == false) {
        std::cout << nb_str_space << "/\\  " << nb_str_space ; // 5h-9,10w pos
    } else {
        std::cout << nb_str_space << nb_str_space << "    " ; // 5h-9,10w pos
    }
    if ( my_tree.root().base()->right->_is_empty == false &&
         my_tree.root().base()->right->left->_is_empty == false &&
         my_tree.root().base()->right->left->right->_is_empty == false) {
        std::cout << nb_str_space << "/\\  " << nb_str_space ; // 5h-11,12w pos
    } else {
        std::cout << nb_str_space << nb_str_space << "    " ; // 5h-11,12w pos
    }
    if ( my_tree.root().base()->right->_is_empty == false &&
         my_tree.root().base()->right->right->_is_empty == false &&
         my_tree.root().base()->right->right->left->_is_empty == false) {
        std::cout << nb_str_space << "/\\  " << nb_str_space ; // 5h-13,14w pos
    } else {
        std::cout << nb_str_space << nb_str_space << "    " ; // 5h-13,14w pos
    }
    if ( my_tree.root().base()->right->_is_empty == false &&
         my_tree.root().base()->right->right->_is_empty == false &&
         my_tree.root().base()->right->right->right->_is_empty == false) {
        std::cout << nb_str_space << "/\\  " << nb_str_space ; // 5h-15,16w pos
    } else {
        std::cout << nb_str_space << nb_str_space << "    " ; // 5h-15,16w pos
    }

    std::cout << std::endl;
    if ( my_tree.root().base()->left->_is_empty == false &&
         my_tree.root().base()->left->left->_is_empty == false &&
         my_tree.root().base()->left->left->left->_is_empty == false) {
        print_int_key_node( my_tree.root().base()->left->left->left->left ); // 5h-1w pos
        std::cout << "  " ;
        print_int_key_node( my_tree.root().base()->left->left->left->right ); // 5h-2w pos
        std::cout << "  " ;
    } else {
        std::cout << nb_str_space << nb_str_space << "    " ;
    }
    if ( my_tree.root().base()->left->_is_empty == false &&
         my_tree.root().base()->left->left->_is_empty == false &&
         my_tree.root().base()->left->left->right->_is_empty == false) {
        print_int_key_node( my_tree.root().base()->left->left->right->left ); // 5h-3w pos
        std::cout << "  " ;
        print_int_key_node( my_tree.root().base()->left->left->right->right ); // 5h-4w pos
        std::cout << "  " ;
    } else {
        std::cout << nb_str_space << nb_str_space << "    " ;
    }
    if ( my_tree.root().base()->left->_is_empty == false &&
         my_tree.root().base()->left->right->_is_empty == false &&
         my_tree.root().base()->left->right->left->_is_empty == false) {
        print_int_key_node( my_tree.root().base()->left->right->left->left ); // 5h-5w pos
        std::cout << "  " ;
        print_int_key_node( my_tree.root().base()->left->right->left->right ); // 5h-6w pos
        std::cout << "  " ;
    } else {
        std::cout << nb_str_space << nb_str_space << "    " ;
    }
    if ( my_tree.root().base()->left->_is_empty == false &&
         my_tree.root().base()->left->right->_is_empty == false &&
         my_tree.root().base()->left->right->right->_is_empty == false) {
        print_int_key_node( my_tree.root().base()->left->right->right->left ); // 5h-7w pos
        std::cout << "  " ;
        print_int_key_node( my_tree.root().base()->left->right->right->right ); // 5h-8w pos
        std::cout << "  " ;
    } else {
        std::cout << nb_str_space << nb_str_space << "    " ;
    }
    if ( my_tree.root().base()->right->_is_empty == false &&
         my_tree.root().base()->right->left->_is_empty == false &&
         my_tree.root().base()->right->left->left->_is_empty == false) {
        print_int_key_node( my_tree.root().base()->right->left->left->left ); // 5h-9w pos
        std::cout << "  " ;
        print_int_key_node( my_tree.root().base()->right->left->left->right ); // 5h-10w pos
        std::cout << "  " ;
    } else {
        std::cout << nb_str_space << nb_str_space << "    " ;
    }
    if ( my_tree.root().base()->right->_is_empty == false &&
         my_tree.root().base()->right->left->_is_empty == false &&
         my_tree.root().base()->right->left->right->_is_empty == false) {
        print_int_key_node( my_tree.root().base()->right->left->right->left ); // 5h-11w pos
        std::cout << "  " ;
        print_int_key_node( my_tree.root().base()->right->left->right->right ); // 5h-12w pos
        std::cout << "  " ;
    } else {
        std::cout << nb_str_space << nb_str_space << "    " ;
    }
    if ( my_tree.root().base()->right->_is_empty == false &&
         my_tree.root().base()->right->right->_is_empty == false &&
         my_tree.root().base()->right->right->left->_is_empty == false) {
        print_int_key_node( my_tree.root().base()->right->right->left->left ); // 5h-13w pos
        std::cout << "  " ;
        print_int_key_node( my_tree.root().base()->right->right->left->right ); // 5h-14w pos
        std::cout << "  " ;
    } else {
        std::cout << nb_str_space << nb_str_space << "    " ;
    }
    if ( my_tree.root().base()->right->_is_empty == false &&
         my_tree.root().base()->right->right->_is_empty == false &&
         my_tree.root().base()->right->right->right->_is_empty == false) {
        print_int_key_node( my_tree.root().base()->right->right->right->left ); // 5h-15w pos
        std::cout << "  " ;
        print_int_key_node( my_tree.root().base()->right->right->right->right ); // 5h-16w pos
        std::cout << "  " ;
    }
    std::cout << std::endl;
    std::cout << "\n\033[36m" << " only for 5 lvls " << "\033[0m"  << std::endl;

}
