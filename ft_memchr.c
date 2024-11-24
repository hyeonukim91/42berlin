/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonuki <hyeonuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 16:36:10 by hyeonuki          #+#    #+#             */
/*   Updated: 2024/11/24 14:48:24 by hyeonuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	usc;

	i = 0;
	usc = (unsigned char)c;
	if (s == NULL || n == 0)
	{
		return (NULL);
	}
	while (i < n)
	{
		if (((unsigned char *)s)[i] == usc)
		{
			return (((unsigned char *)s) + i);
		}
		i++;
	}
	return (NULL);
}
