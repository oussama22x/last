#include "file.h"
void get_x_y_of_the_player(t_all **all)
{
    char c;
    while((*all)->map[(*all)->x])
    {
        (*all)->y = 0;
        while ((*all)->map[(*all)->x][(*all)->y])
        {
            c = (*all)->map[(*all)->x][(*all)->y];
            if(c == 'N')
            {
                return ;
            }
            if(c == 'S')
            {
                return ;
            }
            if(c == 'E')
            {
                return ;
            }
            if(c == 'W')
            {
                return ;
            }
        (*all)->y++;
        }
         (*all)->x++;
    }
}
int count_pinters(char **str)
{
    int i;
    if(!str)
        return(0);
    i = 0;
    while(str[i])
        i++;
    return(i);
}
int all_in_one(t_all **all, t_textr **txtr,  char **argv)
{
    (*all) = malloc(sizeof(t_all));
    (*txtr) = malloc(sizeof(t_textr));
    (*all)->fd = open(argv[1], O_RDONLY);
    if((*all)->fd == -1)
    {
        perror("file error -->\n");
        return (-1);
    }
    init_all(all);
    get_map(all, (*all)->fd);
    int i;
    i = 0;
     init_txters(&(*txtr), (*all));
    if(check_errors((*all)->map) || !(*txtr)->color_c || !(*txtr)->color_f || !(*txtr)->EA || !(*txtr)->NO || !(*txtr)->SO || !(*txtr)->WE)
    {
        printf("unvalid map :(\n");
        return(-1);
    }
    if(count_pinters((*txtr)->EA) != 2 || count_pinters((*txtr)->NO) != 2 || count_pinters((*txtr)->SO) != 2 || count_pinters((*txtr)->WE) != 2)
        return(-1);
    get_x_y_of_the_player((all));
    return(0);
}
void init_txters(t_textr **txtr, t_all *all)
{
    int i;
    int x;

    init_befor_init_hh(txtr);
    x = 0;
    i = 0;
    while(all->map[i])// split from the begining
    {
        if(start_reading_map(all->map[i]) == -1)
                break;
        if(strnstr(all->map[i], "NO", 2))
        {
            x++;
            (*txtr)->NO = ft_split(ft_strdup((all->map[i])), ' ');
            all->map[i] = NULL;
        }
        else if(strnstr(all->map[i], "SO", 2))
        {
            x++;
            (*txtr)->SO = ft_split(ft_strdup((all->map[i])), ' ');
            all->map[i] = NULL;
        }
        else if(strnstr(all->map[i], "WE", 2))
        {
            x++;
            (*txtr)->WE = ft_split(ft_strdup((all->map[i])), ' ');
            all->map[i] = NULL;
        }
       else if(strnstr(all->map[i], "EA", 2))
       {
            x++;
            (*txtr)->EA = ft_split(ft_strdup((all->map[i])), ' ');
            all->map[i] = NULL;
       }
        else if(strnstr(all->map[i], "F", 1))
        {

            x++;
            (*txtr)->color_f = ft_split(ft_strdup((all->map[i])), ' ');
           all->map[i] = NULL;
        }
        else if(strnstr(all->map[i], "C", 1))
        {
            x++;
            (*txtr)->color_c = ft_split(ft_strdup((all->map[i])), ' ');
            all->map[i] = NULL;
        }
        i++;
    }
    all->map = &all->map[x];
}
int check_errors(char **map)
{
    int i;
    int plr;
    int x;
    
    plr = 0;
    i = 0;
    while(map[i])
    {
        x = 0;
        while(map[i][x])
        {
            if(map[i][x] != 'N' && map[i][x] != 'E' && map[i][x] != 'S' && map[i][x] != 'W' && map[i][x] != '0' && map[i][x] != '1' && map[i][x] != ' ')
            {
                    return(1);
            }
            if(map[i][x] == 'N' || map[i][x] == 'E' || map[i][x] == 'S' || map[i][x] == 'W')
                plr++;
            x++;
        }
        i++;
    }
    if(plr > 1 || plr == 0)
        return(1);
    return(0);
}