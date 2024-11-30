/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonuki <hyeonuki@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 19:03:12 by hyeonuki          #+#    #+#             */
/*   Updated: 2024/11/30 13:59:16 by hyeonuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_word(char const *str, char c)
{
	int	i;
	int	count;

	i = 1;
	count = 0;
	if (str[i - 1] != c)
	{
		count++;
	}
	while (str[i] != '\0')
	{
		if (str[i - 1] == c && str[i] != c && str[i] != '\0')
		{
			count++;
		}
		i++;
	}
	return (count);
}

int	word_len(char const *str, char c)
{
	int	output;

	output = 0;
	while (*str != c)
	{
		str++;
		output++;
	}
	return (output);
}

char	**ft_split(char const *s, char c)
{
	char	**output;
	char	*temp;
	int		i;

	output = (char **)ft_calloc((count_word(s, c) + 1), sizeof(char *));
	if (output == NULL || *s == '\0')
		return (NULL);
	i = 0;
	temp = (char *)s;
	while (*temp != '\0' && i < count_word(s, c))
	{
		if (*temp != c)
		{
			output[i] = (char *)malloc(sizeof(char) * word_len(temp, c));
			if (output[i] == NULL)
				return (NULL);
			output[i] = ft_substr(temp, 0, word_len(temp, c));
			temp = temp + word_len(temp, c);
			i++;
		}
		temp++;
	}
	output[i] = NULL;
	return (output);
}
/*
#include <stdio.h>
int	main(void)
{
	char **test;
	printf("%d\n", count_word(",aaaaa,aaaa,,,,aa,,",','));
	printf("%d\n", count_word("aaaaa,aaaa,,,,aa,,aaaaa",','));
	printf("%d\n", word_len("aaaa,",','));

	test = ft_split("aaaaa,,,aaa,aaaammm",",");
	return (42);
}
*/
