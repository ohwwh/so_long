#include "mlx.h"
#include <stdlib.h>

/*typedef struct s_data{
	void *img;
	char *addr;
	int bits_per_pixel;
	int line_length;
	int endian;
}t_data;*/

typedef struct	s_vars {
	void		*mlx;
	void		*win;
}t_vars;

int	key_hook(int keycode, t_vars *vars)
{
	if(keycode == 53)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	return (0);
}

int	main(void)
{
	t_vars vars;
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 500, 500, "New");
	void *image = mlx_new_image(vars.mlx, 250, 250);
	/*t_data image;
	image.img = mlx_new_image(mlx_ptr, 250, 250);
	image.addr = mlx_get_data_addr(image.img, &image.bits_per_pixel, &image.line_length, &image.endian);*/
	for (int i = 0 ; i < 250 ; i++)
	{
		for (int j = 0 ; j < 250 ; j++)
			mlx_pixel_put (vars.mlx, vars.win, i, j, 0x00FFFFFF);
	}
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
