#include "ft_printf.h"

int ft_putaddress(uintptr_t number)
{
    int count;
    char numbers[16] = {'0', '1', '2' , '3' , '4', '5' , '6' , '7' , '8' , '9' ,'a', 'b' , 'c' , 'd' , 'e' , 'f'};
    
    count = 0;
    if (number == 0)
    {
        write(1,"(nil)",5);
        return (5);
    }
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