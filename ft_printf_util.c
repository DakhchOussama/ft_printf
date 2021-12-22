/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odakhch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 16:08:33 by odakhch           #+#    #+#             */
/*   Updated: 2021/12/13 20:32:52 by odakhch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(long int nb)
{
	int	il;

	il = taille(nb);
	if (nb < 0)
	{
		ft_putchar('-');
		nb = nb * (-1);
	}
	if (nb >= 0 && nb < 10)
		ft_putchar(nb + '0');
	else if (nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	return (il);
}

int	ft_putstr(char *str)
{
	size_t	i;

	i = 0;
	if (str == NULL)
	{
		return (write(1, "(null)", 6));
	}
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}

int	ft_lowercasehexadecimal(unsigned int nb)
{
	int		il;
	char	*h;

	il = ft_hx_intlen(nb);
	h = "0123456789abcdef";
	if (nb >= 0 && nb < 16)
		ft_putchar(h[nb]);
	else if (nb >= 16)
	{
		ft_lowercasehexadecimal(nb / 16);
		ft_lowercasehexadecimal(nb % 16);
	}
	return (il);
}

int	ft_hexadecimal(unsigned int nb)
{
	int		il;
	char	*h;

	il = ft_hx_intlen(nb);
	h = "0123456789ABCDEF";
	if (nb >= 0 && nb < 16)
		ft_putchar(h[nb]);
	else if (nb >= 16)
	{
		ft_hexadecimal(nb / 16);
		ft_hexadecimal(nb % 16);
	}
	return (il);
}
