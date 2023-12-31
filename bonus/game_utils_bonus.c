/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aajaanan <aajaanan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 13:07:41 by aajaanan          #+#    #+#             */
/*   Updated: 2023/07/30 16:30:39 by aajaanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	display_score_and_moves(t_params *params)
{
	char	*moves;
	char	*score;

	moves = ft_strjoin("Moves: ", ft_itoa(params->player.moves));
	score = ft_strjoin("Score: ", ft_itoa(params->player.score));
	mlx_string_put(params->mlx, params->win, 100, 20, 0xFFFFFF, moves);
	mlx_string_put(params->mlx, params->win, 500, 20, 0xFFFFFF, score);
	free(moves);
	free(score);
}

void	get_random_collectible_position(t_params *params, int *col, int *row)
{
	int	new_col;
	int	new_row;

	new_col = rand() % params->map.cols;
	new_row = rand() % params->map.rows;
	while (params->map.data[new_row][new_col] != 'C')
	{
		new_col = rand() % params->map.cols;
		new_row = rand() % params->map.rows;
	}
	*col = new_col;
	*row = new_row;
}
