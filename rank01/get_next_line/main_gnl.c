#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main()
{
	int fd = open("text.txt", O_RDONLY);
	char *s1;
    s1 = get_next_line(fd);
	// while (s1 = get_next_line(fd))
	// {
	// 	printf("%s\n", s1);
	// 	free(s1);
	// }
	printf("%s\n", s1);
	close(fd);
}