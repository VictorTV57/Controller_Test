##
## VICTORTV57 PROJECT, 2025
## CONTROLLER_TEST
## File description:
## Makefile
##

CC	=	gcc

SRC	=	$(wildcard src/*.c)

NAME	=	controller_test

OBJ	=	$(SRC:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
		$(CC) -o $(NAME) $(SRC) -lcsfml-graphics -lcsfml-window -lncurses

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re