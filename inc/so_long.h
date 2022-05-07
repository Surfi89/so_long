/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajordan- <ajordan-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 22:47:27 by ajordan-          #+#    #+#             */
/*   Updated: 2022/05/05 23:06:24 by ajordan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "lib/libft/include/libft.h"
# include "lib/minilibx/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_game
{
	void	*mlx;
	void	*mlx_win;
	char	**map;
	char	*file;
	int		map_x;
	int		map_y;
	int		map_area;
	int		x;
	int		y;
	int		pxl;
	int		player;
	int		pl_x;
	int		pl_y;
	int		pl_mov;
	char	*pl_dir;
	int		collect;
	int		exit;
}	t_game;

//SO_LONG
void	ft_check_arg(int argc, char **argv);
void	ft_init_struct(t_game *game);
void	ft_validate_map(char **argv, t_game *game);
void	ft_window(t_game *game)
//VALIDATE_MAP
char	*ft_get_map(int fd);
int	ft_check(char *line);
char	*ft_join(char	*line, char c);
void	ft_check_pce(char *buffer, t_game *game);
void	ft_check_map(char *buffer, t_game *game);
//LIMITS
void	ft_check_x_limits(t_game *game);
void	ft_check_y_limits(t_game *game);
void	ft_limits_error(void);
//WINDOW
void	ft_fill_window(t_game *game);
int	ft_total_collect(t_game *game);
void	ft_fill_floor(t_game *game);
int	ft_close_window(t_game *game);
//FILL_WINDOW
void	ft_put_limits(t_game *game);
void	ft_put_floor(t_game *game);
void	ft_put_collect(t_game *game);
void	ft_put_player(t_game *game);
void	ft_put_exit(t_game *game);
//KEYHOOK
int	ft_keyboard(int keyhook, t_game *game);
void	ft_move_up(t_game *game);
void	ft_move_down(t_game *game);
void	ft_move_left(t_game *game);
void	ft_move_right(t_game *game);

#endif
