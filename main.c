#include "get_next_line.h"
#include "stdio.h"
#include "fcntl.h"

	int main()
	{
		int fd;
		int i;
		int j;
		char *line = 0;

		j = 1;
		if (!(fd = open("../gnl_fh/a", O_RDONLY))) {
			printf("\nError in open\n");
			return (0);
		}
		while ((i = get_next_line(124, &line)) > 0) {
			printf("%s\n", line);
			free(line);
			j++;
		}
		printf("%s", line);
		free(line);
		close(fd);
		return (0);
	}