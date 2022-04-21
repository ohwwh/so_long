/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   character_draw.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoh <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 15:31:08 by hoh               #+#    #+#             */
/*   Updated: 2022/04/19 15:31:11 by hoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	character_draw_w(t_vars *vars, t_character_vars *cvars, int k)
{
	if ((k / (60 / vars->game_speed)) % 4 == 0)
		ft_img(vars, cvars->img_w00, cvars->x, cvars->y);
	else if ((k / (60 / vars->game_speed)) % 4 == 1)
		ft_img(vars, cvars->img_w01, cvars->x, cvars->y);
	else if ((k / (60 / vars->game_speed)) % 4 == 2)
		ft_img(vars, cvars->img_w02, cvars->x, cvars->y);
	else if ((k / (60 / vars->game_speed)) % 4 == 3)
		ft_img(vars, cvars->img_w03, cvars->x, cvars->y);
}

void	character_draw_a(t_vars *vars, t_character_vars *cvars, int k)
{
	if ((k / (60 / vars->game_speed)) % 4 == 0)
		ft_img(vars, cvars->img_a00, cvars->x, cvars->y);
	else if ((k / (60 / vars->game_speed)) % 4 == 1)
		ft_img(vars, cvars->img_a01, cvars->x, cvars->y);
	else if ((k / (60 / vars->game_speed)) % 4 == 2)
		ft_img(vars, cvars->img_a02, cvars->x, cvars->y);
	else if ((k / (60 / vars->game_speed)) % 4 == 3)
		ft_img(vars, cvars->img_a03, cvars->x, cvars->y);
}

void	character_draw_s(t_vars *vars, t_character_vars *cvars, int k)
{
	if ((k / (60 / vars->game_speed)) % 4 == 0)
		ft_img(vars, cvars->img_s00, cvars->x, cvars->y);
	else if ((k / (60 / vars->game_speed)) % 4 == 1)
		ft_img(vars, cvars->img_s01, cvars->x, cvars->y);
	else if ((k / (60 / vars->game_speed)) % 4 == 2)
		ft_img(vars, cvars->img_s02, cvars->x, cvars->y);
	else if ((k / (60 / vars->game_speed)) % 4 == 3)
		ft_img(vars, cvars->img_s03, cvars->x, cvars->y);
}

void	character_draw_d(t_vars *vars, t_character_vars *cvars, int k)
{
	if ((k / (60 / vars->game_speed)) % 4 == 0)
		ft_img(vars, cvars->img_d00, cvars->x, cvars->y);
	else if ((k / (60 / vars->game_speed)) % 4 == 1)
		ft_img(vars, cvars->img_d01, cvars->x, cvars->y);
	else if ((k / (60 / vars->game_speed)) % 4 == 2)
		ft_img(vars, cvars->img_d02, cvars->x, cvars->y);
	else if ((k / (60 / vars->game_speed)) % 4 == 3)
		ft_img(vars, cvars->img_d03, cvars->x, cvars->y);
}

void	character_draw(t_vars *vars, t_character_vars *cvars, int k)
{
	if (cvars->state == -1 | cvars->state == -2)
		k = 0;
	else if (!cvars->is_player && vars->game_state == CHASE)
		k = 0;
	if (cvars->dir == 13)
		character_draw_w(vars, cvars, k);
	else if (cvars->dir == 0)
		character_draw_a(vars, cvars, k);
	else if (cvars->dir == 1)
		character_draw_s(vars, cvars, k);
	else if (cvars->dir == 2)
		character_draw_d(vars, cvars, k);
}
