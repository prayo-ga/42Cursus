/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prayo-ga <prayo-ga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 15:56:32 by prayo-ga          #+#    #+#             */
/*   Updated: 2024/04/09 13:06:23 by prayo-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	get_textures(t_game *game)
{
	game->textures = ft_calloc(1, sizeof(t_textures));
	game->textures->ground = mlx_load_png("assets/terrain/background/ground32_32.png");
	game->textures->wall = mlx_load_png("assets/terrain/background/bush_32_32.png");
	game->textures->bone = mlx_load_png("assets/terrain/win/bone32_32.png");
	game->textures->character = mlx_load_png("assets/character/character32_32.png");
	game->textures->close_chest = mlx_load_png("assets/terrain/win/close_chest32_32.png");
	game->textures->open_chest = mlx_load_png("assets/terrain/win/open_chest32_32.png");
}

void	get_images(t_game *game)
{
	game->images = ft_calloc(1, sizeof(t_images));
	game->images->ground = mlx_texture_to_image(game->mlx, game->textures->ground);
	game->images->wall = mlx_texture_to_image(game->mlx, game->textures->wall);
	game->images->bone = mlx_texture_to_image(game->mlx, game->textures->bone);
	game->images->character = mlx_texture_to_image(game->mlx, game->textures->character);
	game->images->close_chest = mlx_texture_to_image(game->mlx, game->textures->close_chest);
	game->images->open_chest = mlx_texture_to_image(game->mlx, game->textures->open_chest);
	mlx_delete_texture(game->textures->ground);
	mlx_delete_texture(game->textures->wall);
	mlx_delete_texture(game->textures->bone);
	mlx_delete_texture(game->textures->character);
	mlx_delete_texture(game->textures->close_chest);
	mlx_delete_texture(game->textures->open_chest);
}

void	draw_ground(t_game *game, t_images *image)
{
	int	ox;
	int	oy;

	oy = 0;
	while (game->map[oy])
	{
		ox = 0;
		while (game->map[oy][ox])
		{
			mlx_image_to_window(game->mlx, image->ground, ox * 32, oy * 32);
			if (game->map[oy][ox] == WALL)
			
				mlx_image_to_window(game->mlx, image->wall, ox * 32, oy * 32);
			if (game->map[oy][ox] == EXIT_MAP)
			{
				mlx_image_to_window(game->mlx, image->open_chest, ox * 32, oy * 32);
				mlx_image_to_window(game->mlx, image->close_chest, ox * 32, oy * 32);
			}
			ox++;
		}
		oy++;
	}
}

void	draw_map(t_game *game, t_images *images)
{
	int	ox;
	int	oy;

	draw_ground(game, images);
	oy = 0;
	while (game->map[oy])
	{
		ox = 0;
		while (game->map[oy][ox])
		{
			if (game->map[oy][ox] == BONE)
				mlx_image_to_window(game->mlx, images->bone, ox * 32, oy * 32);
			if (game->map[oy][ox] == START_PLAYER)
				mlx_image_to_window(game->mlx, images->character, ox * 32, oy * 32);
			ox++;
		}
		oy++;
	}
}