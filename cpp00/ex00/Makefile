CC = g++
CFLAGS = -std=c++98 -Wall -Wextra -Werror

TARGET = megaphone
SRCS = megaphone.cpp

.PHONY: all clean re

all: $(TARGET) Makefile

$(TARGET):$(SRCS)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -f $(TARGET)

re: clean all

