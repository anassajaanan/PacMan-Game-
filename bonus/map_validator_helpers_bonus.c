/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator_helpers_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aajaanan <aajaanan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 12:09:57 by aajaanan          #+#    #+#             */
/*   Updated: 2023/07/30 14:36:57 by aajaanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	is_valid_character(char c)
{
	if (c == '0' || c == '1' || c == 'C' || c == 'E' || c == 'P')
		return (1);
	return (0);
}

int	count_charcters(t_map *map, char c)
{
	int	i;
	int	j;
	int	count;

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

int	is_row_only_walls(char *row)
{
	int	i;

	i = 0;
	while (row[i])
	{
		if (row[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	is_valid_map_format(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->rows)
	{
		j = 0;
		while (j < map->cols)
		{
			if (!is_valid_character(map->data[i][j]))
			{
				ft_printf("Error\n❌ Invalid character '%c' at row %d, column \
%d ❌ \n", map->data[i][j], i, j);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	is_valid_map(t_map *map)
{
	int	num_exits;
	int	num_collectibles;
	int	num_starting_positions;

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
		ft_printf("Error\n❌ The map must contain exactly one starting \
position ❌ \n");
		return (0);
	}
	return (1);
}
