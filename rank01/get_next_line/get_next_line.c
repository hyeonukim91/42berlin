/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonuki <hyeonuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 18:32:39 by hyeonuki          #+#    #+#             */
/*   Updated: 2025/02/23 12:46:57 by hyeonuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*output;
	static char	*line;

	if (BUFFER_SIZE == 0)
		return (NULL);
	line = read_line(fd);
	output = return_line(line);
	return (output);
}

/*
function 1 -> read one line from the file and save the content to 'file' 
-> can contain chars after the new line character
*/
char	*read_line(int fd)
{
	static char	*line;
	char		*buff;
	int			read_bytes;

	buff = malloc((BUFFER_SIZE + 1) * (sizeof(char)));
	if (!buff)
		return (NULL);
	read_bytes = 1;
	while (ft_strchr(line, '\n') == NULL && read_bytes != 0)
	{
		read_bytes = read(fd, buff, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[read_bytes + 1] = '\0';
		line = ft_strjoin(line, buff);
	}
	free(buff);
	return (line);
}

/*
	function2: return a line till the new line char, 
	and save the remaining part to 'line'
*/
char	*return_line(char *line)
{
	int		i;
	char	*output;

	output = malloc(ft_strlen(line + 1) * sizeof(char));
	if (!output)
	{
		free(output);
		return (NULL);
	}
	i = 0;
	while (line[i] && line[i] != '\n')
	{
		output[i] = line[i];
		i++;
	}
	output[i] = '\0';
	line = rest_to_line(line, i);
	return (output);
}

/*
	input: line, index of '\n'+1
	output: 
*/
char	*rest_to_line(char *s1, int i)
{
	char	*output;
	int		j;

	output = malloc(ft_strlen(s1 + 1) * sizeof(char));
	if (!output)
	{
		free(output);
		return (NULL);
	}
	j = 0;
	while (s1[i])
	{
		output[j] = s1[i];
		i++;
		j++;
	}
	output[j] = '\0';
	return (output);
}
