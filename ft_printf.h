/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odakhch <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 19:05:31 by odakhch           #+#    #+#             */
/*   Updated: 2021/12/15 14:45:02 by odakhch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_putchar(char c);
int		ft_putnbr(long int nb);
int		ft_putstr(char *str);
int		ft_hexadecimal(unsigned int num);
size_t	taille(long int nb);
int		ft_lowercasehexadecimal(unsigned int num);
int		ft_unputnbr(unsigned int num);
int		ft_printf(const char	*format, ...);
int		check(va_list tab, char format);
int		ft_flags(const char	*format, va_list	tab, int	*i);
int		ft_flags2(const char	*format, va_list	tab, int	*i);
int		ft_hx_intlen(unsigned long int a);
int		ft_putnbr_ptr(unsigned long int nb);
int		ft_flags_test(const char *format, va_list tab, int *i);
#endif
