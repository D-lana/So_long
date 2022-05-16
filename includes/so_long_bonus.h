/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlana <dlana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 21:21:49 by dlana             #+#    #+#             */
/*   Updated: 2021/11/19 21:49:46 by dlana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <mlx.h>
# include <unistd.h>
# include <fcntl.h>
# include <limits.h>
# include "libft.h"

typedef struct s_img {
	void	*winner;
	void	*loser;
	void	*p_0;
	void	*p_1;
	void	*p_2;
	void	*p_3;
	void	*p_4;
	void	*p_5;
	void	*p_6;
	void	*p_7;
	void	*p_8;
	void	*p_9;
	void	*p_10;
	void	*p_11;
	void	*p_12;
	void	*e_1;
	void	*e_2;
	void	*e_3;
	void	*e_4;
	void	*wall_1;
	void	*wall_2;
	void	*wall_3;
	void	*wall_4;
	void	*wall_5;
	void	*wall_6;
	void	*wall_7;
	void	*wall_8;
	void	*wall_9;
	void	*fone;
	void	*fone_2;
	void	*c;
	void	*exit_1;
	void	*exit_2;
	void	*snow;
}				t_img;

typedef struct s_exit {
	int		x_player;
	int		y_player;
	int		x_exit;
	int		y_exit;
	int		direct_x;
	int		direct_y;
}				t_exit;

typedef struct s_data {
	void	*mlx;
	void	*win;
	int		key;
	int		x;
	int		y;
	int		action;
	int		time;
	int		time_2;
	int		time_snow;
	int		time_enemy;
	int		steps;
	int		min_steps;
	int		direct;
	int		direct_enemy;
	int		step_enemy;
	int		next_enemy;
	int		height;
	int		width;
	int		exit;
	int		player;
	int		enemy;
	int		c_count;
	char	**map;
	t_img	img;
	t_exit	e;
}				t_data;

char	*sl_read_map(int fd);
void	sl_parser_map(t_data *p, char **argv);
void	sl_open_source(t_data *p);
int		sl_key_hook(int key, t_data *p);
int		sl_close(int keycode, t_data *p);

int		render_next_frame(t_data *p);
void	sl_draw_map(t_data *p);
void	sl_animation_walk(t_data *p);
void	sl_animation_static(t_data *p, int x, int y);
void	sl_animation_snow(t_data *p);
void	sl_draw_enemy(t_data *p, const char *s, int row, int x);
void	sl_get_pos_enemy(t_data *p);

void	sl_error_game(int error);

#endif
