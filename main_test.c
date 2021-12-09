#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"

int main(int argc, char **argv)
{
	int fd;
	char *str;

	fd = open(argv[1], O_RDONLY);

	str = get_next_line(fd);

	printf("\n%s\n", str);
/*
	char c;
 	while (read(fd, &c, 1) && c != '\n')
		write(1, &c, 1);
*/
	close(fd);
	free(str);
	return (0);
}