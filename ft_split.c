/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonuki <hyeonuki@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 19:03:12 by hyeonuki          #+#    #+#             */
/*   Updated: 2024/11/30 18:15:24 by hyeonuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_word(char const *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (str[i] == c)
	{
		i++;
	}
	while (str[i] != '\0')
	{
		if (str[i] != c && (str[i + 1] == c || str[i + 1] == '\0'))
		{
			count++;
		}
		i++;
	}
	return (count);
}

int	word_len(char const *str, char c)
{
	int	i;

	i = 0;
	while (str[i] != c && str[i] != '\0')
	{
		i++;
	}
	return (i);
}

void	*free_mem(char **output, int i)
{
	while (i >= 0)
	{
		free(output[i]);
		i--;
	}
	free(output);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**output;
	char	*temp;
	int		i;

	output = (char **)malloc((count_word(s, c) + 1) * sizeof(char *));
	if (output == NULL || s == NULL)
		return (NULL);
	temp = (char *)s;
	i = 0;
	while (*temp != '\0' && i < count_word(s, c))
	{
		if (*temp != c)
		{
			output[i] = (char *)malloc(sizeof(char) * (word_len(temp, c) + 1));
			if (output[i] == NULL)
				return (free_mem(output, i));
			ft_strlcpy(output[i], temp, word_len(temp, c) + 1);
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
	int	i;
	char	**test;

	i = 0;
	char	*str = "hello!";
	char	c = ' ';
	test = ft_split(str, c);
	printf("%d\n", count_word(str, c));
	printf("%d\n", word_len(str, c));
	while (test[i] != NULL)
	{
		printf("%d\n", word_len(test[i],c));
		printf("%s\n", test[i]);
		i++;
	}
	return (42);
}
*/
