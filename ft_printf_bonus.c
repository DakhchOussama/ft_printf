/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odakhch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 18:38:17 by odakhch           #+#    #+#             */
/*   Updated: 2021/12/15 20:18:27 by odakhch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_flags_test(const char	*format, va_list	tab, int	*i)
{
	int	r;

	r = 0;
	if (format[*i] == '+' || format[*i] == ' ')
	{
		r += ft_flags(format, tab, i);
	}
	else if (format[*i] == '#')
	{
		r += ft_flags2(format, tab, i);
	}
	return (r);
}

int	ft_flags2(const char	*format, va_list	tab, int	*i)
{
	int	r;
	int	nb;

	r = 0;
	nb = va_arg(tab, int);
	while (format[*i] == '#')
		(*i)++;
	if ((format[*i] == 'x' || format[*i] == 'X'))
	{
		if (nb != 0 && format[*i] == 'x')
		{
			r += write(1, "0x", 2);
			r += ft_lowercasehexadecimal(nb);
		}
		else if (nb != 0 && format[*i] == 'X')
		{
			r += write(1, "0X", 2);
			r += ft_hexadecimal(nb);
		}
		else
			r += ft_putnbr(nb);
	}
	return (r);
}

int	ft_flags(const char	*format, va_list	tab, int	*i)
{
	int	r;
	int	nb;

	r = 0;
	nb = va_arg(tab, int);
	while (format[*i] == '+' || format[*i] == ' ')
		(*i)++;
	if ((format[*i] == 'd' || format[*i] == 'i'))
	{
		if (nb >= 0 && format[*i - 1] == ' ')
		{
			r += write(1, " ", 1);
			r += ft_putnbr(nb);
		}
		else if (nb >= 0 && format[*i - 1] == '+')
		{
			r += write(1, "+", 1);
			r += ft_putnbr(nb);
		}
		else
			r += ft_putnbr(nb);
	}
	return (r);
}
