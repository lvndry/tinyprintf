CC= gcc
CFALGS= -Wall -Werror -Wextra -pedantic -std=c99
OBJS= buffer.o utils.o tinyprintf.o
LIB= libprintf.a

.PHONY: all library test

all: test clean

test: library
	$(CC) -L . -l:$(LIB) main.c tinyprintf.c utils.c buffer.c -o tinytest

library: $(OBJS)
	ar cr $(LIB) $(OBJS)

clean:
	$(RM) $(OBJS)
