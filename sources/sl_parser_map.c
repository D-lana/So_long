/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_parser_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlana <dlana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 19:54:42 by dlana             #+#    #+#             */
/*   Updated: 2021/11/20 20:21:31 by dlana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	sl_check_object(t_data *p, char object, int x, int y)
{
	if (object != '0' && object != '1')
	{
		if (object == 'E')
		{
			p->exit++;
			p->e.x_exit = x;
			p->e.y_exit = y;
		}
		else if (object == 'C')
			p->c_count++;
		else if (object == 'P')
		{
			p->player++;
			p->x = x;
			p->y = y;
		}
		else
			sl_error_game(4);
	}
}

static int	ft_check_wall(t_data *p, const char *s, int height, int y)
{
	int	x;

	x = 0;
	if (!s)
		return (0);
	while (s[x] != '\0' && (y + 1 == height || y == 0))
	{
		if (s[x] != '1')
			sl_error_game(1);
		x++;
	}
	while (s[x] != '\0')
	{
		sl_check_object(p, s[x], x, y);
		x++;
	}
	if (s[x - 1] != '1' || s[0] != '1')
		sl_error_game(1);
	return (x);
}

static void	sl_check_map(t_data *p)
{
	int	y;
	int	len_prev;

	p->exit = 0;
	p->player = 0;
	p->c_count = 0;
	p->width = 0;
	y = 0;
	len_prev = 0;
	while (p->map[y])
		y++;
	p->height = y;
	while (y >= 0)
	{
		p->width = ft_check_wall(p, p->map[y], p->height, y);
		if (len_prev == 0)
			len_prev = p->width;
		if (p->width != len_prev)
			sl_error_game(2);
		y--;
	}
	if (p->exit == 0 || p->c_count == 0 || p->player == 0)
		sl_error_game(3);
	if (p->player > 1)
		sl_error_game(5);
}

void	sl_check_name(const char *name)
{
	char	*ber;
	int		i;
	int		j;

	i = 0;
	j = 5;
	ber = ".ber";
	while (name[i])
		i++;
	while (j)
	{
		if (name[i] != ber[j - 1])
			sl_error_game(6);
		i--;
		j--;
	}
}

void	sl_parser_map(t_data *p, char **argv)
{
	int		fd;
	char	*line;
	char	n;

	n = '\n';
	sl_check_name(argv[1]);
	fd = open(argv[1], O_RDONLY);
	line = sl_read_map(fd);
	p->map = ft_split(line, n);
	sl_check_map(p);
	close(fd);
	free(line);
	line = NULL;
}
