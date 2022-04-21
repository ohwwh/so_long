/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoh <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 15:31:37 by hoh               #+#    #+#             */
/*   Updated: 2022/04/19 15:31:38 by hoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	*ft_xpm(t_vars *vars, char *filename, int *width, int *height)
{
	void	*ret;

	ret = mlx_xpm_file_to_image(vars->mlx, filename, width, height);
	if (!ret)
	{
		printf("Error\nfail to load \"%s\"", filename);
		close_game(vars);
	}
	return (ret);
}

int	ft_img(t_vars *vars, void *img_ptr, int x, int y)
{
	return (mlx_put_image_to_window(vars->mlx, vars->win, img_ptr, x, y));
}

void	ft_mlx_init(t_vars *vars)
{
	const int	w = vars->w * 64;
	const int	h = vars->h * 64;

	vars->mlx = mlx_init();
	if (!vars->mlx)
	{
		printf("Error\nmlx_init fail\n");
		exit(0);
	}
	vars->win = mlx_new_window(vars->mlx, w, h, "New");
	if (!vars->win)
	{
		printf("Error\nmlx_new_window fail\n");
		exit(0);
	}
}
