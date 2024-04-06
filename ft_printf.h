#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

int determiner(const char *str, va_list vlist);
int ft_printf(const char *str, ...);
int ft_putchar(char c);
int ft_putnbr(int n);
int ft_putstr(char* s);
int ft_PUTHEX(int n);
int ft_puthex(int n);
int ft_putunbr(unsigned int n);
int ft_putstr(char* s);
int ft_putaddress(unsigned long number);

#endif
