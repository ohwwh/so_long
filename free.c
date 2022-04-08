#include "so_long.h"

void    ft_free(t_vars *vars)
{
    int i;
    
    i = 0;
    while (vars->objs[i])
        free(vars->objs[i ++]);
    free(vars->objs);
    free(vars->order_arr);
}