#include "ft_printf.h"


int ft_PUTHEX(int n)
{
    int count;
    long number = (long)n;
    char numbers[16] = {'0', '1', '2' , '3' , '4', '5' , '6' , '7' , '8' , '9' ,'A', 'B' , 'C' , 'D' , 'E' , 'F'};

    count = 0;
    if (number > 15)
    {
        count += ft_PUTHEX(number / 16);
        count += ft_putchar(numbers[number % 16]);
    }
    else
        count += ft_putchar(numbers[number % 16]);
    return (count);
}


int ft_puthex(int n)
{
    int count;
    long number = (long)n;
    char numbers[15] = {'0', '1', '2' , '3' , ' 4', '5' , '6' , '7' , '8' , '9' ,'a', 'b' , 'c' , 'd' , 'e' , 'f'};
    
    count = 0;
    if (number > 15)
    {
        count += ft_puthex (number / 16);
        count += ft_putchar (numbers[number % 16]);
    }
    else
        count += ft_putchar(numbers[number % 16]);
    return (count);
}