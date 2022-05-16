/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_error_game.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlana <dlana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 17:21:48 by dlana             #+#    #+#             */
/*   Updated: 2021/11/20 19:41:01 by dlana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sl_error_game(int error)
{
	if (error == 0)
		write(2, "Error\nOnly one argument is needed!\n", 36);
	if (error == 1)
		write(2, "Error\nLeaky walls on the map!\n", 31);
	if (error == 2)
		write(2, "Error\nThis map is not rectangular!\n", 36);
	if (error == 3)
		write(2, "Error\nThere's not enough items!\n", 33);
	if (error == 4)
		write(2, "Error\nUnknown items on the map!\n", 33);
	if (error == 5)
		write(2, "Error\nToo many players on the map!\n", 36);
	if (error == 6)
		write(2, "Error\nWrong format of map!\n", 28);
	exit(EXIT_FAILURE);
}
