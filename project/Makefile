NAME        =   mySTL

CPP         =   clang++
FLAGS       =   -Wall -Wextra -Werror -g -std=c++98
# FLAGS       =   -Wall -Wextra -Werror -g -Wpedantic -std=c++98

SRC_CPP     =	main.cpp 


SRC_FOLDER  =   src/
OBJ_FOLDER  =   .obj/
HEAD_FOLDER =   include/

SRC         =   $(addprefix $(SRC_FOLDER), $(SRC_CPP))
OBJ         =   $(addprefix $(OBJ_FOLDER), $(SRC_CPP:.cpp=.o))

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
