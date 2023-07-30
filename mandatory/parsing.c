/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aajaanan <aajaanan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 18:54:47 by aajaanan          #+#    #+#             */
/*   Updated: 2023/07/30 10:00:20 by aajaanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

int	handle_arguments(int argc, char **argv, t_params *params)
{
	int			len;
	char		*map_file;
	struct stat	file_stat;

	if (argc != 2)
	{
		ft_printf("Usage: %s [map_file.ber]\n", argv[0]);
		return (0);
	}
	map_file = argv[1];
	params->map.map_file = map_file;
	len = ft_strlen(map_file);
	if (len < 4 || ft_strcmp(map_file + len - 4, ".ber") != 0)
	{
		ft_printf("Error: Invalid map file. It should end with '.ber'.\n");
		return (0);
	}
	if (stat(map_file, &file_stat) != 0
		|| !S_ISREG(file_stat.st_mode))
	{
		ft_printf("Error: The specified map file '%s' is not a regular file.\n",
			map_file);
		return (0);
	}
	return (1);
}

int	validate_and_parse_arguments(int argc, char **argv, t_params *params)
{
	init_map(&params->map);
	if (handle_arguments(argc, argv, params)
		&& parse_map(params) && validate_map(params))
		return (1);
	else
		return (0);
}