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
	vars->mlx = mlx_init();
	if (!vars->mlx)
	{
		printf("Error\nmlx_init fail\n");
		free(vars->map);
	}
	vars->win = mlx_new_window(vars->mlx, 640, 400, "menu");
	if (!vars->win)
	{
		printf("Error\nmlx_new_window fail\n");
		free(vars->map);
		exit(0);
	}
}

void	ft_mlx_new(t_vars *vars, int x, int y, char *name)
{
	vars->win = mlx_new_window(vars->mlx, x, y, name);
	if (!vars->win)
	{
		printf("Error\nmlx_new_window fail\n");
		ft_free(vars);
		exit(0);
	}
}
