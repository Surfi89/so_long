//***********************SO_LONG.C*******************************

#include "so_long.h"

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

void	ft_window(t_game *game)
{
	game->pxl = 50;
	game->mlx = mlx_init();
	game->mlx_win = mlx_new_window(game->mlx,
			game->pxl * game->map_x,
			game->pxl * game->map_y, "Pokemon: Version 42");
	ft_fill_window(game);
}

//**********************VALIDATE_MAP.C*********************

#include "so_long.h"

void	ft_check_map(char *buffer, t_game *game)
{
	game->map_area = ft_strlen(buffer) - game->map_y;
	if (game->map_area != game->map_x * game->map_y)
	{
		printf("Error!\nThe map has a wrong layout.\n");
		exit (1);	
	}
	ft_check_x_limits(game);
	ft_check_y_limits(game);
}

void	ft_check_pce(char *buffer, t_game *game)
{
	int	i;

	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == 'P')
			game->player++;
		if (buffer[i] == 'C')
			game->collect++;
		if (buffer[i] == 'E')
			game->exit++;
		if (buffer[i] == '\n')
			game->map_y++;
		i++;
	}
	if (game->player != 1 || game->collect < 1 || game->exit != 1)
	{
		printf("Error\nIncorrect number of Players, Collectibles or Exits.\n");
		exit(1);
	}
}

char	*ft_join(char	*line, char c)
{
	int		i;
	char	*str;

	i = 0;
	while (line[i])
		i++;
	str = malloc(i + 2);
	i = 0;
	while (line[i])
	{
		str[i] = line[i];
		i++;
	}
	str[i] = c;
	str[i + 1] = '\0';
	free(line);
	return (str);
}

