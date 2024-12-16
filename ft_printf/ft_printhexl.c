/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhexl.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonuki <hyeonuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 17:39:05 by hyeonuki          #+#    #+#             */
/*   Updated: 2024/12/16 13:18:30 by hyeonuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	ft_hexlen(int n)
{
	int				i;
	unsigned int	nbr;

	i = 0;
	nbr = n;
	if (nbr == 0)
	{
		return (1);
	}
	while (nbr > 0)
	{
		nbr = nbr / 16;
		i++;
	}
	return (i);
}

int	ft_printhexl(int n, int *val)
{
	unsigned int	nbr;

	nbr = n;
	if (nbr >= 16 && *val == 1)
	{
		ft_printhexl(nbr / 16, val);
	}
	if (nbr % 16 < 10 && *val == 1)
	{
		if (ft_printchar((nbr % 16) + '0', val) == -1)
		{
			*val = -1;
			return (-1);
		}
	}
	if (nbr % 16 >= 10 && *val == 1)
	{
		if (ft_printchar((nbr % 16) + 'a' - 10, val) == -1)
		{
			*val = -1;
			return (-1);
		}
	}
	return (ft_hexlen(n));
}
