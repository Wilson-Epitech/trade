##
## TRADE PROJECT, 2024
## trade
## File description:
## Makefile
##

# -------------------------------------------------------------------------- #

CC ?= gcc
CPPFLAGS += -iquote./include
CFLAGS += -Wall -Wextra -Werror -g3

# -------------------------------------------------------------------------- #

SRC_DIR	 =	./src/
NAME =	trade
OBJ =				$(SRC:.c=.o)
SRC	=				$(SRC_DIR)main.c				\
					$(LIB)

# -------------------------------------------------------------------------- #

LIB_DIR = ./src/lib/
LIB =				$(LIB_DIR)word_array_delim.c	\

# -------------------------------------------------------------------------- #

RM = rm -f

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CPPLAGS) $(CFLAGS)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re:	 fclean all

.PHONY = all clean fclean re