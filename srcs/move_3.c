#include "so_long.h"

void	move_wd(t_vars *vars, t_character_vars *cvars)
{
	move_w(vars, cvars, cvars->x, cvars->y);
	move_d(vars, cvars, cvars->x, cvars->y);
	cvars->d -= 2;
}

void	move_wa(t_vars *vars, t_character_vars *cvars)
{
	move_w(vars, cvars, cvars->x, cvars->y);
	move_a(vars, cvars, cvars->x, cvars->y);
	cvars->d -= 2;
}

void	move_sd(t_vars *vars, t_character_vars *cvars)
{
	move_s(vars, cvars, cvars->x, cvars->y);
	move_d(vars, cvars, cvars->x, cvars->y);
	cvars->d -= 3;
}

void	move_sa(t_vars *vars, t_character_vars *cvars)
{
	move_s(vars, cvars, cvars->x, cvars->y);
	move_a(vars, cvars, cvars->x, cvars->y);
	cvars->d -= 3;
}