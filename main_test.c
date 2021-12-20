#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"

int main(int argc, char **argv)
{
	int fd;
	char *str;
	int i = 1;

	if (argc)
		printf("*** start main ***\n");
	fd = open(argv[1], O_RDONLY);

	do
	{
		str = get_next_line(fd);
		printf("******************* %d **********************\n", i);
		printf("%s\n", str);
		printf("********************************************\n");
		i++;
	} while (str && i < 12);


	close(fd);
	free(str);
	return (0);
}
