#include "ft_printf.h"


void	ft_putunbr_pf(unsigned int n, size_t *cter)
{
	if (n == 0)
		ft_putchar_pf('0', cter);
	else
		ft_puthex_pf(n, "0123456789", cter, 0);
}