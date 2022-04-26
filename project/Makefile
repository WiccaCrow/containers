NAME			=   mySTL

# CPP         	=   clang++
CPP         	=   g++
FLAGS       	=   -g
FLAGS       	+=  -Wpedantic
FLAGS     	    +=  -Wall -Wextra -Werror -g
# FLAGS     	  =   -Wall -Wextra -Werror -g -Wpedantic -std=c++98

ifeq ($(MAKE_ENABLE_IF),0)
SRC_CPP     	=	test_enable_if_11.cpp
FLAGS 			+=	-std=c++11
else
FLAGS 			+=	 -std=c++98
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

SRC_FOLDER  	=   src/
OBJ_FOLDER  	=   .obj/
HEAD_FOLDER 	=   include/

SRC         	=   $(addprefix $(SRC_FOLDER), $(SRC_CPP))
OBJ         	=   $(addprefix $(OBJ_FOLDER), $(SRC_CPP:.cpp=.o))

test: ; $(MAKE) MAKE_MAIN=0 all
clean_test: ; $(MAKE) MAKE_MAIN=0 clean
fclean_test: ; $(MAKE) MAKE_MAIN=0 clean ; rm -rf $(NAME)
re_test: ; $(MAKE) MAKE_MAIN=0 fclean test

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

all: objdir $(NAME)

objdir:
	@if ! [ -d ${OBJ_FOLDER} ] ; then mkdir ${OBJ_FOLDER} ; fi

$(OBJ_FOLDER)%.o: $(SRC_FOLDER)%.cpp
	        $(CPP) $(FLAGS) -c $< -o $@ -I $(HEAD_FOLDER)

$(NAME): $(OBJ)
	        $(CPP) $(FLAGS) $^ -o $(NAME)

clean: ; rm -rf $(OBJ_FOLDER)

fclean: clean ; rm -rf $(NAME)

re: fclean all
