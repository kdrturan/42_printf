#include "ft_printf.h"

int ft_putstr(char* s,int loop)
{
    if (s == NULL)
    {
        ft_putstr("(null)",-1);
        return (6);
    }
    int i;

    i = 0;
    while (s[i] && loop--)
    {
        write(1, &s[i], 1);
        i++;
    }
    return (i);
}