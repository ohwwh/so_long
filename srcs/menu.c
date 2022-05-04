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
	if (keycode == 18)
		vars->game_level = EASY;
	if (keycode == 19)
		vars->game_level = MEDIUM;
	if (keycode == 20)
		vars->game_level = HARD;
	if (keycode == 21)
		vars->game_level = HIDDEN;
	if (keycode == 18 | keycode == 19 | keycode == 20 | keycode == 21)
	{
		vars->game_state = SELECT_SPEED;
		ft_img(vars, vars->menu_speed, 0, 0);
		if (vars->game_level == EASY)
			destroy_enemies(vars);
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
		mlx_destroy_window(vars->mlx, vars->win);
		ft_mlx_new(vars, vars->w * 64, vars->h * 64, "1");
		mlx_hook(vars->win, 2, 0, &key_press, vars);
		mlx_hook(vars->win, 3, 0, &key_release, vars);
		mlx_hook(vars->win, 17, 0, &close_game, vars);
		map_draw(vars);
		printf("repeat\n");
	}
}

void	key_hook_menu(int keycode, t_vars *vars)
{
	if (vars->game_state == SELECT_DIFF)
		menu_diff(keycode, vars);
	else if (vars->game_state == SELECT_SPEED)
		menu_speed(keycode, vars);
}
