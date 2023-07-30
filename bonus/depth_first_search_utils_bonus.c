/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   depth_first_search_utils_bonus.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aajaanan <aajaanan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 10:18:11 by aajaanan          #+#    #+#             */
/*   Updated: 2023/07/30 14:35:48 by aajaanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	init_position(int array[2], int x, int y)
{
	array[0] = x;
	array[1] = y;
}

int	**allocate_visited(t_params *params)
{
	int	i;
	int	**visited;

	i = 0;
	visited = (int **)malloc(sizeof(int *) * params->map.rows
			* params->map.cols);
	if (!visited)
		return (NULL);
	while (i < params->map.rows * params->map.cols)
	{
		visited[i] = (int *)malloc(sizeof(int) * 2);
		if (!visited[i])
			return (NULL);
		i++;
	}
	return (visited);
}

void	free_visited(t_params *params, int **visited)
{
	int	i;

	i = 0;
	while (i < params->map.rows * params->map.cols)
	{
		free(visited[i]);
		i++;
	}
	free(visited);
}
