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
    if (flags->left)
        flags_minus(flags,&digit,&number,count);
    else if (flags -> zero && flags -> dot)
        flags_DotZArea(&digit,flags,&number,count);
    else if (flags->dot)
        flags_dot(flags,&digit,&number,count);
    else if (flags -> zero)
        flags_zero(&digit,flags,number,count);
    else if (flags -> area)
        flags_Areaf(&digit,flags,number,count);
    
    return (1);
}

void getfnc(pflags* flags,va_list vlist,int* count,const char str)
{
    if (str == 'd' || str == 'i')
            dflag(flags,vlist,count);
    else if (str == 'x')
        xflag(flags,vlist,count);
    else if (str == 'X')
        Xflag(flags,vlist,count);
    else 
        Xflag(flags,vlist,count);
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




