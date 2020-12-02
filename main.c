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

//	/Users/fhideous/Desktop/fhideous/gnl_v2/42TESTERS-GNL-master/files/4_newlines
//	/Users/fhideous/Desktop/fhideous/gnl_v2/a

	int main() {
		int fd;
		int i;
		int j;
		char *line = 0;
		//	char			*lineadress[66];

		j = 1;


		printf("\n==========================================\n");
		printf("========== TEST 1 : The Alphabet =========\n");
		printf("==========================================\n\n");

		if (!(fd = open("/Users/fhideous/Desktop/fhideous/gnl_v2/42TESTERS"
				  "-GNL-master/files/1_newline", O_RDONLY))) {
			printf("\nError in open\n");
			return (0);
		}
		while ((i = get_next_line(fd, &line)) > 0) {
			printf("|%s\n", line);
			//lineadress[j - 1] = line;
			j++;
		}
		printf("|%s\n", line);
		free(line);
		close(fd);

		if (i == -1)
			printf("\nError in Fonction - Returned -1\n");
		else if (j == 66)
			printf("\nRight number of lines\n");
		else if (j != 66)
			printf("\nNot Good - Wrong Number Of Lines: %d\n", j);
		//	while (--j > 0)
		//		free(lineadress[j - 1]);
		j = 1;
		printf("\n==========================================\n");
		printf("======== TEST 3 : The Empty File =========\n");
		printf("==========================================\n\n");

		if (!(fd = open("/Users/fhideous/Desktop/fhideous/gnl_v2/a", O_RDONLY)))
		{
			printf("\nError in open\n");
			return (0);
		}
		while ((i = get_next_line(fd, &line)) > 0)
		{
			printf("|%s\n", line);
			free(line);
			j++;
		}
		printf("|%s\n", line);
		free(line);
		close(fd);

		if (i == -1)
			printf ("\nError in Fonction - Returned -1\n");
		else if (j == 1)
			printf("\nRight number of lines\n");
		else if (j != 1)
			printf("\nNot Good - Wrong Number Of Lines\n");
		j = 1;
	//	sleep(10000);
		return (0);

	}
