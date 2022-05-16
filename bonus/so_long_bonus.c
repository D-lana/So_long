/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlana <dlana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 20:15:31 by dlana             #+#    #+#             */
/*   Updated: 2021/11/20 20:25:39 by dlana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	sl_write_steps(t_data *p)
{
	char	*steps;
	char	*steps_to_exit;
	char	*socks;
	int		count;
	int		i;

	count = 0;
	if (p->c_count != -1)
		count = p->c_count;
	steps = NULL;
	steps_to_exit = NULL;
	i = 0;
	steps = ft_itoa(p->steps);
	steps_to_exit = ft_itoa(p->min_steps);
	socks = ft_itoa(count);
	mlx_string_put(p->mlx, p->win, 50, 10, 0x00ffffff, "STEPS: ");
	mlx_string_put(p->mlx, p->win, 115, 10, 0x00ffffff, steps);
	mlx_string_put(p->mlx, p->win, 150, 10, 0x00ffffff, "STEPS TO EXIT: ");
	mlx_string_put(p->mlx, p->win, 300, 10, 0x00ffffff, steps_to_exit);
	mlx_string_put(p->mlx, p->win, 350, 10, 0x00ffffff, "SOCKS: ");
	mlx_string_put(p->mlx, p->win, 420, 10, 0x00ffffff, socks);
	free(socks);
	free(steps);
	free(steps_to_exit);
}

void	sl_animation_lose_player(t_data *p)
{
	int	x;

	x = p->x * 64;
	p->img.p_0 = p->img.p_9;
	p->img.p_1 = p->img.p_11;
	if (p->direct == -1)
	{
		p->img.p_0 = p->img.p_10;
		p->img.p_1 = p->img.p_12;
	}
	if (p->time_2 < 10)
		mlx_put_image_to_window(p->mlx, p->win, p->img.p_0, x, (p->y * 64));
	if (p->time_2 >= 20 && p->time_2 < 30)
		mlx_put_image_to_window(p->mlx, p->win, p->img.p_0, x, (p->y * 64));
	if (p->time_2 >= 40 && p->time_2 < 50)
		mlx_put_image_to_window(p->mlx, p->win, p->img.p_0, x, (p->y * 64));
	if (p->time_2 >= 60 && p->time_2 < 70)
		mlx_put_image_to_window(p->mlx, p->win, p->img.p_1, x, (p->y * 64));
	if (p->time_2 >= 80 && p->time_2 < 90)
		mlx_put_image_to_window(p->mlx, p->win, p->img.p_1, x, (p->y * 64));
	p->time_2++;
	if (p->time_2 == 70)
		p->time_2 = -10;
}

void	sl_win_or_lose(t_data *p)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	if (p->action == -1 && p->min_steps != 0 && !p->img.loser)
	{
		mlx_clear_window (p->mlx, p->win);
		sl_draw_map(p);
		p->img.winner = mlx_xpm_file_to_image(p->mlx, "xpm/win.xpm", &x, &y);
		mlx_put_image_to_window(p->mlx, p->win, p->img.winner,
			(p->width * 32) - x / 2, (p->height * 32) - y / 2);
	}
	else if ((p->min_steps == 0 && p->c_count <= 0 && !p->img.winner)
		|| p->action == -10)
	{
		mlx_clear_window (p->mlx, p->win);
		sl_draw_map(p);
		if (p->time_2 != -10)
			sl_animation_lose_player(p);
		p->img.loser = mlx_xpm_file_to_image(p->mlx, "xpm/lose.xpm", &x, &y);
		mlx_put_image_to_window(p->mlx, p->win, p->img.loser,
			(p->width * 32) - x / 2, (p->height * 32) - y / 2);
		p->action = -10;
	}
}

int	render_next_frame(t_data *p)
{
	if (p->action != -1 && p->action != -10)
	{
		if (p->action == 1 || p->c_count == 0 || p->time_2 >= 0)
		{
			sl_animation_walk(p);
			p->action = 0;
		}
		else
			sl_animation_static(p, p->x * 64, p->y * 64);
	}
	sl_win_or_lose(p);
	sl_write_steps(p);
	sl_animation_snow(p);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	p;

	p.key = 0;
	p.min_steps = 0;
	p.direct = 1;
	p.time = 0;
	p.time_2 = -1;
	p.time_snow = 0;
	p.time_enemy = 0;
	p.direct_enemy = 1;
	p.step_enemy = 0;
	p.next_enemy = 0;
	if (argc != 2)
		sl_error_game(0);
	sl_parser_map(&p, argv);
	p.mlx = mlx_init();
	p.win = mlx_new_window(p.mlx, p.width * 64, p.height * 64, "SO LONG!");
	sl_open_source(&p);
	mlx_key_hook(p.win, sl_key_hook, &p);
	mlx_loop_hook(p.mlx, render_next_frame, &p);
	mlx_hook(p.win, 17, 0L, sl_close, &p);
	mlx_loop(p.mlx);
	exit(EXIT_FAILURE);
}
