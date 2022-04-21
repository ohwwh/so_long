/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoh <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 15:32:27 by hoh               #+#    #+#             */
/*   Updated: 2022/04/19 15:32:27 by hoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	reset_collect(t_vars *vars)
{
	int	i;
	int	n;

	n = 0;
	i = 0;
	while (vars->map[i])
	{
		if (vars->map[i] == 'c')
		{
			vars->map[i] = 'C';
			n ++;
		}
		i ++;
	}
	vars->collect_num = n;
}

void	reset(t_vars *vars)
{
	ft_free_reset(vars);
	reset_collect(vars);
	init(vars);
	vars->game_state = INGAME;
	map_draw(vars);
}
