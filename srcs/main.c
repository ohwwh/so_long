/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoh <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 15:32:42 by hoh               #+#    #+#             */
/*   Updated: 2022/04/19 15:32:43 by hoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_press(int keycode, t_vars *vars)
{
	if (keycode == W | keycode == 126)
		key_press_w(vars);
	else if (keycode == A | keycode == 123)
		key_press_a(vars);
	else if (keycode == S | keycode == 125)
		key_press_s(vars);
	else if (keycode == D | keycode == 124)
		key_press_d(vars);
	return (0);
}

int	key_release(int keycode, t_vars *vars)
{
	if (keycode == W | keycode == 126)
		key_release_w(vars);
	if (keycode == A | keycode == 123)
		key_release_a(vars);
	if (keycode == S | keycode == 125)
		key_release_s(vars);
	if (keycode == D | keycode == 124)
		key_release_d(vars);
	if (keycode == 53)
		close_game(vars);
	if (vars->game_state == DEATH | vars->game_state == CLEAR)
	{
		if (keycode == 15)
			reset(vars);
		if (keycode == 36)
			close_game(vars);
	}
	if (vars->game_state == SELECT_DIFF | vars->game_state == SELECT_SPEED)
		key_hook_menu(keycode, vars);
	return (0);
}

int	key_hook_move(t_vars *vars)
{
	if (vars->game_state == DEATH)
		death(vars);
	else if (vars->game_state == CLEAR)
		clear(vars);
	else if (vars->game_state == INGAME | vars->game_state == CHASE)
	{
		if (vars->game_state == CHASE)
			chase(vars);
		objs_draw(vars);
		if (vars->game_state == INGAME)
		{
			all_enemies_search(vars);
			step_draw(vars);
		}
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	t_vars	vars;

	vars.map = parsing(argv[1]);
	arg_check(argc, argv, vars);
	vars.w = gnl_strnlen(vars.map) - 1;
	vars.h = (gnl_strlen(vars.map) + 1) / (vars.w + 1);
	map_check(vars.map, &vars);
	ft_mlx_init(&vars);
	init(&vars);
	ft_img(&vars, vars.menu_diff, 0, 0);
	mlx_hook(vars.win, 2, 0, &key_press, &vars);
	mlx_hook(vars.win, 3, 0, &key_release, &vars);
	mlx_hook(vars.win, 17, 0, &close_game, &vars);
	mlx_loop_hook(vars.mlx, &key_hook_move, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
