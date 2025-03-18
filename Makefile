##
## EPITECH PROJECT, 2025
## Rush02
## File description:
## Makefile
##

SRC  =  array.c	\
		player.c	\
		point.c		\
		new.c	\
		vertex.c	\
		int.c	\
		float.c	\
		char.c	\
		list.c

TESTS =	tests/tests_first_part.c	\
		tests/tests_char.c	\
		tests/tests_float.c	\
		tests/tests_int.c

OBJ	=	$(SRC:.c=.o)

NAME	=	librush.a

all:	$(NAME)

$(NAME):  $(OBJ)
	ar rc $(NAME) $(OBJ)

tests_run:
	gcc -o unit_tests $(SRC) $(TESTS) \
	--coverage -lcriterion
	./unit_tests

clean:
	rm -f $(OBJ) *.gcda *.gcno

fclean:	clean
	rm -f $(NAME) unit_tests

re:	fclean all
