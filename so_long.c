/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aajaanan <aajaanan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 12:27:10 by aajaanan          #+#    #+#             */
/*   Updated: 2023/07/26 18:34:13 by aajaanan         ###   ########.fr       */
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
	else if (keycode == 13)
		move_player_up(params);
	else if (keycode == 0)
		move_player_left(params);
	else if (keycode == 1)
		move_player_down(params);
	else if (keycode == 2)
		move_player_right(params);		


		
	return (0);
}

int	update_window(t_params *params)
{
	mlx_clear_window(params->mlx, params->win);
	draw_images(params);
	mlx_put_image_to_window(params->mlx, params->win, params->player.animation_img, params->player.col * 32, params->player.row * 32);
	draw_fruits(params);
	draw_ghosts(params);
	return (0);
}

int main(void)
{
	t_params	params;

	params.mlx = mlx_init();
	params.win = mlx_new_window(params.mlx, WIN_WIDTH, WIN_HEIGHT, "so_long");


	init_and_load_player(&params);
	init_and_load_fruits(&params);
	load_images(&params);
	init_and_load_fruits(&params);
	load_ghosts_imgs(&params);
	init_ghosts(&params);
	parse_map_data(&params);
	
	mlx_hook(params.win, 2, 1L<<0, handle_keypress, &params);
	mlx_loop_hook(params.mlx, update_window, &params);
	mlx_loop(params.mlx);
	return (0);
}