/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aajaanan <aajaanan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 13:00:36 by aajaanan          #+#    #+#             */
/*   Updated: 2023/07/30 10:31:46 by aajaanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_and_load_player(t_params *params)
{
	int	width;
	int	height;

	params->player.moves = 0;
	params->player.score = 0;
	params->player.direction = 3;
	params->player.img[0] = mlx_xpm_file_to_image(params->mlx,
			"./textures/player/pac_man0.xpm", &width, &height);
	params->player.img[1] = mlx_xpm_file_to_image(params->mlx,
			"./textures/player/pac_man1.xpm", &width, &height);
	params->player.img[2] = mlx_xpm_file_to_image(params->mlx,
			"./textures/player/pac_man2.xpm", &width, &height);
	params->player.img[3] = mlx_xpm_file_to_image(params->mlx,
			"./textures/player/pac_man3.xpm", &width, &height);
	params->player.animation_img = mlx_xpm_file_to_image(params->mlx,
			"./textures/player/animation.xpm", &width, &height);
}

void	find_player_and_exit_position(t_params *params)
{
	int	i;
	int	j;

	i = 0;
	while (i < params->map.rows)
	{
		j = 0;
		while (j < params->map.cols)
		{
			if (params->map.data[i][j] == 'P')
			{
				params->player.col = j;
				params->player.row = i;
			}
			else if (params->map.data[i][j] == 'E')
			{
				params->exit.col = j;
				params->exit.row = i;
			}
			j++;
		}
		i++;
	}
	params->map.target.col = params->exit.col;
	params->map.target.row = params->exit.row;
}

