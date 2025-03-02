/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonuki <hyeonuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 14:48:02 by hyeonuki          #+#    #+#             */
/*   Updated: 2025/03/02 16:23:40 by hyeonuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

char	*join_buffer_to_stash(char *stash, char *buffer)
{
	int	i;
	int	j;
	char	*dest;

	dest = malloc(sizeof(char) * (ft_strlen(stash)  + ft_strlen(buffer) + 1));
	if (dest == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (stash && stash[i] != '\0')
	{
		dest[i] = stash[i];
		i++;
	}
	while (buffer && buffer[j] != '\0')
	{
		dest[i] = buffer[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	free (stash);
	return (dest);
}

char	*extract_line(char *stash)
{
	int		i;
	char	*dest;

	i = 0;
	while (stash[i] != '\n' && stash[i])
		i++;
	dest = malloc(sizeof(char) * (i + 2));
	if (!dest)
		return (NULL);
	i = 0;
	while (stash[i] != '\n' && stash[i])
	{
		dest[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
	{
		dest[i] = '\n';
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*update_stash(char *stash)
{
	int		i;
	int		j;
	int		len;
	char	*dest;

	i = 0;
	j = 0;
	len = ft_strlen(stash);
	while (stash[i] != '\n' && stash[i])
		i++;
	dest = malloc(sizeof(char) * (len - i + 1));
	if (!dest)
		return (NULL);
	i++;
	while (stash[i] != '\0')
	{
		dest[j] = stash[i];
		i++;
		j++;
	}
	dest[j] = '\0';
	return (dest);
}

char	*get_next_line(int fd)
{
	static char	*stash = "";
	char		*buffer;
	char		*dest;
	int			bytes_read;

	if (BUFFER_SIZE < 0)
		return (NULL);
	buffer = malloc((sizeof(char)) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (bytes_read >= 0 && ft_strchr(stash, '\n') == NULL)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == 0)
			break;
		if (bytes_read < 0)
		{
			free (buffer);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		stash = join_buffer_to_stash(stash, buffer);
	}
	free(buffer);
	dest = extract_line(stash);
	stash = update_stash(stash);
	return (dest);
}

int	main(void)
{
	int	fd;
	char	*line;
	
	fd = open("text.txt", O_RDONLY);
	if (fd < 0)
		return (1);
	line = get_next_line(fd);
	printf("%s", line);

	close(fd);
	return (0);
}