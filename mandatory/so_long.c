/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aajaanan <aajaanan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 12:27:10 by aajaanan          #+#    #+#             */
/*   Updated: 2023/07/30 14:57:30 by aajaanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_and_destroy(t_params *params)
{
	mlx_destroy_image(params->mlx, params->images.wall);
	mlx_destroy_image(params->mlx, params->images.collectible);
	mlx_destroy_image(params->mlx, params->images.empty);
	mlx_destroy_image(params->mlx, params->images.exit1);
	mlx_destroy_image(params->mlx, params->images.exit2);
	mlx_destroy_image(params->mlx, params->player.animation_img);
	mlx_destroy_image(params->mlx, params->player.img[0]);
	mlx_destroy_image(params->mlx, params->player.img[1]);
	mlx_destroy_image(params->mlx, params->player.img[2]);
	mlx_destroy_image(params->mlx, params->player.img[3]);
	mlx_destroy_window(params->mlx, params->win);
	free_map(&params->map);
	exit(0);
}

int	handle_keypress(int keycode, t_params *params)
{
	if (keycode == 53)
	{
		free_and_destroy(params);
		return (0);
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
	free_and_destroy(params);
	return (0);
}

int	update_window(t_params *params)
{
	if (params->is_win && params->player.col == params->exit.col
		&& params->player.row == params->exit.row)
	{
		free_and_destroy(params);
		return (0);
	}
	mlx_clear_window(params->mlx, params->win);
	draw_images(params);
	draw_player(params);
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
		check_image_load_status(&params);
		mlx_hook(params.win, 2, 1L << 0, handle_keypress, &params);
		mlx_hook(params.win, 17, 1L << 17, handle_window_close, &params);
		mlx_loop_hook(params.mlx, update_window, &params);
		mlx_loop(params.mlx);
	}
	exit(0);
}
