/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonuki <hyeonuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 22:09:12 by hyeonuki          #+#    #+#             */
/*   Updated: 2024/12/20 20:04:37 by hyeonuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex(int nbr, char c)
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
		len += ft_print_hex(n / 16, c);
	}
	r = ft_print_char(hex[n % 16]);
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
	len += ft_print_char(hex[nbr % 16]);
	return (len);
}

int	ft_print_ptr(void *ptr)
{
	int		r1;
	int		r2;
	long	ptr_temp;

	if (ptr == NULL)
	{
		if (ft_print_str("(nil)") == -1)
			return (-1);
		return (5);
	}
	ptr_temp = (unsigned long)ptr;
	r1 = ft_print_str("0x");
	if (r1 == -1)
		return (-1);
	r2 = ft_printhex_long(ptr_temp);
	if (r2 == -1)
		return (-1);
	return (r1 + r2);
}
