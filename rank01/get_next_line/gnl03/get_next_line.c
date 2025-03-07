#include "get_next_line.h"

char    *get_next_line(int fd)
{
    char static *stash;
    char        *dest;

    //buffer size check;
    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    //read file and save to stash
    stash = file_to_stash(fd, stash);
    if (stash == NULL)
        return (NULL);
    //extract line from the stash -> dest
    dest = extract_line_from_stash(stash);
    stash = update_stash(stash);
    return(dest);
}

char    *file_to_stash(int fd, char *stash)
{
    char    *buffer;
    int     bytes_read;

    buffer = malloc((sizeof(char)) * (BUFFER_SIZE + 1));
    if (buffer == NULL)
        return (NULL);
    bytes_read = 1;
    while (bytes_read > 0 && ft_strchr(stash, '\n') == NULL)
    {
        bytes_read = read(fd, buffer, BUFFER_SIZE);
        if (bytes_read < 0)
        {
            free (buffer);
            buffer = NULL;
            return (NULL);
        }
        buffer[bytes_read] = '\0';
        stash = ft_strjoin(stash, buffer);
    }
    free (buffer);
    return(stash);
}

char    *add_buffer_to_stash(char *stash, char *buffer)
{
    char    *dest;
    int     i;
    int     j;

    i = 0;
    j = 0;
    if (stash == NULL)
    {
        stash = malloc(sizeof(char) * 1);
        if (stash == NULL)
            return(NULL);
        stash[0] = '\0';
    }
    if (buffer == NULL)
        return (NULL);
    dest = malloc(sizeof(char) * (ft_strlen(stash) + ft_strlen(buffer) + 1));
    if (dest == NULL)
        return (NULL);
    while (stash && stash[i] != '\0')
    {
        dest[i] = stash[i];
        i++;
    }
    while (buffer && buffer[i] != '\0')
    {
        dest[i] = buffer[i];
        i++;
        j++;
    }
    dest[i] = '\0';
    free (stash);
    return (dest);
}

char    *extract_line_from_stash(char *stash)
{
    int i;
    char    *dest;

    i = 0;
    if (stash[0] == '\0')
        return (NULL);
    while (stash[i] != '\n' && stash != NULL)
        i++;
    dest = malloc(sizeof(char) * (i + 2));
    if (dest == NULL)
        return (NULL);
    i = 0;
    while (stash[i] != '\n' && stash[i] != '\0')
    {
        dest[i] = stash[i];
        i++;
    }
    if (stash[i] == '\n')
    {
        dest[i] = stash[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}

char    *update_stash(char *stash)
{
    char    *dest;
    int     i;
    int     j;

    i = 0;
    j = 0;
    while (stash[i] != '\n' && stash[i] != '\0')
        i++;
    if (stash[i] == '\0')
    {
        free (stash);
        return (NULL);
    }
    dest = malloc(sizeof(char) * (ft_strlen(stash) - i + 1));
    if (dest == NULL)
        return (NULL);
    i++;
    while (stash != NULL && stash[i] != '\0')
    {
        dest[j] = stash[i];
        i++;
        j++;
    }
    dest[j] = '\0';
    free(stash);
    return (dest);
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
    while (i < 5)
    {
	    dest = get_next_line(fd);
	    printf("%s", dest);
        i++;
    }
        free (dest);

	return (0);
}
