/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonuki <hyeonuki@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 18:54:50 by hyeonuki          #+#    #+#             */
/*   Updated: 2024/11/24 16:09:28 by hyeonuki         ###   ########.fr       */
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
	output = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (output == NULL)
	{
		return (NULL);
	}
	ft_strlcpy(output, s1, s1_len + 1);
	ft_strlcat(output, s2, s1_len + s2_len + 1);
	output[s1_len + s2_len] = '\0';
	return (output);
}
/*
#include <stdio.h>

int main() {
    // Test Case 1: Joining two non-empty strings
    char *result1 = ft_strjoin("Hello", "World");
    printf("Test 1: %s\n", result1);  // Expected: "HelloWorld"
    free(result1);

    // Test Case 2: Joining an empty string with a non-empty string
    char *result2 = ft_strjoin("", "World");
    printf("Test 2: %s\n", result2);  // Expected: "World"
    free(result2);

    // Test Case 3: Joining two empty strings
    char *result3 = ft_strjoin("", "");
    printf("Test 3: %s\n", result3);  // Expected: ""
    free(result3);

    return 0;
}
*/
