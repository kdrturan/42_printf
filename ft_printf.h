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
    char     zero;
    int     dotarea;
    int     zeroarea;
    int     left;
    int     area;

}pflags;

void flags_MDotArea(int* digit,pflags* flags,int* number,int* count);
void    flags_MAreaf(int* digit,pflags* flags, int number,int* count);
void    flags_Mdot(pflags* flags,int* digit,int* number,int* count);
void    flags_Mzero(int* digit,pflags* flags, int number,int* count);
void flags_MDotZArea(int* digit,pflags* flags,int* number,int* count);
void    flags_minus(pflags* flags,int *digit,int *number,int* count);
void    flags_zero(int* digit,pflags* flags, int number,int* count);
void    flags_Areaf(int* digit,pflags* flags, int number,int* count);
int ft_putnbr_minus(int n);
void flags_DotArea(pflags* flags,int* count);
void    flags_dot(pflags* flags,int* digit,int* number,int* count);
int ft_zeroatoi(const char** str);
void flags_DotZArea(int* digit,pflags* flags,int* number,int* count);
void flags_Area(int* digit,pflags* flags,int* count);
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
