#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stddef.h>
# include <stdlib.h>
# include <stdint.h>
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


void    flags_dotU(pflags* flags,int* digit,unsigned int* number,int* count);
void flags_DotAreaU(pflags* flags,int* count);
void flags_DotZAreaU(int* digit,pflags* flags,unsigned int* number,int* count);
void    flags_AreafU(int* digit,pflags* flags,unsigned int number,int* count);
void    flags_zeroU(int* digit,pflags* flags,unsigned int number,int* count);
void flags_AreaU(int* digit,pflags* flags,int* count);
void    flags_MAreafU(int* digit,pflags* flags,unsigned int number,int* count);
void    flags_MzeroU(int* digit,pflags* flags,unsigned int number,int* count);
void    flags_MdotU(pflags* flags,int* digit,unsigned int* number,int* count);
void flags_MDotAreaU(int* digit,pflags* flags,unsigned int* number,int* count);
void flags_MDotZAreaU(int* digit,pflags* flags,unsigned int* number,int* count);
void    flags_minusU(pflags* flags,int *digit,unsigned int *number,int* count);
int find_digitU(unsigned int number);
void    uflag(pflags* flags, va_list vlist,int* count);
int ft_digitaddress(uintptr_t number);
void    pflag(pflags* flags, va_list vlist,int* count);
int Xflag(pflags* flags, va_list vlist,int* count,const char str);
void    flags_minusX(pflags* flags,int *digit,long *number,int* count,const char str);
void flags_MDotZAreaX(int* digit,pflags* flags,long* number,int* count,const char str);
void flags_MDotAreaX(int* digit,pflags* flags,long* number,int* count,const char str);
void    flags_MdotX(pflags* flags,int* digit,long* number,int* count,const char str);
void    flags_MzeroX(int* digit,pflags* flags, long number,int* count,const char str);
void    flags_MAreafX(int* digit,pflags* flags, long number,int* count,const char str);
void flags_AreaX(int* digit,pflags* flags,int* count);
void    flags_zeroX(int* digit,pflags* flags, long number,int* count,const char str);
void    flags_AreafX(int* digit,pflags* flags, long number,int* count,const char str);
void flags_DotZAreaX(int* digit,pflags* flags,long* number,int* count,const char str);
void    flags_dotX(pflags* flags,int* digit,long* number,int* count,const char str);
void flags_DotAreaX(pflags* flags,int* count);
void    sflag(pflags* flags, va_list vlist,int* count);
void    sflag_area(pflags* flags,int* count,char *string,int len);
int	ft_strlen(const char *s);
void sflag_areadot(pflags* flags,int* count,char *string,int len);
void cflag(pflags* flags, va_list vlist,int* count);
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
void	detflags(const char **str,pflags *flags);
int find_digit(int n);
int find_digitX(long number);
int dflag(pflags* flags, va_list vlist,int* count);
int xflag(pflags* flags, va_list vlist,int* count);
void getfnc(pflags* flags,va_list vlist,int* count,const char str);
int ft_atoi(const char** str);
int ft_putaddress(uintptr_t number);
void determiner(const char **str, va_list vlist, int* count);
int ft_printf(const char *str, ...);
int ft_putchar(char c);
int ft_putnbr(int n);
int ft_PUTHEX(long number,const char str);
int ft_putunbr(unsigned int n);
int ft_putstr(char* s,int loop);
int ft_putpercent();

#endif
