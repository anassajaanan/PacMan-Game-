/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aajaanan <aajaanan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 14:13:50 by aajaanan          #+#    #+#             */
/*   Updated: 2023/07/29 08:27:57 by aajaanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_images(t_params *params)
{
	int	width;
	int height;

	params->images.wall = mlx_xpm_file_to_image(params->mlx, "./textures/images/wall.xpm", &width, &height);
	params->images.collectible = mlx_xpm_file_to_image(params->mlx, "./textures/images/collectible.xpm", &width, &height);
	params->images.empty = mlx_xpm_file_to_image(params->mlx, "./textures/images/empty.xpm", &width, &height);
	params->images.img_log = mlx_xpm_file_to_image(params->mlx, "./textures/images/42.xpm", &width, &height);
	params->images.game_over = mlx_xpm_file_to_image(params->mlx, "./textures/images/game_over.xpm", &width, &height);
	params->images.win = mlx_xpm_file_to_image(params->mlx, "./textures/images/win.xpm", &width, &height);
	params->images.exit1 = mlx_xpm_file_to_image(params->mlx, "./textures/images/exit1.xpm", &width, &height);
	params->images.exit2 = mlx_xpm_file_to_image(params->mlx, "./textures/images/exit2.xpm", &width, &height);
}

void	draw_images(t_params *params)
{
	int	i;
	int	j;

	i = 0;
	while (i < params->map.rows)
	{
		j = 0;
		while (j < params->map.cols)
		{
			if (params->map.data[i][j] == '1')
				mlx_put_image_to_window(params->mlx, params->win, params->images.wall, j * 32, i * 32);
			else if (params->map.data[i][j] == 'C')
				mlx_put_image_to_window(params->mlx, params->win, params->images.collectible, j * 32, i * 32);
			else if (params->map.data[i][j] == '0')
				mlx_put_image_to_window(params->mlx, params->win, params->images.img_log, j * 32, i * 32);
			else if (params->map.data[i][j] == 'E')
				mlx_put_image_to_window(params->mlx, params->win, params->images.exit1, j * 32, i * 32);
			j++;
		}
		i++;
	}
}