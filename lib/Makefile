##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## compil my_printf and all dependencies
##

SRC	=	add_char_to_chartab.c	\
		add_char_to_tab.c	\
		my_charcapital.c	\
		my_puterror.c	\
		my_putstr.c	\
		my_strconcat.c	\
		my_strlen.c	\
		my_strstr.c	\
		remove_str_to_tab.c	\
		remove_char_from_str.c	\

SRCS	=	$(addprefix ./src/, $(SRC))

OBJ	=	$(SRCS:.c=.o)

CFLAGS += -I./include

NAME	=	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ) $(INCLUDE)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)
	rm -f *.gc* unit_tests

re: fclean all
