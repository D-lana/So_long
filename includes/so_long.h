/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlana <dlana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 19:44:09 by dlana             #+#    #+#             */
/*   Updated: 2021/11/19 22:03:15 by dlana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

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
	void	*p_5;
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
	int		steps;
	int		min_steps;
	int		direct;
	int		height;
	int		width;
	int		exit;
	int		player;
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
void	sl_animation_static(t_data *p);
void	sl_animation_snow(t_data *p, int x, int y);

int		sl_min_steps_to_exit(t_data *p);

void	sl_error_game(int error);

#endif
