#include "ft_printf.h"

int ft_putaddress(uintptr_t number)
{
    int count;
    char *numbers;

    numbers = "0123456789abcdef";
    count = 0;
    if (number == 0)
        return (ft_putstr("(nil)",-1));
    if (number > 15)
    {
        count += ft_putaddress (number / 16);
        count += ft_putchar (numbers[number % 16]);
    }
    else
    {
        count += ft_putchar('0');
        count += ft_putchar('x');
        count += ft_putchar(numbers[number % 16]);
    }
    return (count);
}