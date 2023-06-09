CC = g++
CFLAGS = -std=c++98 -Wall -Wextra -Werror

SRCS_DIR = src
OBJS_DIR = .obj
NAME = phonebook
SRCS_LIST = main.cpp contact.cpp phonebook.cpp
SRCS = $(addprefix $(SRCS_DIR)/, $(SRCS_LIST))
OBJS = $(addprefix $(OBJS_DIR)/, $(SRCS_LIST:.cpp=.o))
HEADERS_DIR = inc
HEADERS_LIST = contact.hpp phonebook.hpp
HEADERS = $(addprefix $(HEADERS_DIR)/, $(HEADERS_LIST))

all: $(NAME)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.cpp $(HEADERS) Makefile
	mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

.PHONY: all clean fclean re

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all
