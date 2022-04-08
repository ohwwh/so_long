#ifndef SO_LONG_H
# define SO_LONG_H
# include "mlx.h"
# include <unistd.h>
# include <stdlib.h>
#include <stdio.h>
# define SPEED 4
# define INGAME 1
# define DEATH 2

typedef struct s_character_vars {
	void	*character_image1;
	void	*character_image2;
	void	*character_image3;
	void	*character_image4;
	void	*character_image5;
	void	*character_image6;
	void	*character_image7;
	void	*character_image8;
	int		is_player;
	int		state;
	int		dir;
	int		x;
	int		y;
	int		d;
} t_character_vars;


typedef struct	s_vars {
	void				*mlx;
	void				*win;
	int					game_state;
	t_character_vars		**objs;
	int                     *order_arr;
	int						objs_n;
	void		*tile00;
	void		*tile01;
	void		*collect;
	void		*exit;
	char		*map;
	int			width;
	int			height;
	int			collect_num;
}t_vars;

char *parsing(char *map_ber);
int	abs(int x);
int x_loc_left(int x);
int	y_loc_over(int y);
int x_loc_right(int x);
int	y_loc_under(int y);
int	close_game(t_vars *vars);
int	count_obj(char *map);
int key_hook_move(t_vars *vars);
int	key_hook(int keycode, t_vars *vars);
int	key_press(int keycode, t_vars *vars);
int	key_release(int keycode, t_vars *vars);
void	enemy_search(t_vars *vars);
void	map_draw_mini(t_vars *vars, int x, int y);
void	map_draw(t_vars *vars);
void	character_draw(t_vars *vars, t_character_vars *cvars);
void	objs_draw(t_vars *vars);
void	step_draw(t_vars *vars);
void	move_W(t_vars *vars, t_character_vars *cvars);
void	move_A(t_vars *vars, t_character_vars *cvars);
void	move_S(t_vars *vars, t_character_vars *cvars);
void	move_D(t_vars *vars, t_character_vars *cvars);
void	move_around(t_vars *vars, t_character_vars *cvars);
void	character_move(t_vars *vars, t_character_vars *cvars);
void    ft_free(t_vars *vars);
void    init_obj(t_vars *vars);
void    init_player(t_vars *vars, t_character_vars *pvars);
void    init_enemy(t_vars *vars, t_character_vars *pvars, int n);
void    init(t_vars *vars);
void 	sort(int list[], int n, t_character_vars **objs);

#endif