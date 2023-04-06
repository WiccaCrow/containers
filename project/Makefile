NAME			=   mySTL
NAME_STL 		=	testSTL
NAME_FT			=	testFT

# CPP         	=   clang++
CPP         	=   g++
FLAGS       	=   -g
FLAGS       	+=  -Wpedantic
FLAGS     	    +=  -Wall -Wextra -Werror -g
FLAGS 			+=	-std=c++98
# FLAGS     	  =   -Wall -Wextra -Werror -g -Wpedantic -std=c++98

ifeq ($(MAKE_TEST),0)
SRC_CPP_STL         =	testSTL.cpp
SRC_CPP_FT         =	testFT.cpp
endif

ifeq ($(MAKE_ENABLE_IF),0)
SRC_CPP     	=	test_enable_if.cpp
endif

ifeq ($(MAKE_ITERATOR),0)
SRC_CPP     	=	test_iterator.cpp
endif

ifeq ($(MAKE_MAIN),0)
SRC_CPP     	=	main.cpp
endif

ifeq ($(MAKE_VECTOR),0)
SRC_CPP     	=	test_vector.cpp
endif

ifeq ($(MAKE_PAIR),0)
SRC_CPP     	=	test_pair.cpp
endif

ifeq ($(MAKE_MAP),0)
SRC_CPP     	=	test_map.cpp
endif

ifeq ($(MAKE_SET),0)
SRC_CPP     	=	test_set.cpp
endif

ifeq ($(MAKE_STACK),0)
SRC_CPP     	=	test_stack.cpp
endif

ifeq ($(MAKE_INTEGRAL),0)
SRC_CPP     	=	test_is_integral.cpp
endif

SRC_FOLDER  	=   src/
OBJ_FOLDER  	=   .obj/
HEAD_FOLDER 	=   include/

SRC         	=   $(addprefix $(SRC_FOLDER), $(SRC_CPP))
OBJ         	=   $(addprefix $(OBJ_FOLDER), $(SRC_CPP:.cpp=.o))

test: ; $(MAKE) MAKE_TEST=0 test_stl_ft
clean_test: ; $(MAKE) MAKE_TEST=0 clean
fclean_test: ; $(MAKE) MAKE_TEST=0 clean ; rm -rf $(NAME_STL) $(NAME_FT)
re_test: ; $(MAKE) MAKE_TEST=0 fclean test

OBJ_STL       	=   $(addprefix $(OBJ_FOLDER), $(SRC_CPP_STL:.cpp=.o))
OBJ_FT         	=   $(addprefix $(OBJ_FOLDER), $(SRC_CPP_FT:.cpp=.o))

test_stl_ft: objdir $(NAME_STL)

$(NAME_STL): $(OBJ_STL) $(OBJ_FT)
	         $(CPP) $(FLAGS) $(OBJ_STL) -o $(NAME_STL)
	         $(CPP) $(FLAGS) $(OBJ_FT)  -o $(NAME_FT)

# # # # # # # # # # # # # # # # # # # # # # # # # # 

main: ; $(MAKE) MAKE_MAIN=0 all
clean_main: ; $(MAKE) MAKE_MAIN=0 clean
fclean_main: ; $(MAKE) MAKE_MAIN=0 clean ; rm -rf $(NAME)
re_main: ; $(MAKE) MAKE_MAIN=0 fclean main

iterator: ; $(MAKE) MAKE_ITERATOR=0 all
clean_iterator: ; $(MAKE) MAKE_ITERATOR=0 clean
fclean_iterator: ; $(MAKE) MAKE_ITERATOR=0 clean ; rm -rf $(NAME)
re_iterator: ; $(MAKE) MAKE_ITERATOR=0 fclean iterator

enable_if: ; $(MAKE) MAKE_ENABLE_IF=0 all
clean_enable_if: ; $(MAKE) MAKE_ENABLE_IF=0 clean
fclean_enable_if: ; $(MAKE) MAKE_ENABLE_IF=0 clean ; rm -rf $(NAME)
re_enable_if: ; $(MAKE) MAKE_ENABLE_IF=0 fclean enable_if

vector: ; $(MAKE) MAKE_VECTOR=0 all
clean_vector: ; $(MAKE) MAKE_VECTOR=0 clean
fclean_vector: ; $(MAKE) MAKE_VECTOR=0 clean ; rm -rf $(NAME)
re_vector: ; $(MAKE) MAKE_VECTOR=0 fclean vector

pair: ; $(MAKE) MAKE_PAIR=0 all
clean_pair: ; $(MAKE) MAKE_PAIR=0 clean
fclean_pair: ; $(MAKE) MAKE_PAIR=0 clean ; rm -rf $(NAME)
re_pair: ; $(MAKE) MAKE_PAIR=0 fclean pair

map: ; $(MAKE) MAKE_MAP=0 all
clean_map: ; $(MAKE) MAKE_MAP=0 clean
fclean_map: ; $(MAKE) MAKE_MAP=0 clean ; rm -rf $(NAME)
re_map: ; $(MAKE) MAKE_MAP=0 fclean map

set: ; $(MAKE) MAKE_SET=0 all
clean_set: ; $(MAKE) MAKE_SET=0 clean
fclean_set: ; $(MAKE) MAKE_SET=0 clean ; rm -rf $(NAME)
re_set: ; $(MAKE) MAKE_SET=0 fclean map

stack: ; $(MAKE) MAKE_STACK=0 all
clean_stack: ; $(MAKE) MAKE_STACK=0 clean
fclean_stack: ; $(MAKE) MAKE_STACK=0 clean ; rm -rf $(NAME)
re_stack: ; $(MAKE) MAKE_STACK=0 fclean map

integral: ; $(MAKE) MAKE_INTEGRAL=0 all
clean_integral: ; $(MAKE) MAKE_INTEGRAL=0 clean
fclean_integral: ; $(MAKE) MAKE_INTEGRAL=0 clean ; rm -rf $(NAME)
re_integral: ; $(MAKE) MAKE_INTEGRAL=0 fclean map

all: objdir $(NAME)

objdir:
	@if ! [ -d ${OBJ_FOLDER} ] ; then mkdir ${OBJ_FOLDER} ; fi

$(OBJ_FOLDER)%.o: $(SRC_FOLDER)%.cpp
	        $(CPP) $(FLAGS) -c $< -o $@ -I $(HEAD_FOLDER)

$(NAME): $(OBJ)
	        $(CPP) $(FLAGS) $^ -o $(NAME)

clean: ; rm -rf $(OBJ_FOLDER)

fclean: clean ; rm -rf $(NAME) $(NAME_STL) $(NAME_FT)

re: fclean all
