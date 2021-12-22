/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_util2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odakhch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 20:22:00 by odakhch           #+#    #+#             */
/*   Updated: 2021/12/15 14:59:32 by odakhch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

size_t	taille(long int nb)
{
	int	i;

	i = 0;
	if (nb <= 0)
		i++;
	while (nb)
	{
		i++;
		nb = nb / 10;
	}
	return (i);
}

int	ft_hx_intlen(unsigned long int a)
{
	int	i;

	i = 0;
	if (a == 0)
		i++;
	while (a)
	{
		i++;
		a = a / 16;
	}
	return (i);
}

int	ft_unputnbr(unsigned int num)
{
	size_t	compt;

	compt = taille(num);
	if (num >= 10)
	{
		ft_putnbr(num / 10);
		ft_putnbr(num % 10);
	}
	else
	{
		ft_putchar(num + '0');
	}
	return (compt);
}

int	ft_putnbr_ptr(unsigned long int nb)
{
	int		l;
	char	*h;

	l = ft_hx_intlen(nb);
	h = "0123456789abcdef";
	if (nb >= 0 && nb < 16)
		ft_putchar(h[nb]);
	else if (nb >= 16)
	{
		ft_putnbr_ptr(nb / 16);
		ft_putnbr_ptr(nb % 16);
	}
	return (l + 2);
}
