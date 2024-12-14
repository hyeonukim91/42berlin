/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhexu.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonuki <hyeonuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 17:38:56 by hyeonuki          #+#    #+#             */
/*   Updated: 2024/12/14 15:23:38 by hyeonuki         ###   ########.fr       */
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

int	ft_printhexu(int n, int val)
{
	unsigned int	nbr;

	nbr = n;
	if (nbr >= 16)
	{
		ft_printhexu(nbr / 16, val);
	}
	if (nbr % 16 < 10)
	{
		ft_printchar((nbr % 16) + '0', val);
	}
	if (nbr % 16 >= 10)
	{
		ft_printchar((nbr % 16) + 'A' - 10, val);
	}
	return (ft_hexlen(n));
}
