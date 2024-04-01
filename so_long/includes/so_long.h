/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prayo-ga <prayo-ga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 12:36:12 by prayo-ga          #+#    #+#             */
/*   Updated: 2024/04/01 15:26:54 by prayo-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../lib/mlx42/include/MLX42/MLX42.h"
# include "../lib/libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <memory.h>
# include <stdint.h>
# include <fcntl.h>

# define EXIT_MAP 'E'
# define START_PLAYER 'P'
# define BONE 'C'
# define WALL '1'
# define GROUND '0'

# define ERROR_PARAMS "Error: Se necesitan 2 paramaetros.\n"
# define ERROR_EXTENSION_MAP "Error: Se necesita que el mapa sea '.ber'!\n"
# define ERROR_EMPTY_MAP "Error: El mapa está vacio!\n"
# define ERROR_MAP_FORM "Error: El mapa no corresponde con las dimensiones necesarias.\n"
# define ERROR_COMPONENTS_WRONG "Error: Los conmponentes no son los que están estipulados.\n"
# define ERROR_NO_WALLS "Error: No hay paredes alrededor del mapa.\n"
# define ERROR_MINIMUN_COMPONENTS "Error: No hay los suficientes componentes creados para el mapa.\n"
# define ERROR_INVALID_PATH "Error: El camino estipulado no es valido.\n"

# define BUFFER_SIZE 10000
# define FALSE 1
# define TRUE 0
# define MOVE 32

typedef struct struct_texture 
{
	mlx_texture_t	*ground;
	mlx_texture_t	*wall;
	mlx_texture_t	*bone;
	mlx_texture_t	*character;
	mlx_texture_t	*open_chest;
	mlx_texture_t	*close_chest;
}	t_textures;

typedef struct struct_images
{
	mlx_image_t	*ground;
	mlx_image_t	*wall;
	mlx_image_t	*bone;
	mlx_image_t	*character;
	mlx_image_t	*open_chest;
	mlx_image_t	*close_chest;
}	t_images;

typedef struct struct_game
{
	struct struct_texture	*textures;
	struct struct_images	*images;
	mlx_t					*mlx;
	char					**map;
	char					**map_2;
	int						width;
	int						height;
	int						bone_counter;
	int						move_counter;
	int						bone_number;
}	t_game;

int		init_game(t_game *game);
int		check_file_extension(char const *file_name);
char	**read_map(char *map);
void	draw_map(t_game *game, t_images *images);
int		check_map(char **map);
int		check_empty_map(char **map);
int		check_map_geometry(char **map);
int		check_correct_map(char **map);
int		check_map_walls(char **map);
void	get_map_size(t_game *game, char **map);
int		check_correct_path(t_game *game, char *fd);
int		*first_position_player(char  **map);
void	flood_map(t_game *game, int ox, int oy);
int		check_flood_map(char **map);
int		total_bones(t_game *game);
void	free_map(t_game *game);
int		check_minimun_components(char **map);
void	get_textures(t_game *game);
void	get_images(t_game *game);
void	ft_key_hook(mlx_key_data_t keydata, void *param);
void	move_up(t_game *game);
void	move_down(t_game *game);
void	move_left(t_game *game);
void	move_right(t_game *game);
void	collect_bones(t_game *game);
void	delete_bones(t_game *game);
void	ft_exit_game(t_game *game);

#endif