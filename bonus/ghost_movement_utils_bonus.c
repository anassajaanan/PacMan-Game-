/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ghost_movement_utils_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aajaanan <aajaanan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 16:49:11 by aajaanan          #+#    #+#             */
/*   Updated: 2023/07/30 16:49:48 by aajaanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	move_pink(t_params *params)
{
	if (params->pink.direction == 3 && params->pink.col + 1 >= 0
		&& params->pink.col + 1 < params->map.cols
		&& params->map.data[params->pink.row][params->pink.col + 1] != '1')
		params->pink.col++;
	else if (params->pink.direction == 2 && params->pink.row + 1 >= 0
		&& params->pink.row + 1 < params->map.rows
		&& params->map.data[params->pink.row + 1][params->pink.col] != '1')
		params->pink.row++;
	else if (params->pink.direction == 1 && params->pink.col - 1 >= 0
		&& params->pink.col - 1 < params->map.cols
		&& params->map.data[params->pink.row][params->pink.col - 1] != '1')
		params->pink.col--;
	else if (params->pink.direction == 0 && params->pink.row - 1 >= 0
		&& params->pink.row - 1 < params->map.rows
		&& params->map.data[params->pink.row - 1][params->pink.col] != '1')
		params->pink.row--;
	else 
		params->pink.direction = rand() % 4;
}

void	move_yellow(t_params *params)
{
	if (params->yellow.direction == 3 && params->yellow.col + 1 >= 0
		&& params->yellow.col + 1 < params->map.cols
		&& params->map.data[params->yellow.row][params->yellow.col + 1] != '1')
		params->yellow.col++;
	else if (params->yellow.direction == 2 && params->yellow.row + 1 >= 0
		&& params->yellow.row + 1 < params->map.rows
		&& params->map.data[params->yellow.row + 1][params->yellow.col] != '1')
		params->yellow.row++;
	else if (params->yellow.direction == 1 && params->yellow.col - 1 >= 0
		&& params->yellow.col - 1 < params->map.cols
		&& params->map.data[params->yellow.row][params->yellow.col - 1] != '1')
		params->yellow.col--;
	else if (params->yellow.direction == 0 && params->yellow.row - 1 >= 0
		&& params->yellow.row - 1 < params->map.rows
		&& params->map.data[params->yellow.row - 1][params->yellow.col] != '1')
		params->yellow.row--;
	else 
		params->yellow.direction = rand() % 4;
}

void	move_blue(t_params *params)
{
	if (params->blue.direction == 3 && params->blue.col + 1 >= 0
		&& params->blue.col + 1 < params->map.cols
		&& params->map.data[params->blue.row][params->blue.col + 1] != '1')
		params->blue.col++;
	else if (params->blue.direction == 2 && params->blue.row + 1 >= 0
		&& params->blue.row + 1 < params->map.rows
		&& params->map.data[params->blue.row + 1][params->blue.col] != '1')
		params->blue.row++;
	else if (params->blue.direction == 1 && params->blue.col - 1 >= 0
		&& params->blue.col - 1 < params->map.cols
		&& params->map.data[params->blue.row][params->blue.col - 1] != '1')
		params->blue.col--;
	else if (params->blue.direction == 0 && params->blue.row - 1 >= 0
		&& params->blue.row - 1 < params->map.rows
		&& params->map.data[params->blue.row - 1][params->blue.col] != '1')
		params->blue.row--;
	else 
		params->blue.direction = rand() % 4;
}

void	move_red(t_params *params)
{
	if (params->red.direction == 3 && params->red.col + 1 >= 0
		&& params->red.col + 1 < params->map.cols
		&& params->map.data[params->red.row][params->red.col + 1] != '1')
		params->red.col++;
	else if (params->red.direction == 2 && params->red.row + 1 >= 0
		&& params->red.row + 1 < params->map.rows
		&& params->map.data[params->red.row + 1][params->red.col] != '1')
		params->red.row++;
	else if (params->red.direction == 1 && params->red.col - 1 >= 0
		&& params->red.col - 1 < params->map.cols
		&& params->map.data[params->red.row][params->red.col - 1] != '1')
		params->red.col--;
	else if (params->red.direction == 0 && params->red.row - 1 >= 0
		&& params->red.row - 1 < params->map.rows
		&& params->map.data[params->red.row - 1][params->red.col] != '1')
		params->red.row--;
	else 
		params->red.direction = rand() % 4;
}
