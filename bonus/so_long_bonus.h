/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aajaanan <aajaanan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 12:27:21 by aajaanan          #+#    #+#             */
/*   Updated: 2023/07/31 07:05:21 by aajaanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "./ft_printf/ft_printf.h"
# include "./get_next_line/get_next_line.h"
# include "./libft/libft.h"
# include "./mlx/mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/stat.h>

typedef struct s_player
{
	int							col;
	int							row;
	int							score;
	int							moves;
	void						*img[4];
	void						*animation_img;
	int							direction;
}								t_player;

typedef struct s_exit
{
	int							col;
	int							row;
}								t_exit;

typedef struct s_ghost
{
	int							col;
	int							row;
	void						*img[4];
	int							direction;
}								t_ghost;

typedef struct s_fruit
{
	int							col;
	int							row;
	void						*img;
}								t_fruit;

typedef struct s_images
{
	void						*wall;
	void						*collectible;
	void						*exit;
	void						*empty;
	void						*exit1;
	void						*exit2;
}								t_images;

typedef struct s_map
{
	int							rows;
	int							cols;
	char						*map_file;
	char						**data;
	int							collectibles;
	t_exit						target;
}								t_map;

struct							s_line_queue_node
{
	char						*val;
	struct s_line_queue_node	*next;
};

typedef struct s_line_queue
{
	struct s_line_queue_node	*front;
	struct s_line_queue_node	*rear;
}								t_line_queue;

typedef struct s_params
{
	void						*mlx;
	void						*win;
	t_map						map;
	t_line_queue				q;
	t_player					player;
	t_exit						exit;
	t_ghost						red;
	t_ghost						blue;
	t_ghost						yellow;
	t_ghost						pink;
	t_fruit						apple;
	t_fruit						orange;
	t_fruit						cherry;
	t_fruit						strawberry;
	t_images					images;
	int							is_game_over;
	int							is_win;
}								t_params;

// player_bonus.c
void							init_and_load_player(t_params *params);
void							draw_player(t_params *params);
void							find_player_and_exit_position(t_params *params);
void							check_ghost_collision(t_params *params);
void							check_fruit_collision(t_params *params);

// ghosts_bonus.c
void							init_ghosts(t_params *params);
void							load_ghosts_imgs(t_params *params);
void							draw_ghosts(t_params *params);

// fruits_bonus.c
void							init_and_load_fruits(t_params *params);
void							draw_fruits(t_params *params);

// images_bonus.c
void							load_images(t_params *params);
void							draw_images(t_params *params);

// image_utils_bonus.c
void							check_image_load_status(t_params *params);
void							destroy_images(t_params *params);

// parsing_bonus.c
void							parse_map_data(t_params *params);

// mouvements_bonus.c
int								is_valid_mov(t_params *params, int row,
									int col);
void							move_player_up(t_params *params);
void							move_player_left(t_params *params);
void							move_player_down(t_params *params);
void							move_player_right(t_params *params);

// ghost_movement_bonus.c
void							move_pink_ghost(t_params *params);
void							move_yellow_ghost(t_params *params);
void							move_blue_ghost(t_params *params);
void							move_red_ghost(t_params *params);

// ghost_movement_utils_bonus.c
void							move_pink(t_params *params);
void							move_yellow(t_params *params);
void							move_blue(t_params *params);
void							move_red(t_params *params);
void							move_ghosts(t_params *params);

// line_queue_bonus.c
void							init_line_queue(t_line_queue *q);
void							enqueue_line(t_line_queue *q, char *line);
char							*dequeue_line(t_line_queue *q);
int								line_queue_is_empty(t_line_queue *q);
int								line_queue_size(t_line_queue *q);

// map_validator_bonus.c
int								has_duplicates(t_map *map);
int								is_map_rectangular(t_map *map);
int								is_map_closed_by_walls(t_map *map);
int								has_valid_path_to_collectibles(
									t_params *params);
int								validate_map(t_params *params);

// map_validator_utils_bonus.c
int								is_valid_character(char c);
int								count_charcters(t_map *map, char c);
int								is_row_only_walls(char *row);
int								is_valid_map_format(t_map *map);
int								is_valid_map(t_map *map);

// map_bonus.c
void							init_map(t_map *map);
void							parse_map_from_queue(t_line_queue *q,
									t_map *map);
int								parse_map(t_params *params);
int								count_collectibles(t_map *map);
void							free_map(t_map *map);

// depth_first_search_bonus.c
int								is_visited(int **visited, int *index, int col,
									int row);
void							mark_visited(int **visited, int *index, int col,
									int row);
int								valid_move(t_map *map, int *new_pos,
									int **visited, int *index);
int								depth_first_search(t_map *map, int *current_pos,
									int **visited, int *index);
int								has_valid_path(t_params *params);

// game_utils_bonus.c
void							display_score_and_moves(t_params *params);
void							get_random_collectible_position(
									t_params *params, int *col, int *row);

// depth_first_search_utils_bonus.c
void							init_position(int array[2], int x, int y);
int								**allocate_visited(t_params *params);
void							free_visited(t_params *params, int **visited);

// parsing_bonus.c
int								handle_arguments(int argc, char **argv,
									t_params *params);
int								validate_and_parse_arguments(int argc,
									char **argv, t_params *params);
void							free_and_destroy(t_params *params);

#endif // SO_LONG_BONUS_H