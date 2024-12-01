/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonuki <hyeonuki@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 18:56:36 by hyeonuki          #+#    #+#             */
/*   Updated: 2024/11/24 16:12:21 by hyeonuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*output;
	size_t	s_len;
	size_t	i;

	i = 0;
	s_len = ft_strlen(s);
	output = (char *)malloc((sizeof(char)) * (s_len + 1));
	if (output == NULL)
		return (NULL);
	while (i < s_len)
	{
		output[i] = (*f)((unsigned int)i, (char)s[i]);
		i++;
	}
	output[i] = '\0';
	return (output);
}
