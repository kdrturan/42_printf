#include "ft_printf.h"


int ft_PUTHEX(long number,const char str)
{
    int count;
    char *numbers;
    char *NUMBERS;

    numbers = "0123456789abcdef";
    NUMBERS = "0123456789ABCDEF";
    count = 0;
    if (str == 'x')
    {
        if (number > 15)
        {
            count += ft_PUTHEX((number / 16),str);
            count += ft_putchar(numbers[number % 16]);
        }
        else
            count += ft_putchar(numbers[number % 16]);
    }
    else
    {
        if (number > 15)
        {
            count += ft_PUTHEX ((number / 16),str);
            count += ft_putchar (NUMBERS[number % 16]);
        }
        else
            count += ft_putchar(NUMBERS[number % 16]);
    }
    return (count);
}
