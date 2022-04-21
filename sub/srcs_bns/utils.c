/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoh <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 15:32:55 by hoh               #+#    #+#             */
/*   Updated: 2022/04/19 15:32:56 by hoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

static int	getbuf(int n)
{
	int	buf;

	buf = 1;
	if (n <= 0)
	{	
		buf ++;
		n *= -1;
	}
	while (n)
	{
		n /= 10;
		buf ++;
	}
	return (buf);
}

char	*ft_itoa(int n)
{
	int		buf;
	long	temp;
	char	*ret;

	if (n >= 0)
		temp = n;
	else
		temp = -(long)n;
	ret = (char *)malloc(sizeof(char) * (buf = getbuf(n)));
	if (ret)
	{
		ret[(buf--) - 1] = 0;
		while (temp)
		{
			ret[(buf--) - 1] = temp % 10 + '0';
			temp /= 10;
		}
		if (n < 0)
			ret[buf - 1] = '-';
		else if (n == 0)
			ret[buf - 1] = '0';
	}
	return (ret);
}

void	ft_rand(t_character_vars *cvars)
{
	cvars->rand = abs((1664525 * cvars->rand + 1013904223) % (2147483647));
}
