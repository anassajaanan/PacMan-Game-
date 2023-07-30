/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   depth_first_search.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aajaanan <aajaanan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 11:07:12 by aajaanan          #+#    #+#             */
/*   Updated: 2023/07/29 10:30:15 by aajaanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_visited(int **visited, int *index, int col, int row)
{
	int	i;

	i = 0;
	while (i < *index)
	{
		if (visited[i][0] == col && visited[i][1] == row)
			return (1);
		i++;
	}
	return (0);
}

void	mark_visited(int **visited, int *index, int col, int row)
{
	visited[(*index)][0] = col;
	visited[(*index)][1] = row;
	(*index)++;
}

int	valid_move(t_map *map, int *new_pos, int **visited, int *index)
{
	if (new_pos[0] < 0 || new_pos[0] >= map->cols || new_pos[1] < 0
		|| new_pos[1] >= map->rows)
		return (0);
	if (is_visited(visited, index, new_pos[0], new_pos[1]))
		return (0);
	if (map->data[new_pos[1]][new_pos[0]] == '1')
		return (0);
	return (1);
}

int	depth_first_search(t_map *map, int *current_pos, int **visited,
		int *index)
{
	int	left[2];
	int	right[2];
	int	up[2];
	int	down[2];

	init_position(left, current_pos[0] - 1, current_pos[1]);
	init_position(up, current_pos[0], current_pos[1] - 1);
	init_position(down, current_pos[0], current_pos[1] + 1);
	init_position(right, current_pos[0] + 1, current_pos[1]);
	if (current_pos[0] == map->target.col && current_pos[1] == map->target.row)
		return (1);
	mark_visited(visited, index, current_pos[0], current_pos[1]);
	if (valid_move(map, left, visited, index) && depth_first_search(map, left,
			visited, index))
		return (1);
	if (valid_move(map, right, visited, index) && depth_first_search(map, right,
			visited, index))
		return (1);
	if (valid_move(map, up, visited, index) && depth_first_search(map, up,
			visited, index))
		return (1);
	if (valid_move(map, down, visited, index) && depth_first_search(map, down,
			visited, index))
		return (1);
	return (0);
}

int	has_valid_path(t_params *params)
{
	int	index;
	int	**visited;
	int	current_pos[2];

	visited = allocate_visited(params);
	if (!visited)
		return (0);
	init_position(current_pos, params->player.col, params->player.row);
	index = 0;
	if (depth_first_search(&params->map, current_pos, visited, &index))
	{
		free_visited(params, visited);
		return (1);
	}
	free_visited(params, visited);
	ft_printf("Error\n❌ No valid path found ❌ \n");
	return (0);
}
