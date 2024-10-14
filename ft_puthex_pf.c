/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabalvar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 19:18:06 by pabalvar          #+#    #+#             */
/*   Updated: 2024/10/11 19:18:08 by pabalvar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int	ft_strlen(char *str)
{
	size_t	len;

	len = 0;
	while (*str != '\0')
	{
		len++;
		str++;
	}
	return (len);
}

void	ft_puthex_pf(unsigned long long nbr, char *base, size_t *cter)
{
	unsigned long long	len;
	char *str;
	str = "";

	len = ft_strlen(base);
	if (nbr < 0)
	{
		ft_putchar_pf('-', cter);
		nbr = -nbr;
	}
	while (nbr)
	{
		len --;
		str[len] = base[nbr % len];
		nbr /= len;
	}
	ft_putstr_pf(str, cter);
}
