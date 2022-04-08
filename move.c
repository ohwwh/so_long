#include "so_long.h"

void	move_W(t_vars *vars, t_character_vars *cvars)
{
	static int	k;
	int i = cvars->x;
	int j = cvars->y;

	if (j > -64)
	{
		if (vars->map[x_loc_right(i) + (y_loc_over(j) - 1) * (vars->width + 1)] != '1' && vars->map[x_loc_right(i) + (y_loc_over(j) - 1) * (vars->width + 1)] != 'R')
		{
			if (!(i % 64) | (vars->map[(x_loc_right(i) + 1) + (y_loc_over(j) - 1) * (vars->width + 1)] != '1' && vars->map[(x_loc_right(i) + 1) + (y_loc_over(j) - 1) * (vars->width + 1)] != 'R'))
			{
				cvars->y -= SPEED;
				cvars->d += SPEED;
			}
			else if (i > 0 && (vars->map[(x_loc_left(i) - 1) + y_loc_over(j) * (vars->width + 1)] != '1' && vars->map[(x_loc_left(i) + 1) + y_loc_over(j) * (vars->width + 1)] != 'R'))
			{
				cvars->x -= 1;
				cvars->d += 1;
			}
		}
		else if (i < 64 * (vars->width - 1) && vars->map[(x_loc_right(i) + 1) + (y_loc_over(j)) * (vars->width + 1)] != '1' && vars->map[(x_loc_right(i) + 1) + y_loc_over(j) * (vars->width + 1)] != 'R')
		{
			cvars->x += 1;
			cvars->d += 1;
		}	
	}
	cvars->dir = 13;
}

void	move_A(t_vars *vars, t_character_vars *cvars)
{
	static int	k;
	int i = cvars->x;
	int j = cvars->y;

	if (i > 0)
	{
		if (vars->map[(x_loc_left(i) - 1) + y_loc_under(j) * (vars->width + 1)] != '1' && vars->map[(x_loc_left(i) - 1) + y_loc_under(j) * (vars->width + 1)] != 'R')
		{
			if (!(j % 64) | (vars->map[(x_loc_left(i) - 1) + (y_loc_under(j) + 1) * (vars->width + 1)] != '1' && vars->map[(x_loc_left(i) - 1) + (y_loc_under(j) + 1) * (vars->width + 1)] != 'R'))
			{
				cvars->x -= SPEED;
				cvars->d += SPEED;
			}
			else if (j > -64 && (vars->map[x_loc_left(i) + (y_loc_over(j) - 1) * (vars->width + 1)] != '1' && vars->map[x_loc_left(i) + (y_loc_over(j) - 1) * (vars->width + 1)] != 'R'))
			{
				cvars->y -= 1;
				cvars->d += 1;
			}
					
		}
		else if (j < 64 * (vars->height - 2) && vars->map[x_loc_left(i) + (y_loc_under(j) + 1) * (vars->width + 1)] != '1' && vars->map[x_loc_left(i) + (y_loc_under(j) + 1) * (vars->width + 1)] != 'R')
		{
			cvars->y += 1;
			cvars->d += 1;
		}
	}
	cvars->dir = 0;
}

void	move_S(t_vars *vars, t_character_vars *cvars)
{
	static int	k;
	int i = cvars->x;
	int j = cvars->y;

	if (j < 64 * (vars->height - 2))
	{
		if (vars->map[x_loc_right(i) + (y_loc_under(j) + 1) * (vars->width + 1)] != '1' && vars->map[x_loc_right(i) + (y_loc_under(j) + 1) * (vars->width + 1)] != 'R')
		{
			if (!(i % 64) | (vars->map[(x_loc_right(i) + 1) + (y_loc_under(j) + 1) * (vars->width + 1)] != '1' && vars->map[(x_loc_right(i) + 1) + (y_loc_under(j) + 1) * (vars->width + 1)] != 'R'))
			{
				cvars->y += SPEED;
				cvars->d += SPEED;
			}	
			else if (i > 0 && vars->map[(x_loc_left(i) - 1) + y_loc_under(j) * (vars->width + 1)] != '1' && vars->map[(x_loc_left(i) - 1) + y_loc_under(j) * (vars->width + 1)] != 'R')
			{
				cvars->x -= 1;
				cvars->d += 1;
			}
		}
		else if (i < 64 * (vars->width - 1) && vars->map[(x_loc_right(i) + 1) + y_loc_under(j) * (vars->width + 1)] != '1' && vars->map[(x_loc_right(i) + 1) + y_loc_under(j) * (vars->width + 1)] != 'R')
		{
			cvars->x += 1;
			cvars->d += 1;
		}
	}
	cvars->dir = 1;
}

void	move_D(t_vars *vars, t_character_vars *cvars)
{
	static int	k;
	int i = cvars->x;
	int j = cvars->y;

	if (i < 64 * (vars->width - 1))
	{
		if (vars->map[(x_loc_right(i) + 1) + y_loc_under(j) * (vars->width + 1)] != '1' && vars->map[(x_loc_right(i) + 1) + y_loc_under(j) * (vars->width + 1)] != 'R')
		{
			if (!(j % 64) | (vars->map[(x_loc_right(i) + 1) + (y_loc_under(j) + 1) * (vars->width + 1)] != '1' && vars->map[(x_loc_right(i) + 1) + (y_loc_under(j) + 1) * (vars->width + 1)] != 'R'))
			{
				cvars->x += SPEED;
				cvars->d += SPEED;
			}
			else if (j > -64 && vars->map[x_loc_right(i) + (y_loc_over(j) - 1) * (vars->width + 1)] != '1' && vars->map[x_loc_right(i) + (y_loc_over(j) - 1) * (vars->width + 1)] != 'R')
			{
				cvars->y -= 1;
				cvars->d += 1;
			}
		}
		else if (j < 64 * (vars->height - 2) && vars->map[x_loc_right(i) + (y_loc_under(j) + 1) * (vars->width + 1)] != '1' && vars->map[x_loc_right(i) + (y_loc_over(j) + 1) * (vars->width + 1)] != 'R')
		{
			cvars->y += 1;
			cvars->d += 1;
		}
	}
	cvars->dir = 2;
}

void	move_around(t_vars *vars, t_character_vars *cvars)
{
	static int	k;

	if (((k / 130) % 4) == 0)
		cvars->dir = 1;
	else if (((k / 130) % 4) == 1)
		cvars->dir = 2;
	else if (((k / 130) % 4) == 2)
		cvars->dir = 13;
	else if (((k / 130) % 4) == 3)
		cvars->dir = 0;
	k ++;
}

void	character_move(t_vars *vars, t_character_vars *cvars)
{
	if (cvars->state == 13)
		move_W(vars, cvars);
	else if (cvars->state == 0)
		move_A(vars, cvars);
	else if (cvars->state == 1)
		move_S(vars, cvars);
	else if (cvars->state == 2)
		move_D(vars, cvars);
	else if (cvars->state == -2)
		move_around(vars, cvars);
}