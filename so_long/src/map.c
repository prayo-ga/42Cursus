/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prayo-ga <prayo-ga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 15:55:25 by prayo-ga          #+#    #+#             */
/*   Updated: 2024/04/09 12:01:38 by prayo-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_map(char **map)
{
	int	map_path;

	map_path = -1; //lo primero que vamos a hacer es sumarle antes de que se meta en el bucle
	while (map[++map_path])
		free(map[map_path]);
	free(map);
}

void	get_map_size(t_game *game,  char **map)
{
	int	m_p;

	m_p = 0;
	game->bone_number = total_bones(game);
	game->width = ft_strlen(map[0]) * 32; //Es un factor de escala, para hacer el ancho mas grande sin tener la neccesidad de poner tantos numeros.
	while (map[m_p])
		m_p++;
	game->height = m_p * 32; //Al no tener los arrays, el programa va a calcular las dimensiones a lo alto.
}

int	check_file_extension(char const *file_name)//comprueba que al fianl de lo que podamos sea de .ber
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
	int 	tmp_file;

	tmp_file = 0;
	tmp_map = ft_calloc(BUFFER_SIZE + 1, sizeof(char));//alocamos la memoria para el mapa
	if (!tmp_map)
		return (0);
	fd = open(map_file, O_RDONLY);//abrir el archivo del mapa
	if (fd < 0)
		return (free(tmp_map), NULL);
	tmp_file = read(fd, tmp_map, BUFFER_SIZE);//Para que podamos leer el contenido del archivo
	if (tmp_file == -1 || tmp_file == 0)
		return (free(tmp_map), NULL);//porque si falla el read, tenemos que comprobarlo para que no tengamos leaks de memoria
	map = ft_split(tmp_map, '\n');//Read devulve un string y el split nos ayudara para ponerlo en array de nuevo, es decir una matriz.
	free(tmp_map);
	close(fd);//sirve para cerrar el archivo
	return (map);
}