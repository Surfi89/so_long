/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_limits_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajordan- <ajordan-@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 14:59:32 by ajordan-          #+#    #+#             */
/*   Updated: 2022/05/08 01:06:53 by ajordan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include "../lib/libft/inc/ft_printf.h"
#include <stdlib.h>

void	ft_limits_error(void)
{
	ft_printf("Error!\nNot enough trees in the screen limits.\n");
	ft_printf("Please, plant 1 in each hole to continue.\n");
	exit(1);
}

void	ft_check_x_limits(t_game *game)
{
	while ((game->x) < (game->map_x))
	{
		if (game->map[0][game->x] != '1')
			ft_limits_error();
		game->x++;
	}
	game->y = game->map_y - 1;
	game->x = 0;
	while ((game->x) < (game->map_x))
	{
		if (game->map[game->y][game->x] != '1')
			ft_limits_error();
		game->x++;
	}
}

void	ft_check_y_limits(t_game *game)
{
	game->x = 0;
	game->y = 0;
	while ((game->y) < (game->map_y))
	{
		if (game->map[game->y][0] != '1')
			ft_limits_error();
		game->y++;
	}
	game->y = 0;
	game->x = game->map_x - 1;
	while ((game->y) < (game->map_y))
	{
		if (game->map[game->y][game->x] != '1')
			ft_limits_error();
		game->y++;
	}
}
