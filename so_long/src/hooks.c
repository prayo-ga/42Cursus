/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prayo-ga <prayo-ga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 14:02:50 by prayo-ga          #+#    #+#             */
/*   Updated: 2024/03/26 14:20:44 by prayo-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/hooks.h"

void	ft_moves(void *param)
{
	t_game *game;

	game = (t_game *)param;
	if (!game || !game->mlx)
		ft_error();
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(game->mlx);
	if (mlx_is_key_down(game->mlx, MLX_KEY_W))
		game->player->instances[0].y -= 5;
	if (mlx_is_key_down(game->mlx, MLX_KEY_S))
		game->player->instances[0].y += 5;
	if (mlx_is_key_down(game->mlx, MLX_KEY_A))
		game->player->instances[0].x -= 5;
	if (mlx_is_key_down(game->mlx, MLX_KEY_D))
		game->player->instances[0].x += 5;
}
