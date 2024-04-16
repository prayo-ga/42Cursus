/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prayo-ga <prayo-ga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 15:55:25 by prayo-ga          #+#    #+#             */
/*   Updated: 2024/04/16 13:17:53 by prayo-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_map(char **map)
{
	int	map_path;

	map_path = -1;
	while (map[++map_path])
		free(map[map_path]);
	free(map);
}

void	get_map_size(t_game *game, char **map)
{
	int	m_p;

	m_p = 0;
	game->bone_number = total_bones(game);
	game->width = ft_strlen(map[0]) * 32;
	while (map[m_p])
		m_p++;
	game->height = m_p * 32;
}

int	check_file_extension(char const *file_name)
{
	size_t	file_length;

	file_length = ft_strlen(file_name) - 1;
	if (file_name[file_length] != 'r' && file_name[file_length] != 'e'
		&& file_name[file_length] != 'b' && file_name[file_length] != '.')
		return (FALSE);
	return (TRUE);
}

char	**read_map(char *map_file)
{
	int		fd;
	char	*tmp_map;
	char	**map;
	int		tmp_file;

	tmp_file = 0;
	tmp_map = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!tmp_map)
		return (0);
	fd = open(map_file, O_RDONLY);
	if (fd < 0)
		return (free(tmp_map), NULL);
	tmp_file = read(fd, tmp_map, BUFFER_SIZE);
	if (tmp_file == -1 || tmp_file == 0)
		return (free(tmp_map), NULL);
	map = ft_split(tmp_map, '\n');
	free(tmp_map);
	close(fd);
	return (map);
}
