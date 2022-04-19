#include "so_long.h"
#include "get_next_line.h"

void	init_player(t_vars *vars, t_character_vars *pvars)
{
	int	w;
	int	h;

	pvars->is_player = 0;
	pvars->caught = -1;
	pvars->state = -1;
	pvars->d = 0;
	pvars->step = 0;
	pvars->dir = 1;
	pvars->img_W00 = ft_xpm(vars->mlx, "../asset/fox_W00.xpm", &w, &h);
	pvars->img_W01 = ft_xpm(vars->mlx, "../asset/fox_W01.xpm", &w, &h);
	pvars->img_W02 = ft_xpm(vars->mlx, "../asset/fox_W02.xpm", &w, &h);
	pvars->img_W03 = ft_xpm(vars->mlx, "../asset/fox_W03.xpm", &w, &h);
	pvars->img_A00 = ft_xpm(vars->mlx, "../asset/fox_A00.xpm", &w, &h);
	pvars->img_A01 = ft_xpm(vars->mlx, "../asset/fox_A01.xpm", &w, &h);
	pvars->img_A02 = ft_xpm(vars->mlx, "../asset/fox_A02.xpm", &w, &h);
	pvars->img_A03 = ft_xpm(vars->mlx, "../asset/fox_A03.xpm", &w, &h);
	pvars->img_S00 = ft_xpm(vars->mlx, "../asset/fox_S00.xpm", &w, &h);
	pvars->img_S01 = ft_xpm(vars->mlx, "../asset/fox_S01.xpm", &w, &h);
	pvars->img_S02 = ft_xpm(vars->mlx, "../asset/fox_S02.xpm", &w, &h);
	pvars->img_S03 = ft_xpm(vars->mlx, "../asset/fox_S03.xpm", &w, &h);
	pvars->img_D00 = ft_xpm(vars->mlx, "../asset/fox_D00.xpm", &w, &h);
	pvars->img_D01 = ft_xpm(vars->mlx, "../asset/fox_D01.xpm", &w, &h);
	pvars->img_D02 = ft_xpm(vars->mlx, "../asset/fox_D02.xpm", &w, &h);
	pvars->img_D03 = ft_xpm(vars->mlx, "../asset/fox_D03.xpm", &w, &h);
}

void	init_enemy(t_vars *vars, t_character_vars *evars, int n)
{
	int	w;
	int	h;

	evars->is_player = n;
	evars->caught = -1;
	evars->state = -2;
	evars->d = 0;
	evars->step = 0;
	evars->dir = 1;
	evars->img_W00 = ft_xpm(vars->mlx, "../asset/fox_W00.xpm", &w, &h);
	evars->img_W01 = ft_xpm(vars->mlx, "../asset/fox_W01.xpm", &w, &h);
	evars->img_W02 = ft_xpm(vars->mlx, "../asset/fox_W02.xpm", &w, &h);
	evars->img_W03 = ft_xpm(vars->mlx, "../asset/fox_W03.xpm", &w, &h);
	evars->img_A00 = ft_xpm(vars->mlx, "../asset/fox_A00.xpm", &w, &h);
	evars->img_A01 = ft_xpm(vars->mlx, "../asset/fox_A01.xpm", &w, &h);
	evars->img_A02 = ft_xpm(vars->mlx, "../asset/fox_A02.xpm", &w, &h);
	evars->img_A03 = ft_xpm(vars->mlx, "../asset/fox_A03.xpm", &w, &h);
	evars->img_S00 = ft_xpm(vars->mlx, "../asset/fox_S00.xpm", &w, &h);
	evars->img_S01 = ft_xpm(vars->mlx, "../asset/fox_S01.xpm", &w, &h);
	evars->img_S02 = ft_xpm(vars->mlx, "../asset/fox_S02.xpm", &w, &h);
	evars->img_S03 = ft_xpm(vars->mlx, "../asset/fox_S03.xpm", &w, &h);
	evars->img_D00 = ft_xpm(vars->mlx, "../asset/fox_D00.xpm", &w, &h);
	evars->img_D01 = ft_xpm(vars->mlx, "../asset/fox_D01.xpm", &w, &h);
	evars->img_D02 = ft_xpm(vars->mlx, "../asset/fox_D02.xpm", &w, &h);
	evars->img_D03 = ft_xpm(vars->mlx, "../asset/fox_D03.xpm", &w, &h);
}

void	create_objs_arr(t_vars *vars)
{
	int	i;
	int	n;

	vars->objs_n = count_obj(vars->map);
	n = vars->objs_n;
	vars->objs = (t_character_vars **)malloc(sizeof(t_character_vars *) * ++n);
	n --;
	vars->order_arr = (int *)malloc(sizeof(int) * n);
	i = 0;
	while (i < n)
	{
		vars->objs[i] = (t_character_vars *)malloc(sizeof(t_character_vars));
		vars->order_arr[i] = i;
		i ++;
	}
	vars->objs[i] = 0;
}	

void	init_obj(t_vars *vars)
{
	int	i;
	int	n;

	i = 1;
	create_objs_arr(vars);
	init_player(vars, vars->objs[0]);
	while (vars->objs[i])
	{
		init_enemy(vars, vars->objs[i], i);
		i ++;
	}
}

void	init(t_vars *vars)
{
	int	w;
	int	h;

	vars->game_state = INGAME;
	vars->timer = 0;
	vars->tile00 = ft_xpm(vars->mlx, "../asset/tile09.xpm", &w, &h);
	vars->tile01 = ft_xpm(vars->mlx, "../asset/tile08.xpm", &w, &h);
	vars->collect = ft_xpm(vars->mlx, "../asset/meat1.xpm", &w, &h);
	vars->exit = ft_xpm(vars->mlx, "../asset/ladder.xpm", &w, &h);
	init_obj(vars);
}
