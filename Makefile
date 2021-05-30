##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile
##

CC			=	gcc

SRC			=	sources/main.c	\
				sources/my_strcat.c	\
				sources/segmentation.c	\
				sources/do_fork.c	\
				sources/free_all.c	\
				sources/my_array_dup.c	\
				sources/get_path.c	\

OBJ			=	$(SRC:.c=.o)

LDLIBS		=	-lmy

LDFLAGS		=	-L lib/my

CPPFLAGS	=	-I ./include/

CFLAGS		=	-Wall -Wextra

NAME		=	mysh

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C lib/my
	$(CC) $(OBJ) -o $(NAME) $(LDLIBS) $(LDFLAGS) $(CPPFLAGS)

debug:	CFLAGS += -g
debug:	re

clean:
	make clean -C lib/my
	rm -f $(OBJ)

fclean: clean
	make fclean -C lib/my
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
