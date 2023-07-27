/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ghost_movement.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aajaanan <aajaanan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 07:39:15 by aajaanan          #+#    #+#             */
/*   Updated: 2023/07/27 07:49:43 by aajaanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_pink_ghost(t_params *params)
{
	static int counter = 0;
	static int ghost_speed = 20;

	counter++;
	if (counter >= ghost_speed)
	{
		counter = 0;
		if (params->pink.direction == 3 && params->pink.col + 1 >= 0 && params->pink.col + 1 < 23 && params->map_data[params->pink.row][params->pink.col + 1] != '1')
			params->pink.col++;
		else if (params->pink.direction == 2 && params->pink.row + 1 >= 0 && params->pink.row + 1 < 23 && params->map_data[params->pink.row + 1][params->pink.col] != '1')
			params->pink.row++;
		else if (params->pink.direction == 1 && params->pink.col - 1 >= 0 && params->pink.col - 1 < 23 && params->map_data[params->pink.row][params->pink.col - 1] != '1')
			params->pink.col--;
		else if (params->pink.direction == 0 && params->pink.row - 1 >= 0 && params->pink.row - 1 < 23 && params->map_data[params->pink.row - 1][params->pink.col] != '1')
			params->pink.row--;
		else 
			params->pink.direction = rand() % 4;
	}
}

void	move_yellow_ghost(t_params *params)
{
	static int counter = 0;
	static int ghost_speed = 20;

	counter++;
	if (counter >= ghost_speed)
	{
		counter = 0;
		if (params->yellow.direction == 3 && params->yellow.col + 1 >= 0 && params->yellow.col + 1 < 23 && params->map_data[params->yellow.row][params->yellow.col + 1] != '1')
			params->yellow.col++;
		else if (params->yellow.direction == 2 && params->yellow.row + 1 >= 0 && params->yellow.row + 1 < 23 && params->map_data[params->yellow.row + 1][params->yellow.col] != '1')
			params->yellow.row++;
		else if (params->yellow.direction == 1 && params->yellow.col - 1 >= 0 && params->yellow.col - 1 < 23 && params->map_data[params->yellow.row][params->yellow.col - 1] != '1')
			params->yellow.col--;
		else if (params->yellow.direction == 0 && params->yellow.row - 1 >= 0 && params->yellow.row - 1 < 23 && params->map_data[params->yellow.row - 1][params->yellow.col] != '1')
			params->yellow.row--;
		else 
			params->yellow.direction = rand() % 4;
	}
}