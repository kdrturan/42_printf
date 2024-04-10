#include "ft_printf.h"





void    flags_minus(pflags* flags,int *digit,int *number,int* count)
{
    if (flags -> zero && flags -> dot)
        flags_MDotZArea(digit,flags,number,count);
    else if (flags -> area && flags -> dot)
        flags_MDotArea(digit,flags,number,count);
    else if (flags->dot)
        flags_Mdot(flags,digit,number,count);
    else if (flags -> zero)
        flags_Mzero(digit,flags,*number,count);
    else if (flags -> area)
        flags_MAreaf(digit,flags,*number,count);
    else
        *count += ft_putnbr(*number);
}



void flags_MDotZArea(int* digit,pflags* flags,int* number,int* count)
{
    int i;
    int loop;

    i = 0;
    if (*number < 0)
        flags -> zeroarea -= 1;
    if (number == 0)
        *digit = 0;
    if (flags->dotarea < *digit && *number != 0)
        flags->dotarea = *digit;
    loop = (flags-> zeroarea - flags->dotarea);
    flags -> area = flags->dotarea;
    if (*number < 0)
    {
        *count += ft_putchar('-');
        flags_Area(digit,flags,count);
    }
    else
        flags_Area(digit,flags,count);
    if (*number != 0 || flags -> dotarea != 0)
        *count += ft_putnbr_minus(*number);
    while (i++ < loop)
        *count += ft_putchar(' ');
}



void flags_MDotArea(int* digit,pflags* flags,int* number,int* count)
{
    int i;
    int loop;

    i = 0;
    if (*number < 0)
        flags -> area -= 1;
    if (number == 0)
        *digit = 0;
    if (flags->dotarea < *digit && *number != 0)
        flags->dotarea = *digit;
    loop = (flags-> area - flags->dotarea);
    flags -> area = flags->dotarea;
    if (*number < 0)
    {
        *count += ft_putchar('-');
        flags_Area(digit,flags,count);
    }
    else
        flags_Area(digit,flags,count);
    if (*number != 0 || flags -> dotarea != 0)
        ft_putnbr_minus(*number);
    while (i++ < loop)
        *count += ft_putchar(' ');
}

void    flags_Mdot(pflags* flags,int* digit,int* number,int* count)
{
    flags -> area = flags -> dotarea;
    if (*number >= 0)
    {
        flags_Area(digit,flags,count);   
        if (*number != 0 || flags -> dotarea != 0)
            *count += ft_putnbr_minus(*number);
    }
    else
    {
        *count += ft_putchar('-');
        flags_Area(digit,flags,count);
        if (*number != 0 || flags -> dotarea != 0)
            *count += ft_putnbr_minus(*number);
    }
}

void    flags_Mzero(int* digit,pflags* flags, int number,int* count)
{
    flags -> area = flags -> zeroarea;
    flags_Area(digit,flags,count);
    if (number < 0)
    {
        (*digit)++;
        *count += ft_putchar('-');
    }
    *count += ft_putnbr_minus(number);
}

void    flags_MAreaf(int* digit,pflags* flags, int number,int* count)
{
    if (number < 0)
        (*digit)++;
    *count += ft_putnbr(number);
    flags_Area(digit,flags,count);
}









void flags_Area(int* digit,pflags* flags,int* count)
{
    while (*digit < flags->area)
    {
        if (flags->zero == 1 || flags -> dot == 1)
            *count += ft_putchar('0');
        else 
            *count += ft_putchar(' ');
        (*digit)++;
    }
}

void    flags_zero(int* digit,pflags* flags, int number,int* count)
{
    if (number < 0)
    {
        (*digit)++;
        *count += ft_putchar('-');
    }
    flags -> area = flags -> zeroarea;
    flags_Area(digit,flags,count);
    *count += ft_putnbr_minus(number);
}

void    flags_Areaf(int* digit,pflags* flags, int number,int* count)
{
    if (number < 0)
        (*digit)++;
    flags_Area(digit,flags,count);
    *count += ft_putnbr(number);
}

void flags_DotZArea(int* digit,pflags* flags,int* number,int* count)
{
    int i;
    int loop;

    i = 0;
    if (*number < 0)
        flags -> zeroarea -= 1;
    if (number == 0)
        *digit = 0;
    if (flags->dotarea < *digit && *number != 0)
        flags->dotarea = *digit;
    loop = (flags-> zeroarea - flags->dotarea);
    while (i++ < loop)
        *count += ft_putchar(' ');
    flags -> area = flags->dotarea;
    if (*number < 0)
    {
        *count += ft_putchar('-');
        flags_Area(digit,flags,count);
    }
    else
        flags_Area(digit,flags,count);
    if (*number != 0 || flags -> dotarea != 0)
        *count += ft_putnbr_minus(*number);
}


void flags_DotArea(pflags* flags,int* count)
{
    int i;

    i = 0;
    while (i++ < (flags -> area - flags -> dotarea))
        *count += ft_putchar(' ');
}


void    flags_dot(pflags* flags,int* digit,int* number,int* count)
{
    if (*number < 0)
    {
        flags_DotArea(flags,count);
        *count += ft_putchar('-');
    }
    else
        flags_DotArea(flags,count);
    flags -> area = flags -> dotarea;
    flags_Area(digit,flags,count);
    if (*number != 0 || flags -> dotarea != 0)
        *count += ft_putnbr_minus(*number);
}