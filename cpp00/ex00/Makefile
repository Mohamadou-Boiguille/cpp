CC = g++
CFLAGS = -std=c++98 -Wall -Wextra -Werror

NAME = Megaphone
SRCS_LIST = Megaphone.cpp main.cpp
HEADERS_LIST = Megaphone.hpp
SRCS_DIR = src
HEADERS_DIR = inc
OBJS_DIR = .obj
SRCS = $(addprefix $(SRCS_DIR)/, $(SRCS_LIST))
OBJS = $(addprefix $(OBJS_DIR)/, $(SRCS_LIST:.cpp=.o))
HEADERS = $(addprefix $(HEADERS_DIR)/, $(HEADERS_LIST))

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.cpp $(HEADERS) Makefile
	mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all clean fclean re

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

