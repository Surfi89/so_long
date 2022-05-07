# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: indoming <indoming@student.42urduliz.com>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/08 12:51:48 by indoming          #+#    #+#              #
#    Updated: 2022/05/06 16:04:46 by ajordan-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

NAME_BONUS = so_long_bonus

SRC = so_long.c

SRC_BONUS = so_long_bonus.c

LIBFT = lib/libft/

MINILIBX = lib/minilibx/

CC = gcc
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror 
OPENGL = -framework OpenGL -framework AppKit
SANITIZE = -fsanitize=address -g

OBJS = $(SRC:.c=.o)

OBJS_BONUS = $(SRC_BONUS:.c=.o)

all: $(NAME)

bonus: $(NAME_BONUS)
	
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) lib/libft/libft.a -Imlx -Iso_long.h -Llib/minilibx -lmlx $(OPENGL) $(SANITIZE) $^ -o $@

$(NAME_BONUS): $(OBJS_BONUS)
	$(CC) $(CFLAGS) lib/libft/libft.a -Imlx -Iso_long.h -Llib/minilibx -lmlx $(OPENGL) $(SANITIZE) $^ -o $@

%.o: %.c
	$(MAKE) -C $(LIBFT)
	$(MAKE) -C $(MINILIBX)
	$(CC) $(CFLAGS) -Imlx -c $^ -o $@

clean:
	rm -rf $(OBJS) $(OBJS_BONUS) $(LIBFT)sources/libft/*.o $(LIBFT)sources/get_next_line/*.o $(MINILIBX)*.o

fclean: clean
	$(RM) $(NAME) $(NAME_BONUS) $(LIBFT)lib/libft/libft.a $(MINILIBX)libmlx.a lib/libft/libft.a libmlx.a

re:		fclean all bonus

.PHONY: all bonus clean fclean re
