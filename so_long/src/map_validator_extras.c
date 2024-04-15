/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator_extras.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prayo-ga <prayo-ga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 15:58:15 by prayo-ga          #+#    #+#             */
/*   Updated: 2024/04/09 13:23:42 by prayo-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_minimun_components(char **map)
{
	int first;
	int second;
	int num_exit;
	int num_bones;

	first = 0;
	num_bones = 0;
	num_exit = 0;
	while (map[first])
	{
		second = 0;
		while (map[first][second])
		{
			if (map[first][second] == EXIT_MAP || map[first][second] == START_PLAYER)//si exsiste una salida el maà o hay una entrada:
				num_exit++; //le sumamos al contador
			if (map[first][second] == BONE)
				num_bones++;
			second++;
		}
		first++;
	}
	if (num_exit != 2 || num_bones < 1) //Porque la salida se considera dos ya que el uno es la entrada
		return (FALSE);
	else
		return (TRUE);
}

int	*first_position_player(char  **map)
{
	int ox;
	int oy;
	int *pos;

	pos = (int *)ft_calloc(2, sizeof(int)); //Es dos porque solo tenemos dos coordenadas.
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

void	flood_map(t_game *game, int ox, int oy) //determina los distintos aspectos del mapa, como sulo, pared...
{
	if (!(ox < 0 || oy < 0 || ox >= game->width || oy > game->height
			|| game->map_2[oy][ox] == '1' || game->map_2[oy][ox] == 'X')) //Comprobación del mapa y de las coordenadas, la X son las casillas visitables.
			{
				game->map_2[oy][ox] = 'X'; //SI se cumple la condición de antes vamos a marcar las casillas visitables
				flood_map(game, ox + 1, oy);// arriba
				flood_map(game, ox - 1, oy);//abajo
				flood_map(game, ox, oy + 1);// derecha
				flood_map(game, ox, oy - 1);//izquierda
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

