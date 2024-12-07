/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonuki <hyeonuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 17:39:05 by hyeonuki          #+#    #+#             */
/*   Updated: 2024/12/07 22:14:53 by hyeonuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	ft_hexlen(int n)
{
	int				i;
	unsigned int	nbr;

	i = 0;
	nbr = n;
	while (nbr > 0)
	{
		nbr = nbr / 16;
		i++;
	}
	return (i);
}

int	ft_puthexl(int n)
{
	unsigned int	nbr;

	nbr = n;
	if (nbr >= 16)
	{
		ft_puthexl(nbr / 16);
	}
	if (nbr % 16 < 10)
	{
		ft_putchar((nbr % 16) + '0');
	}
	if (nbr % 16 >= 10)
	{
		ft_putchar((nbr % 16) + 'a' - 10);
	}
	return (ft_hexlen(n));
}
