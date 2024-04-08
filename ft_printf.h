#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
# include <stddef.h>
# include <stdlib.h>
#include <stdint.h>
# include <unistd.h>


typedef struct printf_flags
{
    char    dot;
    char    space;
    char    sign;
    char    hash;
    int     zero;
    int     left;
    int     area;

}pflags;

void flags_dot(int* digit,pflags* flags,int* number);
void flags_Area(int* i,pflags* flags);
pflags*	detflags(const char **str);
int find_digit(int n);
int find_digitX(long number);
int dflag(pflags* flags, va_list vlist,int* count);
int xflag(pflags* flags, va_list vlist,int* count);
int Xflag(pflags* flags, va_list vlist,int* count);
int (*getfnc(const char str))(pflags*, va_list,int*);
int ft_atoi(const char** str);
int ft_putaddress(uintptr_t number);
void determiner(const char **str, va_list vlist, int* count);
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
