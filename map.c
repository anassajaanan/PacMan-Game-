/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aajaanan <aajaanan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 07:45:38 by aajaanan          #+#    #+#             */
/*   Updated: 2023/07/29 12:28:58 by aajaanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_map(t_map *map)
{
	map->rows = 0;
	map->cols = 0;
	map->data = NULL;
}

void	parse_map_from_queue(t_line_queue *q, t_map *map)
{
	int	i;
	int	cols;

	map->rows = line_queue_size(q);
	map->data = (char **)malloc(sizeof(char *) * map->rows);
	if (map->data == NULL)
	{
		ft_printf("Error: malloc failed\n");
		exit(1);
	}
	i = 0;
	cols = 0;
	while (i < map->rows)
	{
		map->data[i] = dequeue_line(q);
		if ((int)ft_strlen(map->data[i]) > cols)
			cols = ft_strlen(map->data[i]);
		i++;
	}
	map->cols = cols;
}

int	count_collectibles(t_map *map)
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
			if (map->data[i][j] == 'C')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

void	parse_map(t_params *params)
{
	int		fd;
	char	*line;

	init_line_queue(&params->q);
	init_map(&params->map);
	fd = open("./maps/map.ber", O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		enqueue_line(&params->q, ft_strtrim(line, "\n"));
		free(line);
		line = get_next_line(fd);
	}
	parse_map_from_queue(&params->q, &params->map);
	find_player_and_exit_position(params);
	params->map.collectibles = count_collectibles(&params->map);
}

void	free_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->rows)
	{
		free(map->data[i]);
		i++;
	}
	free(map->data);
}
