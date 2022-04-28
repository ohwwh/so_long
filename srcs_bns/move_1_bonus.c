/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoh <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 15:32:12 by hoh               #+#    #+#             */
/*   Updated: 2022/04/21 22:03:00 by hoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	move_w(t_vars *vars, t_character_vars *cvars, int i, int j)
{
	const int	x = 64 * (vars->w - 1);

	if (j > -64)
	{
		if (vars->map[loc(xl(i), yu(j) - 1, vars)] != '1')
		{
			if (!(i % 64) | (vars->map[loc(xl(i) + 1, yu(j) - 1, vars)] != '1'))
			{
				cvars->y -= vars->game_speed * CHEAT;
				cvars->d += vars->game_speed * CHEAT;
			}
			else if (i > 0 && (vars->map[loc(xr(i) - 1, yu(j), vars)] != '1'))
			{
				cvars->x -= 1;
				cvars->d += 1;
			}
		}
		else if (i < x && vars->map[loc(xl(i) + 1, yu(j), vars)] != '1')
		{
			cvars->x += 1;
			cvars->d += 1;
		}	
	}
	cvars->dir = W;
}

void	move_a(t_vars *vars, t_character_vars *cvars, int i, int j)
{
	const int	x = 64 * (vars->h - 2);

	if (i > 0)
	{
		if (vars->map[loc(xr(i) - 1, yo(j), vars)] != '1')
		{
			if (!(j % 64) | (vars->map[loc(xr(i) - 1, yo(j) + 1, vars)] != '1'))
			{
				cvars->x -= vars->game_speed * CHEAT;
				cvars->d += vars->game_speed * CHEAT;
			}
			else if (j > -64 && (vars->map[loc(xr(i), yu(j) - 1, vars)] != '1'))
			{
				cvars->y -= 1;
				cvars->d += 1;
			}
		}
		else if (j < x && vars->map[loc(xr(i), yo(j) + 1, vars)] != '1')
		{
			cvars->y += 1;
			cvars->d += 1;
		}
	}
	cvars->dir = A;
}

void	move_s(t_vars *vars, t_character_vars *cvars, int i, int j)
{
	const int	x = 64 * (vars->w - 1);

	if (j < 64 * (vars->h - 2))
	{
		if (vars->map[loc(xl(i), yo(j) + 1, vars)] != '1')
		{
			if (!(i % 64) | (vars->map[loc(xl(i) + 1, yo(j) + 1, vars)] != '1'))
			{
				cvars->y += vars->game_speed * CHEAT;
				cvars->d += vars->game_speed * CHEAT;
			}	
			else if (i > 0 && vars->map[loc(xr(i) - 1, yo(j), vars)] != '1')
			{
				cvars->x -= 1;
				cvars->d += 1;
			}
		}
		else if (i < x && vars->map[loc(xl(i) + 1, yo(j), vars)] != '1')
		{
			cvars->x += 1;
			cvars->d += 1;
		}
	}
	cvars->dir = S;
}

void	move_d(t_vars *vars, t_character_vars *cvars, int i, int j)
{
	const int	x = 64 * (vars->h - 2);

	if (i < 64 * (vars->w - 1))
	{
		if (vars->map[loc(xl(i) + 1, yo(j), vars)] != '1')
		{
			if (!(j % 64) | (vars->map[loc(xl(i) + 1, yo(j) + 1, vars)] != '1'))
			{
				cvars->x += vars->game_speed * CHEAT;
				cvars->d += vars->game_speed * CHEAT;
			}
			else if (j > -64 && vars->map[loc(xl(i), yu(j) - 1, vars)] != '1')
			{
				cvars->y -= 1;
				cvars->d += 1;
			}
		}
		else if (j < x && vars->map[loc(xl(i), yo(j) + 1, vars)] != '1')
		{
			cvars->y += 1;
			cvars->d += 1;
		}
	}
	cvars->dir = D;
}

void	character_move(t_vars *vars, t_character_vars *cvars, int k)
{
	if ((cvars->is_player) | (vars->game_state == INGAME))
	{
		if (cvars->is_player && vars->game_state == INGAME)
			move_around(vars, cvars, k);
		if (cvars->is_player == 0)
			move_collect(vars, cvars);
		if (cvars->state == W)
			move_w(vars, cvars, cvars->x, cvars->y);
		else if (cvars->state == A)
			move_a(vars, cvars, cvars->x, cvars->y);
		else if (cvars->state == S)
			move_s(vars, cvars, cvars->x, cvars->y);
		else if (cvars->state == D)
			move_d(vars, cvars, cvars->x, cvars->y);
		else if (cvars->state == WD)
			move_wd(vars, cvars);
		else if (cvars->state == WA)
			move_wa(vars, cvars);
		else if (cvars->state == SD)
			move_sd(vars, cvars);
		else if (cvars->state == SA)
			move_sa(vars, cvars);
	}
}
