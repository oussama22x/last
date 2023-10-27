#include <stdio.h>
#include "file.h"

void get_map(t_all **all, int fd)
{
    char *line;
    char *tmp;

    tmp = NULL;
    line = NULL;
    tmp = get_next_line(fd);
    if(!tmp)
        exit(4);
    while(tmp)
    {
        tmp = ft_strjoin(line, tmp);
        line = ft_strdup(tmp);
        free(tmp);
        tmp = get_next_line(fd);
    }
    (*all)->map = ft_split(line, '\n');
}
void init_befor_init_hh(t_textr **txtr)
{
    (*txtr)->color_c = NULL;
    (*txtr)->color_f = NULL;
    (*txtr)->EA = NULL;
    (*txtr)->NO = NULL;
    (*txtr)->SO = NULL;
    (*txtr)->WE = NULL;
    (*txtr)->C = calloc(sizeof(int) , 3);
    (*txtr)->F = calloc(sizeof(int) , 3);
}
int start_reading_map(char *line)
{
    if(!strnstr(line, "NO", ft_strlen(line)) && !strnstr(line, "SO", ft_strlen(line)) &&\
    !strnstr(line, "WE", ft_strlen(line)) && !strnstr(line, "EA", ft_strlen(line)) &&\
    !strnstr(line, "F", ft_strlen(line)) && !strnstr(line, "C", ft_strlen(line)))
        return (-1);
    return(0);
}







