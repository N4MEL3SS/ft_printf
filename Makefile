NAME = libftprintf.a

CC = clang

CFLAGS = -Wall -Wextra -Werror

HEADER = includes/ft_printf.h

SRC_FILE =	ft_isdigit.c		ft_isflag.c			ft_memset.c			\
			ft_parser.c			ft_putnchar.c		ft_strlen.c			\
			ft_print_char.c		ft_print_hex.c		ft_print_int.c		\
			ft_print_ptr.c		ft_print_str.c		ft_print_uint.c		\
			ft_printf.c			ft_print_percent.c

SRC_NAME = $(addprefix src/, $(SRC_FILE))

OBJ = $(SRC_NAME:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ) $(HEADER)
	@ar rcs $(NAME) $(OBJ)
	@ranlib $(NAME)

bonus:	$(OBJ)
	@ar rcs	$(NAME) $(OBJ)
	@ranlib	$(NAME)

.c.o:
	$(CC) $(CFLAGS) -I $(HEADER) -c $< -o $(<:.c=.o)

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all clean

.PHONY: clean fclean re bonus all
