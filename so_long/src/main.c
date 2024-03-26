/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prayo-ga <prayo-ga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 18:04:43 by prayo-ga          #+#    #+#             */
/*   Updated: 2024/03/26 14:18:04 by prayo-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int32_t	main(int argument_counter, char **argv)
{
	t_game game;
	
	game.mlx = mlx_init(WIDTH, HEIGHT, "So_long", true);
	if (argument_counter == 2 && ft_substr(argv[1], '.', 0))
	{ 
		if (!game.mlx)
			ft_error();
		// Cargamos el jugador
		game.player = charge_texture(game.mlx, "assets/character/sprite_dog_resized.png");
		//Movimiento del jugador
		mlx_loop_hook(game.mlx, ft_moves, &game);
		//Para que no se cierre la ventana.
		mlx_loop(game.mlx);
		mlx_terminate(game.mlx);
		return (EXIT_SUCCESS);
	}
	else
	{
		ft_printf("Error: Archivo de mapa no válido.");
		return (EXIT_FAILURE);
	}
	return (0);
}
