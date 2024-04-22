/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prayo-ga <prayo-ga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 15:22:43 by prayo-ga          #+#    #+#             */
/*   Updated: 2024/04/16 13:13:37 by prayo-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	init_game(t_game *game)
{
	game->move_counter = 0;
	game->bone_counter = 0;
	game->mlx = mlx_init(game->width, game->height, "so_long", false);
	if (!(game->mlx))
		return (FALSE);
	get_textures(game);
	get_images(game);
	draw_map(game, game->images);
	mlx_key_hook(game->mlx, &ft_key_hook, game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
	free_map(game->map);
	free(game->textures);
	free(game->images);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		return (ft_printf(ERROR_PARAMS), FALSE);
	if (check_file_extension(argv[1]) == FALSE)
		return (ft_printf(ERROR_EXTENSION_MAP), FALSE);
	game.map = read_map(argv[1]);
	if (!game.map)
		return (EXIT_FAILURE);
	if (check_map(game.map) == FALSE)
		return (free_map(game.map), FALSE);
	get_map_size(&game, game.map);
	if (check_correct_path(&game, argv[1]) == FALSE)
		return (free_map(game.map), FALSE);
	if (init_game(&game) == FALSE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
