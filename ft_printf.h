#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

void determiner(const char *str, va_list vlist);
void ft_printf(const char *str, ...);
void ft_putchar(char c);
void ft_putnbr(int n);
void ft_putstr(char* s);

#endif
