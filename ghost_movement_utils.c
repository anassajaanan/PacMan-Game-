/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ghost_movement_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aajaanan <aajaanan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 09:34:00 by aajaanan          #+#    #+#             */
/*   Updated: 2023/07/27 09:54:43 by aajaanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void shuffle(int *array, int n)
{
    int	i;
	int	j;
	int	temp;
	
	i = n - 1;
	while (i > 0)
	{
		j = rand() % (i + 1);
		temp = array[i];
		array[i] = array[j];
		array[j] = temp;
		i--;
	}
}

int get_opposite_direction(int direction)
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

void get_available_directions(int *available_directions, int direction)
{
	int	i;
	int count;
	int opposite_direction;
    int	directions[4] = {0, 1, 2, 3};
	
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
			break;
		i++;
	}
}

int is_valid_move(t_params *params, int row, int col, int direction)
{
    if (direction == 0 && row > 0 && params->map_data[row - 1][col] != '1')
        return 1;
    else if (direction == 1 && col < 22 && params->map_data[row][col + 1] != '1')
        return 1;
    else if (direction == 2 && row < 22 && params->map_data[row + 1][col] != '1')
        return 1;
    else if (direction == 3 && col > 0 && params->map_data[row][col - 1] != '1')
        return 1;
    return 0;
}

int has_multiple_options(t_params *params, int row, int col)
{
	int	i;
    int	options;
	int	new_col;
	int	new_row;
    int	directions[4] = {0, 1, 2, 3}; // Array of possible directions (0: up, 1: right, 2: down, 3: left)

	i = 0;
	options = 0;
	while (i < 4)
	{
		new_col = col;
		new_row = row;
		if (directions[i] == 0 && new_row > 0 && params->map_data[new_row - 1][new_col] != '1')
			new_row--;
		else if (directions[i] == 1 && new_col < 22 && params->map_data[new_row][new_col + 1] != '1')
			new_col++;
		else if (directions[i] == 2 && new_row < 22 && params->map_data[new_row + 1][new_col] != '1')
			new_row++;
		else if (directions[i] == 3 && new_col > 0 && params->map_data[new_row][new_col - 1] != '1')
			new_col--;
		if (new_col != col || new_row != row)
			options++;
		i++;
	}
	if (options > 1)
		return (1);
	return (0);
}