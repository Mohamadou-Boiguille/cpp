CC = g++
CFLAGS = -std=c++98 -Wall -Wextra -Werror

TARGET = main
SRCS = main.cpp
OBJS = $(SRCS:.cpp =.o)

.PHONY : all clean re

all : $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o : %.cpp $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean : rm -f $(OBJS) $(TARGET)

re :
	clean all
