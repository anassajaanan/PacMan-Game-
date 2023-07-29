/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_ghost_movement.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aajaanan <aajaanan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 07:56:19 by aajaanan          #+#    #+#             */
/*   Updated: 2023/07/29 12:56:37 by aajaanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	choose_valid_direction_red(t_params *params, int new_col, int new_row,
		int direction)
{
	if (direction == 0 && new_row > 0 && params->map.data[new_row - 1]
		[new_col] != '1')
		new_row--;
	else if (direction == 1 && new_col < params->map.cols - 1
		&& params->map.data[new_row][new_col + 1] != '1')
		new_col++;
	else if (direction == 2 && new_row < params->map.rows - 1
		&& params->map.data[new_row + 1][new_col] != '1')
		new_row++;
	else if (direction == 3 && new_col > 0 && params->map.data[new_row]
		[new_col - 1] != '1')
		new_col--;
	if (new_col != params->red.col || new_row != params->red.row)
	{
		params->red.col = new_col;
		params->red.row = new_row;
		params->red.direction = direction;
		return (1);
	}
	return (0);
}

void	move_red_ghost_random(t_params *params)
{
	int	i;
	int	new_col;
	int	new_row;
	int	direction;
	int	available_directions[3];

	i = 0;
	shuffle(available_directions, 3);
	get_available_directions(available_directions, params->red.direction);
	while (i < 3)
	{
		direction = available_directions[i];
		new_col = params->red.col;
		new_row = params->red.row;
		if (choose_valid_direction_red(params, new_col, new_row, direction))
			break ;
		i++;
	}
}

void	move_red_ghost_continue(t_params *params)
{
	int	new_col;
	int	new_row;

	new_col = params->red.col;
	new_row = params->red.row;
	if (params->red.direction == 0 && new_row > 0 && params->map.data
		[new_row - 1][new_col] != '1')
		new_row--;
	else if (params->red.direction == 1 && new_col < params->map.cols - 1
		&& params->map.data[new_row][new_col + 1] != '1')
		new_col++;
	else if (params->red.direction == 2 && new_row < params->map.rows - 1
		&& params->map.data[new_row + 1][new_col] != '1')
		new_row++;
	else if (params->red.direction == 3 && new_col > 0
		&& params->map.data[new_row][new_col - 1] != '1')
		new_col--;
	params->red.row = new_row;
	params->red.col = new_col;
}

void	move_red_ghost(t_params *params)
{
	int			has_multiple;
	static int	counter;
	static int	ghost_speed;

	counter = 0;
	ghost_speed = 20;
	counter++;
	if (counter >= ghost_speed)
	{
		counter = 0;
		has_multiple = has_multiple_options(params, params->red.row,
				params->red.col);
		if (has_multiple)
			move_red_ghost_random(params);
		else
			move_red_ghost_continue(params);
	}
}
