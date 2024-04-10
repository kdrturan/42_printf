#include "ft_printf.h"
#include <stdio.h>
void	detflags(const char **str,pflags *flags)
{
	if (*(*str) == '0')
    {
        flags -> zero = 1;
        flags-> zeroarea = ft_zeroatoi(str);
    }	
	while ((*(*str) != 'd' && *(*str) != 'i' && *(*str) != 's'&& *(*str) != 'x' && *(*str) != 'X') && *(*str))
	{
		if (*(*str) == '#')
			flags -> hash = 1;
		else if (*(*str) == '-')
			flags -> left = 1;
		else if (*(*str) == '+')
			flags -> sign = 1;
		else if (*(*str) == ' ')
			flags -> space = 1;
		else if (*(*str) >= '1' && *(*str) <= '9')
			flags -> area = ft_atoi(str);
		else if (*(*str) == '.')
        {
            flags -> dot = 1;
            (*str)++;
			flags -> dotarea = ft_atoi(str);
        }
		(*str)++;
	}
}




void determiner(const char **str, va_list vlist, int* count)
{
	pflags flags = {0};
    if (*(*str) == '%')
    {
        *count += ft_putpercent();
        va_arg(vlist, int);
    }
    else if (*(*str) == 'c')
        *count += ft_putchar(va_arg(vlist, int));
    else if (*(*str) == 'd')
        *count += ft_putnbr(va_arg(vlist, int));
    else if (*(*str) == 's')
        *count += ft_putstr(va_arg(vlist, char*));
    else if (*(*str) == 'p')
        *count += ft_putaddress(va_arg(vlist, uintptr_t));
    else if (*(*str) == 'i')
        *count += ft_putnbr(va_arg(vlist, int));
    else if (*(*str) == 'u')
        *count += ft_putunbr(va_arg(vlist, unsigned int));
    else if (*(*str) == 'x')
        *count += ft_puthex(va_arg(vlist, long));
    else if (*(*str) == 'X')
        *count += ft_PUTHEX(va_arg(vlist, long));
    else
	{
		detflags(str,&flags);
        getfnc(&flags,vlist,count,**str);
	}
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
            determiner(&str, vlist, &count);
        }
        else
        {
            write(1, str ,1);
            count++;
        }
        str++;
    }
    va_end(vlist);
    return (count);
}