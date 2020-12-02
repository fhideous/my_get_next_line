/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhideous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 17:25:55 by fhideous          #+#    #+#             */
/*   Updated: 2020/12/02 17:25:57 by fhideous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#define BUFFER_SIZE 4

int		find_transl(const char *str)
{
	int i;

	if (!str)
		return (-1);
	i = 0;
	while (*(str + i) != '\0')
	{
		if (*(str + i) == '\n')
			return (i);
		i++;
	}
	return (-1);
}

int		add_line(char **line, char **donor, int n)
{
	char	*tmp;
	char	*new_rmd;
	int		i;

	if (n < 0)
		return (0);
	if (!(tmp = calloc(n + 1, sizeof(char))))
		return (-1);
	i = -1;
	while (++i < n)
		tmp[i] = *((*donor) + i);
	//free(*line); /////////////////////////free or not to free?
	*line = tmp;
	if (!*donor)
		return (1);
	if (!(new_rmd = ft_substr(*donor, n + 1, ft_strlen(*donor) - n - 1)))
		return (-1);
	free(*donor);
	*donor = new_rmd;
	return (1);
}

int		read_buf(int fd, char **rmd)
{
	int		count;
	char	*buf_rd;
	char	*joined;

	if (!(buf_rd = calloc(BUFFER_SIZE + 1, sizeof(char))))
		return (-1);
	if ((count = read(fd, buf_rd, BUFFER_SIZE)) <= 0)
		free(buf_rd);
	if (count < 0)
		return (-1);
	else if (count == 0)
		return (0);
	if (!(joined = ft_strjoin(*rmd, buf_rd)))
		return (-1);
	free(buf_rd);
	free(*rmd);
	*rmd = joined;
	return (1);
}

int		get_next_line(int fd, char **line)
{
	static char	*remainder;
	int			is_tr;
	int			count;

	count = 1;
	while (count != 0)
	{
		if ((is_tr = add_line(&*line, &remainder, find_transl(remainder))) ==
		-1)
			return (-1);
		if (is_tr == 1)
			return (1);
		if ((count = read_buf(fd, &remainder)) == -1)
			return (-1);
	}
	if (!*line && (!remainder || !*remainder))
		return (0);
	if ((add_line(&*line, &remainder, ft_strlen(remainder))) == -1)
		return (-1);
	free(remainder);
	remainder = NULL;
	return (0);
}
