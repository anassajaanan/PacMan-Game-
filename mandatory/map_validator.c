/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aajaanan <aajaanan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 08:09:58 by aajaanan          #+#    #+#             */
/*   Updated: 2023/07/29 12:19:27 by aajaanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	has_duplicates(t_map *map)
{
	int	num_exits;
	int	num_starting_positions;

	num_exits = count_charcters(map, 'E');
	num_starting_positions = count_charcters(map, 'P');
	if (num_exits > 1)
	{
		ft_printf("Error\n❌ The map contains multiple exit points ❌ \n");
		return (1);
	}
	if (num_starting_positions > 1)
	{
		ft_printf("Error\n❌ The map contains multiple starting positions ❌ \n");
		return (1);
	}
	return (0);
}

int	is_map_rectangular(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->rows)
	{
		if ((int)ft_strlen(map->data[i]) != map->cols)
		{
			ft_printf("Error\n❌ The map is not rectangular ❌ \n");
			return (0);
		}
		i++;
	}
	return (1);
}

int	is_map_closed_by_walls(t_map *map)
{
	int	i;

	i = 1;
	if (!is_row_only_walls(map->data[0])
		|| !is_row_only_walls(map->data[map->rows - 1]))
	{
		ft_printf("Error\n❌ The map is not closed by walls ❌ \n");
		return (0);
	}
	while (i < map->rows - 1)
	{
		if (map->data[i][0] != '1' || map->data[i][map->cols - 1] != '1')
		{
			ft_printf("Error\n❌ The map is not closed by walls ❌ \n");
			return (0);
		}
		i++;
	}
	return (1);
}

int	has_valid_path_to_collectibles(t_params *params)
{
	int	i;
	int	j;

	i = 0;
	while (i < params->map.rows)
	{
		j = 0;
		while (j < params->map.cols)
		{
			if (params->map.data[i][j] == 'C')
			{
				params->map.target.col = j;
				params->map.target.row = i;
				if (!has_valid_path(params))
				{
					ft_printf("❌ No valid path found for collectible at col %d, \
row %d ❌ \n", j, i);
					return (0);
				}
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	validate_map(t_params *params)
{
	if (is_map_rectangular(&params->map) && is_valid_map_format(&params->map)
		&& is_valid_map(&params->map) && !has_duplicates(&params->map)
		&& is_map_closed_by_walls(&params->map) && has_valid_path(params)
		&& has_valid_path_to_collectibles(params))
		return (1);
	return (0);
}
