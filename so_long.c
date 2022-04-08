#include "get_next_line.h"
#include "so_long.h"

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == 53)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	return (0);
}

int	key_press(int keycode, t_vars *vars)
{
	if (vars->game_state == INGAME)
	{
		if (keycode == 13 | keycode == 126)
			vars->objs[0]->state = 13;
		else if (keycode == 0 | keycode == 123)
			vars->objs[0]->state = 0;
		else if (keycode == 1 | keycode == 125)
			vars->objs[0]->state = 1;
		else if (keycode == 2 | keycode == 124)
			vars->objs[0]->state = 2;
	}
	return (0);
}

int	key_release(int keycode, t_vars *vars)
{
	if (keycode == 13 | keycode == 126)
		vars->objs[0]->state = -1;
	if (keycode == 0 | keycode == 123)
		vars->objs[0]->state = -1;
	if (keycode == 1 | keycode == 125)
		vars->objs[0]->state = -1;
	if (keycode == 2 | keycode == 124)
		vars->objs[0]->state = -1;
	if (keycode == 53)
	{
		ft_free(vars);
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	return (0);
}

/*void	enemy_search(t_vars *vars)
{
	int	x = (vars->evars->x) / 64;
	int	y = ((vars->evars->y) / 64) + 1;
	if (vars->evars->dir == 13)
	{
		y --;
		while (y >= 0 && (vars->map[x + y * (vars->width + 1)] != '1' && vars->map[x + y * (vars->width + 1)] != 'R'))
		{
			if (vars->evars->y > vars->pvars->y && abs(vars->evars->x - vars->pvars->x) <= 40)
			{
				vars->game_state = DEATH;
				return ;
			}
			y --;
		}	
	}
	else if (vars->evars->dir == 0)
	{
		x --;
		while (x >= 0 && (vars->map[x + y * (vars->width + 1)] != '1' && vars->map[x + y * (vars->width + 1)] != 'R'))
		{
			if (vars->evars->x > vars->pvars->x && abs(vars->evars->y - vars->pvars->y) <= 40)
			{
				vars->game_state = DEATH;
				return ;
			}
			x --;
		}	
	}
	else if (vars->evars->dir == 1)
	{
		y ++;
		while (y < vars->height && (vars->map[x + y * (vars->width + 1)] != '1' && vars->map[x + y * (vars->width + 1)] != 'R'))
		{
			if (vars->evars->y < vars->pvars->y && abs(vars->evars->x - vars->pvars->x) <= 40)
			{
				vars->game_state = DEATH;
				return ;
			}
			y ++;
		}	
	}
	else if (vars->evars->dir == 2)
	{
		x ++;
		while (x < vars->width && (vars->map[x + y * (vars->width + 1)] != '1' && vars->map[x + y * (vars->width + 1)] != 'R'))
		{
			if (vars->evars->x < vars->pvars->x && abs(vars->evars->y - vars->pvars->y) <= 40)
			{
				vars->game_state = DEATH;
				return ;
			}
			x ++;
		}	
	}
}*/

int key_hook_move(t_vars *vars)
{
	static int k;
	static int f = 0;
	
	//enemy_search(vars);
	objs_draw(vars);
	step_draw(vars);
	return (0);
}

int	close_game(t_vars *vars)
{
	ft_free(vars);
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
}

int	main(int argc, char *argv[])
{
	t_vars	vars;
	int		width;
	int		height;
	int		img_width;
	int		img_height;
	int		n;
	int		i;

	vars.map = parsing(argv[1]);
	vars.width = ft_strnlen(vars.map) - 1;
	vars.height = (ft_strlen(vars.map) + 1) / (vars.width + 1); //주어지는 맵의 마지막에 개행이 붙나??
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, vars.width * 64, vars.height * 64, "New"); 
	init(&vars);
	map_draw(&vars);
	mlx_hook(vars.win, 2, 0, key_press, &vars);
	mlx_hook(vars.win, 3, 1L<<1, &key_release, &vars);
	mlx_hook(vars.win, 17, 0, &close_game, &vars);
	mlx_loop_hook(vars.mlx, &key_hook_move, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
