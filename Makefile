CC= gcc
CFALGS= -Wall -Werror -Wextra -pedantic -std=c99
OBJS= buffer.o utils.o tinyprintf.o
LIB= libprintf.a

.PHONY: all library

all: library clean

library: $(OBJS)
	ar cr $(LIB) $(OBJS)

clean:
	$(RM) $(OBJS)
