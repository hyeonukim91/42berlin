/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonuki <hyeonuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 18:58:49 by hyeonuki          #+#    #+#             */
/*   Updated: 2024/12/20 20:11:28 by hyeonuki         ###   ########.fr       */
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

int	ft_print_un(unsigned int n)
{
	if (n >= 10)
	{
		ft_print_un(n / 10);
	}
	if (ft_print_char((n % 10) + '0') == -1)
		return (-1);
	return (ft_nbrlen(n));
}

int	ft_print_nbr(int n)
{
	unsigned int	nbr;

	if (n < 0)
	{
		nbr = -n;
		if (ft_print_char('-') == -1)
			return (-1);
	}
	else
	{
		nbr = n;
	}
	ft_print_un(nbr);
	return (ft_nbrlen(n));
}
