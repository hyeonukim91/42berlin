/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonuki <hyeonuki@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 17:00:26 by hyeonuki          #+#    #+#             */
/*   Updated: 2024/11/23 17:02:29 by hyeonuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* overflow in multiplication ? */

#include "libft.h"

void	*calloc(size_t nmemb, size_t size)
{
	size_t	i;
	size_t	len;
	char	*output;

	i = 0;
	len = nmemb * size;
	output = malloc(len);
	if (output == NULL)
		return (NULL);
	while (i < len)
	{
		output[i] = 0;
		i++;
	}
	return (output);
}
/*
#include <stdio.h>
#include <stdlib.h>

int main() {
    size_t nmemb = 5;
    size_t size = sizeof(int);

    int *arr = (int *)calloc(nmemb, size);
    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Print the array (should be all zeros)
    for (size_t i = 0; i < nmemb; i++) {
        printf("%d ", arr[i]); // Output: 0 0 0 0 0
    }
    printf("\n");

    // Free allocated memory
    free(arr);
    return 0;
}
*/
