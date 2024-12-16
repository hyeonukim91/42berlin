/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printun.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonuki <hyeonuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 22:11:00 by hyeonuki          #+#    #+#             */
/*   Updated: 2024/12/16 12:43:55 by hyeonuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	ft_nbrlen(unsigned int nbr)
{
	int	i;

	i = 0;
	while (nbr > 0)
	{
		nbr = nbr / 10;
		i++;
	}
	return (i);
}

int	ft_printun(unsigned int n, int *val)
{
	unsigned int	nbr;

	nbr = n;
	if (nbr >= 10)
	{
		ft_printnbr(nbr / 10, val);
	}
	ft_printchar((nbr % 10) + '0', val);
	return (ft_nbrlen(n));
}
