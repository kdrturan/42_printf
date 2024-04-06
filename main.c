#include "ft_printf.h"
#include <stdio.h>
int main()
{
    int*a;
    ft_printf("c = %c\ns = %s\np = %p\nd = %d\ni = %i\nu = %u\nx = %x\nX = %X\n",'a',"kadir",a,-258,658,699,19,15);
    printf ("***********************************\n");
    printf("c = %c\ns = %s\np = %p\nd = %d\ni = %i\nu = %u\nx = %x\nX = %X\n",'a',"kadir",a,-258,658,699,19,15);
}