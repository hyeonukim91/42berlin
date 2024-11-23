/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonuki <hyeonuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 19:07:48 by hyeonuki          #+#    #+#             */
/*   Updated: 2024/11/23 16:46:27 by hyeonuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s1)[i] != ((unsigned char *)s2)[i])
		{
			return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
		}
		i++;
	}
	return (0);
}
// #include <stdio.h>
// #include <string.h>  // For standard memcmp
// void test_memcmp(const void *s1, const void *s2, size_t n)
// {
//     int result1 = memcmp(s1, s2, n);
//     int result2 = ft_memcmp(s1, s2, n);
//     printf("Comparing %zu bytes: \n", n);
//     printf("memcmp returned: %d\n", result1);
//     printf("ft_memcmp returned: %d\n", result2);
//     printf("\n");
// }
// int main()
// {
//     // Test 1: Identical strings
//     char str1[] = "Hello";
//     char str2[] = "Hello";
//     test_memcmp(str1, str2, 5);  // Same strings, should return 0
//     // Test 2: Different strings
//     char str3[] = "Hello";
//     char str4[] = "World";
//     test_memcmp(str3, str4, 5);  // Different strings, should return non-zero
//     // Test 3: Compare first few bytes
//     char str5[] = "Hello";
//     char str6[] = "Hello, World!";
//     test_memcmp(str5, str6, 5);  // First 5 char the same, should return 0
//     // Test 4: Compare empty string
//     char str7[] = "";
//     char str8[] = "Hello";
//     test_memcmp(str7, str8, 0);  // Zero bytes, should return 0
//     return 0;
// }
