/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonuki <hyeonuki@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 19:15:05 by hyeonuki          #+#    #+#             */
/*   Updated: 2024/12/08 19:26:13 by hyeonuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	int	fd;
	ssize_t	bytes_read;
	char buffer[100];

	fd = open("text.txt", O_RDONLY);
	return (0);

	if (fd < 0)
	{
		perror("Error opening file");
		return (0);
	}

	bytes_read = read(fd, buffer, sizeof(buffer) -1);

	if (bytes_read < 0)
	{
		perror("Error reading file");
		close(fd);
		return (0);
	}

	buffer[bytes_read] = '\0';

	printf("file contents:\n%s", buffer);

	close(fd);

	return (0);
}
