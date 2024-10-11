#include "ft_printf.h"
void ft_putnbt_pf(int n, size_t cter)
{
    if (n == -2147483648)
	{
		ft_putnbr_pf((n / 10), cter);
		ft_putchar_pf('8', cter);
	}
	else if (n < 0)
	{
		ft_putchar_pf('-', cter);
		ft_putnbr_pf(-n, cter);
	}
	else
	{
		if (n > 9)
			ft_putnbr_pf((n / 10), cter);
		ft_putchar_pf(('0' + n % 10), cter);
	}
}