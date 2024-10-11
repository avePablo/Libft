#include "ft_printf.h"

void	ft_putchar_pf(char c, size_t *cter)
{
	write(1, &c, 1);
	(*counter)++;
}