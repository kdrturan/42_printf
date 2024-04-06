#include "ft_printf.h"

int determiner(const char *str, va_list vlist)
{
    int count;

    count = 0;
    if (*str == 'd')
        count += ft_putnbr(va_arg(vlist, int));
    if (*str == 'c')
        count += ft_putchar(va_arg(vlist, int));
    if (*str == 's')
        count += ft_putstr(va_arg(vlist, char*));
    if (*str == 'p')
        count += ft_putaddress(va_arg(vlist, unsigned long));
    if (*str == 'i')
        count += ft_putnbr(va_arg(vlist, int));
    if (*str == 'u')
        count += ft_putunbr(va_arg(vlist, unsigned int));
    if (*str == 'x')
        count += ft_puthex(va_arg(vlist, int));
    if (*str == 'X')
        count += ft_PUTHEX(va_arg(vlist, int));
    if (*str == '%')
        count += ft_putchar(va_arg(vlist, int));
    return (count);
}


int ft_printf(const char *str, ...)
{
    va_list vlist;
    va_start(vlist, str);
    int count;

    count = 0;
    while (*str)
    {
        if (*str == 37)
        {
            str++;
            count += determiner(str, vlist);
            str++;
        }
        write(1, str ,1);
        str++;
    }
    va_end(vlist);
    return (count);
}