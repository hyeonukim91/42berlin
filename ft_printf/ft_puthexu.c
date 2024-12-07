/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonuki <hyeonuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 17:38:56 by hyeonuki          #+#    #+#             */
/*   Updated: 2024/12/07 22:13:26 by hyeonuki         ###   ########.fr       */
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

int	ft_puthexu(int n)
{
	unsigned int	nbr;

	nbr = n;
	if (nbr >= 16)
	{
		ft_puthexu(nbr / 16);
	}
	if (nbr % 16 < 10)
	{
		ft_putchar((nbr % 16) + '0');
	}
	if (nbr % 16 >= 10)
	{
		ft_putchar((nbr % 16) + 'A' - 10);
	}
	return (ft_hexlen(n));
}
