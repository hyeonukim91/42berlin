/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonuki <hyeonuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 22:09:12 by hyeonuki          #+#    #+#             */
/*   Updated: 2024/12/14 15:37:40 by hyeonuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// static	int	ft_ptr_len(long ptr)
// {
// 	int	len;

// 	len = 0;
// 	if (ptr == 0)
// 	{
// 		return (0);
// 	}
// 	while (ptr != 0)
// 	{
// 		len++;
// 		ptr = ptr / 16;
// 	}
// 	return (len);
// }

static	int	ft_printhexl_long(unsigned long nbr, int val)
{
	char	*hex;
	int		len;

	hex = "0123456789abcdef";
	len = 0;
	if (nbr >= 16)
	{
		len += ft_printhexl_long(nbr / 16, val);
	}
	len += ft_printchar(hex[nbr % 16], val);
	return (len);
}

int	ft_printptr(void *ptr, int val)
{
	int		len;
	long	ptr_temp;

	len = 0;
	if (ptr == NULL)
	{
		ft_printstr("(nil)", val);
		return (5);
	}
	ptr_temp = (unsigned long)ptr;
	return (ft_printstr("0x", val) + ft_printhexl_long(ptr_temp, val));
}

	// if (nbr >= 16)
	// {
	// 	ft_puthexl_long(nbr / 16);
	// }
	// if (nbr % 16 < 10)
	// {
	// 	ft_putchar((nbr % 16) + '0');
	// }
	// if (nbr % 16 >= 10)
	// {
	// 	ft_putchar((nbr % 16) - 10 + 'a');
	// }
	// return (ft_ptr_len(nbr));