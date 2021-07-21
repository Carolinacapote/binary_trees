NAME := binary_tree
CC := gcc
DEBUGGER := gdb
LEAK_CHECK:= valgrind
CFLAGS := -g -std=gnu90 -Wall -pedantic -Werror -Wextra
VFLAGS := --leak-check=full
MAIN := 0-main.c
CFILES := binary_tree_print.c
DMAIN := ./tests/
SRC := *.c
RM=rm

betty:
	@betty $(SRC) \
	&& betty *.h

build:
	@betty $(SRC) \
	&& betty *.h  \
	&& $(CC) $(CFLAGS) $(CFILES) $(DMAIN)$(MAIN) $(SRC) -o $(NAME)

run:
	@betty $(SRC) \
	&& betty *.h \
	&& $(CC) $(CFLAGS) $(CFILES) $(DMAIN)$(MAIN) $(SRC) -o $(NAME) \
	&& ./$(NAME) \
	&& $(RM) -f ./$(NAME)

gdb:
	@betty $(SRC) \
	&& betty *.h \
	&& $(CC) $(CFLAGS) $(CFILES) $(DMAIN)$(MAIN) $(SRC) -o $(NAME) \
	&& $(DEBUGGER) ./$(NAME) \
	&& $(RM) -f $(NAME)

valgrind:
	@betty $(SRC) \
	&& betty *.h \
	&& $(CC) $(CFLAGS) $(CFILES) $(DMAIN)$(MAIN) $(SRC) -o $(NAME) \
	&& $(LEAK_CHECK) $(VFLAGS) ./$(NAME) \
	&& $(RM) -f ./$(NAME)

