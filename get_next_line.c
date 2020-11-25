#include "get_next_line.h"
#define BUFFER_SIZE 2

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

	if(!(tmp = calloc(BUFFER_SIZE + 1, sizeof(char))))
		return (-1);
	if ((read(fd, tmp, BUFFER_SIZE)) == 0)
		return (2);
	tmp_ptr = *buf;
	if(!(*buf = ft_strjoin(tmp_ptr, tmp)))
		return (-1);				//разобраться с ошибками и очисткой
	free(tmp_ptr);
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

int		find_symb(const char *str, char c)
{
	int i;

	i = 0;
	while (*(str + i) && *(str + i) != c)
		i++;
	if (!*(str + i))
		return (-2);
	return (i);
}

int		get_next_line(int fd, char **line)
{
	static char *remainder;
	int count_bytes;
	char *tmp_buf;
	char *full_buf;
	char *sub_line;
	int len;
	int a;

	tmp_buf = calloc(BUFFER_SIZE + 1, sizeof(char*));
	if (!tmp_buf)
		return (-1);
	count_bytes = read(fd, tmp_buf, BUFFER_SIZE);
	if (count_bytes == -1)
		return (-1);
	while ((a = find_carryover(fd, &tmp_buf)) == 0);
	if (a == -1)
	{
		free(tmp_buf);
		return (-1);
	}
	full_buf = ft_strjoin(remainder, tmp_buf);
	free(tmp_buf);
	static int flag;
	if (!flag && a == 2 && find_symb(full_buf, '\n') == (int)ft_strlen(full_buf) - 1)
	{
		tmp_buf = ft_strjoin(full_buf, "\n");
		free(full_buf);
		full_buf = tmp_buf;
		flag = 1;
	}
	if (!full_buf || !*full_buf)
	{
		if (!*full_buf)
			return (0);
		return (-1);
	}
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
	if (!*(remainder) && (count_bytes < BUFFER_SIZE || a == 2)) // <= ? <
	{
		free(full_buf);
		return (0);
	}
	free(full_buf);
	return(1);
}