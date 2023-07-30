/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ghost_movement_utils1.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aajaanan <aajaanan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 09:34:00 by aajaanan          #+#    #+#             */
/*   Updated: 2023/07/29 15:40:52 by aajaanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_opposite_direction(int direction)
{
	if (direction == 0)
		return (2);
	else if (direction == 1)
		return (3);
	else if (direction == 2)
		return (0);
	else if (direction == 3)
		return (1);
	return (-1);
}

void	get_available_directions(int *available_directions, int direction)
{
	int	i;
	int	count;
	int	opposite_direction;
	int	directions[4];

	init_directions(directions);
	shuffle(directions, 4);
	opposite_direction = get_opposite_direction(direction);
	i = 0;
	count = 0;
	while (i < 4)
	{
		if (directions[i] != opposite_direction)
		{
			available_directions[count] = directions[i];
			count++;
		}
		if (count == 3)
			break ;
		i++;
	}
}

int	is_valid_move(t_params *params, int row, int col, int direction)
{
	if (direction == 0 && row > 0 && params->map.data[row - 1][col] != '1')
		return (1);
	else if (direction == 1 && col < params->map.cols - 1
		&& params->map.data[row][col + 1] != '1')
		return (1);
	else if (direction == 2 && row < params->map.rows - 1
		&& params->map.data[row + 1][col] != '1')
		return (1);
	else if (direction == 3 && col > 0 && params->map.data[row][col - 1] != '1')
		return (1);
	return (0);
}

void	check_move(t_params *params, int direction, int *new_row, int *new_col)
{
	if (direction == 0 && *new_row > 0 && params->map.data[*new_row - 1]
		[*new_col] != '1')
		(*new_row)--;
	else if (direction == 1 && *new_col < params->map.cols - 1
		&& params->map.data[*new_row][*new_col + 1] != '1')
		(*new_col)++;
	else if (direction == 2 && *new_row < params->map.rows - 1
		&& params->map.data[*new_row + 1][*new_col] != '1')
		(*new_row)++;
	else if (direction == 3 && *new_col > 0 && params->map.data[*new_row]
		[*new_col - 1] != '1')
		(*new_col)--;
}

int	has_multiple_options(t_params *params, int row, int col)
{
	int	i;
	int	options;
	int	new_col;
	int	new_row;
	int	directions[4];

	i = 0;
	options = 0;
	init_directions(directions);
	while (i < 4)
	{
		new_col = col;
		new_row = row;
		check_move(params, directions[i], &new_row, &new_col);
		if (new_col != col || new_row != row)
			options++;
		i++;
	}
	if (options > 1)
		return (1);
	return (0);
}
