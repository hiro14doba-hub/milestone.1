#ifndef DET_NEXT_LINE_H
# define DET_NEXT_LINE_H

#include <unistd.h>
#include <stdlib.h>

char *get_next_line(int fd);

int ft_strlen(char *s);
int check_line(char *s);
char *ft_strjoin(char *s1,char *s2);

#endif