
# This is make file for running command math_stuff
#Written by Fahim Imtiaz
# Date 7/7/2023
CC = gcc
CFLAGS = -std=c99 -O0 -g -Wall -Werror

TARGET = math_stuff

SRCS = mathStuff.c
OBJS = $(SRCS:.c=.o)

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
