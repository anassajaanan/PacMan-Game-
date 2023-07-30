/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvements.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aajaanan <aajaanan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 18:19:35 by aajaanan          #+#    #+#             */
/*   Updated: 2023/07/30 10:39:15 by aajaanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#define ANIMATION_DELAY 5

int	is_valid_mov(t_params *params, int row, int col)
{
	if (row < 0 || row > params->map.rows - 1 || col < 0
		|| col > params->map.cols - 1)
		return (0);
	if (params->map.data[row][col] == '1')
		return (0);
	return (1);
}

void	move_player_up(t_params *params)
{
	if (is_valid_mov(params, params->player.row - 1, params->player.col))
	{
		params->player.row--;
		params->player.moves++;
		params->player.direction = 0;
		if (params->map.data[params->player.row][params->player.col] == 'C')
		{
			params->player.score += 10;
			params->map.data[params->player.row][params->player.col] = '2';
		}
		mlx_put_image_to_window(params->mlx, params->win,
			params->player.animation_img, params->player.col * 32,
			params->player.row * 32);
		usleep(ANIMATION_DELAY);
		if (params->player.score == params->map.collectibles * 10)
			params->is_win = 1;
	}
}

void	move_player_left(t_params *params)
{
	if (is_valid_mov(params, params->player.row, params->player.col - 1))
	{
		params->player.col--;
		params->player.moves++;
		params->player.direction = 1;
		if (params->map.data[params->player.row][params->player.col] == 'C')
		{
			params->player.score += 10;
			params->map.data[params->player.row][params->player.col] = '2';
		}
		mlx_put_image_to_window(params->mlx, params->win,
			params->player.animation_img, params->player.col * 32,
			params->player.row * 32);
		usleep(ANIMATION_DELAY);
		if (params->player.score == params->map.collectibles * 10)
			params->is_win = 1;
	}
}

void	move_player_down(t_params *params)
{
	if (is_valid_mov(params, params->player.row + 1, params->player.col))
	{
		params->player.row++;
		params->player.moves++;
		params->player.direction = 2;
		if (params->map.data[params->player.row][params->player.col] == 'C')
		{
			params->player.score += 10;
			params->map.data[params->player.row][params->player.col] = '2';
		}
		mlx_put_image_to_window(params->mlx, params->win,
			params->player.animation_img, params->player.col * 32,
			params->player.row * 32);
		usleep(ANIMATION_DELAY);
		if (params->player.score == params->map.collectibles * 10)
			params->is_win = 1;
	}
}

void	move_player_right(t_params *params)
{
	if (is_valid_mov(params, params->player.row, params->player.col + 1))
	{
		params->player.col++;
		params->player.moves++;
		params->player.direction = 3;
		if (params->map.data[params->player.row][params->player.col] == 'C')
		{
			params->player.score += 10;
			params->map.data[params->player.row][params->player.col] = '2';
		}
		mlx_put_image_to_window(params->mlx, params->win,
			params->player.animation_img, params->player.col * 32,
			params->player.row * 32);
		usleep(ANIMATION_DELAY);
		if (params->player.score == params->map.collectibles * 10)
			params->is_win = 1;
	}
}
