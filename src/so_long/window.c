/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajordan- <ajordan-@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 14:48:18 by ajordan-          #+#    #+#             */
/*   Updated: 2022/05/07 15:56:08 by ajordan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../lib/minilibx/mlx.h"
#include <stdio.h>
#include <stdlib.h>

int	ft_close_window(t_game *game)
{
	mlx_destroy_window(game->mlx, game->mlx_win);
	exit(1);
	return (0);
}

void	ft_fill_floor(t_game *game)
{
	game->y = 0;
	while ((game->y) < (game->map_y))
	{
		game->x = 0;
		while ((game->x) < (game->map_x))
		{
			game->file = mlx_xpm_file_to_image(game->mlx,
					"./img/floor.xpm", &game->pxl, &game->pxl);
			mlx_put_image_to_window (game->mlx, game->mlx_win,
				game->file, game->pxl * game->x,
				game->pxl * game->y);
			game->x++;
		}
		game->y++;
	}
}

int	ft_total_collect(t_game *game)
{
	int	i;

	i = 0;
	game->y = 0;
	while ((game->y) < (game->map_y))
	{
		game->x = 0;
		while ((game->x) < (game->map_x))
		{
			if (game->map[game->y][game->x] == 'C')
				i++;
			game->x++;
		}
		game->y++;
	}
	return (i);
}

void	ft_fill_window(t_game *game)
{
	game->collect = ft_total_collect(game);
	ft_fill_floor(game);
	game->y = 0;
	while ((game->y) < (game->map_y))
	{
		game->x = 0;
		while ((game->x) < (game->map_x))
		{
			if (game->map[game->y][game->x] == '1')
				ft_put_limits(game);
			if (game->map[game->y][game->x] == 'C')
				ft_put_collect(game);
			if (game->map[game->y][game->x] == 'P')
				ft_put_player(game);
			if (game->map[game->y][game->x] == 'E')
				ft_put_exit(game);
			game->x++;
		}
		game->y++;
	}
	printf("Movements: %d\n", game->pl_mov);
}
