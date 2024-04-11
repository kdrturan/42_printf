#include "ft_printf.h"


int ft_digitaddress(uintptr_t number)
{
    int count;

    count = 0;
    if (number > 15)
    {
        count += ft_digitaddress (number / 16);
		count += 1;
    }
    else
        count ++;
    return (count);
}

void    pflag(pflags* flags, va_list vlist,int* count)
{
	int	area;
	uintptr_t number;

	number	= va_arg(vlist, uintptr_t);
	area = ft_digitaddress(number) + 2;
	if (number == 0)
		area = 5;
	if (flags -> left)
	{
		*count += ft_putaddress(number);
		while (flags->area - area > 0)
		{
			*count += ft_putchar(' ');
			area++;
		}
	}
	else
	{
		while (flags->area - area > 0)
		{
			*count += ft_putchar(' ');
			area++;
		}
		*count += ft_putaddress(number);
	}
}