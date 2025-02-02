#include "get_next_line.h"

char	*get_next_line(int fd)
{
    char    *content;
    char    *line;
    static int  by_read_sum;

    by_read_sum = 0;



}

/*
function 1 -> fead all file and save the content to the content
*/
char    *read_file(int fd)
{
    char    *buff;
    char    *file;
	int		rd_bytes;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	rd_bytes = 1;
	while (!ft_strchr(file, '\n') && rd_bytes != 0)
	{
		rd_bytes = read(fd, buff, BUFFER_SIZE);
		if (rd_bytes == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[rd_bytes] = '\0';
		file = ft_strjoin(file, buff);
	}
	free(buff);
	return (file);

}


/*
function 2 -> read one line from fd, update bytes_read
*/

char    *read_one_line(char *file, int by_read_sum)
{
    char    *buff;
    int     by_read_buffer;
    int     by_read_line;

    buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
    by_read_buffer = 1;
    //while (!ft_strchr(file, '\n') && by_read_buffer != 0)   
    

}