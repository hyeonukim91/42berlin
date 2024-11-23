/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonuki <hyeonuki@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 18:54:50 by hyeonuki          #+#    #+#             */
/*   Updated: 2024/11/23 20:04:27 by hyeonuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*output;
	size_t	s1_len;
	size_t	s2_len;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	if (*s1 == '\0' && *s2 == '\0')
		return (NULL);
	output = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (output == NULL)
		return (NULL);
	ft_strlcpy(output, s1, s1_len);
	ft_strlcpy(output + s1_len, s2, s2_len);
	return (output);
}
