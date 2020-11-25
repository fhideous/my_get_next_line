#include "get_next_line.h"
#include "stdio.h"
#include "fcntl.h"

/*
int		main()
{

	int fd = open("/Users/fhideous/Desktop/fhideous/gnl_v2/a", O_RDONLY);
	char *line;
	int i;
int j = 0;
	while((i = get_next_line(fd, &line)))
	{
		printf("%d: i = %d %s\n", j, i, line);
		free(line);
		j++;
		if (j == 15)
		{j++;}
	}
	printf("%d: i = %d %s",j , i, line);
	close(fd);


*/
	int main()
	{
		int             fd;
		int             i;
		int             j;
		char    		*line = 0;
		char			*lineadress[66];

		j = 1;

		printf("\n==========================================\n");
		printf("========== TEST 1 : The Alphabet =========\n");
		printf("==========================================\n\n");
	//	/Users/fhideous/Desktop/fhideous/gnl_v2/42TESTERS-GNL-master/files/4_newlines
		if (!( fd = open("/Users/fhideous/Desktop/fhideous/gnl_v2/a", O_RDONLY)))
		{
			printf("\nError in open\n");
			return (0);
		}
		while ((i = get_next_line(fd, &line)) > 0)
		{
		//	if (j == 65)
		//		j++;
			printf("|%s\n", line);
			lineadress[j - 1] = line;
			j++;
		}
		printf("|%s\n", line);
		free(line);
		close(fd);

		if (i == -1)
			printf ("\nError in Fonction - Returned -1\n");
		else if (j == 66)
			printf("\nRight number of lines\n");
		else if (j != 66)
			printf("\nNot Good - Wrong Number Of Lines: %d\n", j);
		while (--j > 0)
			free(lineadress[j - 1]);
		j = 1;
	return (0);
}