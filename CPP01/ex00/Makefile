NAME		= zombie
CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98

OBJ_DIR		= obj

SRC			=	main.cpp \
				Zombie.cpp \
				randomChump.cpp \
				newZombie.cpp 

OBJ			= $(SRC:%.cpp=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ): Zombie.hpp

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re