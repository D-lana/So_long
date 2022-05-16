/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlana <dlana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 19:54:20 by dlana             #+#    #+#             */
/*   Updated: 2021/11/18 19:54:21 by dlana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

static void	ft_killer(char **str)
{
	if (*str)
	{
		free (*str);
		*str = NULL;
	}
}

static char	*ft_join_str_and_ch(const char *s1, char c)
{
	char	*s2;
	int		i;

	i = 0;
	s2 = 0;
	if (!c)
		ft_error();
	s2 = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 2));
	if (!s2)
		ft_error();
	while (s1[i])
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = c;
	i++;
	s2[i] = '\0';
	return (s2);
}

char	*sl_read_map(int fd)
{
	int		rd;
	char	*line;
	char	ch;
	char	*str;

	rd = 0;
	str = NULL;
	line = malloc(sizeof(char));
	*line = 0;
	while (read(fd, &ch, 1) > 0)
	{
		str = line;
		line = ft_join_str_and_ch(str, ch);
		ft_killer(&str);
		rd++;
	}
	if (line[0] == '\0')
	{
		write(2, "Empty map!\n", 12);
		exit(EXIT_FAILURE);
	}
	return (line);
}
