/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoh <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 18:33:47 by hoh               #+#    #+#             */
/*   Updated: 2022/04/21 18:33:47 by hoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	menu_diff(int keycode, t_vars *vars)
{
	const int	x = (vars->w * 64 - 640) / 2;
	const int	y = (vars->h * 64 - 400) / 2;

	if (keycode == 18)
		vars->game_speed = EASY;
	if (keycode == 19)
		vars->game_level = MEDIUM;
	if (keycode == 20)
		vars->game_level = HARD;
	if (keycode == 18 | keycode == 19 | keycode == 20)
	{
		vars->game_state = SELECT_SPEED;
		ft_img(vars, vars->menu_speed, x, y);
	}
}

static void	menu_speed(int keycode, t_vars *vars)
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

void	key_hook_menu(int keycode, t_vars *vars)
{
	if (vars->game_state == SELECT_DIFF)
		menu_diff(keycode, vars);
	else if (vars->game_state == SELECT_SPEED)
		menu_speed(keycode, vars);
}
