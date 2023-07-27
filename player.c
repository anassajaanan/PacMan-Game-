/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aajaanan <aajaanan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 13:00:36 by aajaanan          #+#    #+#             */
/*   Updated: 2023/07/27 10:07:24 by aajaanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_and_load_player(t_params *params)
{
	int	width;
	int	height;
	
	params->player.col = 1;
	params->player.row = 1;
	params->player.moves = 0;
	params->player.moves = 0;
	params->player.direction = 3;
	params->player.img[0] = mlx_xpm_file_to_image(params->mlx, "./textures/player/pac_man0.xpm", &width, &height);
	params->player.img[1] = mlx_xpm_file_to_image(params->mlx, "./textures/player/pac_man1.xpm", &width, &height);
	params->player.img[2] = mlx_xpm_file_to_image(params->mlx, "./textures/player/pac_man2.xpm", &width, &height);
	params->player.img[3] = mlx_xpm_file_to_image(params->mlx, "./textures/player/pac_man3.xpm", &width, &height);
	params->player.animation_img = mlx_xpm_file_to_image(params->mlx, "./textures/player/animation.xpm", &width, &height);
}

void	check_ghost_collision(t_params *params)
{
	if (params->player.col == params->red.col && params->player.row == params->red.row)
	{
		mlx_destroy_window(params->mlx, params->win);
		exit(0);
	}
	if (params->player.col == params->blue.col && params->player.row == params->blue.row)
	{
		mlx_destroy_window(params->mlx, params->win);
		exit(0);
	}
	if (params->player.col == params->pink.col && params->player.row == params->pink.row)
	{
		mlx_destroy_window(params->mlx, params->win);
		exit(0);
	}
	if (params->player.col == params->yellow.col && params->player.row == params->yellow.row)
	{
		mlx_destroy_window(params->mlx, params->win);
		exit(0);
	}
}

void	check_fruit_collision(t_params *params)
{
	if (params->player.col == params->apple.col && params->player.row == params->apple.row)
	{
		params->player.score += 700;
		params->apple.col = -1;
		params->apple.row = -1;
	}
	else if (params->player.col == params->orange.col && params->player.row == params->orange.row)
	{
		params->player.score += 500;
		params->orange.col = -1;
		params->orange.row = -1;
	}
	else if (params->player.col == params->strawberry.col && params->player.row == params->strawberry.row)
	{
		params->player.score += 300;
		params->strawberry.col = -1;
		params->strawberry.row = -1;
	}
	else if (params->player.col == params->cherry.col && params->player.row == params->cherry.row)
	{
		params->player.score += 100;
		params->cherry.col = -1;
		params->cherry.row = -1;
	}
}