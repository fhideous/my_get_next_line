//
// Created by Formy Hideous on 11/25/20.
//

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <unistd.h>
#include <stdlib.h>

//#include "get_next_line_utils.c"

size_t  ft_strlen(const char *s);
void	*ft_memcpy(void *dst, const void *src, size_t len);
char    *ft_strjoin(char const *s1, char const *s2);
char    *ft_substr(char const *s, unsigned int start, size_t len);
int		get_next_line(int fd, char **line);

#endif //GNL_V2_GET_NEXT_LINE_H
