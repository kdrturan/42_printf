#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
# include <stddef.h>
# include <stdlib.h>
#include <stdint.h>
# include <unistd.h>

int ft_putaddress(uintptr_t number);
void determiner(const char *str, va_list vlist, int* count);
int ft_printf(const char *str, ...);
int ft_putchar(char c);
int ft_putnbr(int n);
int ft_putstr(char* s);
int ft_PUTHEX(long number);
int ft_puthex(long number);
int ft_putunbr(unsigned int n);
int ft_putstr(char* s);
int ft_putpercent();

#endif
