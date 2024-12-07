/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonuki <hyeonuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 18:58:49 by hyeonuki          #+#    #+#             */
/*   Updated: 2024/12/07 22:08:11 by hyeonuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	ft_nbrlen(int n)
{
	int				i;
	unsigned int	nbr;

	i = 0;
	if (n < 0)
	{
		i++;
		nbr = -n;
	}
	else if (n >= 0)
	{
		nbr = n;
	}
	while (nbr > 0)
	{
		nbr = nbr / 10;
		i++;
	}
	return (i);
}

int	ft_putnbr(int n)
{
	unsigned int	nbr;

	if (n < 0)
	{
		nbr = -n;
		ft_putchar('-');
	}
	else
	{
		nbr = n;
	}
	if (nbr >= 10)
	{
		ft_putnbr(nbr / 10);
	}
	ft_putchar((nbr % 10) + '0');
	return (ft_nbrlen(n));
}
