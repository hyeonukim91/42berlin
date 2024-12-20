/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonuki <hyeonuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 19:08:16 by hyeonuki          #+#    #+#             */
/*   Updated: 2024/11/30 18:32:46 by hyeonuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*str;
	size_t	i;

	if (dest == NULL && src == NULL)
		return (NULL);
	str = (char *)dest;
	i = 0;
	while (i < n)
	{
		str[i] = ((char *)src)[i];
		i++;
	}
	return (dest);
}
