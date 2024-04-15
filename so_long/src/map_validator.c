/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prayo-ga <prayo-ga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 15:57:50 by prayo-ga          #+#    #+#             */
/*   Updated: 2024/04/08 11:46:35 by prayo-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int check_empty_map(char **map)
{
	if (map[0])
		return (TRUE);
	else
	{
		ft_printf(ERROR_EMPTY_MAP);
		return (FALSE);
	}
}

int	check_map_geometry(char **map)
{
	size_t	len_map;
	int		map_path;

	len_map = ft_strlen(map[0]);
	map_path = 1;
	while (map[map_path])
	{
		if (ft_strlen(map[map_path]) != len_map) //COmprobamos que se haya hecho correctamente el primer ft_strlen
			return (FALSE);
		else
			map_path++;		
	}
	return (TRUE);
}

int	check_correct_map(char **map)
{
	int	first;
	int	second;

	first = 0;
	while (map[first])
	{
		second = 0;
		while (map[first][second])
		{
			if (!(map[first][second] == EXIT_MAP || map[first][second] == START_PLAYER
					|| map[first][second] == WALL || map[first][second] == GROUND
					|| map[first][second] == BONE)) //No esta corgando correctqamente el mapa, o no es el formato que queremmos
					return (FALSE);
			else
				second++;
		}
		first++;
	}
	return (TRUE);
}

int	check_map_walls(char **map)
{
	size_t	first;
	size_t	second;
	size_t	line;

	line = 0;
	while (map[line])
		line++;
	first = 0;
	while (first < ft_strlen(map[0]))
	{
		if (map[0][first] != '1' || map[line - 1][first] != '1') // Comprobamos si hay muros exteriores (indirectamente)
			return (FALSE);
		first++; //Si lo pusieramos del reves no podriamos hacer ++.
	}
	second = 0;
	while (first < (line - 1))
	{
		if (map[second][0] != '1' || map[ft_strlen(map[0])][0] != '1') // para muros interiores
			return (FALSE);
		second++;
	}
	return (TRUE);
}

int	check_map(char **map) // ejecuta todas las funciones creadas anteriormente.
{
	if (check_empty_map(map) == FALSE)
		return (ft_printf(ERROR_EMPTY_MAP), FALSE);
	if (check_map_geometry(map) == FALSE)
		return (ft_printf(ERROR_MAP_FORM), FALSE);
	if (check_correct_map(map) == FALSE)
		return (ft_printf(ERROR_COMPONENTS_WRONG), FALSE);
	if (check_minimun_components(map) == FALSE)
		return (ft_printf(ERROR_MINIMUN_COMPONENTS), FALSE);
	return (TRUE);
}
