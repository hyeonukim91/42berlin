/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonuki <hyeonuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 19:23:09 by hyeonuki          #+#    #+#             */
/*   Updated: 2024/11/17 18:54:53 by hyeonuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	
	i = 0;
	if (*little == '\0')
	{
		return ((char *)big);
	}
	while (big[i] != '\0' && i < len ||)
	{
		if (little[0] == big[i])
		{
			j = 0;
			while ((little[j] == big[i + j]) && (little[j] != '\0') && i + j < len)
			{
				j++;
			}
			if (little[j] == '\0')
				return ((char *)&big[i]);
			i++;
		}
	}
	return (NULL);
}