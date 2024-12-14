/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonuki <hyeonuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 16:40:56 by hyeonuki          #+#    #+#             */
/*   Updated: 2024/12/14 15:06:13 by hyeonuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printstr(char *str, int val)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_printchar(str[i], val);
		i++;
	}
	return (i);
}
