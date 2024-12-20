/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonuki <hyeonuki@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 18:56:15 by hyeonuki          #+#    #+#             */
/*   Updated: 2024/11/24 19:47:41 by hyeonuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_intlen(int n)
{
	unsigned int	c;
	unsigned int	nbr;

	c = 1;
	if (n < 0)
	{
		nbr = -n;
		c++;
	}
	else
	{
		nbr = n;
	}
	while ((nbr / 10) != 0)
	{
		nbr = nbr / 10;
		c++;
	}
	return (c);
}

char	*ft_itoa(int n)
{
	unsigned int	len;
	unsigned int	nbr;
	char			*output;

	len = ft_intlen(n);
	output = (char *)malloc(sizeof(char) * (len + 1));
	if (output == NULL)
		return (NULL);
	if (n < 0)
	{
		nbr = -n;
		output[0] = '-';
	}
	else
		nbr = n;
	output[len] = '\0';
	if (nbr == 0)
		output[len - 1] = '0';
	while (nbr != 0)
	{
		output[len - 1] = (nbr % 10) + '0';
		nbr = nbr / 10;
		len--;
	}
	return (output);
}
/*
#include <stdio.h>

int	main()
{
	int	a = 0;
	printf("%d\n",ft_intlen(a));
	printf("%s\n",ft_itoa(a));

        int     b = 217483647;
        printf("%d\n",ft_intlen(b));
        printf("%s\n",ft_itoa(b));

	int	c = -217483648;
        printf("%d\n",ft_intlen(c));
        printf("%s\n",ft_itoa(c));

	return (0);
}
*/
