/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonuki <hyeonuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 19:15:05 by hyeonuki          #+#    #+#             */
/*   Updated: 2025/02/02 12:54:39 by hyeonuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int fd;
    ssize_t bytes_read;
    static char buffer[100];
    int i = 0;

    fd = open("text.txt", O_RDONLY);
    if (fd < 0)
    {
        perror("Error opening file");
        return (1);
    }

    // Read bytes from file until we hit the newline or EOF
    while ((bytes_read = read(fd, &buffer[i], 1)) > 0)
    {
        if (buffer[i] == '\n')  // If newline is encountered, stop
        {
            i++;
            break;
        }
        i++;
    }

    // Null-terminate the string
    buffer[i] = '\0';

    if (bytes_read < 0)
    {
        perror("Error reading file");
        close(fd);
        return (1);
    }

    printf("First line:\n%s", buffer);

    while ((bytes_read = read(fd, &buffer[i], 1)) > 0)
    {
        if (buffer[i] == '\n')  // If newline is encountered, stop
        {
            i++;
            break;
        }
        i++;
    }
    printf("second print\n");
    printf("%s", buffer);
    close(fd);

    return (0);
}

