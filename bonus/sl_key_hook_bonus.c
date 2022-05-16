/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_key_hook_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlana <dlana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 17:20:57 by dlana             #+#    #+#             */
/*   Updated: 2021/11/18 17:20:57 by dlana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	sl_close(int key, t_data *p)
{
	if (key == 53)
		mlx_destroy_window(p->mlx, p->win);
	exit (EXIT_SUCCESS);
	return (0);
}

static int	check_item(int next_pos, t_data *p)
{
	if (next_pos == '1')
		return (1);
	if (next_pos == 'E' && p->c_count == -1)
		p->action = -1;
	if (next_pos == 'E' && p->c_count != -1)
		return (1);
	if (next_pos == 'A')
		p->action = -10;
	return (0);
}

static void	get_position(int key, t_data *p)
{
	if (key == 53)
		sl_close(key, p);
	if ((key == 0 || key == 1 || key == 2 || key == 13) && p->action >= 0)
	{
		if (key == 0)
			p->x--;
		if (key == 2)
			p->x++;
		if (key == 1)
			p->y++;
		if (key == 13)
			p->y--;
		p->steps++;
		p->key = key;
		p->action = 1;
		if (p->min_steps != 0)
			p->min_steps--;
	}
}

int	sl_key_hook(int key, t_data *p)
{
	char	next_pos;

	next_pos = 0;
	if (key == 0 && p->x > 0)
	{
		next_pos = p->map[p->y][p->x - 1];
		p->direct = -1;
	}
	if (key == 2 && p->x < p->width - 1)
	{
		next_pos = p->map[p->y][p->x + 1];
		p->direct = 1;
	}
	if (key == 1 && p->y < p->height - 1)
		next_pos = p->map[p->y + 1][p->x];
	if (key == 13 && p->y > 0)
		next_pos = p->map[p->y - 1][p->x];
	if (check_item(next_pos, p) == 1)
		return (0);
	get_position(key, p);
	return (0);
}
