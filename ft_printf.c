/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odakhch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 15:33:59 by odakhch           #+#    #+#             */
/*   Updated: 2021/12/15 20:55:26 by odakhch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check(va_list tab, char format)
{
	int	r;

	r = 0;
	if (format == '%')
		r = ft_putchar('%');
	else if (format == 'd' || format == 'i')
		r = ft_putnbr(va_arg(tab, int));
	else if (format == 'c')
		r = ft_putchar(va_arg(tab, int));
	else if (format == 's')
		r = ft_putstr(va_arg(tab, char *));
	else if (format == 'X')
		r = ft_hexadecimal(va_arg(tab, int));
	else if (format == 'x')
		r = ft_lowercasehexadecimal(va_arg(tab, int));
	else if (format == 'u')
		r = ft_unputnbr(va_arg(tab, int));
	else if (format == 'p')
	{
		write(1, "0x", 2);
		r = ft_putnbr_ptr(va_arg(tab, unsigned long int));
	}
	else
		r = ft_putchar(format);
	return (r);
}

int	ft_printf(const char	*format, ...)
{
	va_list	tab;
	int		n;
	int		i;

	if (!format)
		return (0);
	va_start(tab, format);
	n = 0;
	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == ' ' || format[i] == '+' || format[i] == '#')
					n += ft_flags_test(format, tab, &i);
			else
				n += check(tab, format[i]);
		}
		else
			n += ft_putchar(format[i]);
		i++;
	}
	va_end(tab);
	return (n);
}
