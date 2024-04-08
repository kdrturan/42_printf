#include "ft_printf.h"


void flags_Area(int* digit,pflags* flags)
{
    while (*digit < flags->area)
    {
        if (flags->zero == 1)
            ft_putchar('0');
        else 
            ft_putchar(' ');
        (*digit)++;
    }
}

void flags_dot(int* digit,pflags* flags,int* number)
{

    if (flags->dot && (*number) < 0)
    {
        ft_putchar('-');
        (*number) *= -1;
        (*digit)--;
    }
}