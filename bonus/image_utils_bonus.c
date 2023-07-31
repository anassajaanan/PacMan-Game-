/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aajaanan <aajaanan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 17:21:35 by aajaanan          #+#    #+#             */
/*   Updated: 2023/07/31 07:08:14 by aajaanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	check_image_load_status(t_params *params)
{
	if (!params->images.wall || !params->images.collectible
		|| !params->images.empty || !params->images.exit1
		|| !params->images.exit2 || !params->player.img[0]
		|| !params->player.img[1] || !params->player.img[2]
		|| !params->player.img[3] || !params->player.animation_img
		|| !params->apple.img || !params->orange.img
		|| !params->cherry.img || !params->strawberry.img
		|| !params->red.img[0] || !params->red.img[1]
		|| !params->red.img[2] || !params->red.img[3]
		|| !params->pink.img[0] || !params->pink.img[1]
		|| !params->pink.img[2] || !params->pink.img[3]
		|| !params->yellow.img[0] || !params->yellow.img[1]
		|| !params->yellow.img[2] || !params->yellow.img[3]
		|| !params->blue.img[0] || !params->blue.img[1]
		|| !params->blue.img[2] || !params->blue.img[3])
	{
		ft_printf("Error\n❌ Failed to load one or more images. ❌ \n");
		free_and_destroy(params);
		exit(1);
	}
}

void	destroy_images2(t_params *params)
{
	if (params->yellow.img[2])
		mlx_destroy_image(params->mlx, params->yellow.img[2]);
	if (params->yellow.img[3])
		mlx_destroy_image(params->mlx, params->yellow.img[3]);
	if (params->blue.img[0])
		mlx_destroy_image(params->mlx, params->blue.img[0]);
	if (params->blue.img[1])
		mlx_destroy_image(params->mlx, params->blue.img[1]);
	if (params->blue.img[2])
		mlx_destroy_image(params->mlx, params->blue.img[2]);
	if (params->blue.img[3])
		mlx_destroy_image(params->mlx, params->blue.img[3]);
}

void	destroy_images1(t_params *params)
{
	if (params->cherry.img)
		mlx_destroy_image(params->mlx, params->cherry.img);
	if (params->strawberry.img)
		mlx_destroy_image(params->mlx, params->strawberry.img);
	if (params->red.img[0])
		mlx_destroy_image(params->mlx, params->red.img[0]);
	if (params->red.img[1])
		mlx_destroy_image(params->mlx, params->red.img[1]);
	if (params->red.img[2])
		mlx_destroy_image(params->mlx, params->red.img[2]);
	if (params->red.img[3])
		mlx_destroy_image(params->mlx, params->red.img[3]);
	if (params->pink.img[0])
		mlx_destroy_image(params->mlx, params->pink.img[0]);
	if (params->pink.img[1])
		mlx_destroy_image(params->mlx, params->pink.img[1]);
	if (params->pink.img[2])
		mlx_destroy_image(params->mlx, params->pink.img[2]);
	if (params->pink.img[3])
		mlx_destroy_image(params->mlx, params->pink.img[3]);
	if (params->yellow.img[0])
		mlx_destroy_image(params->mlx, params->yellow.img[0]);
	if (params->yellow.img[1])
		mlx_destroy_image(params->mlx, params->yellow.img[1]);
	destroy_images2(params);
}

void	destroy_images(t_params *params)
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
	if (params->player.img[0])
		mlx_destroy_image(params->mlx, params->player.img[0]);
	if (params->player.img[1])
		mlx_destroy_image(params->mlx, params->player.img[1]);
	if (params->player.img[2])
		mlx_destroy_image(params->mlx, params->player.img[2]);
	if (params->player.img[3])
		mlx_destroy_image(params->mlx, params->player.img[3]);
	if (params->player.animation_img)
		mlx_destroy_image(params->mlx, params->player.animation_img);
	if (params->apple.img)
		mlx_destroy_image(params->mlx, params->apple.img);
	if (params->orange.img)
		mlx_destroy_image(params->mlx, params->orange.img);
	destroy_images1(params);
}
