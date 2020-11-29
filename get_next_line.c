#include "get_next_line.h"
#define BUFFER_SIZE 6

int len_bef_carryout(const char *str)
{
	int len;

	len = 0;
	while ( *(str + len) && *(str + len) != '\n')
		len++;

	return (len);
}

int find_carryover(int fd, char **buf)
{
	int i;
	char *tmp;
	char *tmp_ptr;
	int count;

	if(!(tmp = calloc(BUFFER_SIZE + 1, sizeof(char))))
		return (-1);
	if ((count = read(fd, tmp, BUFFER_SIZE)) == 0)
		return (2);
	tmp_ptr = *buf;
	if(count == -1 || !(*buf = ft_strjoin(tmp_ptr, tmp)))
		return (-1);				//разобраться с ошибками и очисткой
//	free(tmp_ptr);
	i = -1;
	while (*(tmp + ++i))
		if (*(tmp + i) == '\n')
		{
			free(tmp);
			return (1);
		}
	free(tmp);
	return (0);
}

int		make_buf(int fd, char **full_buf, char *remainder)
{
	char *tmp_buf;
	int a;



//	tmp_buf = calloc(BUFFER_SIZE + 1, sizeof(char*));
//	if (!tmp_buf)
//		return (-1);
//	count_bytes = read(fd, tmp_buf, BUFFER_SIZE);
//	if (count_bytes == -1)
//		return (-1);
	tmp_buf = NULL;
	while ((a = find_carryover(fd, &tmp_buf)) == 0);
	if (a == -1)
	{
		free(tmp_buf);
		return (-1);
	}
	*full_buf = ft_strjoin(remainder, tmp_buf);
//	free(tmp_buf);
	static int flag;
	if (a == 2 && (!*full_buf || !**full_buf)) {
		flag = 0;
		return (0);
	}
	if (!flag && a == 2 && find_symb(*full_buf, '\n') == (int)ft_strlen(*full_buf) - 1)
	{
		tmp_buf = ft_strjoin(*full_buf, "\n");
		free(*full_buf);
		*full_buf = tmp_buf;
		flag = 1;
	}
	return (a);
}

int		get_next_line(int fd, char **line)
{
	static char *remainder;
	char *full_buf;
	char *sub_line;
	int len;
	int a;

	if ( (a = make_buf(fd, &full_buf, remainder)) == -1 )
		return (-1);
	if (a == 0) {
		*line = calloc (2 , sizeof(char));
		**line = '\n';
		return (0);
	}
	if (!*full_buf)
		return (0);
	len = len_bef_carryout(full_buf);
	if (!(sub_line = ft_substr(full_buf, 0, len)))
	{
		free(full_buf);
		return (-1);
	}
	int len_remainder = ft_strlen(full_buf) - len;
	*line = sub_line;
	if(!(remainder = ft_substr(full_buf, len + 1, len_remainder)))
	{
		free(full_buf);
		return (-1);
	}
	if (!*(remainder) && a == 2)
	{
		free(full_buf);
		return (0);
	}
	free(full_buf);
	return(1);
}