/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aajaanan <aajaanan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 18:54:47 by aajaanan          #+#    #+#             */
/*   Updated: 2023/07/30 15:10:27 by aajaanan         ###   ########.fr       */
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
		ft_printf("Error\n❌ Invalid map file. It should end with '.ber' ❌ \n");
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

void	free_and_destroy(t_params *params)
{
	if (params->images.wall)
		mlx_destroy_image(params->mlx, params->images.wall);
	if (params->images.collectible)
		mlx_destroy_image(params->mlx, params->images.collectible);
	if (params->images.empty)
		mlx_destroy_image(params->mlx, params->images.empty);
	if (params->images.exit1)
		mlx_destroy_image(params->mlx, params->images.exit1);
	if (params->images.exit2)
		mlx_destroy_image(params->mlx, params->images.exit2);
	if (params->player.animation_img)
		mlx_destroy_image(params->mlx, params->player.animation_img);
	if (params->player.img[0])
		mlx_destroy_image(params->mlx, params->player.img[0]);
	if (params->player.img[1])
		mlx_destroy_image(params->mlx, params->player.img[1]);
	if (params->player.img[2])
		mlx_destroy_image(params->mlx, params->player.img[2]);
	if (params->player.img[3])
		mlx_destroy_image(params->mlx, params->player.img[3]);
	mlx_destroy_window(params->mlx, params->win);
	free_map(&params->map);
	exit(0);
}
