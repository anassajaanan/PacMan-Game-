/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ghosts.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aajaanan <aajaanan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 13:34:39 by aajaanan          #+#    #+#             */
/*   Updated: 2023/07/27 08:47:38 by aajaanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void	init_ghosts(t_params *params)
{
	params->red.col = 9;
	params->red.row = 3;
	params->red.direction = 0;
	params->blue.col = 13;
	params->blue.row = 3;
	params->blue.direction = 1;
	params->yellow.col = 13;
	params->yellow.row = 19;
	params->yellow.direction = 1;
	params->pink.col = 9;
	params->pink.row = 19;
	params->pink.direction = 1;
}

void	load_ghosts_imgs(t_params *params)
{
	int	width;
	int	height;

	params->red.img[0] = mlx_xpm_file_to_image(params->mlx, "./textures/ghosts/red/red0.xpm", &width, &height);
	params->red.img[1] = mlx_xpm_file_to_image(params->mlx, "./textures/ghosts/red/red1.xpm", &width, &height);
	params->red.img[2] = mlx_xpm_file_to_image(params->mlx, "./textures/ghosts/red/red2.xpm", &width, &height);
	params->red.img[3] = mlx_xpm_file_to_image(params->mlx, "./textures/ghosts/red/red3.xpm", &width, &height);
	params->blue.img[0] = mlx_xpm_file_to_image(params->mlx, "./textures/ghosts/blue/blue0.xpm", &width, &height);
	params->blue.img[1] = mlx_xpm_file_to_image(params->mlx, "./textures/ghosts/blue/blue1.xpm", &width, &height);
	params->blue.img[2] = mlx_xpm_file_to_image(params->mlx, "./textures/ghosts/blue/blue2.xpm", &width, &height);
	params->blue.img[3] = mlx_xpm_file_to_image(params->mlx, "./textures/ghosts/blue/blue3.xpm", &width, &height);
	params->yellow.img[0] = mlx_xpm_file_to_image(params->mlx, "./textures/ghosts/yellow/yellow0.xpm", &width, &height);
	params->yellow.img[1] = mlx_xpm_file_to_image(params->mlx, "./textures/ghosts/yellow/yellow1.xpm", &width, &height);
	params->yellow.img[2] = mlx_xpm_file_to_image(params->mlx, "./textures/ghosts/yellow/yellow2.xpm", &width, &height);
	params->yellow.img[3] = mlx_xpm_file_to_image(params->mlx, "./textures/ghosts/yellow/yellow3.xpm", &width, &height);
	params->pink.img[0] = mlx_xpm_file_to_image(params->mlx, "./textures/ghosts/pink/pink0.xpm", &width, &height);
	params->pink.img[1] = mlx_xpm_file_to_image(params->mlx, "./textures/ghosts/pink/pink1.xpm", &width, &height);
	params->pink.img[2] = mlx_xpm_file_to_image(params->mlx, "./textures/ghosts/pink/pink2.xpm", &width, &height);
	params->pink.img[3] = mlx_xpm_file_to_image(params->mlx, "./textures/ghosts/pink/pink3.xpm", &width, &height);
}

void	draw_ghosts(t_params *params)
{
	mlx_put_image_to_window(params->mlx, params->win, params->images.empty, params->red.col * 32, params->red.row * 32);
	mlx_put_image_to_window(params->mlx, params->win, params->red.img[params->red.direction], params->red.col * 32, params->red.row * 32);
	mlx_put_image_to_window(params->mlx, params->win, params->images.empty, params->blue.col * 32, params->blue.row * 32);
	mlx_put_image_to_window(params->mlx, params->win, params->blue.img[params->blue.direction], params->blue.col * 32, params->blue.row * 32);
	mlx_put_image_to_window(params->mlx, params->win, params->images.empty, params->yellow.col * 32, params->yellow.row * 32);
	mlx_put_image_to_window(params->mlx, params->win, params->yellow.img[params->yellow.direction], params->yellow.col * 32, params->yellow.row * 32);
	mlx_put_image_to_window(params->mlx, params->win, params->images.empty, params->pink.col * 32, params->pink.row * 32);
	mlx_put_image_to_window(params->mlx, params->win, params->pink.img[params->pink.direction], params->pink.col * 32, params->pink.row * 32);
}