#include "so_long.h"

void    reset_collect(t_vars *vars)
{
    int i;

    i = 0;
    while (vars->map[i])
    {
        if (vars->map[i] == 'c')
            vars->map[i] = 'C';
        i ++;
    }
}

void    reset(t_vars *vars)
{
    reset_collect(vars);
    init(vars);
	map_draw(vars);
}