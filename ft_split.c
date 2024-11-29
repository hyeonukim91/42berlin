/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonuki <hyeonuki@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 19:03:12 by hyeonuki          #+#    #+#             */
/*   Updated: 2024/11/23 19:03:32 by hyeonuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_word(char *str, char c)
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
		if(str[i - 1] == c && str[i] != c && str[i] != '\0')
		{
			count++;
		}
		i++;
	}
	return (count);
}

char	**ft_split(char const *s, char c);

#include <stdio.h>
int	main(void)
{	
	printf("%d\n", count_word(",aaaaa,aaaa,,,,aa,,",','));
	printf("%d\n", count_word("aaaaa,aaaa,,,,aa,,aaaaa",','));
	return (42);
}

