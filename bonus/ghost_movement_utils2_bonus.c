/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ghost_movement_utils2_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aajaanan <aajaanan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 15:12:22 by aajaanan          #+#    #+#             */
/*   Updated: 2023/07/30 14:36:23 by aajaanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	shuffle(int *array, int n)
{
	int	i;
	int	j;
	int	temp;

	i = n - 1;
	while (i > 0)
	{
		j = rand() % (i + 1);
		temp = array[i];
		array[i] = array[j];
		array[j] = temp;
		i--;
	}
}

void	init_directions(int directions[4])
{
	directions[0] = 0;
	directions[1] = 1;
	directions[2] = 2;
	directions[3] = 3;
}
