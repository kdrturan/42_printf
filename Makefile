NAME = libftprintf.a
CFLAGS = -Wall -Wextra -Werror 

MSRCS = ft_printf.c		\
		put_address.c \
		ft_putchar.c 	\
		ft_putnbr.c 	\
		ft_putstr.c 	\
		ft_atoi.c 	\
		ft_puthex.c		\
		ft_setstr_bonus.c \
		ft_putflags.c	\


BSRCS = ft_setstr_bonus.c		\
		

MOBJS = $(MSRCS:.c=.o)
BOBJS = $(BSRCS:.c=.o)

all: $(NAME)

$(NAME): $(MOBJS) $(BOBJS)
	ar rc $(NAME) $(MOBJS) $(BOBJS)
	ranlib $(NAME)

bonus: $(NAME) $(BOBJS)
	ar rc $(NAME) $(BOBJS)
	ranlib $(NAME)

clean:
	$(RM) $(MOBJS) $(BOBJS)

fclean:	clean
	$(RM) $(NAME)
	
re: fclean all