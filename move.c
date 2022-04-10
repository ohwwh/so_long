#include "so_long.h"

void	move_W(t_vars *vars, t_character_vars *cvars)
{
	int i = cvars->x;
	int j = cvars->y;

	if (j > -64)
	{
		if (vars->map[x_loc_right(i) + (y_loc_over(j) - 1) * (vars->width + 1)] != '1')
		{
			if (!(i % 64) | (vars->map[(x_loc_right(i) + 1) + (y_loc_over(j) - 1) * (vars->width + 1)] != '1'))
			{
				cvars->y -= SPEED;
				cvars->d += SPEED;
			}
			else if (i > 0 && (vars->map[(x_loc_left(i) - 1) + y_loc_over(j) * (vars->width + 1)] != '1'))
			{
				cvars->x -= 1;
				cvars->d += 1;
			}
		}
		else if (i < 64 * (vars->width - 1) && vars->map[(x_loc_right(i) + 1) + (y_loc_over(j)) * (vars->width + 1)] != '1')
		{
			cvars->x += 1;
			cvars->d += 1;
		}	
	}
	cvars->dir = 13;
	if (!cvars->is_player)
	{
		i = all_enemy_touch(vars);
		if (i)
		{
			vars->game_state = CHASE;
			vars->objs[i]->dir = 1;
			cvars->caught = vars->objs[i]->is_player;
		}
	}
}

void	move_A(t_vars *vars, t_character_vars *cvars)
{
	int i = cvars->x;
	int j = cvars->y;

	if (i > 0)
	{
		if (vars->map[(x_loc_left(i) - 1) + y_loc_under(j) * (vars->width + 1)] != '1')
		{
			if (!(j % 64) | (vars->map[(x_loc_left(i) - 1) + (y_loc_under(j) + 1) * (vars->width + 1)] != '1'))
			{
				cvars->x -= SPEED;
				cvars->d += SPEED;
			}
			else if (j > -64 && (vars->map[x_loc_left(i) + (y_loc_over(j) - 1) * (vars->width + 1)] != '1'))
			{
				cvars->y -= 1;
				cvars->d += 1;
			}
					
		}
		else if (j < 64 * (vars->height - 2) && vars->map[x_loc_left(i) + (y_loc_under(j) + 1) * (vars->width + 1)] != '1')
		{
			cvars->y += 1;
			cvars->d += 1;
		}
	}
	cvars->dir = 0;
	if (!cvars->is_player)
	{
		i = all_enemy_touch(vars);
		if (i)
		{
			vars->game_state = CHASE;
			vars->objs[i]->dir = 2;
			cvars->caught = vars->objs[i]->is_player;
		}
	}
}

void	move_S(t_vars *vars, t_character_vars *cvars)
{
	int i = cvars->x;
	int j = cvars->y;

	if (j < 64 * (vars->height - 2))
	{
		if (vars->map[x_loc_right(i) + (y_loc_under(j) + 1) * (vars->width + 1)] != '1')
		{
			if (!(i % 64) | (vars->map[(x_loc_right(i) + 1) + (y_loc_under(j) + 1) * (vars->width + 1)] != '1'))
			{
				cvars->y += SPEED;
				cvars->d += SPEED;
			}	
			else if (i > 0 && vars->map[(x_loc_left(i) - 1) + y_loc_under(j) * (vars->width + 1)] != '1')
			{
				cvars->x -= 1;
				cvars->d += 1;
			}
		}
		else if (i < 64 * (vars->width - 1) && vars->map[(x_loc_right(i) + 1) + y_loc_under(j) * (vars->width + 1)] != '1')
		{
			cvars->x += 1;
			cvars->d += 1;
		}
	}
	cvars->dir = 1;
	if (!cvars->is_player)
	{
		i = all_enemy_touch(vars);
		if (i)
		{
			vars->game_state = CHASE;
			vars->objs[i]->dir = 13;
			cvars->caught = vars->objs[i]->is_player;
		}
	}
}

void	move_D(t_vars *vars, t_character_vars *cvars)
{
	int i = cvars->x;
	int j = cvars->y;

	if (vars->map[(x_loc_right(i) + 1) + y_loc_under(j) * (vars->width + 1)] == 'C')
	{
		vars->map[(x_loc_right(i) + 1) + y_loc_under(j) * (vars->width + 1)] = 'c';
		(vars->collect_num) --;
	}
	if (i < 64 * (vars->width - 1))
	{
		if (vars->map[(x_loc_right(i) + 1) + y_loc_under(j) * (vars->width + 1)] != '1')
		{
			if (!(j % 64) | (vars->map[(x_loc_right(i) + 1) + (y_loc_under(j) + 1) * (vars->width + 1)] != '1'))
			{
				cvars->x += SPEED;
				cvars->d += SPEED;
			}
			else if (j > -64 && vars->map[x_loc_right(i) + (y_loc_over(j) - 1) * (vars->width + 1)] != '1')
			{
				cvars->y -= 1;
				cvars->d += 1;
			}
		}
		else if (j < 64 * (vars->height - 2) && vars->map[x_loc_right(i) + (y_loc_under(j) + 1) * (vars->width + 1)] != '1')
		{
			cvars->y += 1;
			cvars->d += 1;
		}
	}
	cvars->dir = 2;
	if (!cvars->is_player)
	{
		i = all_enemy_touch(vars);
		if (i)
		{
			vars->game_state = CHASE;
			vars->objs[i]->dir = 0;
			cvars->caught = vars->objs[i]->is_player;
		}
	}
}

void	move_around(t_vars *vars, t_character_vars *cvars, int k)
{
	if (((k / 130) % 4) == 0)
		cvars->dir = 1;
	else if (((k / 130) % 4) == 1)
		cvars->dir = 2;
	else if (((k / 130) % 4) == 2)
		cvars->dir = 13;
	else if (((k / 130) % 4) == 3)
		cvars->dir = 0;
}

void	character_move(t_vars *vars, t_character_vars *cvars, int k)
{
	if ((cvars->is_player) | (vars->game_state == INGAME))
	{
		if (cvars->state == 13)
			move_W(vars, cvars);
		else if (cvars->state == 0)
			move_A(vars, cvars);
		else if (cvars->state == 1)
			move_S(vars, cvars);
		else if (cvars->state == 2)
			move_D(vars, cvars);
		else if (cvars->state == -2 && vars->game_state == INGAME)
			move_around(vars, cvars, k);
	}
}