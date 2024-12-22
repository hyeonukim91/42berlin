/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonuki <hyeonuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 18:03:32 by hyeonuki          #+#    #+#             */
/*   Updated: 2024/12/21 14:22:54 by hyeonuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	ft_print_scanned_type(char *str, va_list args)
{
	int	r;

	r = -1;
	if (*str == 'c')
		r = ft_print_char((char)va_arg(args, int));
	else if (*str == 's')
		r = (ft_print_str(va_arg(args, char *)));
	else if (*str == 'p')
		r = (ft_print_ptr(va_arg(args, void *)));
	else if (*str == 'i' || *str == 'd')
		r = (ft_print_nbr(va_arg(args, int)));
	else if (*str == 'u')
		r = (ft_print_un((va_arg(args, unsigned int))));
	else if (*str == 'X' || *str == 'x')
		r = (ft_print_hex(va_arg(args, int), *str));
	else if (*str == '%')
		r = (ft_print_char('%'));
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
			count = count + ft_print_char(*str);
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
	va_end(args);
	return (count);
}
// #include <stdio.h>
// #include <limits.h>
// int     main(void)
// {
// 	int		a = 42;
// 	int		*np = NULL;
// 	char	b = 'b';

// 		ft_printf("\nCharacter String\n");
//         ft_printf("%d\n", ft_printf("%%_%s_%c_%s_\n","abc", 0, ""));
//         printf("%d\n",  printf("%%_%s_%c_%s_\n","abc", 0, ""));
//      	ft_printf("%d\n", ft_printf("%s_%%\n",(char *)NULL));
//         printf("%d\n",  printf("%s_%%\n",(char *)NULL));
// 		ft_printf("\nnumbers\n");
//         ft_printf("%d\n", ft_printf("%i_%i_%d\n", INT_MAX, INT_MIN, a));
//         printf("%d\n",  printf("%i_%i_%d\n", INT_MAX, INT_MIN, a));
// 		ft_printf("\nHexcodes\n");		
//         ft_printf("%d\n", ft_printf("%X_%x_\n", INT_MAX, INT_MIN));
//         printf("%d\n",  printf("%X_%x_\n", INT_MAX, INT_MIN));
//         ft_printf("%d\n", ft_printf("%x_%X_\n", INT_MAX, INT_MIN));
//         printf("%d\n",  printf("%x_%X_\n", INT_MAX, INT_MIN));
// 		ft_printf("\nPointer\n");
//         ft_printf("%d\n", ft_printf("%p_%p\n", &b, np));
//         printf("%d\n",  printf("%p_%p\n", &b, np));	
// 		ft_printf("\nNULL input\n");
//         ft_printf(("%d\n"), ft_printf((char *)NULL));
//         printf("%d\n",  printf((char *)NULL));

//         return (0);
// }
