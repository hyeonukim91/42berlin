/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonuki <hyeonuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 22:09:12 by hyeonuki          #+#    #+#             */
/*   Updated: 2024/12/20 19:16:20 by hyeonuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printhex(int nbr, char c)
{
	char			*hex;
	int				len;
	int				r;
	unsigned int	n;

	len = 0;
	n = nbr;
	if (c == 'X')
		hex = "0123456789ABCDEF";
	else
		hex = "0123456789abcdef"; 
	if (n >= 16)
	{
		len += ft_printhex(n / 16, c);
	}
	r = ft_printchar(hex[n % 16]);
	if (r == -1)
		return (-1);
	len += r;
	return (len);
}

static	int	ft_printhex_long(unsigned long nbr)
{
	char	*hex;
	int		len;

	hex = "0123456789abcdef";
	len = 0;
	if (nbr >= 16)
	{
		len += ft_printhex_long(nbr / 16);
	}
	len += ft_printchar(hex[nbr % 16]);
	return (len);
}

int	ft_printptr(void *ptr)
{
	int		r1;
	int		r2;
	long	ptr_temp;

	if (ptr == NULL)
	{
		if (ft_printstr("(nil)") == -1)
			return (-1);
		return (5);
	}
	ptr_temp = (unsigned long)ptr;
	r1 = ft_printstr("0x");
	if (r1 == -1)
		return (-1);
	r2 = ft_printhex_long(ptr_temp);
	if (r2 == -1)
		return (-1);
	return (r1 + r2);
}
