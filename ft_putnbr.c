#include "ft_printf.h"

int ft_putnbr(int n)
{
    int count;

    count = 0;
    if (n == -2147483648)
    {
        write(1,"-2147483648",11);
        return (11);
    }
    if (n < 0)
    {
        count += ft_putchar('-');
        n *= -1;
    }
    if (n > 9)
    {
	    count += ft_putnbr(n / 10);
        count += ft_putchar(((n % 10) + 48));
    }
    else
	    count += ft_putchar(((n % 10) + 48));
        return (count);
}
        
int ft_putunbr(unsigned int n)
{
    int count;

    count = 0;    
    if (n > 9)
    {
        count += ft_putnbr(n / 10);
        count += ft_putchar(((n % 10) + 48));
    }
    else
	    count += ft_putchar(((n % 10) + 48));
        return (count);
}
        
