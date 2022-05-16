/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_draw_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlana <dlana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 17:22:39 by dlana             #+#    #+#             */
/*   Updated: 2021/11/18 19:38:21 by dlana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sl_draw_walls(t_data *p, const char *s, int row, int x)
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

void	sl_draw_fone(t_data *p, const char *s, int row, int x)
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

void	sl_draw_collect(t_data *p, const char *s, int row, int x)
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

void	sl_draw_exit(t_data *p, const char *s, int row, int x)
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

	y = 0;
	while (p->map[y])
	{
		sl_draw_walls(p, p->map[y], y, 0);
		sl_draw_fone(p, p->map[y], y, 0);
		sl_draw_collect(p, p->map[y], y, 0);
		sl_draw_exit(p, p->map[y], y, 0);
		y++;
	}
}
