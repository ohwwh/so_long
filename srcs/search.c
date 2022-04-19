#include "so_long.h"

void enemy_touch(t_vars *vars, int i)
{
	if (abs(vars->objs[0]->x - vars->objs[i]->x) < 64)
	{
		if (abs(vars->objs[0]->y - vars->objs[i]->y) < 64)
		{
			if (vars->objs[i]->y - vars->objs[0]->y >= 32)
				vars->objs[i]->dir = 13;
			else if (vars->objs[0]->y - vars->objs[i]->y >= 32)
				vars->objs[i]->dir = 1;
			else if (vars->objs[0]->x >= vars->objs[i]->x)
				vars->objs[i]->dir = 2;
			else
				vars->objs[i]->dir = 0;
		}
	}
}

int enemy_search_touch(t_vars *vars, int i)
{
	if (abs(vars->objs[0]->x - vars->objs[i]->x) < 64)
	{
		if (abs(vars->objs[0]->y - vars->objs[i]->y) < 64)
		{
			enemy_touch(vars, i);
			return(1);
		}
	}
	return (0);
}

int enemy_search_W(t_vars *vars, t_character_vars *evars, int x, int y)
{
	int ret;

	ret = 0;
	y --;
	if (abs(evars->x - vars->objs[0]->x) <= 40)
	{
		while (y * 64 >= (vars->objs[0]->y + 64))
		{
			ret = 1;
			if (y < 0)
				return (0);
			else if (vars->map[loc(x, y, vars)] == '1')
				return (0);
			else if (vars->map[loc(x, y, vars)] == 'R')
				return (0);
			y --;
		}
	}
	/*while (y * 64 >= (vars->objs[0]->y + 64) && abs(evars->x - vars->objs[0]->x) <= 40)
	{
		ret = 1;
		if (y < 0)
			return (0);
		else if (vars->map[loc(x, y, vars)] == '1')
			return (0);
		else if (vars->map[loc(x, y, vars)] == 'R')
			return (0);
		y --;
	}*/
	return (ret);
}

int enemy_search_A(t_vars *vars, t_character_vars *evars, int x, int y)
{
	int ret;

	ret = 0;
	x --;
	while (x * 64 >= vars->objs[0]->x && abs(evars->y - vars->objs[0]->y) <= 40)
	{
		ret = 1;
		if (x < 0 | vars->map[x + y * (vars->w + 1)] == '1' | vars->map[x + y * (vars->w + 1)] == 'R')
			return (0);
		x --;
	}
	return (ret);
}

int enemy_search_S(t_vars *vars, t_character_vars *evars, int x, int y)
{
	int ret;

	ret = 0;
	y ++;
	while (y * 64 <= (vars->objs[0]->y + 64) && abs(evars->x - vars->objs[0]->x) <= 40)
	{
		ret = 1;
		if (y > vars->h | vars->map[x + y * (vars->w + 1)] == '1' | vars->map[x + y * (vars->w + 1)] == 'R')
			return (0);
		y ++;
	}
	return (ret);
}

int enemy_search_D(t_vars *vars, t_character_vars *evars, int x, int y)
{
	int ret;

	ret = 0;
	x ++;
	while (x * 64 <= vars->objs[0]->x && abs(evars->y - vars->objs[0]->y) <= 40)
	{
		ret = 1;
		if (x > vars->w | vars->map[x + y * (vars->w + 1)] == '1' | vars->map[x + y * (vars->w + 1)] == 'R')
			return (0);
		x ++;
	}
	return (ret);
}

void	enemy_search(t_vars *vars, t_character_vars *evars)
{
	int	x = (evars->x) / 64;
	int	y = ((evars->y) / 64) + 1;
	int	flag;

	flag = 0;
	if (evars->dir == 13)
		flag = enemy_search_W(vars, evars, x, y);
	else if (evars->dir == 0)
		flag = enemy_search_A(vars, evars, x, y);
	else if (evars->dir == 1)
		flag = enemy_search_S(vars, evars, x, y);
	else if (evars->dir == 2)
		flag = enemy_search_D(vars, evars, x, y);
	if (!flag)
		flag = enemy_search_touch(vars, evars->is_player);
	if (flag == 1)
	{
		vars->game_state = CHASE;
		vars->objs[0]->caught = evars->is_player;
	}
}

void    all_enemies_search(t_vars *vars)
{
	int i;

	i = 1;
	while (vars->objs[i])
		enemy_search(vars, vars->objs[i ++]);
}