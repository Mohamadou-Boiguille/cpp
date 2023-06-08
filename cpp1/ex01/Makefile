CC = g++
CFLAGS = -std=c++98 -Wall -Wextra -Werror

TARGET = main
SRCS = main.cpp zombieHorde.cpp Zombie.cpp
HEADERS = Zombie.h
OBJS = $(SRCS:.cpp =.o)

.PHONY : all clean re

all : $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) $(CFLAGS) -g3 -o $@ $^

%.o : %.cpp $(HEADERS)
	$(CC) $(CFLAGS) -g3 -c $< -o $@

clean : rm -f $(OBJS) $(TARGET)

re :
	clean all
