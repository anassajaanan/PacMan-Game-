/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aajaanan <aajaanan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 13:00:36 by aajaanan          #+#    #+#             */
/*   Updated: 2023/07/30 19:17:45 by aajaanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	init_and_load_player(t_params *params)
{
	int	width;
	int	height;

	params->player.moves = 0;
	params->player.score = 0;
	params->player.direction = 3;
	params->is_game_over = 0;
	params->is_win = 0;
	params->player.img[0] = mlx_xpm_file_to_image(params->mlx,
			"./textures/player/pac_man0.xpm", &width, &height);
	params->player.img[1] = mlx_xpm_file_to_image(params->mlx,
			"./textures/player/pac_man1.xpm", &width, &height);
	params->player.img[2] = mlx_xpm_file_to_image(params->mlx,
			"./textures/player/pac_man2.xpm", &width, &height);
	params->player.img[3] = mlx_xpm_file_to_image(params->mlx,
			"./textures/player/pac_man3.xpm", &width, &height);
	params->player.animation_img = mlx_xpm_file_to_image(params->mlx,
			"./textures/player/animation.xpm", &width, &height);
}

void	draw_player(t_params *params)
{
	mlx_put_image_to_window(params->mlx, params->win,
		params->player.img[params->player.direction], params->player.col * 32,
		params->player.row * 32);
}

void	find_player_and_exit_position(t_params *params)
{
	int	i;
	int	j;

	i = 0;
	while (i < params->map.rows)
	{
		j = 0;
		while (j < params->map.cols)
		{
			if (params->map.data[i][j] == 'P')
			{
				params->player.col = j;
				params->player.row = i;
			}
			else if (params->map.data[i][j] == 'E')
			{
				params->exit.col = j;
				params->exit.row = i;
			}
			j++;
		}
		i++;
	}
	params->map.target.col = params->exit.col;
	params->map.target.row = params->exit.row;
}

void	check_ghost_collision(t_params *params)
{
	if (params->player.col == params->red.col
		&& params->player.row == params->red.row)
		params->is_game_over = 1;
	if (params->player.col == params->blue.col
		&& params->player.row == params->blue.row)
		params->is_game_over = 1;
	if (params->player.col == params->pink.col
		&& params->player.row == params->pink.row)
		params->is_game_over = 1;
	if (params->player.col == params->yellow.col
		&& params->player.row == params->yellow.row)
		params->is_game_over = 1;
}

void	check_fruit_collision(t_params *params)
{
	if (params->player.col == params->apple.col
		&& params->player.row == params->apple.row)
	{
		params->player.score += 700;
		params->apple.col = -1;
	}
	else if (params->player.col == params->orange.col
		&& params->player.row == params->orange.row)
	{
		params->player.score += 500;
		params->orange.col = -1;
	}
	else if (params->player.col == params->strawberry.col
		&& params->player.row == params->strawberry.row)
	{
		params->player.score += 300;
		params->strawberry.col = -1;
	}
	else if (params->player.col == params->cherry.col
		&& params->player.row == params->cherry.row)
	{
		params->player.score += 100;
		params->cherry.col = -1;
	}
}
