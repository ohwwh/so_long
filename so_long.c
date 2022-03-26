#include "mlx.h"
#include "get_next_line.h"
#include <stdlib.h>
extern char *parsing(char *map_ber);
/*typedef struct s_data{
	void *img;
	char *addr;
	int bits_per_pixel;
	int line_length;
	int endian;
}t_data;*/

typedef struct s_player_vars {
	void	*player_image1;
	void	*player_image2;
	int		state;
} t_player_vars;


typedef struct	s_vars {
	void				*mlx;
	void				*win;
	t_player_vars		pvars;
	void		*tile00;
	void		*tile01;
	char		*map;
	int			width;
	int			height;
}t_vars;

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == 53)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	return (0);
}

int	key_press(int keycode, t_player_vars *pvars)
{
	if (keycode == 13)
		pvars -> state = 13;
	else if (keycode == 0)
		pvars -> state = 0;
	else if (keycode == 1)
		pvars -> state = 1;
	else if (keycode == 2)
		pvars -> state = 2;
	return (0);
}

int	key_release(int keycode, t_player_vars *pvars)
{
	if (keycode == 13)
		pvars -> state = -1;
	if (keycode == 0)
		pvars -> state = -1;
	if (keycode == 1)
		pvars -> state = -1;
	if (keycode == 2)
		pvars -> state = -1;
	return (0);
}

int key_hook_move(t_vars *vars)
{
	int		img_width;
	int		img_height;
	static int i = 64;
	static int j = 0;
	static int k;

	if (vars->pvars.state == 13)
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->tile00, i, (j / 64) * 64);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->tile00, i, ((j / 64) +1) * 64);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->tile00, i, ((j / 64) +2) * 64);
		if ((k / 15) % 2 == 0)
			mlx_put_image_to_window(vars->mlx, vars->win, vars->pvars.player_image1, i, j);
		if ((k / 15) % 2 == 1)
			mlx_put_image_to_window(vars->mlx, vars->win, vars->pvars.player_image2, i, j);
		if (j > 0 && vars->map[(i / 64) + ((j / 64) + 1) * (vars->width + 1)] != '1')
		{
			if (!(i % 64) | (vars->map[((i / 64) + 1) + ((j / 64) + 1)* (vars->width + 1)] != '1'))
				j -= 4;
		}
		k += 1;
	}
	else if (vars->pvars.state == 0)
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->tile00, (i / 64) * 64, ((j / 64) + 1) * 64);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->tile00, ((i / 64) + 1) * 64, ((j / 64) + 1) * 64);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->tile01, (i / 64) * 64, (j / 64) * 64);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->tile01, ((i / 64) + 1) * 64, (j / 64) * 64);
		if ((k / 15) % 2 == 0)
			mlx_put_image_to_window(vars->mlx, vars->win, vars->pvars.player_image1, i, j);
		if ((k / 15) % 2 == 1)
			mlx_put_image_to_window(vars->mlx, vars->win, vars->pvars.player_image2, i, j);
		if (vars->map[(i / 64) + ((j + 64) / 64) * (vars->width + 1)] != '1')
		{
			if (!((j + 64) % 64) | (vars->map[((i / 64) - 1) + ((j + 64) / 64) * (vars->width + 1)] != '1'))
				i -= 4;
		}
		k += 1;
	}
	else if (vars->pvars.state == 1)
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->tile00, i, (j / 64) * 64);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->tile00, i, ((j / 64) +1) * 64);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->tile00, i, ((j / 64) +2) * 64);
		if ((k / 15) % 2 == 0)
			mlx_put_image_to_window(vars->mlx, vars->win, vars->pvars.player_image1, i, j);
		if ((k / 15) % 2 == 1)
			mlx_put_image_to_window(vars->mlx, vars->win, vars->pvars.player_image2, i, j);
		if ((j < -64) | (vars->map[(i / 64) + ((j / 64) + 2) * (vars->width + 1)] != '1'))
		{
			if (vars->map[((i / 64) + 1) + ((j / 64) + 2) * (vars->width + 1)] != '1')
				j += 4;
		}
		k += 1;
	}
	else if (vars->pvars.state == 2)
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->tile00, (i / 64) * 64, ((j / 64) + 1) * 64);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->tile00, ((i / 64) - 1) * 64, ((j / 64) + 1) * 64);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->tile01, (i / 64) * 64, (j / 64) * 64);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->tile01, ((i / 64) - 1) * 64, (j / 64) * 64);
		if ((k / 15) % 2 == 0)
			mlx_put_image_to_window(vars->mlx, vars->win, vars->pvars.player_image1, i, j);
		if ((k / 15) % 2 == 1)
			mlx_put_image_to_window(vars->mlx, vars->win, vars->pvars.player_image2, i, j);
		if (vars->map[((i / 64) + 2) + ((j / 64) + 2) * (vars->width + 1)] != '1')
		{
			if (vars->map[((i / 64) + 2) + ((j / 64) + 3) * (vars->width + 1)] != '1')
				i += 4;
		}
		k += 1;
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	t_vars	vars;
	int		width;
	int		height;
	int		img_width;
	int		img_height;
	int		i;
	int		j;

	j = 0;
	vars.pvars.state = -1;
	vars.map = parsing(argv[1]);
	vars.width = ft_strnlen(vars.map) - 1;
	vars.height = (ft_strlen(vars.map) + 1) / (vars.width + 1); //주어지는 맵의 마지막에 개행이 붙나??
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, vars.width * 64, vars.height * 64, "New"); 
	vars.tile00 = mlx_xpm_file_to_image(vars.mlx, "asset/tile00.xpm", &img_width, &img_height);
	vars.tile01 = mlx_xpm_file_to_image(vars.mlx, "asset/tile01.xpm", &img_width, &img_height);
	vars.pvars.player_image1 = mlx_xpm_file_to_image(vars.mlx, "asset/player_S00.xpm", &img_width, &img_height);
	vars.pvars.player_image2 = mlx_xpm_file_to_image(vars.mlx, "asset/player_S01.xpm", &img_width, &img_height);
	void *collect = mlx_xpm_file_to_image(vars.mlx, "asset/ball.xpm", &img_width, &img_height);
	void *exit = mlx_xpm_file_to_image(vars.mlx, "asset/ladder.xpm", &img_width, &img_height);
	while (j < vars.height)
	{
		i = 0;
		while (i < vars.width)
		{
			if (vars.map[i + j * (vars.width + 1)] != '1')
			{
				mlx_put_image_to_window(vars.mlx, vars.win, vars.tile00, i * 64, j * 64);
				if (vars.map[i + j * (vars.width + 1)] == 'P')
					mlx_put_image_to_window(vars.mlx, vars.win, vars.pvars.player_image1, i * 64, j * 64);
				else if (vars.map[i + j * (vars.width + 1)] == 'C')
					mlx_put_image_to_window(vars.mlx, vars.win, collect, i * 64, j * 64);
				else if (vars.map[i + j * (vars.width + 1)] == 'E')
					mlx_put_image_to_window(vars.mlx, vars.win, exit, i * 64, j * 64);
				
			}
			else
				mlx_put_image_to_window(vars.mlx, vars.win, vars.tile01, i * 64, j * 64);
			i ++;
		}
		j ++;
	}
	mlx_hook(vars.win, 2, 1L<<0, key_press, &(vars.pvars));
	mlx_hook(vars.win, 3, 1L<<1, key_release, &(vars.pvars));
	mlx_loop_hook(vars.mlx, key_hook_move, &vars);
	//mlx_loop(vars.mlx);

	mlx_loop(vars.mlx);
	return (0);
}
