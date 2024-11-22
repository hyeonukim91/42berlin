/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonuki <hyeonuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 19:23:40 by hyeonuki          #+#    #+#             */
/*   Updated: 2024/11/18 18:48:31 by hyeonuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t i;
	
	i = ft_strlen(s);
	if (c == '\0')
	{
		return ((char *)s + i);
	}
	while (i > 0)
	{
		i--;
		if (s[i] == c)
		{
			return ((char *)s + i);
		}
	}
	return (NULL);
}
// #include <stdio.h>

// int main()
// {
//     char *str = "Hello, world!";
//     char *result = ft_strrchr(str, 'o');

//     if (result != NULL) {
//         printf("Last occurrence of 'o': %s\n", result);  // Should print: "o, world!"
//     } else {
//         printf("'o' not found\n");
//     }

//     return 0;
// }
