#include "so_long.h"

void	character_draw_w(t_vars *vars, t_character_vars *cvars, int k)
{
	if ((k / (60 / SPEED)) % 4 == 0)
		ft_img(vars, cvars->img_W00, cvars->x, cvars->y);
	else if ((k / (60 / SPEED)) % 4 == 1)
		ft_img(vars, cvars->img_W01, cvars->x, cvars->y);
	else if ((k / (60 / SPEED)) % 4 == 2)
		ft_img(vars, cvars->img_W02, cvars->x, cvars->y);
	else if ((k / (60 / SPEED)) % 4 == 3)
		ft_img(vars, cvars->img_W03, cvars->x, cvars->y);
}

void	character_draw_a(t_vars *vars, t_character_vars *cvars, int k)
{
	if ((k / (60 / SPEED)) % 4 == 0)
		ft_img(vars, cvars->img_A00, cvars->x, cvars->y);
	else if ((k / (60 / SPEED)) % 4 == 1)
		ft_img(vars, cvars->img_A01, cvars->x, cvars->y);
	else if ((k / (60 / SPEED)) % 4 == 2)
		ft_img(vars, cvars->img_A02, cvars->x, cvars->y);
	else if ((k / (60 / SPEED)) % 4 == 3)
		ft_img(vars, cvars->img_A03, cvars->x, cvars->y);
}

void	character_draw_s(t_vars *vars, t_character_vars *cvars, int k)
{
	if ((k / (60 / SPEED)) % 4 == 0)
		ft_img(vars, cvars->img_S00, cvars->x, cvars->y);
	else if ((k / (60 / SPEED)) % 4 == 1)
		ft_img(vars, cvars->img_S01, cvars->x, cvars->y);
	else if ((k / (60 / SPEED)) % 4 == 2)
		ft_img(vars, cvars->img_S02, cvars->x, cvars->y);
	else if ((k / (60 / SPEED)) % 4 == 3)
		ft_img(vars, cvars->img_S03, cvars->x, cvars->y);
}

void	character_draw_d(t_vars *vars, t_character_vars *cvars, int k)
{
	if ((k / (60 / SPEED)) % 4 == 0)
		ft_img(vars, cvars->img_D00, cvars->x, cvars->y);
	else if ((k / (60 / SPEED)) % 4 == 1)
		ft_img(vars, cvars->img_D01, cvars->x, cvars->y);
	else if ((k / (60 / SPEED)) % 4 == 2)
		ft_img(vars, cvars->img_D02, cvars->x, cvars->y);
	else if ((k / (60 / SPEED)) % 4 == 3)
		ft_img(vars, cvars->img_D03, cvars->x, cvars->y);
}

void	character_draw(t_vars *vars, t_character_vars *cvars, int k)
{
	if (cvars->state == -1 | cvars->state == -2)
		k = 0;
	else if (!cvars->is_player && vars->game_state == CHASE)
		k = 0;
	if (cvars->dir == 13)
		character_draw_w(vars, cvars, k);
	else if (cvars->dir == 0)
		character_draw_a(vars, cvars, k);
	else if (cvars->dir == 1)
		character_draw_s(vars, cvars, k);
	else if (cvars->dir == 2)
		character_draw_d(vars, cvars, k);
}
