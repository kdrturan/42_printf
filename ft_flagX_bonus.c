#include "ft_printf.h"


int Xflag(pflags* flags, va_list vlist,int* count,const char str)
{
    long number;
    int digit;

    number = va_arg(vlist, unsigned int);
    digit = find_digitX(number);
    if (flags->hash && number != 0 && str == 'X')
        *count += ft_putstr("0X",-1);
    else if (flags->hash && number != 0 && str == 'x')
        *count += ft_putstr("0x",-1);
    if (flags->left)
        flags_minusX(flags,&digit,&number,count,str);
    else if (flags -> zero && flags -> dot)
        flags_DotZAreaX(&digit,flags,&number,count,str);
    else if (flags->dot)
        flags_dotX(flags,&digit,&number,count,str);
    else if (flags -> zero)
        flags_zeroX(&digit,flags,number,count,str);
    else if (flags -> area)
        flags_AreafX(&digit,flags,number,count,str);
    else
        *count += ft_PUTHEX(number,str);
    return (1);
}



void    flags_minusX(pflags* flags,int *digit,long *number,int* count,const char str)
{
    if (flags -> zero && flags -> dot)
        flags_MDotZAreaX(digit,flags,number,count,str);
    else if (flags -> area && flags -> dot)
        flags_MDotAreaX(digit,flags,number,count,str);
    else if (flags->dot)
        flags_MdotX(flags,digit,number,count,str);
    else if (flags -> zero)
        flags_MzeroX(digit,flags,*number,count,str);
    else if (flags -> area)
        flags_MAreafX(digit,flags,*number,count,str);
    else
        *count += ft_PUTHEX(*number,str);
}


void flags_MDotZAreaX(int* digit,pflags* flags,long* number,int* count,const char str)
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
    flags_AreaX(digit,flags,count);
    if (*number != 0 || flags -> dotarea != 0)
        *count += ft_PUTHEX(*number,str);
    while (i++ < loop)
        *count += ft_putchar(' ');
}

void flags_MDotAreaX(int* digit,pflags* flags,long* number,int* count,const char str)
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
    flags_AreaX(digit,flags,count);  
    if (*number != 0 || flags -> dotarea != 0)
        *count += ft_PUTHEX(*number,str);
    while (i++ < loop)
        *count += ft_putchar(' ');
}

void    flags_MdotX(pflags* flags,int* digit,long* number,int* count,const char str)
{
    flags -> area = flags -> dotarea;
    flags_AreaX(digit,flags,count);   
    if (*number != 0 || flags -> dotarea != 0)
        *count += ft_PUTHEX(*number,str);
}

void    flags_MzeroX(int* digit,pflags* flags, long number,int* count,const char str)
{
    flags -> area = flags -> zeroarea;
    flags_AreaX(digit,flags,count);
    *count += ft_PUTHEX(number,str);
}

void    flags_MAreafX(int* digit,pflags* flags, long number,int* count,const char str)
{
    *count += ft_PUTHEX(number,str);
    flags_AreaX(digit,flags,count);
}

void flags_AreaX(int* digit,pflags* flags,int* count)
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

void    flags_zeroX(int* digit,pflags* flags, long number,int* count,const char str)
{
    flags -> area = flags -> zeroarea;
    flags_AreaX(digit,flags,count);
    *count += ft_PUTHEX(number,str);
}

void    flags_AreafX(int* digit,pflags* flags, long number,int* count,const char str)
{
    flags_AreaX(digit,flags,count);
    *count += ft_PUTHEX(number,str);
}

void flags_DotZAreaX(int* digit,pflags* flags,long* number,int* count,const char str)
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
    flags_AreaX(digit,flags,count);
    if (*number != 0 || flags -> dotarea != 0)
        *count += ft_PUTHEX(*number,str);
}

void flags_DotAreaX(pflags* flags,int* count)
{
    int i;

    i = 0;
    while (i++ < (flags -> area - flags -> dotarea))
        *count += ft_putchar(' ');
}

void    flags_dotX(pflags* flags,int* digit,long* number,int* count,const char str)
{
    if (*digit > flags -> dotarea)
    {
        flags->dotarea = *digit;
        flags->left = 1;
    }
    flags_DotAreaX(flags,count);
    flags -> area = flags -> dotarea;
    flags_AreaX(digit,flags,count);
    if (*number != 0 || !flags -> left != 0)
        *count += ft_PUTHEX(*number,str);
}