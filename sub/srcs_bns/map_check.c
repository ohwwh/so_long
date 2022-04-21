/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoh <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 15:32:06 by hoh               #+#    #+#             */
/*   Updated: 2022/04/19 15:32:06 by hoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "get_next_line.h"

int	count_obj(char *map)
{
	int	ret;

	ret = 0;
	while (*map)
	{
		if (*map == 'P' | *map == 'R')
			ret ++;
		map ++;
	}
	return (ret);
}

int	map_check_comp(char *map, t_vars *vars)
{
	int	check_p;
	int	check_e;

	check_p = 0;
	check_e = 0;
	vars->collect_num = 0;
	while (*map)
	{
		if (*map != '\n')
		{
			if (*map == 'C')
				vars->collect_num ++;
			else if (*map == 'P')
				(check_p)++;
			else if (*map == 'E')
				(check_e)++;
			else if (*map != 'R' && *map != '1' && *map != '0')
				return (2);
		}
		map ++;
	}
	if ((check_p != 1) | (!check_e) | (!vars->collect_num))
		return (1);
	return (0);
}

int	map_check_surr(char *map, t_vars *vars)
{
	int	width;
	int	h;

	h = 0;
	while (*map)
	{
		if (*map != '1')
			return (1);
		width = 0;
		while (*map != '\n' && *map)
		{
			if (((!h) | (h == vars->h - 1)) && *map != '1')
				return (1);
			map ++;
			width ++;
		}
		if (vars->w != width | *(map - 1) != '1')
			return (1);
		if (*map)
			break ;
		map ++;
		h ++;
	}
	return (0);
}

void	map_check(char *map, t_vars *vars)
{
	int	ret;

	ret = map_check_comp(map, vars);
	if (ret == 1)
	{
		printf("Error\nNot enough necessary components in the map\n");
		exit(0);
	}
	else if (ret == 2)
	{
		printf("Error\nInvalid componenets in the map\n");
		exit(0);
	}
	else if (map_check_surr(map, vars) == 1)
	{
		printf("Error\nInvalid shape of the map\n");
		exit(0);
	}
}
