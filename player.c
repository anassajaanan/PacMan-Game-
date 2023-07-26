/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aajaanan <aajaanan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 13:00:36 by aajaanan          #+#    #+#             */
/*   Updated: 2023/07/26 14:06:52 by aajaanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_and_load_player(t_params *params)
{
	int	width;
	int	height;
	
	params->player.col = 1;
	params->player.row = 1;
	params->player.moves = 0;
	params->player.moves = 0;
	params->player.img[0] = mlx_xpm_file_to_image(params->mlx, "./textures/player/pac_man0.xpm", &width, &height);
	params->player.img[1] = mlx_xpm_file_to_image(params->mlx, "./textures/player/pac_man1.xpm", &width, &height);
	params->player.img[2] = mlx_xpm_file_to_image(params->mlx, "./textures/player/pac_man2.xpm", &width, &height);
	params->player.img[3] = mlx_xpm_file_to_image(params->mlx, "./textures/player/pac_man3.xpm", &width, &height);
	params->player.animation_img = mlx_xpm_file_to_image(params->mlx, "./textures/player/animation.xpm", &width, &height);
}