#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

// int	main(void)
// {
// 	int fd = open("text.txt", O_RDONLY);
// 	char buffer[10];
// 	size_t i;
// 	int	j;
// 	char *s1;

// 	j = 0;

// 	while (j < 2)
// 	{
// 		i = read(fd, buffer, sizeof(buffer) + 1);
// 		printf("%s", buffer);
// 		s1 = ft_strjoin(s1, buffer);
// 		j++;
// 	}
// 	close(fd);
// }


// int	main(void)
// {
// 	int fd = open("text.txt", O_RDONLY);
// 	printf("%s", get_next_line(fd));
// }

char	*get_next_line(int fd)
{
	static char	*stash;
	char		buffer;
	int			bytes_read;

	//check: BUFFER_SIZE
	if (BUFFER_SIZE <= 0)
		return (NULL);

	bytes_read = 1;
	//[1]save: to *stash 
		//1.save: to buffer
			//loop 
			//int bytes_read = read(fd, buffer, BUFFER_SIZE)
			//if bytes_read < 0
			//if bytes_read == 0
			//[1]copy: whole buffer to stash (bytes_read)
			// break when '\n' shows up. || eof
	while (bytes_read >= 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
	}
}

	//[2]extract from stash: till \n, eof
char	*extract_line(char *stash)
{
	int	i;
	char	*dest;

	i = 0;
	dest = NULL;
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
	dest[i] = '\0';
	return (dest);
}

	//[3]update stash from dest: from \n till end of string 

	char	*update_stash(char *stash)
	{
		int	i;
		int	j;
		int	len;
		char	*dest;

		i = 0;
		j = 0;
		len = ft_strlen(stash);
		while (stash[i] != '\n' && stash[i])
			i++;
		dest = malloc(sizeof(char) * (len - i + 2));
		if (!dest)
			return (NULL);
		while (stash[i])
		{
			dest[j] = stash[i];
			i++;
			j++;
		}
		stash = dest;
		free(dest);
	}

	//return: one line (if: encounters 'eof', '\n')


}


/*

gnl
	int bytes_read =1
	static char *stash;
	char *dest;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char))
	while (1)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE)
		if (bytes_read < 0)
			printf("ERROR")
			break ;
		buffer[bytes_read] = 0; //where: null-terminating?
		if (bytes_read == 0 || ft_strchr(dest, '\n'))
			dest = extract_line(buffer);
			break ;
		stash = update_rest(buffer);
	}
	return (dest)
*/


int main(int ac, char **av)
{
	int	fd;
	char *str;

	fd = open("text.txt", O_RDONLY);
	if (fd < 0)
		return (1);
	while (1)
	{
		str = get_next_line(fd);
		if (!str)
			break ;
		printf("%s", str);
		free(str);
	}
	close(fd);
}
