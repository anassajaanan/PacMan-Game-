/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aajaanan <aajaanan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 18:54:47 by aajaanan          #+#    #+#             */
/*   Updated: 2023/07/29 19:47:35 by aajaanan         ###   ########.fr       */
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
	int		len;
	char	*map_file;

	if (argc != 2)
	{
		printf("Usage: %s [map_file.ber]\n", argv[0]);
		return (0);
	}
	params->map.map_file = argv[1];
	map_file = argv[1];
	len = ft_strlen(map_file);
	if (len < 4 || ft_strcmp(map_file + len - 4, ".ber") != 0)
	{
		printf("Error: Invalid map file. It should end with '.ber'.\n");
		return (0);
	}
	return (1);
}
