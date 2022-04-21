#include "so_long.h"

void    menu_diff(t_vars *vars, int k)
{
    ft_img(vars, vars->menu_diff, 0, 0);
}

void    menu_speed(t_vars *vars, int k)
{
    ft_img(vars, vars->menu_speed, 0, 0);
}

void    key_hook_menu(int keycode, t_vars *vars)
{
    if (vars->game_state == SELECT_DIFF)
	{
		if (keycode == 18)
			vars->game_speed = EASY;
		if (keycode == 19)
			vars->game_level = MEDIUM;
		if (keycode == 20)
			vars->game_level = HARD;
        if (keycode == 18 | keycode == 19 | keycode == 20)
        {
            vars->game_state = SELECT_SPEED;
            ft_img(vars, vars->menu_speed, 0, 0);
        }
	}
	else if (vars->game_state == SELECT_SPEED)
	{
		if (keycode == 18)
			vars->game_speed = SLOW;
		if (keycode == 19)
			vars->game_speed = MEDIUM;
		if (keycode == 20)
			vars->game_speed = FAST;
        if (keycode == 18 | keycode == 19 | keycode == 20)
        {
            vars->game_state = INGAME;
            map_draw(vars);
        }
	}
}