/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvements.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aajaanan <aajaanan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 18:19:35 by aajaanan          #+#    #+#             */
/*   Updated: 2023/07/26 18:32:52 by aajaanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#define ANIMATION_DELAY 5

int	is_valid_mov(t_params *params, int row, int col)
{
	if (row < 0 || row > 22 || col < 0 || col > 22)
		return (0);
	if (params->map_data[row][col] == '1')
		return (0);
	return (1);
}

void	move_player_up(t_params *params)
{
	params->player.row--;
	params->player.moves++;
	params->player.score += 10;
	params->player.direction = 0;
	params->map_data[params->player.row][params->player.col] = '2';
	mlx_put_image_to_window(params->mlx, params->win, params->player.animation_img, params->player.col * 32, params->player.row * 32);
	usleep(ANIMATION_DELAY);
}

void	move_player_left(t_params *params)
{
	params->player.col--;
	params->player.moves++;
	params->player.score += 10;
	params->player.direction = 1;
	params->map_data[params->player.row][params->player.col] = '2';
	mlx_put_image_to_window(params->mlx, params->win, params->player.animation_img, params->player.col * 32, params->player.row * 32);
	usleep(ANIMATION_DELAY);
}

void	move_player_down(t_params *params)
{
	params->player.row++;
	params->player.moves++;
	params->player.score += 10;
	params->player.direction = 2;
	params->map_data[params->player.row][params->player.col] = '2';
	mlx_put_image_to_window(params->mlx, params->win, params->player.animation_img, params->player.col * 32, params->player.row * 32);
	usleep(ANIMATION_DELAY);
}

void	move_player_right(t_params *params)
{
	params->player.col++;
	params->player.moves++;
	params->player.score += 10;
	params->player.direction = 3;
	params->map_data[params->player.row][params->player.col] = '2';
	mlx_put_image_to_window(params->mlx, params->win, params->player.animation_img, params->player.col * 32, params->player.row * 32);
	usleep(ANIMATION_DELAY);
}