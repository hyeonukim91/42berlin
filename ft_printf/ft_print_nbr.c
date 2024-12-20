/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonuki <hyeonuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 18:58:49 by hyeonuki          #+#    #+#             */
/*   Updated: 2024/12/20 18:13:48 by hyeonuki         ###   ########.fr       */
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

int	ft_printnbr(long n)
{
	long	nbr;

	if (n < 0)
	{
		nbr = -n;
		if (ft_printchar('-') == -1)
			return (-1);
	}
	else
	{
		nbr = n;
	}
	if (nbr >= 10)
	{
		ft_printnbr(nbr / 10);
	}
	if (ft_printchar((nbr % 10) + '0') == -1)
		return (-1);
	return (ft_nbrlen(n));
}

int	ft_printun(unsigned int n)
{
	unsigned int	nbr;

	nbr = n;
	if (nbr >= 10)
	{
		ft_printnbr(nbr / 10);
	}
	if (ft_printchar((nbr % 10) + '0') == -1)
		return (-1);
	return (ft_nbrlen(n));
}
