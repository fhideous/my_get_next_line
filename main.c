#include <stdio.h>
#include <stdlib.h>
#include "fcntl.h"
//#include "get_next_line.h"
#include "get_next_line.h"
/*
char    *str_fill(char* dst, char *src, size_t len)
{
    int iter;

    iter = 0;
    dst = calloc((len + 1), sizeof(char));
    while (len--)
    {
        *(dst + iter) = *(src + iter);
        iter++;
    }
    dst[2] = "fuck, what the fuck";
    dst[iter] = '\0';
    return (dst);
}

int     test_dstar(char **text_fl)
{
   // free(*text_fl);
    //char *str = calloc(32, sizeof(char*));
    //str = "Good bye";
    *text_fl = "Good bye";
    return (0);
}

int     test_ostar(char *str)
{
    char *c_str = calloc (32, sizeof(char));
    c_str = "Changed str";
    str = &c_str;
    printf("%s", c_str);
    return (2);
}
*/
static void print_txt(char **text)
{
    while (*text)
        printf("%s", *text++);
}


int main() {

    int fd = 0;
    int i;

    char **text = calloc(2 , sizeof(char*));
 //  fd = open("/Users/fhideous/Desktop/fhideous/clion_gnl/a.txt", O_RDONLY);
   i = 0;
   while (get_next_line(fd, text) == 1)
   {
     //  text++;
     //  i++;
   }
   text -= i;
    print_txt(text);

    return(0);
}
