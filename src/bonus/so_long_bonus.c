/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajordan- <ajordan-@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 14:55:30 by ajordan-          #+#    #+#             */
/*   Updated: 2022/05/07 16:00:21 by ajordan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../lib/libft/inc/libft.h"
#include "../lib/minilibx/mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

void	ft_window(t_game *game)
{
	game->pxl = 50;
	game->mlx = mlx_init();
	game->mlx_win = mlx_new_window(game->mlx,
			game->pxl * game->map_x,
			game->pxl * game->map_y, "Pokemon: Version 42");
	ft_fill_window(game);
}

void	ft_validate_map(char **argv, t_game *game)
{
	int		i;
	int		fd;
	char	*buffer;

	i = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		printf("Error!\nThe map could not be read.\n");
		exit (1);
	}
	buffer = ft_get_map(fd);
	ft_check_pce(buffer, game);
	game->map = ft_split(buffer, '\n');
	while (game->map[0][i] != '\0')
	{
		game->map_x++;
		i++;
	}
	ft_check_map(buffer, game);
	close(fd);
}

void	ft_init_struct(t_game *game)
{
	game->map_x = 0;
	game->map_y = 0;
	game->map_area = 0;
	game->x = 0;
	game->y = 0;
	game->pxl = 0;
	game->player = 0;
	game->pl_mov = 0;
	game->pl_dir = "./img/down.xpm";
	game->collect = 0;
	game->exit = 0;
}

void	ft_check_arg(int argc, char **argv)
{
	if (argc != 2)
	{
		printf("Error\nInvalid number of arguments. Must be 2.\n");
		exit(0);
	}
	if (!ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])))
	{
		printf("Error\nInvalid file type. Must be: \"<name>.ber\"\n");
		exit (1);
	}
}

int	main(int argc, char **argv)
{
	t_game	game;

	ft_check_arg(argc, argv);
	ft_init_struct(&game);
	ft_validate_map(argv, &game);
	ft_window(&game);
	mlx_hook(game.mlx_win, 2, 1L << 0, ft_keyboard, &game);
	mlx_hook(game.mlx_win, 17, 1L << 5, ft_close_window, &game);
	mlx_loop(game.mlx);
	exit(0);
	return (0);
}
