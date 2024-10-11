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
	int	len;

	len = 0;
	while (*str != '\0')
	{
		len++;
		str++;
	}
	return (len);
}

void	ft_puthex_pf(int nbr, char *base, size_t cter)
{
	int	len;

	len = ft_strlen(base);
	if (nbr < 0)
	{
		ft_putchar_pf('-');
		nbr = -nbr;
	}
	while (nbr > (len - 1))
	{
		ft_puthex_pf(nbr /= len, base, cter);
	}
	write(1, &base[nbr % len], 1);
}
