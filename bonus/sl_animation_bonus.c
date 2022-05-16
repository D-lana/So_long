/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_animation_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlana <dlana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 18:15:50 by dlana             #+#    #+#             */
/*   Updated: 2021/11/18 18:18:52 by dlana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	sl_animation_static(t_data *p, int x, int y)
{
	mlx_clear_window (p->mlx, p->win);
	sl_draw_map(p);
	if (p->time < 20)
	{
		if (p->direct == 1)
			p->img.p_0 = p->img.p_1;
		if (p->direct == -1)
			p->img.p_0 = p->img.p_5;
		mlx_put_image_to_window(p->mlx, p->win, p->img.p_0, x, y);
	}
	if (p->time >= 20 && p->time < 40)
	{
		if (p->direct == 1)
			p->img.p_0 = p->img.p_2;
		if (p->direct == -1)
			p->img.p_0 = p->img.p_6;
		mlx_put_image_to_window(p->mlx, p->win, p->img.p_0, x, y);
	}
	p->time++;
	if (p->time == 40)
		p->time = 0;
}

static void	sl_get_img_player(t_data *p, int posx)
{
	if (p->direct == -1 && posx == 48)
		p->img.p_0 = p->img.p_7;
	if (p->direct == -1 && posx == 32)
		p->img.p_0 = p->img.p_5;
	if (p->direct == -1 && posx == 16)
		p->img.p_0 = p->img.p_8;
	if (p->direct == -1 && posx == 0)
		p->img.p_0 = p->img.p_5;
	if (p->direct == 1 && posx == 48)
		p->img.p_0 = p->img.p_3;
	if (p->direct == 1 && posx == 32)
		p->img.p_0 = p->img.p_1;
	if (p->direct == 1 && posx == 16)
		p->img.p_0 = p->img.p_4;
	if (p->direct == 1 && posx == 0)
		p->img.p_0 = p->img.p_1;
}

static void	sl_put_player(t_data *p, int posx)
{
	sl_get_img_player(p, posx);
	if (p->key == 0)
		mlx_put_image_to_window(p->mlx, p->win, p->img.p_0,
			(p->x * 64) + posx, (p->y * 64));
	if (p->key == 2)
		mlx_put_image_to_window(p->mlx, p->win, p->img.p_0,
			(p->x * 64) - posx, (p->y * 64));
	if (p->key == 1)
		mlx_put_image_to_window(p->mlx, p->win, p->img.p_0,
			(p->x * 64), (p->y * 64) - posx);
	if (p->key == 13)
		mlx_put_image_to_window(p->mlx, p->win, p->img.p_0,
			(p->x * 64), (p->y * 64) + posx);
}

void	sl_animation_walk(t_data *p)
{
	mlx_clear_window (p->mlx, p->win);
	sl_draw_map(p);
	if (p->time_2 < 10)
		sl_put_player(p, 48);
	if (p->time_2 >= 10 && p->time_2 < 20)
		sl_put_player(p, 32);
	if (p->time_2 >= 20 && p->time_2 < 30)
		sl_put_player(p, 16);
	if (p->time_2 >= 30 && p->time_2 < 40)
		sl_put_player(p, 0);
	p->time_2++;
	if (p->time_2 == 40)
	{
		sl_put_player(p, 0);
		p->time_2 = -1;
	}
}
