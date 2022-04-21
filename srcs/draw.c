/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoh <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 15:31:16 by hoh               #+#    #+#             */
/*   Updated: 2022/04/19 15:31:17 by hoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_draw_m(t_vars *vars, int x, int y)
{
	int	i;
	int	j;

	j = y - 1;
	while (j < y + 2)
	{
		i = x;
		while (i < x + 2)
		{
			if (vars->map[i + j * (vars->w + 1)] != '1')
			{
				ft_img(vars, vars->tile00, i * 64, j * 64);
				if (vars->map[i + j * (vars->w + 1)] == 'C')
					ft_img(vars, vars->collect, i * 64, j * 64);
				else if (vars->map[i + j * (vars->w + 1)] == 'E')
					ft_img(vars, vars->exit, i * 64, j * 64);
			}
			else if (i != 0 | j != 0)
				ft_img(vars, vars->tile01, i * 64, j * 64);
			i ++;
		}
		j ++;
	}
}

void	map_draw_2(t_vars *vars, int i, int j, int *n)
{
	while (i < vars->w)
	{
		if (vars->map[i + j * (vars->w + 1)] != '1')
		{
			ft_img(vars, vars->tile00, i * 64, j * 64);
			if (vars->map[i + j * (vars->w + 1)] == 'P')
			{
				vars->objs[0]->x = i * 64;
				vars->objs[0]->y = (j - 1) * 64;
			}
			else if (vars->map[i + j * (vars->w + 1)] == 'R')
			{
				vars->objs[*n]->x = i * 64;
				vars->objs[*n]->y = (j - 1) * 64;
				*n += 1;
			}
			if (vars->map[i + j * (vars->w + 1)] == 'C')
				ft_img(vars, vars->collect, i * 64, j * 64);
			else if (vars->map[i + j * (vars->w + 1)] == 'E')
				ft_img(vars, vars->exit, i * 64, j * 64);
		}
		else
			ft_img(vars, vars->tile01, i * 64, j * 64);
		i ++;
	}
}

void	map_draw(t_vars *vars)
{
	int	j;
	int	n;

	n = 1;
	j = 0;
	while (j < vars->h)
	{
		map_draw_2(vars, 0, j, &n);
		j ++;
	}
	ft_img(vars, vars->num_box, 0, 0);
}

void	objs_draw(t_vars *vars)
{
	int			i;
	static int	k;
	static int	l;

	i = 0;
	while (vars->objs[i])
	{
		map_draw_m(vars, xl(vars->objs[i]->x), yo(vars->objs[i]->y));
		i ++;
	}
	move_exit(vars, vars->objs[0]);
	i = 0;
	while (vars->objs[i])
		character_move(vars, vars->objs[i ++], l);
	sort(vars->order_arr, vars->objs_n, vars->objs);
	i = 0;
	while (i < vars->objs_n)
	{
		character_draw(vars, vars->objs[vars->order_arr[i]], k);
		i ++;
	}
	i = 1;
	k ++;
	l ++;
}

void	step_draw(t_vars *vars)
{
	char	*str;

	if (vars->objs[0]->state != -1)
	{
		if (vars->objs[0]->d / 64 > vars->objs[0]->step)
		{
			printf("%d\n", ++ vars->objs[0]->step);
			str = ft_itoa(vars->objs[0]->step);
			ft_img(vars, vars->num_box, 0, 0);
			mlx_string_put(vars->mlx, vars->win, 24, 24, 0, str);
			free(str);
			str = 0;
		}
	}
}
