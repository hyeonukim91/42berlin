#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

typedef struct get_next_line_list
{
    int     fd;
    char        *buf;
    size_t  size;
} g_list;

char	*get_next_line(int fd);
char	*ft_strjoin(char const *s1, char const *s2);

#endif