#include "ft_printf.h"

void ft_putstr_pf(char *std, size_t *cter)
{
    int i;

    i = 0;
    if (!std)
        return(0);
    while (std[i] != '\0')
    {
        ft_putchar_pf(std[i], cter)
        i++;
    }
}