/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonuki <hyeonuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 18:03:32 by hyeonuki          #+#    #+#             */
/*   Updated: 2024/12/07 22:18:15 by hyeonuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	ft_print_scanned_type(char *str, va_list args)
{
	if (*str == 'c')
		return (ft_putchar((char)va_arg(args, int)));
	else if (*str == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (*str == 'p')
		return (ft_putptr(va_arg(args, void *)));
	else if (*str == 'i' || *str == 'd')
		return (ft_putnbr(va_arg(args, int)));
	else if (*str == 'u')
		return (ft_putunsnbr(va_arg(args, unsigned int)));
	else if (*str == 'X')
		return (ft_puthexu(va_arg(args, int)));
	else if (*str == 'x')
		return (ft_puthexl(va_arg(args, int)));
	else if (*str == '%')
		return (ft_putchar('%'), 1);
	return (0);
}

int	ft_printf(const char *str, ...)
{
	int			count;
	int			buffer;
	char		*s;
	va_list		args;

	s = (char *)str;
	count = 0;
	va_start(args, str);
	while (*s)
	{
		if (*s != '%')
		{
			ft_putchar(*s);
			count++;
		}
		if (*s == '%')
		{
			buffer = ft_print_scanned_type(s + 1, args);
			count = count + buffer;
			s++;
		}
		s++;
	}
	return (count);
}
