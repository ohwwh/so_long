/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   location.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoh <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 15:31:58 by hoh               #+#    #+#             */
/*   Updated: 2022/04/19 15:31:58 by hoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	loc(int x, int y, t_vars *vars)
{
	return (x + y * (vars->w + 1));
}

int	xl(int x)
{
	int	ret;

	if (!(x % 64))
		ret = x / 64;
	else
		ret = (x / 64) + 1;
	return (ret);
}

int	yo(int y)
{
	int	ret;

	y += 64;
	if (!(y % 64))
		ret = y / 64;
	else
		ret = (y / 64) + 1;
	return (ret);
}

int	xr(int x)
{
	int	ret;

	ret = x / 64;
	return (ret);
}

int	yu(int y)
{
	int	ret;

	y += 64;
	ret = y / 64;
	return (ret);
}
