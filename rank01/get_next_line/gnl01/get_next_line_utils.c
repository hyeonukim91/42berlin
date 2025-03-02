/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonuki <hyeonuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 18:32:49 by hyeonuki          #+#    #+#             */
/*   Updated: 2025/03/02 16:14:45 by hyeonuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if  (!s)
		return (0);
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

// char	*ft_strjoin(char *s1, char *s2)
// {
// 	int		i;
// 	int		len1;
// 	int		len2;
// 	char	*str;

// 	if (s1 && s2)
// 	{
// 		len1 = ft_strlen(s1);
// 		len2 = ft_strlen(s2);
// 		str = (char *)malloc((sizeof(char)) * (len1 + len2 + 1));
// 		if (str == NULL)
// 			return (NULL);
// 		i = -1;
// 		while (s1[++i])
// 			str[i] = s1[i];
// 		i = -1;
// 		while (s2[++i])
// 		{
// 			str[len1] = s2[i];
// 			len1++;
// 		}
// 		str[len1] = '\0';
// 		return (str);
// 	}
// 	return (NULL);
// }

char    *ft_strjoin(char *s1, char *s2)
{
    size_t  len1;
    size_t  len2;
    char    *result;
    size_t  i;

    if (!s1 || !s2)
        return (NULL);
    len1 = ft_strlen(s1);
    len2 = ft_strlen(s2);
    result = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
    if (!result)
        return (NULL);
    i = 0;
    while (*s1)
        result[i++] = *s1++;
    while (*s2)
        result[i++] = *s2++;
    result[i] = '\0';
    return (result);
}
