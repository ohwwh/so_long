#include "mlx.h"
#include "get_next_line.h"
#include <stdlib.h>
#include <stdio.h>
#define SPEED 4
extern char *parsing(char *map_ber);

typedef struct s_player_vars {
	void	*player_image1;
	void	*player_image2;
	void	*player_image3;
	void	*player_image4;
	void	*player_image5;
	void	*player_image6;
	void	*player_image7;
	void	*player_image8;
	int		state;
	int		*x;
	int		*y;
	int		*d;
} t_player_vars;


typedef struct	s_vars {
	void				*mlx;
	void				*win;
	t_player_vars		pvars;
	void		*tile00;
	void		*tile01;
	void		*collect;
	void		*exit;
	char		*map;
	int			width;
	int			height;
}t_vars;

int x_loc_left(int x)
{
	int	ret;

	if (!(x % 64))
		ret = x / 64;
	else
		ret = (x / 64) + 1;
		return (ret);
}

int	y_loc_over(int y)
{
	int	ret;

	y += 64;
	if (!(y % 64))
		ret = y / 64;
	else
		ret = (y / 64) + 1;
	return (ret);
}

int x_loc_right(int x)
{
	int	ret;

	ret = x / 64;
	return (ret);
}

int	y_loc_under(int y)
{
	int	ret;

	y += 64;
	ret = y / 64;
	return (ret);
}

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

void	map_draw_mini(t_vars vars, int x, int y)
{
	int	i;
	int	j;

	if (vars.map[x + y * (vars.width + 1)] == 'C')
		vars.map[x + y * (vars.width + 1)] = '0';
	j = y - 1;
	while (j < y + 2)
	{
		i = x;
		while (i < x + 2)
		{
			if (vars.map[i + j * (vars.width + 1)] != '1')
			{
				mlx_put_image_to_window(vars.mlx, vars.win, vars.tile00, i * 64, j * 64);
				if (vars.map[i + j * (vars.width + 1)] == 'C')
					mlx_put_image_to_window(vars.mlx, vars.win, vars.collect, i * 64, j * 64);
				else if (vars.map[i + j * (vars.width + 1)] == 'E')
					mlx_put_image_to_window(vars.mlx, vars.win, vars.exit, i * 64, j * 64);
				
			}
			else
				mlx_put_image_to_window(vars.mlx, vars.win, vars.tile01, i * 64, j * 64);
			i ++;
		}
		j ++;
	}
}

void	map_draw(t_vars vars)
{
	int	i;
	int	j;

	j = 0;
	while (j < vars.height)
	{
		i = 0;
		while (i < vars.width)
		{
			if (vars.map[i + j * (vars.width + 1)] != '1')
			{
				mlx_put_image_to_window(vars.mlx, vars.win, vars.tile00, i * 64, j * 64);
				if (vars.map[i + j * (vars.width + 1)] == 'P')
				{
					*(vars.pvars.x) = i * 64;
					*(vars.pvars.y) = (j - 1) * 64;
				}
				else if (vars.map[i + j * (vars.width + 1)] == 'C')
					mlx_put_image_to_window(vars.mlx, vars.win, vars.collect, i * 64, j * 64);
				else if (vars.map[i + j * (vars.width + 1)] == 'E')
					mlx_put_image_to_window(vars.mlx, vars.win, vars.exit, i * 64, j * 64);
			}
			else
				mlx_put_image_to_window(vars.mlx, vars.win, vars.tile01, i * 64, j * 64);
			i ++;
		}
		j ++;
	}
	mlx_put_image_to_window(vars.mlx, vars.win, vars.pvars.player_image1, *(vars.pvars.x), *(vars.pvars.y));
}

void	move_W(t_vars *vars, t_player_vars *cvars)
{
	static int	k;
	int i = *(cvars->x);
	int j = *(cvars->y);

	map_draw_mini(*vars, x_loc_right(i), y_loc_under(j));
	if (i > 0 && j > -64 && i < 64 * (vars->width - 1))
	{
		if (vars->map[x_loc_right(i) + (y_loc_over(j) - 1) * (vars->width + 1)] != '1')
		{
			if (!(i % 64) | vars->map[(x_loc_right(i) + 1) + (y_loc_over(j) - 1) * (vars->width + 1)] != '1')
			{
				*(cvars->y) -= SPEED;
				*(cvars->d) += SPEED;
			}
			else
			{
				*(cvars->x) -= 1;
				*(cvars->d) += 1;
			}
		}
		else if (vars->map[(x_loc_right(i) + 1) + y_loc_under(j) * (vars->width + 1)] != '1')
		{
			*(cvars->x) += 1;
			*(cvars->d) += 1;
		}	
	}
	if ((k / 15) % 2 == 0)
		mlx_put_image_to_window(vars->mlx, vars->win, cvars->player_image3, *(cvars->x), *(cvars->y));
	if ((k ++ / 15) % 2 == 1)
		mlx_put_image_to_window(vars->mlx, vars->win, cvars->player_image4, *(cvars->x), *(cvars->y));
}

void	move_A(t_vars *vars, t_player_vars *cvars)
{
	static int	k;
	int i = *(cvars->x);
	int j = *(cvars->y);

	map_draw_mini(*vars, x_loc_right(i), y_loc_under(j));
	if (i > 0 && j > -64 && j < 64 * (vars->height - 2))
	{
		if (vars->map[(x_loc_left(i) - 1) + y_loc_under(j) * (vars->width + 1)] != '1')
		{
			if (!(j % 64) | vars->map[(x_loc_left(i) - 1) + (y_loc_under(j) + 1) * (vars->width + 1)] != '1')
			{
				*(cvars->x) -= SPEED;
				*(cvars->d) += SPEED;
			}
			else
			{
				*(cvars->y) -= 1;
				*(cvars->d) += 1;
			}
					
		}
		else if (vars->map[x_loc_right(i) + (y_loc_under(j) + 1) * (vars->width + 1)] != '1')
		{
			*(cvars->y) += 1;
			*(cvars->d) += 1;
		}
		if ((k / 15) % 2 == 0)
			mlx_put_image_to_window(vars->mlx, vars->win, cvars->player_image7, *(cvars->x), *(cvars->y));
		if ((k ++ / 15) % 2 == 1)
			mlx_put_image_to_window(vars->mlx, vars->win, cvars->player_image8, *(cvars->x), *(cvars->y));
	}
}

