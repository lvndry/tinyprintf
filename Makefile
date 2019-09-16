CC=gcc
CFALGS=-Wall -Werror -Wextra -pedantic -std=c99

.PHONY: all library

all: library clean

library:
clean:
	$(RM) $(OBJS)
