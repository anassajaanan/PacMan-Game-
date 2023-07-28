/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blue_ghost_algorithm.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aajaanan <aajaanan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 09:41:19 by aajaanan          #+#    #+#             */
/*   Updated: 2023/07/28 19:58:49 by aajaanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h" 

int	choose_valid_direction_blue(t_params *params, int new_col, int new_row, int direction)
{
	if (direction == 0 && new_row > 0 && params->map.data[new_row - 1][new_col] != '1')
		new_row--;
	else if (direction == 1 && new_col < params->map.cols - 1 && params->map.data[new_row][new_col + 1] != '1')
		new_col++;
	else if (direction == 2 && new_row < params->map.rows - 1 && params->map.data[new_row + 1][new_col] != '1')
		new_row++;
	else if (direction == 3 && new_col > 0 && params->map.data[new_row][new_col - 1] != '1')
		new_col--;
	if (new_col != params->blue.col || new_row != params->blue.row)
	{
		params->blue.col = new_col;
		params->blue.row = new_row;
		params->blue.direction = direction;
		return (1);
	}
	return (0);
}

void	move_blue_ghost_random(t_params *params)
{
	int	i;
	int	new_col;
	int	new_row;
	int	direction;
	int available_directions[3];
	
	i = 0;
    shuffle(available_directions, 3);
	get_available_directions(available_directions, params->blue.direction);
	while (i < 3)
	{
		direction = available_directions[i];
		new_col = params->blue.col;
		new_row = params->blue.row;
		if (choose_valid_direction_blue(params, new_col, new_row, direction))
			break;
		i++;
	}
}

void	move_blue_ghost_continue(t_params *params)
{
	int new_col;
	int new_row;

	new_col = params->blue.col;
	new_row = params->blue.row;
	if (params->blue.direction == 0 && new_row > 0 && params->map.data[new_row - 1][new_col] != '1')
		new_row--;
	else if (params->blue.direction == 1 && new_col < params->map.cols - 1 && params->map.data[new_row][new_col + 1] != '1')
		new_col++;
	else if (params->blue.direction == 2 && new_row < params->map.rows - 1 && params->map.data[new_row + 1][new_col] != '1')
		new_row++;
	else if (params->blue.direction == 3 && new_col > 0 && params->map.data[new_row][new_col - 1] != '1')
		new_col--;
	params->blue.row = new_row;
	params->blue.col = new_col;
}

void	move_blue_ghost(t_params *params)
{
	int has_multiple;
	static int counter = 0;
	static int ghost_speed = 20;

	counter++;
	if (counter >= ghost_speed)
	{
		counter = 0;
		has_multiple = has_multiple_options(params, params->blue.row, params->blue.col);
		if (has_multiple)
			move_blue_ghost_random(params);
		else
			move_blue_ghost_continue(params);
	}
}