#include "ft_printf.h"

void ft_putunbr_pf(int n, size_t *cter)
{   
    if (n < 0)
        n = -n;
    ft_putnbr_pf(n, cter);
}