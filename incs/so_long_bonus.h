/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoh <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 16:11:54 by hoh               #+#    #+#             */
/*   Updated: 2022/04/28 12:50:35 by hoh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H
# include "mlx.h"
# include "get_next_line.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# define CHEAT 1
# define SELECT_DIFF -1
# define EASY 3
# define MEDIUM 4
# define HARD 5
# define HIDDEN 6
# define SELECT_SPEED 0
# define SLOW 2
# define FAST 8
# define INGAME 1
# define CHASE 2
# define DEATH 3
# define CLEAR 5
# define W 13
# define A 0
# define S 1
# define D 2
# define WA 33
# define WD 20
# define SA 21
# define SD 22
# define STAY -1
# define AROUND -2

typedef struct s_character_vars {
	void	*img_w00;
	void	*img_w01;
	void	*img_w02;
	void	*img_w03;
	void	*img_a00;
	void	*img_a01;
	void	*img_a02;
	void	*img_a03;
	void	*img_s00;
	void	*img_s01;
	void	*img_s02;
	void	*img_s03;
	void	*img_d00;
	void	*img_d01;
	void	*img_d02;
	void	*img_d03;
	int		is_player;
	int		caught;
	int		state;
	int		dir;
	int		x;
	int		y;
	int		d;
	int		rand;
	int		step;
}	t_character_vars;

typedef struct s_vars {
	void					*mlx;
	void					*win;
	int						game_level;
	int						game_speed;
	int						game_state;
	t_character_vars		**objs;
	int						*order_arr;
	int						dir_arr[4];
	int						objs_n;
	void					*menu_diff;
	void					*menu_speed;
	void					*game_over;
	void					*clear;
	void					*tile00;
	void					*tile01;
	void					*collect;
	void					*exit;
	void					*num_box;
	char					*map;
	int						w;
	int						h;
	int						collect_num;
	int						timer;
}	t_vars;

char	*parsing(char *map_ber);
void	arg_check(int argc, char *argv[], t_vars vars);
int		extension_check(char *filename);
int		abs(int x);
int		xl(int x);
int		yo(int y);
int		xr(int x);
int		yu(int y);
int		loc(int x, int y, t_vars *vars);
int		close_game(t_vars *vars);
int		count_obj(char *map);
int		key_hook_move(t_vars *vars);
void	key_hook_menu(int keycode, t_vars *vars);
int		key_hook(int keycode, t_vars *vars);
int		key_press(int keycode, t_vars *vars);
int		key_release(int keycode, t_vars *vars);
void	ft_mlx_init(t_vars *vars);
void	ft_mlx_new(t_vars *vars, int x, int y, char *name);
void	*ft_xpm(t_vars *vars, char *filename, int *width, int *height);
int		ft_img(t_vars *vars, void *img_ptr, int x, int y);
void	enemy_search(t_vars *vars, t_character_vars *evars);
void	all_enemies_search(t_vars *vars);
void	enemy_touch(t_vars *vars, int i);
int		all_enemy_touch(t_vars *vars);
int		enemy_search_w(t_vars *vars, t_character_vars *evars, int x, int y);
int		enemy_search_a(t_vars *vars, t_character_vars *evars, int x, int y);
int		enemy_search_s(t_vars *vars, t_character_vars *evars, int x, int y);
int		enemy_search_d(t_vars *vars, t_character_vars *evars, int x, int y);
int		enemy_search_touch(t_vars *vars, int i);
void	map_draw_m(t_vars *vars, int x, int y);
void	map_draw(t_vars *vars);
void	map_draw_2(t_vars *vars, int i, int j, int *n);
int		map_check_comp(char *map, t_vars *vars);
int		map_check_surr(char *map, t_vars *vars);
void	map_check(char *map, t_vars *vars);
void	character_draw(t_vars *vars, t_character_vars *cvars, int k);
void	character_draw_well(t_vars *vars, t_character_vars *cvars);
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
void	move_wd(t_vars *vars, t_character_vars *cvars);
void	move_wa(t_vars *vars, t_character_vars *cvars);
void	move_sd(t_vars *vars, t_character_vars *cvars);
void	move_sa(t_vars *vars, t_character_vars *cvars);
void	move_block(t_character_vars *cvars);
void	key_press_w(t_vars *vars);
void	key_press_a(t_vars *vars);
void	key_press_s(t_vars *vars);
void	key_press_d(t_vars *vars);
void	key_release_w(t_vars *vars);
void	key_release_a(t_vars *vars);
void	key_release_s(t_vars *vars);
void	key_release_d(t_vars *vars);
void	move_around(t_vars *vars, t_character_vars *cvars, int k);
void	move_around_random(t_vars *vars, t_character_vars *cvars, int k);
void	move_around_wander(t_vars *vars, t_character_vars *cvars, int k);
void	character_move(t_vars *vars, t_character_vars *cvars, int k);
void	ft_free(t_vars *vars);
void	ft_free_reset(t_vars *vars);
void	init_obj(t_vars *vars);
void	create_objs_arr(t_vars *vars);
void	init_player(t_vars *vars, t_character_vars *pvars);
void	init_enemy(t_vars *vars, t_character_vars *pvars, int n);
void	init(t_vars *vars);
void	sort(int list[], int n, t_character_vars **objs);
char	*ft_itoa(int n);
void	ft_rand(t_character_vars *cvars);
void	chase(t_vars *vars);
void	death(t_vars *vars);
void	clear(t_vars *vars);
void	reset(t_vars *vars);
void	reset_collect(t_vars *vars);
void	destroy_enemies(t_vars *vars);

#endif
