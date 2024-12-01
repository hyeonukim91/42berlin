/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonuki <hyeonuki@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 18:55:33 by hyeonuki          #+#    #+#             */
/*   Updated: 2024/11/30 16:45:35 by hyeonuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_set(char c, const char *set)
{
	int	i;

	if (set == NULL || *set == '\0')
	{
		return (0);
	}
	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
		{
			return (1);
		}
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	int		len;
	char	*output;

	start = 0;
	end = ft_strlen(s1) - 1;
	while (is_set(s1[start], set) == 1)
		start++;
	while (is_set(s1[end], set) == 1)
		end--;
	if (start > end)
		len = 0;
	else
		len = end - start + 1;
	output = (char *)malloc(sizeof(char) * (len + 1));
	if (output == NULL)
		return (NULL);
	ft_strlcpy(output, (s1 + start), (size_t)(len + 1));
	return (output);
}
/*
#include <stdio.h>

int	main(void)
{
	printf("%s\n",ft_strtrim("lorem \n ipsum \t dolor \n sit \t amet"," "));
	return (0);
}
*/
