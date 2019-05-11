NAME	=	my_ls

CC	=	gcc -g3

RM	=	rm -f

SRC	=	main.c	\
		parsing.c	\
		handle_recursive_flag.c	\
		display_no_flags.c	\
		sort_tab_in_alpha_order.c	\
		get_last_char_str.c	\
		handle_list_flag.c	\
		get_file_size.c	\
		get_file_user.c	\
		find_length.c	\
		get_mode.c	\
		get_total.c

SRCS	=	$(addprefix ./src/, $(SRC))

OBJS	=	$(SRCS:.c=.o)

LIB		=	-L./lib -lmy

CFLAGS	=	-I./include
CFLAGS	+=	-Wall -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	make -C lib
	$(CC) $(OBJS) $(CFLAGS) -o $(NAME) $(LDFLAGS) $(LIB)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
