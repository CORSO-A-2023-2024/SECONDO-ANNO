# Makefile for compiling test-file.c with list.c module

CC = gcc
CFLAGS = -Wall -Wextra -g

# List of source files
SRCS = test-list.c list.c

# List of object files
OBJS = $(SRCS:.c=.o)

# Target executable
TARGET = test-list

# Default target
all: $(TARGET)

# Rule to build the executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Rule to build object files
%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

# Clean up
clean:
	rm -f $(TARGET) $(OBJS)

# Phony target to avoid conflicts with files named 'all' or 'clean'
.PHONY: all clean

