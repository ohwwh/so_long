/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoh <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 11:47:56 by hoh               #+#    #+#             */
/*   Updated: 2022/04/28 11:49:30 by hoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	key_press_w(t_vars *vars)
{
	if (vars->objs[0]->state == D | vars->objs[0]->state == WD)
		vars->objs[0]->state = WD;
	else if (vars->objs[0]->state == A | vars->objs[0]->state == WA)
		vars->objs[0]->state = WA;
	else
		vars->objs[0]->state = W;
}

void	key_press_a(t_vars *vars)
{
	if (vars->objs[0]->state == W | vars->objs[0]->state == WA)
		vars->objs[0]->state = WA;
	else if (vars->objs[0]->state == S | vars->objs[0]->state == SA)
		vars->objs[0]->state = SA;
	else
		vars->objs[0]->state = A;
}

void	key_press_s(t_vars *vars)
{
	if (vars->objs[0]->state == D | vars->objs[0]->state == SD)
		vars->objs[0]->state = SD;
	else if (vars->objs[0]->state == A | vars->objs[0]->state == SA)
		vars->objs[0]->state = SA;
	else
		vars->objs[0]->state = S;
}

void	key_press_d(t_vars *vars)
{
	if (vars->objs[0]->state == W | vars->objs[0]->state == WD)
		vars->objs[0]->state = WD;
	else if (vars->objs[0]->state == S | vars->objs[0]->state == SD)
		vars->objs[0]->state = SD;
	else
		vars->objs[0]->state = D;
}
