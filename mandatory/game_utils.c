/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aajaanan <aajaanan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 13:07:41 by aajaanan          #+#    #+#             */
/*   Updated: 2023/07/30 10:58:19 by aajaanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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



