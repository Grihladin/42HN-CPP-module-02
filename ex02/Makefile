NAME = ex02
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++17
SRC_DIR = src
OBJ_DIR = objects

SRC = main.cpp Fixed.cpp
SRC_FILES = $(addprefix $(SRC_DIR)/, $(SRC))
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.cpp=.o))

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
