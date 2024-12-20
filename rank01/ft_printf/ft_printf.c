/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonuki <hyeonuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 18:03:32 by hyeonuki          #+#    #+#             */
/*   Updated: 2024/12/20 19:11:23 by hyeonuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	ft_print_scanned_type(char *str, va_list args)
{
	int	r;

	r = -1;
	if (*str == 'c')
		r = ft_printchar((char)va_arg(args, int));
	else if (*str == 's')
		r = (ft_printstr(va_arg(args, char *)));
	else if (*str == 'p')
		r = (ft_printptr(va_arg(args, void *)));
	else if (*str == 'i' || *str == 'd')
		r = (ft_printnbr(va_arg(args, int)));
	else if (*str == 'u')
		r = (ft_printun((va_arg(args, unsigned int))));
	else if (*str == 'X' || *str == 'x')
		r = (ft_printhex(va_arg(args, int), *str));
	else if (*str == '%')
		r = (ft_printchar('%'));
	return (r);
}

int	ft_printf(const char *str, ...)
{
	int			count;
	int			i;
	va_list		args;

	count = 0;
	i = 1;
	va_start(args, str);
	if (str == (char *) NULL)
		return (-1);
	while (*str)
	{
		if (*str != '%')
			count = count + ft_printchar(*str);
		if (*str == '%')
		{
			i = ft_print_scanned_type((char *)(str + 1), args);
			if (i == -1)
				return (-1);
			count += i;
			str++;
		}
		str++;
	}
	return (count);
}
// #include <stdio.h>
// #include <limits.h>
// int     main(void)
// {
// 	int		a = 42;
// 	int		*np = NULL;
// 	char	b = 'b';

//         ft_printf("%d\n", ft_printf("%c_%s_%i_%d_%p\n", 0, "", 0, 0, &a));
//         printf("%d\n",  printf("%c_%s_%i_%d_%p\n", 0, "", 0, 0, &a));
//         ft_printf("%d\n", ft_printf("%i_%i_\n", INT_MAX, INT_MIN));
//         printf("%d\n",  printf("%i_%i_\n", INT_MAX, INT_MIN));
//         ft_printf("%d\n", ft_printf("%X_%x_\n", INT_MAX, INT_MIN));
//         printf("%d\n",  printf("%X_%x_\n", INT_MAX, INT_MIN));
//         ft_printf("%d\n", ft_printf("%p_%p\n", &b, np));
//         printf("%d\n",  printf("%p_%p\n", &b, np));	

//         return (0);
// }