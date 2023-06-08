CC = g++
CFLAGS = -std=c++98 -Wall -Wextra -Werror

TARGET = main
SRCS = tests.cpp
HEADER = Account.hpp
OBJS = $(SRCS:.cpp=.o)

.PHONY: all clean re

all: $(TARGET) $(HEADER)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.cpp Account.hpp
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

re: clean all
