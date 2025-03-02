/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonuki <hyeonuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 18:32:44 by hyeonuki          #+#    #+#             */
/*   Updated: 2025/03/02 16:14:14 by hyeonuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

// typedef struct get_next_line_list
// {
//     int     fd;
//     char        *buf;
//     size_t  size;
// } g_list;

char	*get_next_line(int fd);
char	*extract_line(char *stash);
char	*update_stash(char *stash);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);
char    *ft_strjoin(char *s1, char *s2);

#endif
