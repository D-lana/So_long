/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_draw_map_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlana <dlana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 18:03:36 by dlana             #+#    #+#             */
/*   Updated: 2021/11/18 18:06:23 by dlana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	sl_draw_walls(t_data *p, const char *s, int row, int x)
{
	int	y;

	y = row * 64;
	while (s[x] != '\0')
	{
		if (x == 0 && row == 0)
			mlx_put_image_to_window(p->mlx, p->win, p->img.wall_8, x * 64, y);
		else if (x != 0 && x != p->width - 1 && row == 0)
			mlx_put_image_to_window(p->mlx, p->win, p->img.wall_3, x * 64, y);
		else if (x == 0 && row == p->height - 1)
			mlx_put_image_to_window(p->mlx, p->win, p->img.wall_5, x * 64, y);
		else if (x == p->width - 1 && row == 0)
			mlx_put_image_to_window(p->mlx, p->win, p->img.wall_7, x * 64, y);
		else if (x == p->width - 1 && row == p->height - 1)
			mlx_put_image_to_window(p->mlx, p->win, p->img.wall_6, x * 64, y);
		else if (x == 0 && row != 0 && row != p->height - 1)
			mlx_put_image_to_window(p->mlx, p->win, p->img.wall_4, x * 64, y);
		else if (x == p->width - 1 && row != 0 && row != p->height - 1)
			mlx_put_image_to_window(p->mlx, p->win, p->img.wall_2, x * 64, y);
		else if (x != p->width - 1 && x != 0 && row == p->height - 1)
			mlx_put_image_to_window(p->mlx, p->win, p->img.wall_1, x * 64, y);
		else if (s[x] == '1')
			mlx_put_image_to_window(p->mlx, p->win, p->img.wall_9, x * 64, y);
		x++;
	}
}

static void	sl_draw_fone(t_data *p, const char *s, int row, int x)
{
	int	y;

	y = row * 64;
	while (s[x] != '\0')
	{
		if (s[x] != '1')
			mlx_put_image_to_window(p->mlx, p->win, p->img.fone, x * 64, y);
		if (x == p->e.x_exit && row == p->e.y_exit + 1 && s[x] == '0')
			mlx_put_image_to_window(p->mlx, p->win, p->img.fone_2, x * 64, y);
		x++;
	}
}

static void	sl_draw_collect(t_data *p, const char *s, int row, int x)
{
	int	y;

	y = row * 64;
	while (s[x] != '\0')
	{
		if (s[x] == 'C')
		{
			if (x != p->x || row != p->y)
				mlx_put_image_to_window(p->mlx, p->win, p->img.c, x * 64, y);
			if (x == p->x && row == p->y)
			{
				p->map[p->y][p->x] = '0';
				p->c_count--;
			}
		}
		x++;
	}
}

static void	sl_draw_exit(t_data *p, const char *s, int row, int x)
{
	int	y;

	y = row * 64;
	while (s[x] != '\0')
	{
		if (s[x] == 'E' && p->c_count > 0)
			mlx_put_image_to_window(p->mlx, p->win, p->img.exit_1, x * 64, y);
		if (p->c_count == 0 && p->min_steps == 0)
			p->min_steps = p->width + p->height;
		if (s[x] == 'E' && p->c_count <= 0)
		{
			mlx_put_image_to_window(p->mlx, p->win, p->img.exit_2, x * 64, y);
			p->c_count = -1;
		}
		x++;
	}
}

void	sl_draw_map(t_data *p)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (p->map[y])
	{
		sl_draw_walls(p, p->map[y], y, x);
		sl_draw_fone(p, p->map[y], y, x);
		sl_draw_collect(p, p->map[y], y, x);
		sl_draw_exit(p, p->map[y], y, x);
		sl_draw_enemy(p, p->map[y], y, x);
		y++;
	}
}
