#include "ft_printf.h"

int ft_putaddress(unsigned long number)
{
    int count;
    char numbers[16] = {'0', '1', '2' , '3' , '4', '5' , '6' , '7' , '8' , '9' ,'a', 'b' , 'c' , 'd' , 'e' , 'f'};
    
    count = 0;
    if (number > 15)
    {
        count += ft_putaddress (number / 16);
        count += ft_putchar (numbers[number % 16]);
    }
    else
    {
        write(1, "0x", 2);
        count += ft_putchar(numbers[number % 16]);
    }
    return (count + 2);
}