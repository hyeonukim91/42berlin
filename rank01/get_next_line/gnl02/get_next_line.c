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
	char	*new_loc;

	new_loc = ft_strchr(buffer, '\n');
	buffer = new_loc + 1;
	return (buffer);
}

char	*read_line_from_file(int fd, char *buffer)
{
	char	*stash;
	int		bytes_read;

	bytes_read = 1;
	stash = ft_strdup("");
	while (bytes_read > 0 && !ft_strchr(stash, '\n'))
	{
		if (stash[0] == '\0')
			stash = ft_strdup(buffer);
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (NULL);
		buffer[bytes_read] = '\0';
		stash = ft_strjoin(stash, buffer);
	}
	buffer = update_buffer(buffer);
	stash = extract_line_from_stash(stash);
}

char	*get_next_line(int fd) //+ buffer size check
{
	static char	*buffer;
	char			*dest;

	if (!buffer)
		buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	read_line_from_file(fd, buffer);
	buffer = update_buffer(buffer);
	dest = extract_line_from_stash(dest);
	return(dest);
}

int	main(void)
{
	int	fd;
	int i;
	char	*dest;

	i = 0;
	fd = open("text.txt", O_RDONLY);
	if (fd < 0)
		return (1);
	while (i < 2)
	{
		dest = get_next_line(fd);
		printf("%s", dest);
		i++;
	}

	return (1);
}
