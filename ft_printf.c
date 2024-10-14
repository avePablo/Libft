/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabalvar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 19:16:50 by pabalvar          #+#    #+#             */
/*   Updated: 2024/10/11 19:16:59 by pabalvar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    ft_option(va_list va, char *std, size_t *cter)
{
    if (*std == 'c')
        ft_putchar_pf(va_arg(va, int), cter);
    else if (*std == 's')
        ft_putstr_pf(va_arg(va, char*), cter);
    else if (*std == 'p')
        {   
        ft_putstr_pf("0x", cter);
        ft_puthex_pf(va_arg(va, unsigned long long), "0123456789abcdef", cter);
        }
    else if (*std == 'd' || *std == 'i')
        ft_putnbr_pf(va_arg(va, int), cter);
    else if (*std == 'u')
        ft_putunbr_pf(va_arg(va, int), cter);
    else if (*std == 'x' || *std == 'X')
    {
        if (*std == 'x')
            ft_puthex_pf(va_arg(va, unsigned long long),"0123456789abcdef", cter);
        else
            ft_puthex_pf(va_arg(va, unsigned long long),"0123456789ABCDEF", cter);
    }
    else if (*std == '%')
        ft_putchar_pf(*std, cter);
}

int ft_printf(char const *str, ...)
{
    va_list va;
    size_t  cter;
    int     i;
    char    *std;

    std = (char *)str;
    i = 0;
    if(!std)
        return (0);
    cter = 0;
    va_start(va, str);    
    while (std[i] != '\0')
    {
        if (std[i] == '%')
        {
            i++;
            ft_option(va, &std[i], &cter);
        }
        else
            ft_putchar_pf(std[i], &cter);
        i++;
    }
    va_end(va);
    return (cter);
}
//char *s = "que tal";
//printf("hola%s %d %i",s 55 66)

int main()
{
    char str[] = "que tal";
    ft_printf("%x\n", 54);
    return (0);
}