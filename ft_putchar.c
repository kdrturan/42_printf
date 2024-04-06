#include "ft_printf.h"

int ft_putchar(char c)
{
    write(1, &c, 1);
    return (1);
}

int ft_putpercent()
{
    write(1, "%%", 1);
    return (1);
}