/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aajaanan <aajaanan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 08:09:58 by aajaanan          #+#    #+#             */
/*   Updated: 2023/07/29 06:53:24 by aajaanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int is_valid_character(char c)
{
	if (c == '0' || c == '1' || c == 'C' || c == 'E' || c == 'P')
		return (1);
	return (0);
}

int count_charcters(t_map *map, char c)
{
	int i;
	int j;
	int count;

	i = 0;
	count = 0;
	while (i < map->rows)
	{
		j = 0;
		while (j < map->cols)
		{
			if (map->data[i][j] == c)
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

int is_valid_map_format(t_map *map)
{
	int i;
	int j;

	i = 0;
	while (i < map->rows)
	{
		j = 0;
		while (j < map->cols)
		{
			if (!is_valid_character(map->data[i][j]))
			{
				ft_printf("Error\n❌ Invalid character '%c' at row %d, column %d ❌ \n", map->data[i][j], i, j);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int is_valid_map(t_map *map)
{
	int num_exits;
	int num_collectibles;
	int num_starting_positions;

	num_exits = count_charcters(map, 'E');
	num_collectibles = count_charcters(map, 'C');
	num_starting_positions = count_charcters(map, 'P');
	if (num_exits != 1)
	{
		ft_printf("Error\n❌ The map must contain exactly one exit point ❌ \n");
		return (0);
	}
	else if (num_collectibles < 1)
	{
		ft_printf("Error\n❌ The map must contain at least one collectible ❌ \n");
		return (0);
	}
	else if (num_starting_positions != 1)
	{
		ft_printf("Error\n❌ The map must contain exactly one starting position ❌ \n");
		return (0);
	}
	return (1);
}

int has_duplicates(t_map *map)
{
	int num_exits;
	int num_starting_positions;

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

int is_map_rectangular(t_map *map)
{
	int i;

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

int is_row_only_walls(char *row)
{
	int i;

	i = 0;
	while (row[i])
	{
		if (row[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int is_map_closed_by_walls(t_map *map)
{
	int i;

	i = 1;
	if (!is_row_only_walls(map->data[0]) || !is_row_only_walls(map->data[map->rows - 1]))
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
					ft_printf("❌ No valid path found for collectible at col %d, row %d ❌ \n", j, i);
					return (0);
				}
			}
			j++;
		}
		i++;
	}
	return (1);
}

int validate_map(t_params *params)
{
	if (is_map_rectangular(&params->map) && is_valid_map_format(&params->map) && is_valid_map(&params->map) && !has_duplicates(&params->map)
		&& is_map_closed_by_walls(&params->map) && has_valid_path(params) &&  has_valid_path_to_collectibles(params))
		return (1);
	return (0);
}
