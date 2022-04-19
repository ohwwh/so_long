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

int	map_check_comp(char *map, t_vars *vars)
{
	int	check_p;
	int	check_e;

	check_p = 0;
	check_e = 0;
	vars->collect_num = 0;
	while (*map)
	{
		if (*map == 'C')
			vars->collect_num ++;
		else if (*map == 'P')
			(check_p)++;
		else if (*map == 'E')
			(check_e)++;
		map ++;
	}
	if (!check_p | !check_e | !vars->collect_num)
		return (1);
	return (0);
}

int	map_check_surr(char *map, t_vars *vars)
{
	int	width;
	int	h;

	h = 0;
	while (*map)
	{
		if (*map != '1')
			return (1);
		width = 0;
		while (*map != '\n' && *map)
		{
			if (((!h) | (h == vars->h - 1)) && *map != '1')
				return (1);
			map ++;
			width ++;
		}
		if (vars->w != width | *(map - 1) != '1')
			return (1);
		if (*map)
			break ;
		map ++;
		h ++;
	}
	return (0);
}

void	map_check(char *map, t_vars *vars)
{
	if (map_check_comp(map, vars) == 1)
	{
		printf("Error\n맵에 필요한 요소가 부족합니다\n");
		exit(0);
	}
	else if (map_check_surr(map, vars) == 1)
	{
		printf("Error\n맵이 직사각형이 아니거나, 벽으로 둘러쌓여 있지 않습니다\n");
		exit(0);
	}
}
