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

#include "get_next_line.h"
#include "so_long.h"

int	key_press(int keycode, t_vars *vars)
{
	if (keycode == 13 | keycode == 126)
		vars->objs[0]->state = 13;
	else if (keycode == 0 | keycode == 123)
		vars->objs[0]->state = 0;
	else if (keycode == 1 | keycode == 125)
		vars->objs[0]->state = 1;
	else if (keycode == 2 | keycode == 124)
		vars->objs[0]->state = 2;
	return (0);
}

int	key_release(int keycode, t_vars *vars)
{
	if (keycode == 13 | keycode == 126)
		vars->objs[0]->state = -1;
	if (keycode == 0 | keycode == 123)
		vars->objs[0]->state = -1;
	if (keycode == 1 | keycode == 125)
		vars->objs[0]->state = -1;
	if (keycode == 2 | keycode == 124)
		vars->objs[0]->state = -1;
	if (keycode == 53)
		close_game(vars);
	if (keycode == 15)
	{
		if (vars->game_state == DEATH | vars->game_state == CLEAR)
			reset(vars);
	}
	return (0);
}

int	key_hook_move(t_vars *vars)
{
	if (vars->game_state == DEATH)
		death(vars);
	else if (vars->game_state == CLEAR)
		clear(vars);
	else
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
	vars.w = ft_strnlen(vars.map) - 1;
	vars.h = (ft_strlen(vars.map) + 1) / (vars.w + 1);
	map_check(vars.map, &vars);
	ft_mlx_init(&vars);
	init(&vars);
	map_draw(&vars);
	mlx_hook(vars.win, 2, 0, key_press, &vars);
	mlx_hook(vars.win, 3, 0, &key_release, &vars);
	mlx_hook(vars.win, 17, 0, &close_game, &vars);
	mlx_loop_hook(vars.mlx, &key_hook_move, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
