/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonuki <hyeonuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 16:25:02 by hyeonuki          #+#    #+#             */
/*   Updated: 2024/11/23 16:48:22 by hyeonuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*str;

	i = 0;
	str = (char *)s;
	while (i < n)
	{
		str[i] = 0;
		i++;
	}
}
// #include <stdio.h>
// #include <string.h> // for bzero
//
// int main() {
//     char str1[] = "Hello, World!";
//     char str2[] = "Hello, World!";
//
//     // Using ft_bzero
//     ft_bzero(str1, 5);
//     printf("After ft_bzero: %s\n", str1);  // Expected: ", World!"
//     // Using bzero
//     bzero(str2, 5);
//     printf("After bzero: %s\n", str2);  // Expected: ", World!"
//     return 0;
// }
