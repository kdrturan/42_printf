#include "ft_printf.h"

int	ft_strlen(const char *s)
{
    int i;

    i = 0;
    while (s[i])
        i++;
    return (i);
}


void cflag(pflags* flags, va_list vlist,int* count)
{
    if (flags->left)
    {
        *count += ft_putchar(va_arg(vlist,int));   
        while (flags->area > 1)
        {
            *count += ft_putchar(' ');
            flags->area--;
        }
    }
    else
    {
        while (flags->area > 1)
        {
            *count += ft_putchar(' ');
            flags->area--;
        }
        *count += ft_putchar(va_arg(vlist,int));
    }
}


void    sflag(pflags* flags, va_list vlist,int* count)
{
    char *string;
    int len;

    string = (va_arg(vlist,char*));
    if (string != NULL)
        len = ft_strlen(string);
    if(flags->dot)
        sflag_areadot(flags,count,string,len);
    else if (flags->area)
        sflag_area(flags,count,string,len);
    else
        *count += ft_putstr(string,-1);
}



void    sflag_area(pflags* flags,int* count,char *string,int len)
{
    int loop;

    loop = flags->area - len;
    if (string == NULL)
    {
        loop = flags -> area - 6;
        while (loop-- > 0)
            *count += ft_putchar(' ');
        if (flags->dotarea >= 6 || !flags->dot)
           *count += ft_putstr("(null)",-1);
    }
    else if (flags->left)
    {
        *count += ft_putstr(string,-1);   
        while (loop-- > 0)
            *count += ft_putchar(' ');
    }
    else
    {
        while (loop-- > 0)
            *count += ft_putchar(' ');
        *count += ft_putstr(string,-1);
    }
}

void sflag_areadot(pflags* flags,int* count,char *string,int len)
{
    int area;
    if (len < flags -> dotarea)
        area = flags -> area - len;
    else
        area = flags->area - flags->dotarea;
    if (string == NULL)
    {
        if (flags->dotarea >= 6)
            *count += ft_putstr("(null)",-1);
    }    
    else if (flags->left)
    {
        *count += ft_putstr(string,flags->dotarea);
        while (area-- > 0)
            *count += ft_putchar(' ');
    }
    else
    {
        while (area-- > 0)
            *count += ft_putchar(' ');
        *count += ft_putstr(string,flags->dotarea);
    }

}