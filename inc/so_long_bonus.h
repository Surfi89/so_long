/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajordan- <ajordan-@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 15:16:38 by ajordan-          #+#    #+#             */
/*   Updated: 2022/05/07 16:05:59 by ajordan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

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
void	ft_window(t_game *game);
//MAP_VALIDATION
char	*ft_get_map(int fd);
int		ft_check(char *line);
char	*ft_join(char	*line, char c);
void	ft_check_pce(char *buffer, t_game *game);
void	ft_check_map(char *buffer, t_game *game);
//CHECK_LIMITS
void	ft_check_x_limits(t_game *game);
void	ft_check_y_limits(t_game *game);
void	ft_limits_error(void);
//WINDOW
void	ft_fill_window(t_game *game);
int		ft_total_collect(t_game *game);
void	ft_fill_floor(t_game *game);
int		ft_close_window(t_game *game);
//WINDOW_FILL
void	ft_put_limits(t_game *game);
void	ft_put_floor(t_game *game);
void	ft_put_collect(t_game *game);
void	ft_put_player(t_game *game);
void	ft_put_exit(t_game *game);
//KEYHOOK
int		ft_keyboard(int keyhook, t_game *game);
void	ft_move_up(t_game *game);
void	ft_move_down(t_game *game);
void	ft_move_left(t_game *game);
void	ft_move_right(t_game *game);
//UTILS_BONUS
void	ft_mov_display(t_game *game);
void	ft_put_enemy(t_game *game);
void	ft_enemy(int keyhook, t_game *game);

#endif
