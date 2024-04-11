#include "ft_printf.h"


int find_digitU(unsigned int number)
{
    int digit;
    digit = 0;

    while (number > 9)
    {
        number /= 10;
        digit++;
    }
    return (++digit);
}


void    uflag(pflags* flags, va_list vlist,int* count)
{
    unsigned int    number;
    int digit;

    number = va_arg(vlist,unsigned int);
    digit = find_digitU(number);
    if (flags->space)
        *count += ft_putchar(' ');
    if (flags->sign)
        *count += ft_putchar('+');
    if (flags->left)
        flags_minusU(flags,&digit,&number,count);
    else if (flags -> zero && flags -> dot)
        flags_DotZAreaU(&digit,flags,&number,count);
    else if (flags->dot)
        flags_dotU(flags,&digit,&number,count);
    else if (flags -> zero)
        flags_zeroU(&digit,flags,number,count);
    else if (flags -> area)
        flags_AreafU(&digit,flags,number,count);
    else
        *count += ft_putunbr(number);  
}



void    flags_minusU(pflags* flags,int *digit,unsigned int *number,int* count)
{
    if (flags -> zero && flags -> dot)
        flags_MDotZAreaU(digit,flags,number,count);
    else if (flags -> area && flags -> dot)
        flags_MDotAreaU(digit,flags,number,count);
    else if (flags->dot)
        flags_MdotU(flags,digit,number,count);
    else if (flags -> zero)
        flags_MzeroU(digit,flags,*number,count);
    else if (flags -> area)
        flags_MAreafU(digit,flags,*number,count);
    else
        *count += ft_putunbr(*number);
}



void flags_MDotZAreaU(int* digit,pflags* flags,unsigned int* number,int* count)
{
    int i;
    int loop;

    i = 0;
    if (number == 0)
        *digit = 0;
    if (flags->dotarea < *digit && *number != 0)
        flags->dotarea = *digit;
    loop = (flags-> zeroarea - flags->dotarea);
    flags -> area = flags->dotarea;
    flags_AreaU(digit,flags,count);
    if (*number != 0 || flags -> dotarea != 0)
        *count += ft_putunbr(*number);
    while (i++ < loop)
        *count += ft_putchar(' ');
}



void flags_MDotAreaU(int* digit,pflags* flags,unsigned int* number,int* count)
{
    int i;
    int loop;

    i = 0;
    if (number == 0)
        *digit = 0;
    if (flags->dotarea < *digit && *number != 0)
        flags->dotarea = *digit;
    loop = (flags-> area - flags->dotarea);
    flags -> area = flags->dotarea;
    flags_AreaU(digit,flags,count);
    if (*number != 0 || flags -> dotarea != 0)
        *count += ft_putunbr(*number);
    while (i++ < loop)
        *count += ft_putchar(' ');
}

void    flags_MdotU(pflags* flags,int* digit,unsigned int* number,int* count)
{
    flags -> area = flags -> dotarea;
    flags_AreaU(digit,flags,count);
    if (*number != 0 || flags -> dotarea != 0)
        *count += ft_putunbr(*number);

}

void    flags_MzeroU(int* digit,pflags* flags,unsigned int number,int* count)
{
    flags -> area = flags -> zeroarea;
    flags_AreaU(digit,flags,count);
    *count += ft_putunbr(number);
}

void    flags_MAreafU(int* digit,pflags* flags,unsigned int number,int* count)
{
    *count += ft_putunbr(number);
    flags_AreaU(digit,flags,count);
}









void flags_AreaU(int* digit,pflags* flags,int* count)
{
    while (*digit < flags->area)
    {
        if (flags->zero == 1 || flags -> dot == 1)
            *count += ft_putchar('0');
        else 
            *count += ft_putchar(' ');
        (*digit)++;
    }
}

void    flags_zeroU(int* digit,pflags* flags,unsigned int number,int* count)
{
    flags -> area = flags -> zeroarea;
    flags_AreaU(digit,flags,count);
    *count += ft_putunbr(number);
}

void    flags_AreafU(int* digit,pflags* flags,unsigned int number,int* count)
{
    flags_AreaU(digit,flags,count);
    *count += ft_putunbr(number);
}

void flags_DotZAreaU(int* digit,pflags* flags,unsigned int* number,int* count)
{
    int i;
    int loop;

    i = 0;
    if (number == 0)
        *digit = 0;
    if (flags->dotarea < *digit && *number != 0)
        flags->dotarea = *digit;
    loop = (flags-> zeroarea - flags->dotarea);
    while (i++ < loop)
        *count += ft_putchar(' ');
    flags -> area = flags->dotarea;
    flags_AreaU(digit,flags,count);
    if (*number != 0 || flags -> dotarea != 0)
        *count += ft_putunbr(*number);
}


void flags_DotAreaU(pflags* flags,int* count)
{
    int i;

    i = 0;
    while (i++ < (flags -> area - flags -> dotarea))
        *count += ft_putchar(' ');
}


void    flags_dotU(pflags* flags,int* digit,unsigned int* number,int* count)
{

    flags -> area = flags -> dotarea;
    flags_AreaU(digit,flags,count);
    if (*number != 0 || flags -> dotarea != 0)
        *count += ft_putunbr(*number);
}