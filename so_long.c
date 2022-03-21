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

typedef struct	s_vars {
	void		*mlx;
	void		*win;
	void		*player;
	void		*player1;
	void		*tile01;
	int			state;
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

int	key_press(int keycode, t_vars *vars)
{
	if (keycode == 1)
	{
		vars -> state = 1;
	}
	return (0);
}

int	key_release(int keycode, t_vars *vars)
{
	if (keycode == 1)
	{
		vars -> state = 0;
	}
	return (0);
}

int key_hook_move(t_vars *vars)
{
	void	*temp;
	int		img_width;
	int		img_height;
	static int i, j, k;

	
	if (vars -> state == 1)
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->tile01, i, (j / 64) * 64);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->tile01, i, ((j / 64) +1) * 64);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->tile01, i, ((j / 64) +2) * 64);
		if ((k / 15) % 2 == 0)
			mlx_put_image_to_window(vars->mlx, vars->win, vars->player, i, j);
		if ((k / 15) % 2 == 1)
			mlx_put_image_to_window(vars->mlx, vars->win, vars->player1, i, j);
		j += 3;
		k += 1;
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	t_vars	vars;
	char	*map;
	int		width;
	int		height;
	int		img_width;
	int		img_height;
	int		i;
	int		j;

	j = 0;
	map = parsing(argv[1]);
	width = ft_strnlen(map) - 1;
	height = ft_strlen(map) / (width + 1); //주어지는 맵의 마지막에 개행이 붙나??
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, width * 64, height * 64, "New");
	vars.state = 0;
	void *tile00 = mlx_xpm_file_to_image(vars.mlx, "asset/tile00.xpm", &img_width, &img_height);
	vars.tile01 = mlx_xpm_file_to_image(vars.mlx, "asset/tile01.xpm", &img_width, &img_height);
	vars.player = mlx_xpm_file_to_image(vars.mlx, "asset/player_S00.xpm", &img_width, &img_height);
	vars.player1 = mlx_xpm_file_to_image(vars.mlx, "asset/player_S01.xpm", &img_width, &img_height);
	void *collect = mlx_xpm_file_to_image(vars.mlx, "asset/ball.xpm", &img_width, &img_height);
	void *exit = mlx_xpm_file_to_image(vars.mlx, "asset/ladder.xpm", &img_width, &img_height);
	while (j < height)
	{
		i = 0;
		while (i < width)
		{
			if (map[i + j * (width + 1)] != '1')
			{
				mlx_put_image_to_window(vars.mlx, vars.win, tile00, i * 64, j * 64);
				if (map[i + j * (width + 1)] == 'P')
					mlx_put_image_to_window(vars.mlx, vars.win, vars.player, i * 64, j * 64);
				else if (map[i + j * (width + 1)] == 'C')
					mlx_put_image_to_window(vars.mlx, vars.win, collect, i * 64, j * 64);
				else if (map[i + j * (width + 1)] == 'E')
					mlx_put_image_to_window(vars.mlx, vars.win, exit, i * 64, j * 64);
				
			}
			else
				mlx_put_image_to_window(vars.mlx, vars.win, vars.tile01, i * 64, j * 64);
			i ++;
		}
		j ++;
	}
	mlx_hook(vars.win, 2, 1L<<0, key_press, &vars);
	mlx_hook(vars.win, 3, 1L<<1, key_release, &vars);
	mlx_loop_hook(vars.mlx, key_hook_move, &vars);

	mlx_loop(vars.mlx);
	return (0);
}