int	ft_check(char *line)
{
	int	i;

	i = 0;
	if (!line)
		return (0);
	while (line[i])
	{
		if (line[i] == '\0')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_get_map(int fd)
{
	char	buffer;
	char	*line;
	int		rd_bytes;

	rd_bytes = 1;
	if (fd < 0)
		line = NULL;
	line = malloc(1);
	line[0] = '\0';
	while (!ft_check(line) && rd_bytes > 0)
	{
		rd_bytes = read(fd, &buffer, 1);
		if ((rd_bytes == 0 && line[0] == '\0') || rd_bytes < 0)
		{
			free(line);
			return (NULL);
		}
		if (rd_bytes == 0 && line[0] != '\0')
			return (line);
		line = ft_join(line, buffer);
	}
	return (line);
}

//*******************CHECK_LIMITS.C******************

#include "so_long.h"

void	ft_limits_error(void)
{
	printf("Error!\nNot enough trees in the screen limits.\n");
	printf("Please, plant 1 where they are supposed to be.\n");
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

//***************WINDOW.C*********************

#include "so_long.h"

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

void	ft_mov_display(t_game *game)
{
	mlx_string_put(game->mlx, game->mlx_win,
		game->pxl * game->map_x * (0.84), 10, 0x80000,
		"Movements: ");
	mlx_string_put(game->mlx, game->mlx_win,
		game->pxl * game->map_x * (0.96), 10, 0x80000,
		ft_itoa(game->pl_mov));
}

void	ft_put_enemy(t_game *game)
{
	game->file = mlx_xpm_file_to_image(game->mlx,
			"./img/enemy.xpm", &game->pxl, &game->pxl);
	mlx_put_image_to_window (game->mlx, game->mlx_win,
		game->file, game->pxl * game->x,
		game->pxl * game->y);
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
			if (game->map[game->y][game->x] == 'K')
				ft_put_enemy(game);
			game->x++;
		}
		game->y++;
	}
	ft_mov_display(game);
}

//***************FILL_WINDOW**********************

#include "so_long.h"

void	ft_put_limits(t_game *game)
{
	game->file = mlx_xpm_file_to_image(game->mlx,
			"./img/wall.xpm", &game->pxl, &game->pxl);
	mlx_put_image_to_window (game->mlx, game->mlx_win,
		game->file, game->pxl * game->x,
		game->pxl * game->y);
}

void	ft_put_floor(t_game *game)
{
	game->file = mlx_xpm_file_to_image(game->mlx,
			"./img/floor.xpm", &game->pxl, &game->pxl);
	mlx_put_image_to_window (game->mlx, game->mlx_win,
		game->file, game->pxl * game->x,
		game->pxl * game->y);
}

void	ft_put_collect(t_game *game)
{
	game->file = mlx_xpm_file_to_image(game->mlx,
			"./img/pokeball.xpm", &game->pxl, &game->pxl);
	mlx_put_image_to_window (game->mlx, game->mlx_win,
		game->file, game->pxl * game->x,
		game->pxl * game->y);
	game->collect++;
}

void	ft_put_player(t_game *game)
{
	game->file = mlx_xpm_file_to_image(game->mlx,
			game->pl_dir, &game->pxl, &game->pxl);
	game->pl_y = game->y;
	game->pl_x = game->x;
	mlx_put_image_to_window (game->mlx, game->mlx_win,
		game->file, game->pxl * game->x,
		game->pxl * game->y);
}

void	ft_put_exit(t_game *game)
{
	if (game->collect == 0)
		game->file = mlx_xpm_file_to_image(game->mlx,
				"./img/exit_open.xpm", &game->pxl, &game->pxl);
	else
		game->file = mlx_xpm_file_to_image(game->mlx,
				"./img/exit_closed.xpm", &game->pxl, &game->pxl);
	mlx_put_image_to_window (game->mlx, game->mlx_win,
		game->file, game->pxl * game->x,
		game->pxl * game->y);
}

//**********************KEYHOOK.C*******************************

#include "so_long.h"

void	ft_move_up(t_game *game)
{
	game->map[game->pl_y][game->pl_x] = '0';
	game->map[game->pl_y - 1][game->pl_x] = 'P';
	game->pl_mov++;
	game->pl_dir = "./img/up.xpm";
	ft_fill_window(game);
}

void	ft_move_down(t_game *game)
{
	game->map[game->pl_y][game->pl_x] = '0';
	game->map[game->pl_y + 1][game->pl_x] = 'P';
	game->pl_mov++;
	game->pl_dir = "./img/down.xpm";
	ft_fill_window(game);
}

void	ft_move_left(t_game *game)
{
	game->map[game->pl_y][game->pl_x] = '0';
	game->map[game->pl_y][game->pl_x - 1] = 'P';
	game->pl_mov++;
	game->pl_dir = "./img/left.xpm";
	ft_fill_window(game);
}

void	ft_move_right(t_game *game)
{
	game->map[game->pl_y][game->pl_x] = '0';
	game->map[game->pl_y][game->pl_x + 1] = 'P';
	if (game)
	game->pl_mov++;
	game->pl_dir = "./img/right.xpm";
	ft_fill_window(game);
}

void	ft_enemy(int keyhook, t_game *game)
{
	if (((keyhook == 2 && game->map[game->pl_y][game->pl_x + 1] == 'K')
		|| (keyhook == 1 && game->map[game->pl_y + 1][game->pl_x] == 'K')
		|| (keyhook == 0 && game->map[game->pl_y][game->pl_x - 1] == 'K')
		|| (keyhook == 13 && game->map[game->pl_y - 1][game->pl_x] == 'K')))
	{
		printf("OAK: Fainted! You cannot beat Mewtwo...\n");
		ft_close_window(game);
	}
}

int	ft_keyboard(int keyhook, t_game *game)
{
	if (keyhook == 53)
		ft_close_window(game);
	ft_enemy(keyhook, game);
	if (game->collect == 0
		&& ((keyhook == 2 && game->map[game->pl_y][game->pl_x + 1] == 'E')
		|| (keyhook == 1 && game->map[game->pl_y + 1][game->pl_x] == 'E')
		|| (keyhook == 0 && game->map[game->pl_y][game->pl_x - 1] == 'E')
		|| (keyhook == 13 && game->map[game->pl_y - 1][game->pl_x] == 'E')))
	{
		printf("OAK: Oh! Thank you for collecting all my Pokemon!\n");
		ft_close_window(game);
	}
	if (keyhook == 13 && game->map[game->pl_y - 1][game->pl_x] != '1'
		&& game->map[game->pl_y - 1][game->pl_x] != 'E')
		ft_move_up(game);
	if (keyhook == 0 && game->map[game->pl_y][game->pl_x - 1] != '1'
		&& game->map[game->pl_y][game->pl_x - 1] != 'E')
		ft_move_left(game);
	if (keyhook == 1 && game->map[game->pl_y + 1][game->pl_x] != '1'
		&& game->map[game->pl_y + 1][game->pl_x] != 'E')
		ft_move_down(game);
	if (keyhook == 2 && game->map[game->pl_y][game->pl_x + 1] != '1'
		&& game->map[game->pl_y][game->pl_x + 1] != 'E')
		ft_move_right(game);
	return (0);
}

//************UTILS_BONUS.C******************

#include "so_long_bonus.h"