/*
		printf("\n==========================================\n");
		printf("========= TEST 2 : Empty Lines ===========\n");
		printf("==========================================\n\n");

		if (!(fd = open("/Users/fhideous/Desktop/fhideous/gnl_v2/42TESTERS-GNL-master/files/empty_lines", O_RDONLY)))
		{
			printf("\nError in open\n");
			return (0);
		}
		while ((i = get_next_line(fd, &line)) > 0)
		{
			printf("|%s\n", line);
			free(line);
			j++;
		}
		printf("|%s\n", line);
		free(line);
		close(fd);

		if (i == -1)
			printf ("\nError in Fonction - Returned -1\n");
		else if (j == 9)
			printf("\nRight number of lines\n");
		else if (j != 9)
			printf("\nNot Good - Wrong Number Of Lines\n");
		j = 1;
		printf("\n==========================================\n");
		printf("======== TEST 3 : The Empty File =========\n");
		printf("==========================================\n\n");

		if (!(fd = open("/Users/fhideous/Desktop/fhideous/gnl_v2/42TESTERS-GNL-master/files/empty_file", O_RDONLY)))
		{
			printf("\nError in open\n");
			return (0);
		}
		while ((i = get_next_line(fd, &line)) > 0)
		{
			printf("|%s\n", line);
			free(line);
			j++;
		}
		printf("|%s\n", line);
		free(line);
		close(fd);

		if (i == -1)
			printf ("\nError in Fonction - Returned -1\n");
		else if (j == 1)
			printf("\nRight number of lines\n");
		else if (j != 1)
			printf("\nNot Good - Wrong Number Of Lines\n");
		j = 1;

		printf("\n==========================================\n");
		printf("========= TEST 4 : One New Line ==========\n");
		printf("==========================================\n\n");

		if (!(fd = open("/Users/fhideous/Desktop/fhideous/gnl_v2/42TESTERS-GNL-master/files/1_newline", O_RDONLY)))
		{
			printf("\nError in open\n");
			return (0);
		}
		while ((i = get_next_line(fd, &line)) > 0)
		{
			printf("|%s\n", line);
			free(line);
			j++;
		}
		printf("|%s\n", line);
		free(line);
		close(fd);

		if (i == -1)
			printf ("\nError in Fonction - Returned -1\n");
		else if (j == 2)
			printf("\nRight number of lines\n");
		else if (j != 2)
			printf("\nNot Good - Wrong Number Of Lines\n: %d", j);
		j = 1;

		printf("\n==========================================\n");
		printf("========= TEST 5 : Four New Lines ========\n");
		printf("==========================================\n\n");

		if (!(fd = open("/Users/fhideous/Desktop/fhideous/gnl_v2/42TESTERS-GNL-master/files/4_newlines", O_RDONLY)))
		{
			printf("\nError in open\n");
			return (0);
		}
		while ((i = get_next_line(fd, &line)) > 0)
		{
			printf("|%s\n", line);
			free(line);
			j++;
		}
		printf("|%s\n", line);
		free(line);
		close(fd);

		if (i == -1)
			printf ("\nError in Fonction - Returned -1\n");
		else if (j == 5)
			printf("\nRight number of lines\n");
		else if (j != 5)
			printf("\nNot Good - Wrong Number Of Lines\n, %d", j);
		j = 1;

		printf("\n==========================================\n");
		printf("============== TEST 6 : 42 ===============\n");
		printf("==========================================\n\n");

		if (!(fd = open("/Users/fhideous/Desktop/fhideous/gnl_v2/42TESTERS-GNL-master/files/41_char", O_RDONLY)))
		{
			printf("\nError in open\n");
			return (0);
		}
		while ((i = get_next_line(fd, &line)) > 0)
		{
			printf("|%s\n", line);
			free(line);
			j++;
		}
		printf("|%s\n", line);
		free(line);
		close(fd);
		if (!(fd = open("/Users/fhideous/Desktop/fhideous/gnl_v2/42TESTERS-GNL-master/files/42_char", O_RDONLY)))
		{
			printf("\nError in open\n");
			return (0);
		}
		while ((i = get_next_line(fd, &line)) > 0)
		{

			printf("|%s\n", line);
			free(line);
			j++;
		}
		printf("|%s\n", line);
		free(line);
		close(fd);
		if (!(fd = open("/Users/fhideous/Desktop/fhideous/gnl_v2/42TESTERS-GNL-master/files/43_char", O_RDONLY)))
		{
			printf("\nError in open\n");
			return (0);
		}
		while ((i = get_next_line(fd, &line)) > 0)
		{
			printf("|%s\n", line);
			free(line);
			j++;
		}
		printf("|%s\n", line);
		free(line);
		close(fd);

		if (i == -1)
			printf ("\nError in Fonction - Returned -1\n");
		else if (j == 1)
			printf("\nRight number of lines\n");
		else if (j != 1)
			printf("\nNot Good - Wrong Number Of Lines\n");
		j = 1;
		printf("\n==========================================\n");
		printf("============= TEST 7 : Marge =============\n");
		printf("==========================================\n\n");

		int fd2;

		if (!(fd = open("/Users/fhideous/Desktop/fhideous/gnl_v2/42TESTERS-GNL-master/files/half_marge_top", O_RDONLY)))
		{
			printf("\nError in open\n");
			return (0);
		}
		if (!(fd2 = open("/Users/fhideous/Desktop/fhideous/gnl_v2/42TESTERS-GNL-master/files/half_marge_bottom", O_RDONLY)))
		{
			printf("\nError in open\n");
			return (0);
		}
		while ((i = get_next_line(fd, &line)) > 0)
		{
			printf("%s\n", line);
			free(line);
			j++;
		}
		free(line);
		while ((i = get_next_line(fd2, &line)) > 0)
		{
			printf("%s\n", line);
			free(line);
			j++;
		}
		printf("%s\n", line);
		free(line);
		close(fd);
		close(fd2);

		if (i == -1)
			printf ("\nError in Fonction - Returned -1\n");
		else if (j == 25)
			printf("\nRight number of lines\n");
		else if (j != 25)
			printf("\nNot Good - Wrong Number Of Lines\n");
		j = 1;
		printf("\n==========================================\n");
		printf("========= TEST 8 : Wrong Input ===========\n");
		printf("==========================================\n\n");

		if (get_next_line(180, &line) == -1)
			printf("Well Done, you return -1 if no FD\n\n");
		else
			printf("Not Good, you don't return -1 if no FD\n\n");

		return (0);
*/
//	}
