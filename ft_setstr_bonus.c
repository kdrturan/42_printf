#include "ft_printf.h"




int find_digit(int n)
{
    int digit;
    long number = (long)n;
    digit = 0;
    if (number < 0)
        number *= -1;

    while (number > 9)
    {
        number /= 10;
        digit++;
    }
    return (++digit);
}

int find_digitX(long number)
{
    
    int digit;

    digit = 0;
    while (number > 15)
    {
        number /= 16;
        digit++;
    }
    return (++digit);
}


int dflag(pflags* flags, va_list vlist,int* count)
{
    int number;
    int digit;

    number = va_arg(vlist, int);
    digit = find_digit(number);
    if (number < 0)
        digit++;
    if (flags->dot && number == 0 && !(flags -> area))
        return 0;
    flags_dot(&digit, flags, &number);
    flags_Area(&digit, flags);
    if (number == -2147483648 && flags->dot)
    {
        ft_putnbr(214748364);
        number = 8;
    }
    *count += ft_putnbr(number);
    return (1);
}

int (*getfnc(const char str))(pflags*, va_list,int*)
{
    if (str == 'd' || str == 'i')
        return (dflag);
    else if (str == 'x')
        return (xflag);
    else if (str == 'X')
        return (Xflag);
    else 
        return (Xflag);
}

int xflag(pflags* flags, va_list vlist,int* count)
{

    long number;
    int digit;
    int i;

    number = va_arg(vlist, long);
    digit = find_digitX(number);
    i = digit;
    while (i < flags->area)
    {
        if (flags->zero)
            *count += ft_putchar('0');
        else 
            *count += ft_putchar(' ');
        i++;
    }
    *count += ft_puthex(number);
    return (1);

}


int Xflag(pflags* flags, va_list vlist,int* count)
{
    long number;
    int digit;
    int i;
    number = va_arg(vlist, long);
    digit = find_digitX(number);
    i = digit;
    while (i < flags->area)
    {
        if (flags->zero)
            *count += ft_putchar('0');
        else 
            *count += ft_putchar(' ');
        i++;
    }
    *count += ft_PUTHEX(number);
    return (1);
}




