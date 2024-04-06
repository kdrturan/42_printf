NAME = libftprintf.a
CFLAGS = -Wall -Wextra -Werror 

MSRCS = ft_printf.c \ ft_putchar.c \ ft_puthex.c   \ ft_putnbr.c    \ ft_putstr.c     \ put_address.c     \ main.c
MOBJS = $(MSRCS:.c=.o)


all: $(NAME)

$(NAME): $(MOBJS) 
	ar rc $(NAME) $(MOBJS) 
	ranlib $(NAME)

bonus: $(NAME) 
	ar rc $(NAME) 
	ranlib $(NAME)

clean:
	$(RM) $(MOBJS) 

fclean:	clean
	$(RM) $(NAME)
	
re: fclean all