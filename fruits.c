/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fruits.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aajaanan <aajaanan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 13:59:38 by aajaanan          #+#    #+#             */
/*   Updated: 2023/07/27 10:07:20 by aajaanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_and_load_fruits(t_params *params)
{
	int	width;
	int height;
	
	params->apple.col = 11;
	params->apple.row = 11;
	params->cherry.col = 1;
	params->cherry.row = 19;
	params->strawberry.col = 1;
	params->strawberry.row = 17;
	params->orange.col = 21;
	params->orange.row = 19;
	params->apple.img = mlx_xpm_file_to_image(params->mlx, "./textures/fruits/apple.xpm", &width, &height);
	params->orange.img = mlx_xpm_file_to_image(params->mlx, "./textures/fruits/orange.xpm", &width, &height);
	params->cherry.img = mlx_xpm_file_to_image(params->mlx, "./textures/fruits/cherry.xpm", &width, &height);
	params->strawberry.img = mlx_xpm_file_to_image(params->mlx, "./textures/fruits/strawberry.xpm", &width, &height);
}

void	draw_fruits(t_params *params)
{
	mlx_put_image_to_window(params->mlx, params->win, params->images.empty, params->apple.col * 32, params->apple.row * 32);
	mlx_put_image_to_window(params->mlx, params->win, params->apple.img, params->apple.col * 32, params->apple.row * 32);
	mlx_put_image_to_window(params->mlx, params->win, params->images.empty, params->cherry.col * 32, params->cherry.row * 32);
	mlx_put_image_to_window(params->mlx, params->win, params->cherry.img, params->cherry.col * 32, params->cherry.row * 32);
	mlx_put_image_to_window(params->mlx, params->win, params->images.empty, params->strawberry.col * 32, params->strawberry.row * 32);
	mlx_put_image_to_window(params->mlx, params->win, params->strawberry.img, params->strawberry.col * 32, params->strawberry.row * 32);
	mlx_put_image_to_window(params->mlx, params->win, params->images.empty, params->orange.col * 32, params->orange.row * 32);
	mlx_put_image_to_window(params->mlx, params->win, params->orange.img, params->orange.col * 32, params->orange.row * 32);
}