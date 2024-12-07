/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonuki <hyeonuki@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 22:09:12 by hyeonuki          #+#    #+#             */
/*   Updated: 2024/12/07 22:10:48 by hyeonuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	ft_puthexl_uns(unsigned long nbr)
{
	if (nbr >= 16)
	{
		ft_puthexl_uns(nbr / 16);
	}
	if (nbr % 16 < 10)
	{
		ft_putchar((nbr % 16) + '0');
	}
	if (nbr % 16 >= 10)
	{
		ft_putchar((nbr % 16) + 'a' - 10);
	}
}

int	ft_putptr(void *ptr)
{
	unsigned long	ptr_temp;

	ptr_temp = (unsigned long)ptr;
	ft_putchar('0');
	ft_putchar('x');
	ft_puthexl_uns(ptr_temp);
	return (14);
}
