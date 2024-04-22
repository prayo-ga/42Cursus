/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bones.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prayo-ga <prayo-ga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 15:57:20 by prayo-ga          #+#    #+#             */
/*   Updated: 2024/04/16 13:09:37 by prayo-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	total_bones(t_game *game)
{
	int	total;
	int	first;
	int	second;

	total = 0;
	first = 0;
	while (game->map[first])
	{
		second = 0;
		while (game->map[first][second])
		{
			if (game->map[first][second] == BONE)
				total++;
			second++;
		}
		first++;
	}
	return (total);
}

void	collect_bones(t_game *game)
{
	int	len;
	int	counter;

	len = 0;
	counter = game->bone_number;
	while (len < counter)
	{
		if (((game->images->bone->instances[len].y
					/ 32 == game->images->character->instances->y / 32)
				&& (game->images->bone->instances[len].x
					/ 32 == game->images->character->instances->x / 32))
			&& game->images->bone->instances[len].enabled == true)
		{
			counter--;
			game->images->bone->instances[len].enabled = false;
			game->map[game->images->character->instances->y
				/ 32][game->images->character->instances->x / 32] = GROUND;
			game->bone_counter++;
			if (game->bone_counter == game->bone_number)
				game->images->close_chest->instances->enabled = false;
			return ;
		}
		len++;
	}
}

void	ft_exit_game(t_game *game)
{
	if (game->images->close_chest->instances->enabled == false
		&& game->images->close_chest->instances->x
		/ 32 == game->images->character->instances->x / 32
		&& game->images->close_chest->instances->y
		/ 32 == game->images->character->instances->y / 32)
	{
		ft_printf("You won the game with %i movements", game->move_counter);
		mlx_close_window(game->mlx);
	}
}
