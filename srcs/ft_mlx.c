#include "so_long.h"

void	*ft_xpm(void *mlx_ptr, char *filename, int *width, int *height)
{
	return (mlx_xpm_file_to_image(mlx_ptr, filename, width, height));
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