/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prayo-ga <prayo-ga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 15:56:52 by prayo-ga          #+#    #+#             */
/*   Updated: 2024/04/16 13:18:35 by prayo-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	move_up(t_game *game)
{
	if (game->map[game->images->character->instances->y / 32
			- 1][game->images->character->instances->x / 32] != WALL)
	{
		game->images->character->instances->y -= MOVE;
		game->move_counter++;
		ft_printf("MOVE: %i\n", game->move_counter);
	}
}

void	move_down(t_game *game)
{
	if (game->map[game->images->character->instances->y / 32
			+ 1][game->images->character->instances->x / 32] != WALL)
	{
		game->images->character->instances->y += MOVE;
		game->move_counter++;
		ft_printf("MOVE: %i\n", game->move_counter);
	}
}

void	move_left(t_game *game)
{
	if (game->map[game->images->character->instances->y
			/ 32][game->images->character->instances->x / 32 - 1] != WALL)
	{
		game->images->character->instances->x -= MOVE;
		game->move_counter++;
		ft_printf("MOVE: %i\n", game->move_counter);
	}
}

void	move_right(t_game *game)
{
	if (game->map[game->images->character->instances->y
			/ 32][game->images->character->instances->x / 32 + 1] != WALL)
	{
		game->images->character->instances->x += MOVE;
		game->move_counter++;
		ft_printf("MOVE: %i\n", game->move_counter);
	}
}

void	ft_key_hook(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = param;
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_RELEASE)
		move_up(game);
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_RELEASE)
		move_down(game);
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_RELEASE)
		move_left(game);
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_RELEASE)
		move_right(game);
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		mlx_close_window(game->mlx);
		ft_printf("\nClosed Game-You Lose");
		return ;
	}
	collect_bones(game);
	ft_exit_game(game);
}
