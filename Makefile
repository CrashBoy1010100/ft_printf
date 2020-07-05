SRCS	=	ft_printf.c 			\
			ft_control_base.c		\
			ft_flag_time.c			\
			ft_print_time.c			\
			ft_print_char.c			\
			ft_print_str.c
OBJS	=	$(SRCS:.c=.o)
NAME	=	libftprintf
CFLAGS	=	-Wall -Werror -Wextra

$(NAME):	$(OBJS) _libft
			@gcc -o $(NAME) $(OBJS) $(shell find libft/ -name "*.o")
			#@ar -rcs $(NAME) $(OBJS) $(shell find libft/ -name "*.o")
			#@ranlib $(NAME)

.c.o:
			@gcc -c $< -o $(<:.c=.o)

_libft:
			@make -C libft

all:		$(NAME)

clean:
			@rm -f $(OBJS)
			@make clean -C libft

fclean:		clean
			rm -f $(NAME)
			@make fclean -C libft

re:			fclean all

.PHONY:		all clean fclean re
