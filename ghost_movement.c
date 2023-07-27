/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ghost_movement.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aajaanan <aajaanan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 07:39:15 by aajaanan          #+#    #+#             */
/*   Updated: 2023/07/27 07:43:19 by aajaanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// void	move_pink_ghost(t_params *params)
// {
// 	static int counter = 0;
// 	static int ghost_speed = 20; // Adjust this value to control the ghost's movement speed

// 	counter++;

// 	if (counter >= ghost_speed)
// 	{
// 		counter = 0;
// 		if (params->pink_direction == 3 && params->pink_col + 1 >= 0 && params->pink_col + 1 < 23 && params->data[params->pink_row][params->pink_col + 1] != '1')
// 			params->pink_col++;
// 		else if (params->pink_direction == 2 && params->pink_row + 1 >= 0 && params->pink_row + 1 < 23 && params->data[params->pink_row + 1][params->pink_col] != '1')
// 			params->pink_row++;
// 		else if (params->pink_direction == 1 && params->pink_col - 1 >= 0 && params->pink_col - 1 < 23 && params->data[params->pink_row][params->pink_col - 1] != '1')
// 			params->pink_col--;
// 		else if (params->pink_direction == 0 && params->pink_row - 1 >= 0 && params->pink_row - 1 < 23 && params->data[params->pink_row - 1][params->pink_col] != '1')
// 			params->pink_row--;
// 		else 
// 			params->pink_direction = rand() % 4;
// 	}
// }

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