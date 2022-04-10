#include "so_long.h"

void	map_draw_mini(t_vars *vars, int x, int y)
{
	int	i;
	int	j;

	/*if (vars->map[x + y * (vars->width + 1)] == 'C')
	{
		vars->map[x + y * (vars->width + 1)] = 'c';
		(vars->collect_num) --;
	}*/
	//캐릭터를 기준으로 2x3짜리 위로 길쭉한 미니 맵을 그리는 함수
	if (vars->map[x + y * (vars->width + 1)] == 'E' && !vars->collect_num)
		vars->game_state = CLEAR;
	j = y - 1;
	while (j < y + 2)
	{
		i = x;
		while (i < x + 2)
		{
			if (vars->map[i + j * (vars->width + 1)] != '1')
			{
				mlx_put_image_to_window(vars->mlx, vars->win, vars->tile00, i * 64, j * 64);
				if (vars->map[i + j * (vars->width + 1)] == 'C')
					mlx_put_image_to_window(vars->mlx, vars->win, vars->collect, i * 64, j * 64);
				else if (vars->map[i + j * (vars->width + 1)] == 'E')
					mlx_put_image_to_window(vars->mlx, vars->win, vars->exit, i * 64, j * 64);
			}
			else
				mlx_put_image_to_window(vars->mlx, vars->win, vars->tile01, i * 64, j * 64);
			i ++;
		}
		j ++;
	}
}

void	map_draw(t_vars *vars)
{
	int	i;
	int	j;
	int	n;

	n = 1;
	j = 0;
	while (j < vars->height)
	{
		i = 0;
		while (i < vars->width)
		{
			if (vars->map[i + j * (vars->width + 1)] != '1')
			{
				mlx_put_image_to_window(vars->mlx, vars->win, vars->tile00, i * 64, j * 64);
				if (vars->map[i + j * (vars->width + 1)] == 'P')
				{
					vars->objs[0]->x = i * 64;
					vars->objs[0]->y = (j - 1) * 64;
				}
				else if (vars->map[i + j * (vars->width + 1)] == 'R')
				{
					vars->objs[n]->x = i * 64;
					vars->objs[n ++]->y = (j - 1) * 64;
				}
				if (vars->map[i + j * (vars->width + 1)] == 'C')
				{
					mlx_put_image_to_window(vars->mlx, vars->win, vars->collect, i * 64, j * 64);
					vars->collect_num ++;
				}
				else if (vars->map[i + j * (vars->width + 1)] == 'E')
					mlx_put_image_to_window(vars->mlx, vars->win, vars->exit, i * 64, j * 64);
			}
			else
				mlx_put_image_to_window(vars->mlx, vars->win, vars->tile01, i * 64, j * 64);
			i ++;
		}
		j ++;
	}
}

void	character_draw(t_vars *vars, t_character_vars *cvars, int k)
{
	int i = cvars->x;
	int j = cvars->y;

	if (cvars->state == -1 | cvars->state == -2 | (!cvars->is_player && vars->game_state == CHASE))
		k = 0;
	if (cvars->dir == 13)
	{
		if ((k / (60 / SPEED)) % 2 == 0)
			mlx_put_image_to_window(vars->mlx, vars->win, cvars->character_image3, i, j);
		else if ((k / (60 / SPEED)) % 2 == 1)
			mlx_put_image_to_window(vars->mlx, vars->win, cvars->character_image4, i, j);
	}
	else if (cvars->dir == 0)
	{
		if ((k / (60 / SPEED)) % 2 == 0)
			mlx_put_image_to_window(vars->mlx, vars->win, cvars->character_image7, i, j);
		else if ((k / (60 / SPEED)) % 2 == 1)
			mlx_put_image_to_window(vars->mlx, vars->win, cvars->character_image8, i, j);
	}
	else if (cvars->dir == 1)
	{
		if ((k / (60 / SPEED)) % 2 == 0)
			mlx_put_image_to_window(vars->mlx, vars->win, cvars->character_image1, i, j);
		else if ((k / (60 / SPEED)) % 2 == 1)
			mlx_put_image_to_window(vars->mlx, vars->win, cvars->character_image2, i, j);
	}
	else if (cvars->dir == 2)
	{
		if ((k / (60 / SPEED)) % 2 == 0)
			mlx_put_image_to_window(vars->mlx, vars->win, cvars->character_image5, i, j);
		else if ((k / (60 / SPEED)) % 2 == 1)
			mlx_put_image_to_window(vars->mlx, vars->win, cvars->character_image6, i, j);
	}
}

void	objs_draw(t_vars *vars)
{
	int	i;
	static int	k;
	static int	l;

	i = 0;
	while (vars->objs[i])
	{
		map_draw_mini(vars, x_loc_right(vars->objs[i]->x), y_loc_under(vars->objs[i]->y));
		i ++;
	}
	i = 0;
	while (vars->objs[i])
		character_move(vars, vars->objs[i ++], l);
	sort(vars->order_arr, vars->objs_n, vars->objs);
	i = 0;
	while (i < vars->objs_n)
	{
		character_draw(vars, vars->objs[vars->order_arr[i]], k);
		i ++;
	}
	i = 1;
	k ++;
	l ++;
}

void	step_draw(t_vars *vars)
{
	static int f = 0;
	
	if (vars->objs[0]->state != -1 && vars->objs[0]->d / 64 > f)
		printf("%d\n", ++ f);
	//mlx_put_image_to_window(vars->mlx, vars->win, vars->tile01, 0, 0);
	mlx_string_put(vars->mlx, vars->win, 24, 36, 0x000000, "4");
}