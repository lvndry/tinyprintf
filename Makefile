CC=gcc
CFALGS=-Wall -Werror -Wextra -pedantic -std=c99
OBJS=buffer.o utils.o tinyprintf.o

.PHONY: all library

all: library clean

library: $(OBJS)
	ar cr libraryprintf.a $(OBJS)

clean:
	$(RM) $(OBJS)
