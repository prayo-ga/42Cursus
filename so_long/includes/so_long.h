/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prayo-ga <prayo-ga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 12:36:12 by prayo-ga          #+#    #+#             */
/*   Updated: 2024/04/09 12:32:25 by prayo-ga         ###   ########.fr       */
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

# define ERROR_PARAMS "Error: You need 2 paramas.\n"
# define ERROR_EXTENSION_MAP "Error: your map must be '.ber'!\n"
# define ERROR_EMPTY_MAP "Error: The map is empty!\n"
# define ERROR_MAP_FORM "Error: The map doesn't have the dimentions needed.\n"
# define ERROR_COMPONENTS_WRONG "Error: The components are not the needed ones.\n"
# define ERROR_NO_WALLS "Error: There are no walls around the map.\n"
# define ERROR_MINIMUN_COMPONENTS "Error: THere are not enough components created for the map.\n"
# define ERROR_INVALID_PATH "Error: The path is not valid.\n"

# define BUFFER_SIZE 10000
# define FALSE 1
# define TRUE 0
# define MOVE 32

typedef struct s_texture 
{
	mlx_texture_t	*ground;
	mlx_texture_t	*wall;
	mlx_texture_t	*bone;
	mlx_texture_t	*character;
	mlx_texture_t	*open_chest;
	mlx_texture_t	*close_chest;
}	t_textures;

typedef struct s_images
{
	mlx_image_t	*ground;
	mlx_image_t	*wall;
	mlx_image_t	*bone;
	mlx_image_t	*character;
	mlx_image_t	*open_chest;
	mlx_image_t	*close_chest;
}	t_images;

typedef struct s_game
{
	struct s_texture	*textures;
	struct s_images	*images;
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
char	**read_map(char *map_file);
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
void	free_map(char **map);
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