#include "get_next_line.h"
#include <stdlib.h>
#include <fcntl.h>

void    free_map();

char    *parsing(char *map_ber)
{
    int     fd;
    int     width;
    char    *pars;
    char    *map;

    map = 0;
    fd = open(map_ber, O_RDONLY);
    pars = get_next_line(fd);
    width = ft_strlen(pars);
    map = ft_strjoin(map, pars);
    free(pars);
    while (pars)
    {
        pars = get_next_line(fd);
        width = ft_strlen(pars);
        map = ft_strjoin(map, pars);
        free(pars);
    }
    return (map);
}