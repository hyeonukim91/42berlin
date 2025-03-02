/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonuki <hyeonuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 18:32:39 by hyeonuki          #+#    #+#             */
/*   Updated: 2025/03/02 17:10:38 by hyeonuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*

static variable -> save only the buffer (the most recently read part)

1. read buffer, add them to a line

2. when there is an end of file or a new line charactor, the reading process stops

3. extract a line from the temp line for the return value

4. update the buffer to remove 


*/

char	*extract_line_from_stash(char *stash)
{
	int	i;

	i = 0;
	while (stash[i] != '\n')
		i++;
	stash[i + 1] = '\0';
	return (stash);
}

char	*update_buffer(char *buffer)
{
	int	i;

	i = 0;
	
	
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char			*stash;
	int				bytes_read;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0 && !ft_strchr(stash, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == 0)
			break;
		if (bytes_read < 0)
			return (NULL);
		stash = ft_strjoin(stash, buffer);
	}
	buffer = update_buffer(buffer);
	return(extract_line_from_stash(stash));
}

int	main(int argc, char *argv[])
{
	int	fd;

	fd = open("text.txt", O_RDONLY);
	if (fd < 0)
		return (NULL);
	
}
