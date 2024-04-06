NAME = libftprintf.a
CFLAGS = -Wall -Wextra -Werror 

MSRCS = ft_printf.c	\
		ft_puthex.c \
		ft_putchar.c\
		ft_putnbr.c\
		ft_putstr.c\
		put_address.c\
 
MOBJS = $(MSRCS:.c=.o)


all: $(NAME)

$(NAME): $(MOBJS) 
	ar rc $(NAME) $(MOBJS) 
	ranlib $(NAME)

program: main.c
	cc -o program  *.c ft_printf.h

run: program	
	./program


clean:
	$(RM) $(MOBJS) 

fclean:	clean
	$(RM) $(NAME) 

re: fclean all