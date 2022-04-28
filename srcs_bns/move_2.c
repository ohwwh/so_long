/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoh <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 15:32:12 by hoh               #+#    #+#             */
/*   Updated: 2022/04/19 15:32:13 by hoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_collect(t_vars *vars, t_character_vars *cvars)
{
	const int	i = cvars->x;
	const int	j = cvars->y;

	if (vars->map[xl(i) + (yo(j)) * (vars->w + 1)] == 'C')
	{
		vars->map[xl(i) + (yo(j)) * (vars->w + 1)] = 'c';
		(vars->collect_num)--;
	}
	else if (vars->map[xr(i) + (yo(j)) * (vars->w + 1)] == 'C')
	{
		vars->map[xr(i) + (yo(j)) * (vars->w + 1)] = 'c';
		(vars->collect_num)--;
	}
	else if (vars->map[xl(i) + (yu(j)) * (vars->w + 1)] == 'C')
	{
		vars->map[xl(i) + (yu(j)) * (vars->w + 1)] = 'c';
		(vars->collect_num)--;
	}
	else if (vars->map[xr(i) + (yu(j)) * (vars->w + 1)] == 'C')
	{
		vars->map[xr(i) + (yu(j)) * (vars->w + 1)] = 'c';
		(vars->collect_num)--;
	}
}

void	move_exit(t_vars *vars, t_character_vars *cvars)
{
	const int	i = cvars->x;
	const int	j = cvars->y;

	if (vars->map[xl(i) + (yu(j)) * (vars->w + 1)] == 'E')
	{
		if (!vars->collect_num)
			vars->game_state = CLEAR;
	}
}

void	move_around_random(t_vars *vars, t_character_vars *cvars, int k)
{
	if (k % (1000 / (vars->game_speed * 2)) == 0)
		ft_rand(cvars);
	cvars->dir = vars->dir_arr[cvars->rand % 4];
}

void	move_around_wander(t_vars *vars, t_character_vars *cvars, int k)
{
	if (k % (1000 / (vars->game_speed * 2)) == 0)
		ft_rand(cvars);
	if ((((k / (1000 / (vars->game_speed * 2))) % 8)) % 2 == 0)
	{
		cvars->d = 0;
		cvars->dir = vars->dir_arr[cvars->rand % 4];
	}
	else
		move_block(cvars);
}

void	move_around(t_vars *vars, t_character_vars *cvars, int k)
{
	if (vars->game_level == HARD)
		move_around_random(vars, cvars, k);
	else if (vars->game_level == HIDDEN)
		move_around_wander(vars, cvars, k);
	else
	{
		if (((k / (1000 / vars->game_speed)) % 4) == 0)
			cvars->dir = vars->dir_arr[2];
		else if (((k / (1000 / vars->game_speed)) % 4) == 1)
			cvars->dir = vars->dir_arr[3];
		else if (((k / (1000 / vars->game_speed)) % 4) == 2)
			cvars->dir = vars->dir_arr[0];
		else if (((k / (1000 / vars->game_speed)) % 4) == 3)
			cvars->dir = vars->dir_arr[1];
	}
}
