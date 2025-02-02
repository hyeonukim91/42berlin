/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonuki <hyeonuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 18:32:39 by hyeonuki          #+#    #+#             */
/*   Updated: 2025/02/02 14:53:46 by hyeonuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_lines(int fd, char	*out)
{
	char	*buffer;
	int		size_read;


	// buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	// if (buffer == NULL)
	// {
	// 	free(buffer);
	// 	return (NULL);
	// }
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
	{
		return (NULL);
	}
	
	while (ft_strchr(*out, '\n') != NULL || ft_strchr(*out, '\0'))
	{
		size_read = read(fd, buffer, BUFFER_SIZE);
		if (size_read = -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[size_read] = '\0';
		out = ft_strjoin(out, buffer);
	}

	return (out);
}

char	*get_next_line(int fd)
{
	char		*buffer;	
	static char	*out;

	if (fd <= 0 || BUFFER_SIZE <= 0)
	{
		return (NULL);
	}
	out = read_line(fd, out);
	
}
