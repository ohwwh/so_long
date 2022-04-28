/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   touch.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoh <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 15:32:58 by hoh               #+#    #+#             */
/*   Updated: 2022/04/19 15:32:59 by hoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	enemy_touch(t_vars *vars, int i)
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

int	enemy_search_touch(t_vars *vars, int i)
{
	if (abs(vars->objs[0]->x - vars->objs[i]->x) < 64)
	{
		if (abs(vars->objs[0]->y - vars->objs[i]->y) < 64)
		{
			enemy_touch(vars, i);
			return (1);
		}
	}
	return (0);
}

void	all_enemies_search(t_vars *vars)
{
	int	i;

	i = 1;
	while (vars->objs[i])
		enemy_search(vars, vars->objs[i ++]);
}
