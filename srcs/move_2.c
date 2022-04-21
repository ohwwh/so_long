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

	if (vars->map[xr(i) + (yu(j)) * (vars->w + 1)] == 'C')
	{
		vars->map[xr(i) + (yu(j)) * (vars->w + 1)] = 'c';
		(vars->collect_num)--;
	}
	else if (vars->map[xl(i) + (yu(j)) * (vars->w + 1)] == 'C')
	{
		vars->map[xl(i) + (yu(j)) * (vars->w + 1)] = 'c';
		(vars->collect_num)--;
	}
	else if (vars->map[xr(i) + (yo(j)) * (vars->w + 1)] == 'C')
	{
		vars->map[xr(i) + (yo(j)) * (vars->w + 1)] = 'c';
		(vars->collect_num)--;
	}
	else if (vars->map[xl(i) + (yo(j)) * (vars->w + 1)] == 'C')
	{
		vars->map[xl(i) + (yo(j)) * (vars->w + 1)] = 'c';
		(vars->collect_num)--;
	}
}

void	move_exit(t_vars *vars, t_character_vars *cvars)
{
	const int	i = cvars->x;
	const int	j = cvars->y;

	if (vars->map[xr(i) + (yu(j)) * (vars->w + 1)] == 'E')
	{
		if (!vars->collect_num)
			vars->game_state = CLEAR;
	}
}

void	move_around_random(t_vars *vars, t_character_vars *cvars, int k)
{
	if (k % (480 / SPEED) == 0)
		cvars->rand = ft_rand();
	if (((k / (480 / SPEED)) % 4) == 0)
		cvars->dir = vars->dir_arr[cvars->rand % 4];
	else if (((k / (480 / SPEED)) % 4) == 1)
		cvars->dir = vars->dir_arr[cvars->rand % 4];
	else if (((k / (480 / SPEED)) % 4) == 2)
		cvars->dir = vars->dir_arr[cvars->rand % 4];
	else if (((k / (480 / SPEED)) % 4) == 3)
		cvars->dir = vars->dir_arr[cvars->rand % 4];
}

void	move_around(t_vars *vars, t_character_vars *cvars, int k)
{
	/*if (k % (480 / SPEED) == 0)
		r = ft_rand();
	if (((k / (480 / SPEED)) % 4) == 0)
		cvars->dir = vars->dir_arr[r % 4];
	else if (((k / (480 / SPEED)) % 4) == 1)
		cvars->dir = vars->dir_arr[r % 4];
	else if (((k / (480 / SPEED)) % 4) == 2)
		cvars->dir = vars->dir_arr[r % 4];
	else if (((k / (480 / SPEED)) % 4) == 3)
		cvars->dir = vars->dir_arr[r % 4];*/
	move_around_random(vars, cvars, k);
	
}
