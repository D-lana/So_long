/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlana <dlana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 19:52:37 by dlana             #+#    #+#             */
/*   Updated: 2021/11/20 19:22:27 by dlana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	else if (p->min_steps == 0 && p->c_count <= 0 && !p->img.winner)
	{
		mlx_clear_window(p->mlx, p->win);
		sl_draw_map(p);
		p->img.loser = mlx_xpm_file_to_image(p->mlx, "xpm/lose.xpm", &x, &y);
		mlx_put_image_to_window(p->mlx, p->win, p->img.loser,
			(p->width * 32) - x / 2, (p->height * 32) - y / 2);
		p->action = -1;
	}
}

int	render_next_frame(t_data *p)
{
	if (p->action != -1)
	{
		mlx_clear_window(p->mlx, p->win);
		sl_draw_map(p);
		if (p->direct == 1)
			p->img.p_0 = p->img.p_1;
		if (p->direct == -1)
			p->img.p_0 = p->img.p_5;
		mlx_put_image_to_window(p->mlx, p->win, p->img.p_0,
			p->x * 64, p->y * 64);
	}
	sl_win_or_lose(p);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	p;

	p.key = 0;
	p.time = 0;
	p.time_2 = -1;
	p.time_snow = 0;
	p.direct = 1;
	p.min_steps = 0;
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
