#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"

int main(int argc, char **argv)
{
	int fd;
	char *str;

	printf("*** start main ***\n");
	fd = open(argv[1], O_RDONLY);

	str = get_next_line(fd);
	printf("%s\n", str);
	printf("*****************************************\n");
/*
	do
	{
		str = get_next_line(fd);
		printf("%s\n", str);
		printf("*****************************************\n");
	} while (*str);
*/


	close(fd);
	//fix it!
	//	free(str);
	return (0);
}