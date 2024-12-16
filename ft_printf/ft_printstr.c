/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonuki <hyeonuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 16:40:56 by hyeonuki          #+#    #+#             */
/*   Updated: 2024/12/16 13:12:07 by hyeonuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printstr(char *str, int *val)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && *val == 1)
	{
		if (ft_printchar(str[i], val) == -1)
		{
			return (-1);
		}
		i++;
	}
	return (i);
}
