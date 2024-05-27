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
DOXYFILE = $(DOC_DIR)Doxygen_conf
DOC_NAME = Documentation.md

# -------------------------------------------------------------------------- #

RM = rm -f

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CPPLAGS) $(CFLAGS)
	@printf "[\033[0;36mbuilt\033[0m] -> %s\n" $(NAME)

doc:
	@$(DOXYGEN) $(DOXYFILE)
	@printf "[\033[0;36mdoc built\033[0m] -> %s\n" $(DOC_NAME)
	@xsltproc xml/combine.xslt xml/index.xml > ./$(DOC_NAME)
	@$(RM) -rf xml

clean:
	@$(RM) $(OBJ)
	@printf "[\033[0;31mdeleted\033[0m] -> %s\n" $(OBJ)

fclean: clean
	@$(RM) $(NAME)
	@printf "[\033[0;31mdeleted\033[0m] -> %s\n" $(NAME)

re:	 fclean all

.PHONY = all clean fclean re