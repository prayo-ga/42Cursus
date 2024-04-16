/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator_extras.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prayo-ga <prayo-ga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 15:58:15 by prayo-ga          #+#    #+#             */
/*   Updated: 2024/04/16 13:15:17 by prayo-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_minimun_components(char **map)
{
	int	fst;
	int	snd;
	int	num_exit;
	int	num_bones;

	fst = 0;
	num_bones = 0;
	num_exit = 0;
	while (map[fst])
	{
		snd = 0;
		while (map[fst][snd])
		{
			if (map[fst][snd] == EXIT_MAP || map[fst][snd] == START_PLAYER)
				num_exit++;
			if (map[fst][snd] == BONE)
				num_bones++;
			snd++;
		}
		fst++;
	}
	if (num_exit != 2 || num_bones < 1)
		return (FALSE);
	else
		return (TRUE);
}

int	*first_position_player(char **map)
{
	int	ox;
	int	oy;
	int	*pos;

	pos = (int *)ft_calloc(2, sizeof(int));
	oy = 0;
	while (map[oy])
	{
		ox = 0;
		while (map[oy][ox])
		{
			if (map[oy][ox] == START_PLAYER)
			{
				pos[0] = oy;
				pos[1] = ox;
			}
			ox++;
		}
		oy++;
	}
	return (pos);
}

void	flood_map(t_game *game, int ox, int oy)
{
	if (!(ox < 0 || oy < 0 || ox >= game->width || oy > game->height
			|| game->map_2[oy][ox] == '1' || game->map_2[oy][ox] == 'X'))
	{
		game->map_2[oy][ox] = 'X';
		flood_map(game, ox + 1, oy);
		flood_map(game, ox - 1, oy);
		flood_map(game, ox, oy + 1);
		flood_map(game, ox, oy - 1);
	}
}

int	check_flood_map(char **map)
{
	int	first;
	int	second;

	first = 0;
	while (map[first])
	{
		second = 0;
		while (map[first][second])
		{
			if (!(map[first][second] == WALL || map[first][second] == GROUND
					|| map[first][second] == 'X'))
				return (FALSE);
			second++;
		}
		first++;
	}
	return (TRUE);
}

int	check_correct_path(t_game *game, char *fd)
{
	int	*position;

	game->map_2 = read_map(fd);
	position = first_position_player(game->map_2);
	flood_map(game, position[0], position[1]);
	if (check_flood_map(game->map_2) == FALSE)
	{
		free(position);
		free_map(game->map_2);
		return (ft_printf(ERROR_INVALID_PATH), FALSE);
	}
	free(position);
	free_map(game->map_2);
	return (TRUE);
}
