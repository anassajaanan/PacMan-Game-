/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aajaanan <aajaanan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 12:27:10 by aajaanan          #+#    #+#             */
/*   Updated: 2023/07/30 10:57:39 by aajaanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_keypress(int keycode, t_params *params)
{
	if (keycode == 53)
	{
		mlx_destroy_window(params->mlx, params->win);
		exit(0);
	}
	else if (keycode == 13 || keycode == 126)
		move_player_up(params);
	else if (keycode == 0 || keycode == 123)
		move_player_left(params);
	else if (keycode == 1 || keycode == 125)
		move_player_down(params);
	else if (keycode == 2 || keycode == 124)
		move_player_right(params);
	return (0);
}

int	handle_window_close(t_params *params)
{
	mlx_destroy_window(params->mlx, params->win);
	exit(0);
	return (0);
}

int	update_window(t_params *params)
{
	if (params->is_win && params->player.col == params->exit.col
		&& params->player.row == params->exit.row)
	{
		mlx_destroy_window(params->mlx, params->win);
		exit(0);
		return (0);
	}
	mlx_clear_window(params->mlx, params->win);
	draw_images(params);
	mlx_put_image_to_window(params->mlx, params->win,
		params->player.img[params->player.direction], params->player.col * 32,
		params->player.row * 32);
	display_score_and_moves(params);
	return (0);
}

int	main(int argc, char **argv)
{
	t_params	params;

	if (validate_and_parse_arguments(argc, argv, &params))
	{
		params.mlx = mlx_init();
		params.win = mlx_new_window(params.mlx, params.map.cols * 32,
				params.map.rows * 32, "so_long");
		init_and_load_player(&params);
		load_images(&params);
		mlx_hook(params.win, 2, 1L << 0, handle_keypress, &params);
		mlx_hook(params.win, 17, 1L << 17, handle_window_close, &params);
		mlx_loop_hook(params.mlx, update_window, &params);
		mlx_loop(params.mlx);
	}
	if (params.map.data)
		free_map(&params.map);
	return (0);
}
