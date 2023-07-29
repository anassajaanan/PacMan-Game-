/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aajaanan <aajaanan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 12:27:10 by aajaanan          #+#    #+#             */
/*   Updated: 2023/07/29 06:53:39 by aajaanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// void	display_score_and_moves(t_params *params)
// {
// 	char	*moves;
// 	char	*score;
	
// 	moves = ft_strjoin("Moves: ", ft_itoa(params->player.moves));
// 	score = ft_strjoin("Score: ", ft_itoa(params->player.score));
//     mlx_string_put(params->mlx, params->win, 100, 20, 0xFFFFFF, moves);
// 	mlx_string_put(params->mlx, params->win, 500, 20, 0xFFFFFF, score);
	
// 	free(moves);
// 	free(score);
// }

// int	handle_keypress(int keycode, t_params *params)
// {
// 	if (keycode == 53)
// 	{
// 		mlx_destroy_window(params->mlx, params->win);
// 		exit(0);
// 	}
// 	else if (keycode == 13)
// 		move_player_up(params);
// 	else if (keycode == 0)
// 		move_player_left(params);
// 	else if (keycode == 1)
// 		move_player_down(params);
// 	else if (keycode == 2)
// 		move_player_right(params);		


		
// 	return (0);
// }

// int	update_window(t_params *params)
// {
// 	if (params->player.score>= 5230)
// 	{
// 		mlx_clear_window(params->mlx, params->win);
// 		mlx_put_image_to_window(params->mlx, params->win, params->images.win, 0, 0);
// 		return (0);
// 	}
// 	if (params->is_game_over)
// 	{
// 		mlx_clear_window(params->mlx, params->win);
// 		mlx_put_image_to_window(params->mlx, params->win, params->images.game_over, 0, 0);
// 		return (0);
// 	}
// 	mlx_clear_window(params->mlx, params->win);
// 	draw_images(params);
// 	mlx_put_image_to_window(params->mlx, params->win, params->player.img[params->player.direction], params->player.col * 32, params->player.row * 32);
// 	draw_fruits(params);
// 	draw_ghosts(params);
// 	move_pink_ghost(params);
// 	move_yellow_ghost(params);
// 	move_blue_ghost(params);
// 	move_red_ghost(params);
// 	display_score_and_moves(params);
// 	check_ghost_collision(params);
// 	return (0);
// }

// int main(void)
// {
// 	t_params	params;

// 	params.mlx = mlx_init();
// 	params.win = mlx_new_window(params.mlx, WIN_WIDTH, WIN_HEIGHT, "so_long");
// 	params.is_game_over = 0;


// 	init_and_load_player(&params);
// 	init_and_load_fruits(&params);
// 	load_images(&params);
// 	init_and_load_fruits(&params);
// 	load_ghosts_imgs(&params);
// 	init_ghosts(&params);
// 	parse_map_data(&params);
	
// 	mlx_hook(params.win, 2, 1L<<0, handle_keypress, &params);
// 	mlx_loop_hook(params.mlx, update_window, &params);
// 	mlx_loop(params.mlx);
// 	return (0);
// }

int main(void)
{
	t_params	params;

	// params.mlx = mlx_init();
	// params.win = mlx_new_window(params.mlx, WIN_WIDTH, WIN_HEIGHT, "so_long");
	// params.is_game_over = 0;

	parse_map(&params);

	ft_printf("rows: %d\n", params.map.rows);
	ft_printf("cols: %d\n", params.map.cols);
	ft_printf("player col: %d\n", params.player.col);
	ft_printf("player row: %d\n", params.player.row);
	ft_printf("exit col: %d\n", params.exit.col);
	ft_printf("exit row: %d\n", params.exit.row);
	ft_printf("collectibles: %d\n", params.map.collectibles);
	
	int res = validate_map(&params);
	if (res)
		ft_printf("Map is valid\n");


	
	return (0);
}