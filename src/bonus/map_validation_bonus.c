/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajordan- <ajordan-@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 14:57:27 by ajordan-          #+#    #+#             */
/*   Updated: 2022/05/08 01:08:05 by ajordan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include "../lib/libft/inc/libft.h"
#include "../lib/libft/inc/ft_printf.h"
#include <stdlib.h>

void	ft_check_map(char *buffer, t_game *game)
{
	game->map_area = ft_strlen(buffer) - game->map_y;
	if (game->map_area != game->map_x * game->map_y)
	{
		ft_printf("Error!\nThe map has a wrong layout.\n");
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
		ft_printf("Error\nIncorrect number of Players, Collectibles or Exits.\n");
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
