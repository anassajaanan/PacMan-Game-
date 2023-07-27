/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aajaanan <aajaanan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 12:27:21 by aajaanan          #+#    #+#             */
/*   Updated: 2023/07/27 07:43:31 by aajaanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#define WIN_WIDTH 736
#define WIN_HEIGHT 736

# include "./mlx/mlx.h"
# include "./libft/libft.h"
# include "./ft_printf/ft_printf.h"
# include "./get_next_line/get_next_line.h"

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_player
{
	int		col;
	int		row;
	int		score;
	int		moves;
	void	*img[4];
	void	*animation_img;
	int		direction;
}			t_player;

typedef struct s_ghost
{
	int		col;
	int		row;
	void	*img[4];
	int		direction;
}			t_ghost;

typedef struct s_fruit
{
	int		col;
	int		row;
	void	*img;
}			t_fruit;

typedef struct s_images
{
	void	*wall;
	void	*collectible;
	void	*exit;
	void	*empty;
}			t_images;

typedef struct s_params
{
	void		*mlx;
	void		*win;
	t_player	player;
	t_ghost		red;
	t_ghost		blue;
	t_ghost		yellow;
	t_ghost		pink;
	t_fruit		apple;
	t_fruit		orange;
	t_fruit		cherry;
	t_fruit		strawberry;
	char		*map_data[23];
	t_images	images;
}				t_params;


// player.c
void	init_and_load_player(t_params *params);

// ghosts.c
void	init_ghosts(t_params *params);
void	load_ghosts_imgs(t_params *params);
void	draw_ghosts(t_params *params);

// fruits.c
void	init_and_load_fruits(t_params *params);
void	draw_fruits(t_params *params);
void	check_fruit_collision(t_params *params);

// images.c
void	load_images(t_params *params);
void	draw_images(t_params *params);

// parsing.c
void	parse_map_data(t_params *params);

// mouvements.c
int		is_valid_mov(t_params *params, int row, int col);
void	move_player_up(t_params *params);
void	move_player_left(t_params *params);
void	move_player_down(t_params *params);
void	move_player_right(t_params *params);

// ghost_movement.c
void	move_pink_ghost(t_params *params);

#endif // SO_LONG_H