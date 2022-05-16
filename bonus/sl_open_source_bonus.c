/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_open_source_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlana <dlana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 20:21:23 by dlana             #+#    #+#             */
/*   Updated: 2021/11/18 17:27:12 by dlana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	sl_open_heroes(t_data *p, int x, int y)
{
	p->img.p_1 = mlx_xpm_file_to_image(p->mlx, "xpm/p(1).xpm", &x, &y);
	p->img.p_2 = mlx_xpm_file_to_image(p->mlx, "xpm/p(2).xpm", &x, &y);
	p->img.p_3 = mlx_xpm_file_to_image(p->mlx, "xpm/p(3).xpm", &x, &y);
	p->img.p_4 = mlx_xpm_file_to_image(p->mlx, "xpm/p(4).xpm", &x, &y);
	p->img.p_5 = mlx_xpm_file_to_image(p->mlx, "xpm/p(5).xpm", &x, &y);
	p->img.p_6 = mlx_xpm_file_to_image(p->mlx, "xpm/p(6).xpm", &x, &y);
	p->img.p_7 = mlx_xpm_file_to_image(p->mlx, "xpm/p(7).xpm", &x, &y);
	p->img.p_8 = mlx_xpm_file_to_image(p->mlx, "xpm/p(8).xpm", &x, &y);
	p->img.p_9 = mlx_xpm_file_to_image(p->mlx, "xpm/p(9).xpm", &x, &y);
	p->img.p_10 = mlx_xpm_file_to_image(p->mlx, "xpm/p(10).xpm", &x, &y);
	p->img.p_11 = mlx_xpm_file_to_image(p->mlx, "xpm/p(11).xpm", &x, &y);
	p->img.p_12 = mlx_xpm_file_to_image(p->mlx, "xpm/p(12).xpm", &x, &y);
	p->img.e_1 = mlx_xpm_file_to_image(p->mlx, "xpm/enemy(1).xpm", &x, &y);
	p->img.e_2 = mlx_xpm_file_to_image(p->mlx, "xpm/enemy(2).xpm", &x, &y);
	p->img.e_3 = mlx_xpm_file_to_image(p->mlx, "xpm/enemy(3).xpm", &x, &y);
	p->img.e_4 = mlx_xpm_file_to_image(p->mlx, "xpm/enemy(4).xpm", &x, &y);
	p->img.p_0 = p->img.p_1;
	if (!p->img.p_1 || !p->img.p_2 || !p->img.p_3 || !p->img.p_4 || !p->img.e_4
		|| !p->img.p_5 || !p->img.p_6 || !p->img.p_7 || !p->img.p_8
		|| !p->img.p_9 || !p->img.p_10 || !p->img.p_11 || !p->img.p_12
		||!p->img.e_1 || !p->img.e_2 || !p->img.e_3)
		exit(EXIT_FAILURE);
}

static void	sl_open_walls(t_data *p, int x, int y)
{
	p->img.wall_1 = mlx_xpm_file_to_image(p->mlx, "xpm/wall(1).xpm", &x, &y);
	p->img.wall_2 = mlx_xpm_file_to_image(p->mlx, "xpm/wall(2).xpm", &x, &y);
	p->img.wall_3 = mlx_xpm_file_to_image(p->mlx, "xpm/wall(3).xpm", &x, &y);
	p->img.wall_4 = mlx_xpm_file_to_image(p->mlx, "xpm/wall(4).xpm", &x, &y);
	p->img.wall_5 = mlx_xpm_file_to_image(p->mlx, "xpm/wall(5).xpm", &x, &y);
	p->img.wall_6 = mlx_xpm_file_to_image(p->mlx, "xpm/wall(6).xpm", &x, &y);
	p->img.wall_7 = mlx_xpm_file_to_image(p->mlx, "xpm/wall(7).xpm", &x, &y);
	p->img.wall_8 = mlx_xpm_file_to_image(p->mlx, "xpm/wall(8).xpm", &x, &y);
	p->img.wall_9 = mlx_xpm_file_to_image(p->mlx, "xpm/wall(9).xpm", &x, &y);
	if (!p->img.wall_1 || !p->img.wall_2 || !p->img.wall_3 || !p->img.wall_4
		|| !p->img.wall_5 || !p->img.wall_6 || !p->img.wall_7 || !p->img.wall_8
		|| !p->img.wall_9)
		exit(EXIT_FAILURE);
}

void	sl_open_source(t_data *p)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	sl_open_heroes(p, x, y);
	sl_open_walls(p, x, y);
	p->img.exit_1 = mlx_xpm_file_to_image(p->mlx, "xpm/exit(1).xpm", &x, &y);
	p->img.exit_2 = mlx_xpm_file_to_image(p->mlx, "xpm/exit(2).xpm", &x, &y);
	p->img.fone = mlx_xpm_file_to_image(p->mlx, "xpm/fone(1).xpm", &x, &y);
	p->img.fone_2 = mlx_xpm_file_to_image(p->mlx, "xpm/fone(2).xpm", &x, &y);
	p->img.c = mlx_xpm_file_to_image(p->mlx, "xpm/c(1).xpm", &x, &y);
	p->img.snow = mlx_xpm_file_to_image(p->mlx, "xpm/snow.xpm", &x, &y);
	if (!p->img.fone || !p->img.fone_2 || !p->img.c || !p->img.exit_1
		|| !p->img.exit_2 || !p->img.snow)
		exit(EXIT_FAILURE);
}
