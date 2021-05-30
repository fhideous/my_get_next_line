# my_get_next_line

Function name: get_next_line

Prototype: int get_next_line(int fd, char **line);

Turn in files: get_next_line.c, get_next_line_utils.c,get_next_line.h

Parameters #1.  file descriptor for reading #2.The value of what has been read

Return value: 1 - A line has been read; 0 - EOF has been reached; -1 - An error happened

External functs: read, malloc, free

Description Write a function which returns a line read from afile descriptor, without the newline
