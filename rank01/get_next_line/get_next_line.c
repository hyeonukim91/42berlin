/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonuki <hyeonuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 18:32:39 by hyeonuki          #+#    #+#             */
/*   Updated: 2024/12/22 19:51:48 by hyeonuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_line(int fd, char	*start)
{
	char	*buffer;
	char	*out;
	int		size_read;

	buffer = malloc(BUFFER_SIZE + 1 * sizeof(char));
	if (buffer == NULL)
	{
		free(buffer);
		return (NULL);
	}
	while (ft_strchr(buffer, '\n') != NULL)
	{
		read(fd, buffer, BUFFER_SIZE);
		ft_strjoin(out, buffer);
	}
	

	return (out);
}





char	*get_next_line(int fd)
{
	static char	*buffer;	
	char	*out;

	if (fd <= 0)
		return (-1);
	
}
