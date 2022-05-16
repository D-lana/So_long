/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_animation_enemy_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlana <dlana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 18:08:23 by dlana             #+#    #+#             */
/*   Updated: 2021/11/18 18:51:48 by dlana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	sl_get_pos_enemy(t_data *p)
{
	int	y;
	int	x;

	y = 1;
	x = 1;
	while (y != p->height - 1)
	{
		while (x != p->width - 1)
		{
			if (p->map[y][x] == '0')
			{
				if (p->map[y][x + 1] == '0' && p->map[y][x + 2] == '0'
					&& p->map[y][x + 3] == '0')
				{
					p->map[y][x] = 'A';
					return ;
				}
			}
			x++;
		}
		y++;
		x = 0;
	}
}

static void	sl_put_img_enemy(t_data *p, int x, int y, int pos)
{
	if (p->direct_enemy == 1)
	{
		if (pos == 0 || pos == 32)
			mlx_put_image_to_window(p->mlx, p->win, p->img.e_1,
				(x * 64) + pos, (y * 64));
		if (pos == 16 || pos == 48)
			mlx_put_image_to_window(p->mlx, p->win, p->img.e_2,
				(x * 64) + pos, (y * 64));
	}
	if (p->direct_enemy == -1)
	{
		if (pos == 0 || pos == 32)
			mlx_put_image_to_window(p->mlx, p->win, p->img.e_3,
				(x * 64) - pos, (y * 64));
		if (pos == 16 || pos == 48)
			mlx_put_image_to_window(p->mlx, p->win, p->img.e_4,
				(x * 64) - pos, (y * 64));
	}
}

static void	sl_animation_enemy(t_data *p, int x, int y)
{
	if (p->time_enemy < 10)
		sl_put_img_enemy(p, x, y, 0);
	if (p->time_enemy >= 10 && p->time_enemy < 20)
		sl_put_img_enemy(p, x, y, 16);
	if (p->time_enemy >= 20 && p->time_enemy < 30)
		sl_put_img_enemy(p, x, y, 32);
	if (p->time_enemy >= 30 && p->time_enemy < 40)
		sl_put_img_enemy(p, x, y, 48);
	p->time_enemy++;
	if (p->time_enemy == 40)
	{
		p->time_enemy = 0;
		p->step_enemy++;
		p->next_enemy = 1;
		if (p->step_enemy == 3)
		{
			p->step_enemy = 0;
			p->direct_enemy = p->direct_enemy * -1;
			p->next_enemy = 2;
		}
	}
}

void	sl_draw_enemy(t_data *p, const char *s, int row, int x)
{
	while (s[x] != '\0')
	{
		if (s[x] == 'A')
		{
			if (p->next_enemy == 1)
			{
				p->map[row][x] = '0';
				p->map[row][x + p->direct_enemy] = 'A';
				x = x + p->direct_enemy;
				p->next_enemy = 0;
			}
			if (p->next_enemy == 2)
			{
				p->map[row][x] = '0';
				p->map[row][x - p->direct_enemy] = 'A';
				x = x - p->direct_enemy;
				p->next_enemy = 0;
			}
			sl_animation_enemy(p, x, row);
			if (p->x == x && p->y == row)
				p->action = -10;
		}
		x++;
	}
}