void	move_S(t_vars *vars, t_player_vars *cvars)
{
	static int	k;
	int i = *(cvars->x);
	int j = *(cvars->y);

	map_draw_mini(*vars, x_loc_right(i), y_loc_under(j));
	if (i > 0 && i < 64 * (vars->width - 1) && j < 64 * (vars->height - 2))
	{
		if (vars->map[x_loc_right(i) + (y_loc_under(j) + 1) * (vars->width + 1)] != '1')
		{
			if (!(i % 64) | vars->map[(x_loc_right(i) + 1) + (y_loc_under(j) + 1) * (vars->width + 1)] != '1')
			{
				*(cvars->y) += SPEED;
				*(cvars->d) += SPEED;
			}	
			else
			{
				*(cvars->x) -= 1;
				*(cvars->d) += 1;
			}
		}
		else if (vars->map[(x_loc_right(i) + 1) + y_loc_under(j) * (vars->width + 1)] != '1')
		{
			*(cvars->x) += 1;
			*(cvars->d) += 1;
		}
	}
	if ((k / 15) % 2 == 0)
		mlx_put_image_to_window(vars->mlx, vars->win, cvars->player_image1, *(cvars->x), *(cvars->y));
	if ((k ++ / 15) % 2 == 1)
		mlx_put_image_to_window(vars->mlx, vars->win, cvars->player_image2, *(cvars->x), *(cvars->y));
	
}

void	move_D(t_vars *vars, t_player_vars *cvars)
{
	static int	k;
	int i = *(cvars->x);
	int j = *(cvars->y);

	map_draw_mini(*vars, x_loc_right(i), y_loc_under(j));
	if (j > -64 && i < 64 * (vars->width - 1) && j < 64 * (vars->height - 2))
	{
		if (vars->map[(x_loc_right(i) + 1) + y_loc_under(j) * (vars->width + 1)] != '1')
		{
			if (!(j % 64) | vars->map[(x_loc_right(i) + 1) + (y_loc_under(j) + 1) * (vars->width + 1)] != '1')
			{
				*(cvars->x) += SPEED;
				*(cvars->d) += SPEED;
			}
			else
			{
				*(cvars->y) -= 1;
				*(cvars->d) += 1;
			}
		}
		else if (vars->map[x_loc_right(i) + (y_loc_under(j) + 1) * (vars->width + 1)] != '1')
		{
			*(cvars->y) += 1;
			*(cvars->d) += 1;
		}
	}
	if ((k / 15) % 2 == 0)
		mlx_put_image_to_window(vars->mlx, vars->win, cvars->player_image5, *(cvars->x), *(cvars->y));
	if ((k ++ / 15) % 2 == 1)
		mlx_put_image_to_window(vars->mlx, vars->win, cvars->player_image6, *(cvars->x), *(cvars->y));
}

int key_hook_move(t_vars *vars)
{
	int i = *(vars->pvars.x);
	int j = *(vars->pvars.y);
	static int k;
	static int f = 0;

	if (vars->pvars.state == 13)
		move_W(vars, &(vars->pvars));
	else if (vars->pvars.state == 0)
		move_A(vars, &(vars->pvars));
	else if (vars->pvars.state == 1)
		move_S(vars, &(vars->pvars));
	else if (vars->pvars.state == 2)
		move_D(vars, &(vars->pvars));
	if (*(vars->pvars.d) / 64 > f)
		printf("%d\n", ++ f);
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
	int		d;

	d = 0;
	vars.pvars.d = &d;
	vars.pvars.x = &i;
	vars.pvars.y = &j;
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
	vars.pvars.player_image3 = mlx_xpm_file_to_image(vars.mlx, "asset/player_N00.xpm", &img_width, &img_height);
	vars.pvars.player_image4 = mlx_xpm_file_to_image(vars.mlx, "asset/player_N01.xpm", &img_width, &img_height);
	vars.pvars.player_image5 = mlx_xpm_file_to_image(vars.mlx, "asset/player_E00.xpm", &img_width, &img_height);
	vars.pvars.player_image6 = mlx_xpm_file_to_image(vars.mlx, "asset/player_E01.xpm", &img_width, &img_height);
	vars.pvars.player_image7 = mlx_xpm_file_to_image(vars.mlx, "asset/player_W00.xpm", &img_width, &img_height);
	vars.pvars.player_image8 = mlx_xpm_file_to_image(vars.mlx, "asset/player_W01.xpm", &img_width, &img_height);
	vars.collect = mlx_xpm_file_to_image(vars.mlx, "asset/ball.xpm", &img_width, &img_height);
	vars.exit = mlx_xpm_file_to_image(vars.mlx, "asset/ladder.xpm", &img_width, &img_height);
	map_draw(vars);
	mlx_hook(vars.win, 2, 1L<<0, key_press, &(vars.pvars));
	mlx_hook(vars.win, 3, 1L<<1, key_release, &(vars.pvars));
	mlx_loop_hook(vars.mlx, key_hook_move, &vars);
	//mlx_loop(vars.mlx);

	mlx_loop(vars.mlx);
	return (0);
}
