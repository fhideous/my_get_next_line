#include "get_next_line.h"
#define BUFFER_SIZE 42

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
	int flag;

	flag = 0;
	if(!(tmp = calloc(BUFFER_SIZE + 1, sizeof(char))))
		return (-1);
	if ((flag = read(fd, tmp, BUFFER_SIZE)) == 0)
		return (1);
	tmp_ptr = *buf;
	if(!(*buf = ft_strjoin(tmp_ptr, tmp)))// || flag == 1)
		return (-1);				//разобраться с ошибками и очисткой
	free(tmp_ptr);
	//buf = &tmp_ptr;
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

int		get_next_line(int fd, char **line)
{
	static char *remainder;
	int count_bytes;
//	static int del;
	char *tmp_buf;
	char *full_buf;
//	char *new_line;
	char *sub_line;
//	char *over_remainder;
//	char buf_len_symb;
	int len;
	int a;
//	int is_last;

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
//	if (remainder && *remainder == '\n')
//		full_buf = ft_strjoin(++remainder, tmp_buf);
//	else
	full_buf = ft_strjoin(remainder, tmp_buf);
	free(tmp_buf);
//	if (remainder)
//		free(remainder);	как чистить?
	if (!full_buf || !*full_buf)
	{
		if (!*full_buf) {
			return (0);
		}
			return (-1);
	}
	len = len_bef_carryout(full_buf);
//	buf_len_symb = *(full_buf + len);
	if (!(sub_line = ft_substr(full_buf, 0, len)))
	{
		free(full_buf);
		return (-1);
	}
//	if (!(new_line = ft_strjoin(*line, sub_line)))
//	{
//		free(full_buf);
//		free(sub_line);
//		return (-1);
//	}
//	free(sub_line);

//	if (**line)
//		free(*line); чистится за пределами?

//	*line = new_line;

	*line = sub_line;
//	if (full_buf[ft_strlen(full_buf) - 1] =='\n')
//		full_buf = ft_strjoin(full_buf, "\n");
	if(!(remainder = ft_substr(full_buf, len + 1, ft_strlen(full_buf) - len)))
	{
		free(full_buf);
		return (-1);
	}

	free(full_buf);
//	if (buf_len_symb != '\n')
//	len = -1;
	if (!*(remainder))
		return (0);
	return(1);
//	if (!(over_remainder = ft_strjoin("\n", remainder)))
//		return (-1);
//	free(remainder);
//	remainder = over_remainder;
//	return (1);
}