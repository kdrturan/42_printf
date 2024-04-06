NAME = libftprintf.a
CFLAGS = -Wall -Wextra -Werror

SRCS = $(wildcard .c)

OBJC = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	randlib $(NAME)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)
	
re: fclean all