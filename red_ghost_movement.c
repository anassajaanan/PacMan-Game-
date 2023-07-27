/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_ghost_movement.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aajaanan <aajaanan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 07:56:19 by aajaanan          #+#    #+#             */
/*   Updated: 2023/07/27 08:31:31 by aajaanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void shuffle(int *array, int n)
{
    for (int i = n - 1; i > 0; i--)
    {
        int j = rand() % (i + 1);
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
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

void	move_red_ghost_random(t_params *params)
{
	int	i;
	int	new_col;
	int	new_row;
	int direction;
    int directions[4] = {0, 1, 2, 3};
    
	shuffle(directions, 4);
	i = 0;
	while (i < 4)
	{
		direction = directions[i];
		new_col = params->red.col;
		new_row = params->red.row;
		if (direction == 0 && new_row > 0 && params->map_data[new_row - 1][new_col] != '1')
			new_row--;
		else if (direction == 1 && new_col < 22 && params->map_data[new_row][new_col + 1] != '1')
			new_col++;
		else if (direction == 2 && new_row < 22 && params->map_data[new_row + 1][new_col] != '1')
			new_row++;
		else if (direction == 3 && new_col > 0 && params->map_data[new_row][new_col - 1] != '1')
			new_col--;
		if (new_col != params->red.col || new_row != params->red.row)
		{
			params->red.col = new_col;
			params->red.row = new_row;
			params->red.direction = direction;
			break;
		}
		i++;
	}
}

void	move_red_ghost_continue(t_params *params)
{
    int new_col;
    int new_row;

	new_col = params->red.col;
	new_row = params->red.row;
    if (params->red.direction == 0 && new_row > 0 && params->map_data[new_row - 1][new_col] != '1')
		new_row--;
    else if (params->red.direction == 1 && new_col < 22 && params->map_data[new_row][new_col + 1] != '1')
        new_col++;
    else if (params->red.direction == 2 && new_row < 22 && params->map_data[new_row + 1][new_col] != '1')
        new_row++;
    else if (params->red.direction == 3 && new_col > 0 && params->map_data[new_row][new_col - 1] != '1')
        new_col--;
    params->red.row = new_row;
    params->red.col = new_col;
}

void	move_red_ghost(t_params *params)
{
	// int has_multiple;
    static int counter = 0;
    static int ghost_speed = 20;

    counter++;
    if (counter >= ghost_speed)
    {
        counter = 0;

        int has_multiple = has_multiple_options(params, params->red.row, params->red.col);
        if (has_multiple)
            move_red_ghost_random(params);
        else
            move_red_ghost_continue(params);
    }
}
