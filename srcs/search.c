/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoh <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 15:32:32 by hoh               #+#    #+#             */
/*   Updated: 2022/04/19 15:32:33 by hoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	enemy_search_w(t_vars *vars, t_character_vars *evars, int x, int y)
{
	int	ret;

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
	return (ret);
}

int	enemy_search_a(t_vars *vars, t_character_vars *evars, int x, int y)
{
	int	ret;

	ret = 0;
	x --;
	if (abs(evars->y - vars->objs[0]->y) <= 40)
	{
		while (x * 64 >= vars->objs[0]->x)
		{
			ret = 1;
			if (x < 0)
				return (0);
			else if (vars->map[x + y * (vars->w + 1)] == '1')
				return (0);
			else if (vars->map[x + y * (vars->w + 1)] == 'R')
				return (0);
			x --;
		}
	}
	return (ret);
}

int	enemy_search_s(t_vars *vars, t_character_vars *evars, int x, int y)
{
	int	ret;

	ret = 0;
	y ++;
	if (abs(evars->x - vars->objs[0]->x) <= 40)
	{
		while (y * 64 <= (vars->objs[0]->y + 64))
		{
			ret = 1;
			if (y > vars->h)
				return (0);
			else if (vars->map[x + y * (vars->w + 1)] == '1')
				return (0);
			else if (vars->map[x + y * (vars->w + 1)] == 'R')
				return (0);
			y ++;
		}
	}
	return (ret);
}

int	enemy_search_d(t_vars *vars, t_character_vars *evars, int x, int y)
{
	int	ret;

	ret = 0;
	x ++;
	if (abs(evars->y - vars->objs[0]->y) <= 40)
	{
		while (x * 64 <= vars->objs[0]->x)
		{
			ret = 1;
			if (x > vars->w)
				return (0);
			else if (vars->map[x + y * (vars->w + 1)] == '1')
				return (0);
			else if (vars->map[x + y * (vars->w + 1)] == 'R')
				return (0);
			x ++;
		}
	}
	return (ret);
}

void	enemy_search(t_vars *vars, t_character_vars *evars)
{
	const int	x = (evars->x) / 64;
	const int	y = ((evars->y) / 64) + 1;
	int			flag;

	flag = 0;
	if (evars->dir == W)
		flag = enemy_search_w(vars, evars, x, y);
	else if (evars->dir == A)
		flag = enemy_search_a(vars, evars, x, y);
	else if (evars->dir == S)
		flag = enemy_search_s(vars, evars, x, y);
	else if (evars->dir == D)
		flag = enemy_search_d(vars, evars, x, y);
	if (!flag)
		flag = enemy_search_touch(vars, evars->is_player);
	if (flag == 1)
	{
		vars->game_state = CHASE;
		vars->objs[0]->caught = evars->is_player;
	}
}
