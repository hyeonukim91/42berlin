/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonuki <hyeonuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 18:58:49 by hyeonuki          #+#    #+#             */
/*   Updated: 2024/12/14 15:26:16 by hyeonuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	ft_nbrlen(long n)
{
	int		i;
	long	nbr;

	i = 0;
	if (n < 0)
	{
		i++;
		nbr = -n;
	}
	else
	{
		nbr = n;
	}
	if (nbr == 0)
	{
		return (1);
	}
	while (nbr > 0)
	{
		nbr = nbr / 10;
		i++;
	}
	return (i);
}

int	ft_printnbr(long n, int val)
{
	long	nbr;

	if (n < 0)
	{
		nbr = -n;
		ft_printchar('-', val);
	}
	else
	{
		nbr = n;
	}
	if (nbr >= 10)
	{
		ft_printnbr(nbr / 10, val);
	}
	ft_printchar((nbr % 10) + '0', val);
	return (ft_nbrlen(n));
}
