#include "ft_printf.h"

int ft_putstr(char* s)
{
    if (s == NULL)
    {
        ft_putstr("(null)");
        return (6);
    }
    int i;

    i = 0;
    while (s[i])
    {
        write(1, &s[i], 1);
        i++;
    }
    return (i);
}