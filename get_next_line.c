/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhideous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 20:45:41 by fhideous          #+#    #+#             */
/*   Updated: 2020/11/15 20:37:41 by fhideous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#define BUFFER_SIZE 10
size_t	ft_strlen(const char *s)
{
	size_t cnt;

	cnt = 0;
	while (*(s + cnt) != '\0')
		cnt++;
	return (cnt);
}

void			*ft_memcpy(void *dst, const void *src, size_t len)
{
	unsigned char		*ptr;
	const unsigned char	*src_ptr;

	if (dst == NULL && src == NULL)
		return (0);
	ptr = (unsigned char *)dst;
	src_ptr = (unsigned char *)src;
	while (len--)
		*ptr++ = *src_ptr++;
	return (dst);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*conc_str;
	size_t	s1_len;
	size_t	s2_len;

	if (s1 == NULL || s2 == NULL)
		return (s2);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	conc_str = (char *)malloc(s1_len + s2_len + 1);
	if (!conc_str)
		return (NULL);
	ft_memcpy(conc_str, s1, s1_len);
	ft_memcpy(conc_str + s1_len, s2, s2_len);
	*(conc_str + s1_len + s2_len) = '\0';
	free(s1);
	free(s2);
	return (conc_str);
}

char	*add_remainder(char *buf)
{
	int len;
	char *n_rem;
	int iter;

	len = 0;
	iter = 0;
	while (*buf && *buf != '\n')
		buf++;
	if (!*buf)
    {
	    n_rem = calloc((1), sizeof(char));
	    return (n_rem);
    }
	while (buf[len])
		len++;
	n_rem = calloc((len) , sizeof(char));
	if (!n_rem)
	    return(NULL);
	if (!n_rem)
		return (0);
	buf++;
	while (*buf)
	{
		n_rem[iter] = *buf;
		iter++;
		buf++;
	}
	return (n_rem);
}

char *set_line(char *str)
{
	char *line;
	int i;
	int len;

	i = 0;
	while (str[i] && str[i] != '\n')
	    i++;
	line = calloc(i + 1, sizeof(char));
	if(!line)
		return (0);
	i = -1;
	while (str[++i] && str[i] != '\n')
		line[i] = str[i];
	return(line);
}

int get_next_line(int fd, char **line)
{
	char *buf;
	static char *remainder;
	char *new_buf;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (0);
	buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return(-1);
	buf[BUFFER_SIZE] = '\0';
	if (!read(fd, buf, BUFFER_SIZE))
	{
		free(buf);
		free(remainder);
		return (0);
	}
	new_buf = ft_strjoin(remainder, buf);
//	free(buf);
//    free(remainder);
	if (!new_buf)
		return(-1);

	*line = set_line(new_buf);
	free(remainder);
	remainder = add_remainder(new_buf);
	if (!remainder)
		return (-1);
	free(new_buf);
    return (1);
}
