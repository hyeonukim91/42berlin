/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonuki <hyeonuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 18:03:32 by hyeonuki          #+#    #+#             */
/*   Updated: 2024/12/16 13:16:16 by hyeonuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	ft_print_scanned_type(char *str, va_list args, int *val)
{
	if (*str == 'c')
		return (ft_printchar((char)va_arg(args, int), val));
	else if (*str == 's')
		return (ft_printstr(va_arg(args, char *), val));
	else if (*str == 'p')
		return (ft_printptr(va_arg(args, void *), val));
	else if (*str == 'i' || *str == 'd')
		return (ft_printnbr((long)(va_arg(args, int)), val));
	else if (*str == 'u')
		return (ft_printnbr((long)(va_arg(args, unsigned int)), val));
	else if (*str == 'X')
		return (ft_printhexu(va_arg(args, int), val));
	else if (*str == 'x')
		return (ft_printhexl(va_arg(args, int), val));
	else if (*str == '%')
		return (ft_printchar('%', val));
	return (*val);
}

int	ft_printf(const char *str, ...)
{
	int			count;
	int			i;
	int			*val;
	char		*s;
	va_list		args;

	i = 1;
	val = &i;
	s = (char *)str;
	count = 0;
	va_start(args, str);
	while (*s && *val == 1)
	{
		if (*s != '%')
			count = count + ft_printchar(*s, val);
		if (*s == '%')
		{
			count = count + ft_print_scanned_type(s + 1, args, val);
			s++;
		}
		s++;
	}
	if (*val == -1)
		return (-1);
	return (count);
}
// #include <stdio.h>
// #include <limits.h>
// int     main(void)
// {
//         int		a = 42;
// 	int		*np = NULL;
// 	char	b = 'b';

//         ft_printf("%d\n", ft_printf("%c_%s_%i_%d_%p\n", 0, "z", 0, 0, &a));
//         printf("%d\n",  printf("%c_%s_%i_%d_%p\n", 0, "z", 0, 0, &a));
//         ft_printf("%d\n", ft_printf("%i_%i_\n", INT_MAX, INT_MIN));
//         printf("%d\n",  printf("%i_%i_\n", INT_MAX, INT_MIN));
//         ft_printf("%d\n", ft_printf("%X_%x_\n", INT_MAX, INT_MIN));
//         printf("%d\n",  printf("%X_%x_\n", INT_MAX, INT_MIN));
//         ft_printf("%d\n", ft_printf("%p_%p\n", &b, np));
//         printf("%d\n",  printf("%p_%p\n", &b, np));	

//         return (0);
// }
