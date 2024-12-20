/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonuki <hyeonuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 18:57:29 by hyeonuki          #+#    #+#             */
/*   Updated: 2024/12/20 18:17:06 by hyeonuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_printstr(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		if (write(1, "(null)", 6) == -1)
		{
			return (-1);
		}
		return (6);
	}
	while (str[i] != '\0')
	{
		if (ft_printchar(str[i]) == -1)
		{
			return (-1);
		}
		i++;
	}
	return (i);
}
