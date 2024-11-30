/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonuki <hyeonuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 19:14:38 by hyeonuki          #+#    #+#             */
/*   Updated: 2024/11/30 14:37:38 by hyeonuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	c = c % 256;
	if (c == '\0')
	{
		return ((char *)s + ft_strlen(s));
	}
	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			return ((char *)s + i);
		}
		i++;
	}
	return (NULL);
}
// #include <stdio.h>
// int main()
// {
// 	const char *str = "Hello, World!";
//	char target = 'o';
//
//     // Search for the character 'o'
//     char *result = ft_strchr(str, target);
//     if (result != NULL) {
//         printf("Found '%c' at position: %ld\n", target, result - str);
//     } else {
//         printf("Character '%c' not found.\n", target);
//     }

//     // Search for the null terminator
//     result = ft_strchr(str, '\0');
//     printf("Found null terminator at position: %ld\n", result - str);

//     return 0;
// }
