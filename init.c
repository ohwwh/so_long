#include "so_long.h"
#include "get_next_line.h"

int	count_obj(char *map)
{
	int	ret;

	ret = 0;
	while (*map)
	{
		if (*map == 'P' | *map == 'R')
			ret ++;
		map ++;
	}
	return (ret);
}

void    init_player(t_vars *vars, t_character_vars *pvars)
{
    int img_width;
    int img_height;
    
    pvars->is_player = 0;
    pvars->state = -1;
    pvars->d = 0;
    pvars->dir = 1;
    pvars->character_image1 = mlx_xpm_file_to_image(vars->mlx, "asset/player_S00.xpm", &img_width, &img_height);
	pvars->character_image2 = mlx_xpm_file_to_image(vars->mlx, "asset/player_S01.xpm", &img_width, &img_height);
	pvars->character_image3 = mlx_xpm_file_to_image(vars->mlx, "asset/player_N00.xpm", &img_width, &img_height);
	pvars->character_image4 = mlx_xpm_file_to_image(vars->mlx, "asset/player_N01.xpm", &img_width, &img_height);
	pvars->character_image5 = mlx_xpm_file_to_image(vars->mlx, "asset/player_E00.xpm", &img_width, &img_height);
	pvars->character_image6 = mlx_xpm_file_to_image(vars->mlx, "asset/player_E01.xpm", &img_width, &img_height);
	pvars->character_image7 = mlx_xpm_file_to_image(vars->mlx, "asset/player_W00.xpm", &img_width, &img_height);
	pvars->character_image8 = mlx_xpm_file_to_image(vars->mlx, "asset/player_W01.xpm", &img_width, &img_height);
}

void    init_enemy(t_vars *vars, t_character_vars *evars, int n)
{
    int img_width;
    int img_height;
    
    evars->is_player = n;
    evars->state = -2;
    evars->d = 0;
    evars->dir = 1;
    evars->character_image1 = mlx_xpm_file_to_image(vars->mlx, "asset/rocket_S00.xpm", &img_width, &img_height);
	evars->character_image2 = mlx_xpm_file_to_image(vars->mlx, "asset/rocket_S00.xpm", &img_width, &img_height);
	evars->character_image3 = mlx_xpm_file_to_image(vars->mlx, "asset/rocket_N00.xpm", &img_width, &img_height);
	evars->character_image4 = mlx_xpm_file_to_image(vars->mlx, "asset/rocket_N00.xpm", &img_width, &img_height);
	evars->character_image5 = mlx_xpm_file_to_image(vars->mlx, "asset/rocket_E00.xpm", &img_width, &img_height);
	evars->character_image6 = mlx_xpm_file_to_image(vars->mlx, "asset/rocket_E00.xpm", &img_width, &img_height);
	evars->character_image7 = mlx_xpm_file_to_image(vars->mlx, "asset/rocket_W00.xpm", &img_width, &img_height);
	evars->character_image8 = mlx_xpm_file_to_image(vars->mlx, "asset/rocket_W00.xpm", &img_width, &img_height);
}

void    init_obj(t_vars *vars)
{
    int i;
    int n;

    vars->objs_n = count_obj(vars->map);
	n = vars->objs_n;
	vars->objs = (t_character_vars **)malloc(sizeof(t_character_vars *) * (n + 1));
    vars->order_arr = (int *)malloc(sizeof(int) * n);
	i = 0;
	while (i < n)
	{
		vars->objs[i] = (t_character_vars *)malloc(sizeof(t_character_vars));
        vars->order_arr[i] = i;
		i ++;
	}
	vars->objs[i] = 0;
    i = 1;
    init_player(vars, vars->objs[0]);
    while (vars->objs[i])
    {
        init_enemy(vars, vars->objs[i], i);
        i ++;
    }
        
}

void    init(t_vars *vars)
{
    int img_width;
    int img_height;

    vars->game_state = INGAME;
	vars->collect_num = 0;
    vars->tile00 = mlx_xpm_file_to_image(vars->mlx, "asset/tile00.xpm", &img_width, &img_height);
	vars->tile01 = mlx_xpm_file_to_image(vars->mlx, "asset/tile01.xpm", &img_width, &img_height);
    vars->collect = mlx_xpm_file_to_image(vars->mlx, "asset/ball.xpm", &img_width, &img_height);
	vars->exit = mlx_xpm_file_to_image(vars->mlx, "asset/ladder.xpm", &img_width, &img_height);
    init_obj(vars);
}