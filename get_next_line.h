//
// Created by Formy Hideous on 11/19/20.
//

#ifndef GNL_GET_NEXT_LINE_H
#define GNL_GET_NEXT_LINE_H

#include <stdlib.h>
#include "fcntl.h"

size_t  ft_strlen(const char *s);
void    *ft_memcpy(void *dst, const void *src, size_t len);
char    *ft_strjoin(char const *s1, char const *s2);
int     get_next_line(int fd, char **line);

#endif //GNL_GET_NEXT_LINE_H
