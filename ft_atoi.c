/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonuki <hyeonuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 16:24:55 by hyeonuki          #+#    #+#             */
/*   Updated: 2024/11/18 15:52:49 by hyeonuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_atoi(const char *nptr)
{
	int	output;
	int	sign;

	sign = 1;
	output = 0;
	while (*nptr == ' ' || *nptr == '\f' || *nptr == '\n' \
			|| *nptr == '\r' || *nptr == '\t' || *nptr == '\v')
	{
		nptr++;
	}
	if (*nptr == '-')
	{
		sign = sign * -1;
		nptr++;
	}
	else if (*nptr == '+')
	{
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9' )
	{
		output = output * 10 + (*nptr - '0');
		nptr++;
	}
	return (output * sign);
}

/*
#include <stdio.h>

int ft_atoi(const char *nptr);

int main()
{
    printf("%d\n", ft_atoi("   -123")); // Expected output: -123
    printf("%d\n", ft_atoi("42"));      // Expected output: 42
    printf("%d\n", ft_atoi("+7"));      // Expected output: 7
    printf("%d\n", ft_atoi("   0"));    // Expected output: 0
    printf("%d\n", ft_atoi("999abc"));  // Expected output: 999
    printf("%d\n", ft_atoi("abc123"));  // Expected output: 0
    return 0;
}
*/
