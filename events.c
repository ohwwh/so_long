#include "so_long.h"

void    chase(t_vars *vars)
{
    static int  k;

    if (k > 50)
    {
        if (!enemy_touch(vars, vars->objs[0]->caught))
            vars->objs[vars->objs[0]->caught]->state = vars->objs[vars->objs[0]->caught]->dir;
        else
        {
            vars->objs[vars->objs[0]->caught]->state = -1;
            vars->game_state = DEATH;
        }
    }
    k ++;
}

void    clear(t_vars *vars)
{
    static int  k;

    vars->objs[0]->dir = 1;
    if (k > 10000)
        mlx_clear_window(vars->mlx, vars->win);
    k ++;
}