#include "ft_printf.h"
int ft_atoi(const char** str)
{
    int result;

    result = 0;
    while (*(*str) >= '0' && *(*str) <= '9' && *(*str))
    {
        
        result = (result * 10) + (*(*str) - 48);
        (*str)++;
    }
    (*str)--;
    return (result);
}
