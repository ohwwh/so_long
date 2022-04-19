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

void	move_around(t_vars *vars, t_character_vars *cvars, int k)
{
	int	arr[4];

	arr[0] = S;
	arr[1] = D;
	arr[2] = W;
	arr[3] = A;
	if (((k / (480 / SPEED)) % 4) == 0)
		cvars->dir = arr[0];
	else if (((k / (480 / SPEED)) % 4) == 1)
		cvars->dir = arr[1];
	else if (((k / (480 / SPEED)) % 4) == 2)
		cvars->dir = arr[2];
	else if (((k / (480 / SPEED)) % 4) == 3)
		cvars->dir = arr[3];
}
