#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>

char	*ft_strchr(const char *str, int c);
char	*ft_strdup(char *src);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char *s1, char *s2);
char    *file_to_stash(int fd, char *stash);
char    *add_buffer_to_stash(char *stash, char *buffer);
char    *extract_line_from_stash(char *stash);
char    *update_stash(char *stash);
char	*get_next_line(int fd);

#endif