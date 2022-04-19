#include "so_long.h"

void	move_collect(t_vars *vars, t_character_vars *cvars)
{
	const int	i = cvars->x;
	const int	j = cvars->y;

	if (vars->map[xr(i) + (yu(j)) * (vars->w + 1)] == 'C')
	{
		vars->map[xr(i) + (yu(j)) * (vars->w + 1)] = 'c';
		(vars->collect_num)--;
	}
	else if (vars->map[xl(i) + (yu(j)) * (vars->w + 1)] == 'C')
	{
		vars->map[xl(i) + (yu(j)) * (vars->w + 1)] = 'c';
		(vars->collect_num)--;
	}
	else if (vars->map[xr(i) + (yo(j)) * (vars->w + 1)] == 'C')
	{
		vars->map[xr(i) + (yo(j)) * (vars->w + 1)] = 'c';
		(vars->collect_num)--;
	}
	else if (vars->map[xl(i) + (yo(j)) * (vars->w + 1)] == 'C')
	{
		vars->map[xl(i) + (yo(j)) * (vars->w + 1)] = 'c';
		(vars->collect_num)--;
	}
}

void	move_exit(t_vars *vars, t_character_vars *cvars)
{
	const int	i = cvars->x;
	const int	j = cvars->y;

	if (vars->map[xr(i) + (yu(j)) * (vars->w + 1)] == 'E')
	{
		if (!vars->collect_num)
			vars->game_state = CLEAR;
	}
}

void	move_w(t_vars *vars, t_character_vars *cvars, int i, int j)
{
	const int	x = 64 * (vars->w - 1);

	if (j > -64)
	{
		if (vars->map[loc(xr(i), yo(j) - 1, vars)] != '1')
		{
			if (!(i % 64) | (vars->map[loc(xr(i) + 1, yo(j) - 1, vars)] != '1'))
			{
				cvars->y -= SPEED;
				cvars->d += SPEED;
			}
			else if (i > 0 && (vars->map[loc(xl(i) - 1, yo(j), vars)] != '1'))
			{
				cvars->x -= 1;
				cvars->d += 1;
			}
		}
		else if (i < x && vars->map[loc(xr(i) + 1, yo(j), vars)] != '1')
		{
			cvars->x += 1;
			cvars->d += 1;
		}	
	}
	cvars->dir = 13;
}

void	move_a(t_vars *vars, t_character_vars *cvars, int i, int j)
{
	const int	x = 64 * (vars->h - 2);

	if (i > 0)
	{
		if (vars->map[loc(xl(i) - 1, yu(j), vars)] != '1')
		{
			if (!(j % 64) | (vars->map[loc(xl(i) - 1, yu(j) + 1, vars)] != '1'))
			{
				cvars->x -= SPEED;
				cvars->d += SPEED;
			}
			else if (j > -64 && (vars->map[loc(xl(i), yo(j) - 1, vars)] != '1'))
			{
				cvars->y -= 1;
				cvars->d += 1;
			}
		}
		else if (j < x && vars->map[loc(xl(i), yu(j) + 1, vars)] != '1')
		{
			cvars->y += 1;
			cvars->d += 1;
		}
	}
	cvars->dir = 0;
}

void	move_s(t_vars *vars, t_character_vars *cvars, int i, int j)
{
	const int x = 64 * (vars->w - 1);

	if (j < 64 * (vars->h - 2))
	{
		if (vars->map[loc(xr(i), yu(j) + 1, vars)] != '1')
		{
			if (!(i % 64) | (vars->map[loc(xr(i) + 1, yu(j) + 1, vars)] != '1'))
			{
				cvars->y += SPEED;
				cvars->d += SPEED;
			}	
			else if (i > 0 && vars->map[loc(xl(i) - 1, yu(j), vars)] != '1')
			{
				cvars->x -= 1;
				cvars->d += 1;
			}
		}
		else if (i < x && vars->map[loc(xr(i) + 1, yu(j), vars)] != '1')
		{
			cvars->x += 1;
			cvars->d += 1;
		}
	}
	cvars->dir = 1;
}

void	move_d(t_vars *vars, t_character_vars *cvars, int i, int j)
{
	const int x = 64 * (vars->h - 2);
	
	if (i < 64 * (vars->w - 1))
	{
		if (vars->map[loc(xr(i) + 1, yu(j), vars)] != '1')
		{
			if (!(j % 64) | (vars->map[loc(xr(i) + 1, yu(j) + 1, vars)] != '1'))
			{
				cvars->x += SPEED;
				cvars->d += SPEED;
			}
			else if (j > -64 && vars->map[loc(xr(i), yo(j) - 1, vars)] != '1')
			{
				cvars->y -= 1;
				cvars->d += 1;
			}
		}
		else if (j < x && vars->map[loc(xr(i), yu(j) + 1, vars)] != '1')
		{
			cvars->y += 1;
			cvars->d += 1;
		}
	}
	cvars->dir = 2;
}

void	move_around(t_vars *vars, t_character_vars *cvars, int k)
{
	int	arr[4];

	arr[0] = 1;
	arr[1] = 2;
	arr[2] = 13;
	arr[3] = 0;
	if (((k / (480 / SPEED)) % 4) == 0)
		cvars->dir = arr[0];
	else if (((k / (480 / SPEED)) % 4) == 1)
		cvars->dir = arr[1];
	else if (((k / (480 / SPEED)) % 4) == 2)
		cvars->dir = arr[2];
	else if (((k / (480 / SPEED)) % 4) == 3)
		cvars->dir = arr[3];
}

void	character_move(t_vars *vars, t_character_vars *cvars, int k)
{
	if ((cvars->is_player) | (vars->game_state == INGAME))
	{
		move_collect(vars, cvars);
		move_exit(vars, cvars);
		if (cvars->state == 13)
			move_w(vars, cvars, cvars->x, cvars->y);
		else if (cvars->state == 0)
			move_a(vars, cvars, cvars->x, cvars->y);
		else if (cvars->state == 1)
			move_s(vars, cvars, cvars->x, cvars->y);
		else if (cvars->state == 2)
			move_d(vars, cvars, cvars->x, cvars->y);
		else if (cvars->state == -2 && vars->game_state == INGAME)
			move_around(vars, cvars, k);
	}
}