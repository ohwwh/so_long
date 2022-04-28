/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoh <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 11:48:35 by hoh               #+#    #+#             */
/*   Updated: 2022/04/28 11:48:56 by hoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_wd(t_vars *vars, t_character_vars *cvars)
{
	move_w(vars, cvars, cvars->x, cvars->y);
	move_d(vars, cvars, cvars->x, cvars->y);
	cvars->d -= 2;
}

void	move_wa(t_vars *vars, t_character_vars *cvars)
{
	move_w(vars, cvars, cvars->x, cvars->y);
	move_a(vars, cvars, cvars->x, cvars->y);
	cvars->d -= 2;
}

void	move_sd(t_vars *vars, t_character_vars *cvars)
{
	move_s(vars, cvars, cvars->x, cvars->y);
	move_d(vars, cvars, cvars->x, cvars->y);
	cvars->d -= 3;
}

void	move_sa(t_vars *vars, t_character_vars *cvars)
{
	move_s(vars, cvars, cvars->x, cvars->y);
	move_a(vars, cvars, cvars->x, cvars->y);
	cvars->d -= 3;
}

void	move_block(t_character_vars *cvars)
{
	if (cvars->d == 64)
	{
		cvars->state = AROUND;
		return ;
	}
	cvars->state = cvars->dir;
}
