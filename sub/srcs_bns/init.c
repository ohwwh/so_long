/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoh <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 15:31:50 by hoh               #+#    #+#             */
/*   Updated: 2022/04/19 15:31:52 by hoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "get_next_line.h"

void	init_player(t_vars *vars, t_character_vars *pvars)
{
	int	w;

	pvars->is_player = 0;
	pvars->caught = -1;
	pvars->state = STAY;
	pvars->d = 0;
	pvars->step = 0;
	pvars->dir = S;
	pvars->rand = 0;
	pvars->img_w00 = ft_xpm(vars, "../asset/fox_W00.xpm", &w, &w);
	pvars->img_w01 = ft_xpm(vars, "../asset/fox_W01.xpm", &w, &w);
	pvars->img_w02 = ft_xpm(vars, "../asset/fox_W02.xpm", &w, &w);
	pvars->img_w03 = ft_xpm(vars, "../asset/fox_W03.xpm", &w, &w);
	pvars->img_a00 = ft_xpm(vars, "../asset/fox_A00.xpm", &w, &w);
	pvars->img_a01 = ft_xpm(vars, "../asset/fox_A01.xpm", &w, &w);
	pvars->img_a02 = ft_xpm(vars, "../asset/fox_A02.xpm", &w, &w);
	pvars->img_a03 = ft_xpm(vars, "../asset/fox_A03.xpm", &w, &w);
	pvars->img_s00 = ft_xpm(vars, "../asset/fox_S00.xpm", &w, &w);
	pvars->img_s01 = ft_xpm(vars, "../asset/fox_S01.xpm", &w, &w);
	pvars->img_s02 = ft_xpm(vars, "../asset/fox_S02.xpm", &w, &w);
	pvars->img_s03 = ft_xpm(vars, "../asset/fox_S03.xpm", &w, &w);
	pvars->img_d00 = ft_xpm(vars, "../asset/fox_D00.xpm", &w, &w);
	pvars->img_d01 = ft_xpm(vars, "../asset/fox_D01.xpm", &w, &w);
	pvars->img_d02 = ft_xpm(vars, "../asset/fox_D02.xpm", &w, &w);
	pvars->img_d03 = ft_xpm(vars, "../asset/fox_D03.xpm", &w, &w);
}

void	init_enemy(t_vars *vars, t_character_vars *evars, int n)
{
	int	w;

	evars->is_player = n;
	evars->caught = -1;
	evars->state = AROUND;
	evars->d = 0;
	evars->step = 0;
	evars->dir = S;
	evars->rand = n;
	evars->img_w00 = ft_xpm(vars, "../asset/cowboy_W00.xpm", &w, &w);
	evars->img_w01 = ft_xpm(vars, "../asset/cowboy_W01.xpm", &w, &w);
	evars->img_w02 = ft_xpm(vars, "../asset/cowboy_W02.xpm", &w, &w);
	evars->img_w03 = ft_xpm(vars, "../asset/cowboy_W03.xpm", &w, &w);
	evars->img_a00 = ft_xpm(vars, "../asset/cowboy_A00.xpm", &w, &w);
	evars->img_a01 = ft_xpm(vars, "../asset/cowboy_A01.xpm", &w, &w);
	evars->img_a02 = ft_xpm(vars, "../asset/cowboy_A02.xpm", &w, &w);
	evars->img_a03 = ft_xpm(vars, "../asset/cowboy_A03.xpm", &w, &w);
	evars->img_s00 = ft_xpm(vars, "../asset/cowboy_S00.xpm", &w, &w);
	evars->img_s01 = ft_xpm(vars, "../asset/cowboy_S01.xpm", &w, &w);
	evars->img_s02 = ft_xpm(vars, "../asset/cowboy_S02.xpm", &w, &w);
	evars->img_s03 = ft_xpm(vars, "../asset/cowboy_S03.xpm", &w, &w);
	evars->img_d00 = ft_xpm(vars, "../asset/cowboy_D00.xpm", &w, &w);
	evars->img_d01 = ft_xpm(vars, "../asset/cowboy_D01.xpm", &w, &w);
	evars->img_d02 = ft_xpm(vars, "../asset/cowboy_D02.xpm", &w, &w);
	evars->img_d03 = ft_xpm(vars, "../asset/cowboy_D03.xpm", &w, &w);
}

void	create_objs_arr(t_vars *vars)
{
	int	i;
	int	n;

	vars->objs_n = count_obj(vars->map);
	n = vars->objs_n;
	vars->objs = (t_character_vars **)malloc(sizeof(t_character_vars *) * ++n);
	n --;
	vars->order_arr = (int *)malloc(sizeof(int) * n);
	i = 0;
	while (i < n)
	{
		vars->objs[i] = (t_character_vars *)malloc(sizeof(t_character_vars));
		vars->order_arr[i] = i;
		i ++;
	}
	vars->objs[i] = 0;
}	

void	init_obj(t_vars *vars)
{
	int	i;
	int	n;

	i = 1;
	create_objs_arr(vars);
	init_player(vars, vars->objs[0]);
	while (vars->objs[i])
	{
		init_enemy(vars, vars->objs[i], i);
		i ++;
	}
}

void	init(t_vars *vars)
{
	int	w;
	int	h;

	vars->game_state = SELECT_DIFF;
	vars->timer = 0;
	vars->dir_arr[0] = W;
	vars->dir_arr[1] = A;
	vars->dir_arr[2] = S;
	vars->dir_arr[3] = D;
	init_obj(vars);
	vars->menu_diff = ft_xpm(vars, "../asset/menu_difficulty.xpm", &w, &w);
	vars->menu_speed = ft_xpm(vars, "../asset/menu_speed.xpm", &w, &w);
	vars->clear = ft_xpm(vars, "../asset/clear.xpm", &w, &w);
	vars->game_over = ft_xpm(vars, "../asset/game_over.xpm", &w, &w);
	vars->tile00 = ft_xpm(vars, "../asset/test_tile.xpm", &w, &w);
	vars->tile01 = ft_xpm(vars, "../asset/test_tile2.xpm", &w, &w);
	vars->collect = ft_xpm(vars, "../asset/meat1.xpm", &w, &w);
	vars->exit = ft_xpm(vars, "../asset/exit.xpm", &w, &w);
	vars->num_box = ft_xpm(vars, "../asset/num_box_16.xpm", &w, &w);
}
