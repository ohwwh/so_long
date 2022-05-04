/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoh <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 15:32:55 by hoh               #+#    #+#             */
/*   Updated: 2022/04/28 12:54:51 by hoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	abs(int x)
{
	if (x >= 0)
		return (x);
	else
		return (-x);
}

void	sort(int list[], int n, t_character_vars **objs)
{
	int	i;
	int	j;
	int	key;

	i = 1;
	while (i < n)
	{
		key = list[i];
		j = i - 1;
		while (j >= 0 && objs[list[j]]->y > objs[key]->y)
		{
			list[j + 1] = list[j];
			j --;
		}
		list[j + 1] = key;
		i ++;
	}
}

void	ft_rand(t_character_vars *cvars)
{
	cvars->rand = abs((1664525 * cvars->rand + 1013904223) % (2147483647));
}
