/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ghost_movement_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aajaanan <aajaanan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 07:39:15 by aajaanan          #+#    #+#             */
/*   Updated: 2023/07/30 16:52:49 by aajaanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	move_pink_ghost(t_params *params)
{
	static int	counter = 0;
	static int	ghost_speed = 20;

	counter++;
	if (counter >= ghost_speed)
	{
		counter = 0;
		move_pink(params);
	}
}

void	move_yellow_ghost(t_params *params)
{
	static int	counter = 0;
	static int	ghost_speed = 20;

	counter++;
	if (counter >= ghost_speed)
	{
		counter = 0;
		move_yellow(params);
	}
}

void	move_blue_ghost(t_params *params)
{
	static int	counter = 0;
	static int	ghost_speed = 20;

	counter++;
	if (counter >= ghost_speed)
	{
		counter = 0;
		move_blue(params);
	}
}

void	move_red_ghost(t_params *params)
{
	static int	counter = 0;
	static int	ghost_speed = 20;

	counter++;
	if (counter >= ghost_speed)
	{
		counter = 0;
		move_red(params);
	}
}

void	move_ghosts(t_params *params)
{
	move_pink_ghost(params);
	move_yellow_ghost(params);
	move_blue_ghost(params);
	move_red_ghost(params);
}