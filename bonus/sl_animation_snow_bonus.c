/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_animation_snow_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlana <dlana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 18:07:02 by dlana             #+#    #+#             */
/*   Updated: 2021/11/20 20:32:05 by dlana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	put_img_snow(t_data *p, int x, int y)
{
	if (p->time_snow < 10)
		mlx_put_image_to_window(p->mlx, p->win, p->img.snow, x - 5, y - 56);
	if (p->time_snow >= 10 && p->time_snow < 20)
		mlx_put_image_to_window(p->mlx, p->win, p->img.snow, x - 10, y - 48);
	if (p->time_snow >= 20 && p->time_snow < 30)
		mlx_put_image_to_window(p->mlx, p->win, p->img.snow, x - 15, y - 32);
	if (p->time_snow >= 30 && p->time_snow < 40)
		mlx_put_image_to_window(p->mlx, p->win, p->img.snow, x - 10, y - 24);
	if (p->time_snow >= 40 && p->time_snow < 50)
		mlx_put_image_to_window(p->mlx, p->win, p->img.snow, x - 15, y - 16);
	if (p->time_snow >= 50 && p->time_snow < 60)
		mlx_put_image_to_window(p->mlx, p->win, p->img.snow, x - 10, y - 8);
	if (p->time_snow >= 60 && p->time_snow < 70)
		mlx_put_image_to_window(p->mlx, p->win, p->img.snow, x - 5, y - 0);
	p->time_snow++;
	if (p->time_snow == 70)
		p->time_snow = 0;
}

void	sl_animation_snow(t_data *p)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < p->width * 64)
	{
		put_img_snow(p, x, y);
		x = x + 960;
	}
	while (y < p->height * 64)
	{
		put_img_snow(p, x, y);
		y = y + 640;
	}
}
