#ifndef SO_LONG_H
# define SO_LONG_H
# include "mlx.h"
# include <unistd.h>
# include <stdlib.h>
#include <stdio.h>
# define SPEED 4
# define INGAME 1
# define CHASE 2
# define DEATH 3
# define CLEAR 5


//state 13 0 1 2 방향으로 이동중 -1 대기중 -2 사주경계중

typedef struct s_character_vars {
	void	*img_W00;
	void	*img_W01;
	void	*img_W02;
	void	*img_W03;
	void	*img_A00;
	void	*img_A01;
	void	*img_A02;
	void	*img_A03;
	void	*img_S00;
	void	*img_S01;
	void	*img_S02;
	void	*img_S03;
	void	*img_D00;
	void	*img_D01;
	void	*img_D02;
	void	*img_D03;
	int		is_player;
	int		caught;
	int		state;
	int		dir;
	int		collecting;
	int		x;
	int		y;
	int		d;
	int		step;
} t_character_vars;


typedef struct	s_vars 
{
	void					*mlx;
	void					*win;
	int						game_state;
	t_character_vars		**objs;
	int                     *order_arr;
	int						objs_n;
	void					*tile00;
	void					*tile01;
	void					*collect;
	void					*exit;
	char					*map;
	int						w;
	int						h;
	int						collect_num;
	int						timer;
}t_vars;

char 	*parsing(char *map_ber);
int		abs(int x);
int		xl(int x);
int		yo(int y);
int		xr(int x);
int		yu(int y);
int		loc(int x, int y, t_vars *vars);
int		close_game(t_vars *vars);
int		count_obj(char *map);
int		key_hook_move(t_vars *vars);
int		key_hook(int keycode, t_vars *vars);
int		key_press(int keycode, t_vars *vars);
int		key_release(int keycode, t_vars *vars);
void 	*ft_xpm(void *mlx_ptr, char *filename, int *width, int *height);
int		ft_img(t_vars *vars, void *img_ptr, int x, int y);
void	enemy_search(t_vars *vars, t_character_vars *evars);
void    all_enemies_search(t_vars *vars);
void 	enemy_touch(t_vars *vars, int i);
int 	all_enemy_touch(t_vars *vars);
int 	enemy_search_W(t_vars *vars, t_character_vars *evars, int x, int y);
int 	enemy_search_A(t_vars *vars, t_character_vars *evars, int x, int y);
int 	enemy_search_S(t_vars *vars, t_character_vars *evars, int x, int y);
int 	enemy_search_D(t_vars *vars, t_character_vars *evars, int x, int y);
int		enemy_search_touch(t_vars *vars, int i);
void	map_draw_m(t_vars *vars, int x, int y);
void	map_draw(t_vars *vars);
void	map_draw_2(t_vars *vars, int i, int j, int n);
int 	map_check_comp(char *map, t_vars *vars);
int 	map_check_surr(char *map, t_vars *vars);
void    map_check(char *map, t_vars *vars);
void	character_draw(t_vars *vars, t_character_vars *cvars, int k);
void 	character_draw_well(t_vars *vars, t_character_vars *cvars);
void	character_draw_w(t_vars *vars, t_character_vars *cvars, int k);
void	character_draw_a(t_vars *vars, t_character_vars *cvars, int k);
void	character_draw_s(t_vars *vars, t_character_vars *cvars, int k);
void	character_draw_d(t_vars *vars, t_character_vars *cvars, int k);
void	objs_draw(t_vars *vars);
void	step_draw(t_vars *vars);
void	move_collect(t_vars *vars, t_character_vars *cvars);
void	move_exit(t_vars *vars, t_character_vars *cvars);
void	move_w(t_vars *vars, t_character_vars *cvars, int i, int j);
void	move_a(t_vars *vars, t_character_vars *cvars, int i, int j);
void	move_s(t_vars *vars, t_character_vars *cvars, int i, int j);
void	move_d(t_vars *vars, t_character_vars *cvars, int i, int j);
void	move_around(t_vars *vars, t_character_vars *cvars, int k);
void	character_move(t_vars *vars, t_character_vars *cvars, int k);
void    ft_free(t_vars *vars);
void    init_obj(t_vars *vars);
void	create_objs_arr(t_vars *vars);
void    init_player(t_vars *vars, t_character_vars *pvars);
void    init_enemy(t_vars *vars, t_character_vars *pvars, int n);
void    init(t_vars *vars);
void    ft_mlx_init(t_vars *vars);
void 	sort(int list[], int n, t_character_vars **objs);
char	*ft_itoa(int n);
void    chase(t_vars *vars);
void	death(t_vars *vars);
void	clear(t_vars *vars);
void    reset(t_vars *vars);
void    reset_collect(t_vars *vars);

#endif