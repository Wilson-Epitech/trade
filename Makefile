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

DOXYGEN = doxygen
DOC_DIR = ./documentation/
DOXYFILE = $(DOC_DIR)Doxyfile

# -------------------------------------------------------------------------- #

RM = rm -f

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CPPLAGS) $(CFLAGS)
	@printf "%s -> [\033[0;36mbuilt\033[0m]\n" $(NAME)

doc:
	@$(DOXYGEN) $(DOXYFILE) > /dev/null
	@printf "[\033[0;36mdoc built\033[0m]\n"

clean:
	@$(RM) $(OBJ)
	@printf "%s -> [\033[0;31mdeleted\033[0m]\n" $(OBJ)

fclean: clean
	@$(RM) $(NAME)
	@printf "%s -> [\033[0;31mdeleted\033[0m]\n" $(NAME)

re:	 fclean all

.PHONY = all clean fclean re