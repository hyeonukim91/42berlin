#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*output;
    static char  *line;

	if (BUFFER_SIZE == 0)
		return (NULL);

	line = read_file(fd);
	output = return_line(line);
	return (output);
}

/*
function 1 -> read one line from the file and save the content to 'file'. -> can contain chars after new line character
*/
char    *read_line(int fd)
{
    char    *buff;
    char    *line;
	int		read_bytes;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
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
	function2: return a line till the new line char, and save the remaining part to 'line'
*/
char	*return_line(char *line)
{
	int		i;
	int		j;
	char	*output;
	char	*new_line;

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
	j = 0;
	while (line[i])
	{
		new_line[j] = line[i];
		i++;
		j++;
	}
	new_line[j + 1] = '\0';
	line = new_line;
	return (output);
}

char	*new_line(char *line)
{

}