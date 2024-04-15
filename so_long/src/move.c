/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prayo-ga <prayo-ga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 15:56:52 by prayo-ga          #+#    #+#             */
/*   Updated: 2024/04/09 12:32:46 by prayo-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	move_up(t_game *game)
{
	if (game->map[game->images->character->instances->y / 32 - 1] //Estamos accediendo al mapa para posicionar el jugador y comprobamos que no sea una pared
			[game->images->character->instances->x / 32] != WALL) //32 Es el tamaño de cada celda que esta prototipado en el archivo de images.
			{
				game->images->character->instances->y -= MOVE; //ES la velocidad del movimiento (cnto se va a desplazar por cada movimiento)
				game->move_counter++; //Para sumarle 1 al movimiento.
				ft_printf("MOVE: %i\n", game->move_counter);
			}
}

void	move_down(t_game *game)
{
	if (game->map[game->images->character->instances->y / 32 + 1] //Estamos accediendo al mapa para posicionar el jugador y comprobamos que no sea una pared
			[game->images->character->instances->x / 32] != WALL) //32 Es el tamaño de cada celda que esta prototipado en el archivo de images.
			{
				game->images->character->instances->y += MOVE; //ES la velocidad del movimiento (cnto se va a desplazar por cada movimiento)
				game->move_counter++; //Para sumarle 1 al movimiento.
				ft_printf("MOVE: %i\n", game->move_counter);
			}
}

void	move_left(t_game *game)
{
	if (game->map[game->images->character->instances->y / 32] //Estamos accediendo al mapa para posicionar el jugador y comprobamos que no sea una pared
			[game->images->character->instances->x / 32 - 1] != WALL) //32 Es el tamaño de cada celda que esta prototipado en el archivo de images.
			{
				game->images->character->instances->x -= MOVE; //ES la velocidad del movimiento (cnto se va a desplazar por cada movimiento)
				game->move_counter++; //Para sumarle 1 al movimiento.
				ft_printf("MOVE: %i\n", game->move_counter);
			}
}

void	move_right(t_game *game)
{
	if (game->map[game->images->character->instances->y / 32] //Estamos accediendo al mapa para posicionar el jugador y comprobamos que no sea una pared
			[game->images->character->instances->x / 32 + 1] != WALL) //32 Es el tamaño de cada celda que esta prototipado en el archivo de images.
			{
				game->images->character->instances->x += MOVE; //ES la velocidad del movimiento (cnto se va a desplazar por cada movimiento)
				game->move_counter++; //Para sumarle 1 al movimiento.
				ft_printf("MOVE: %i\n", game->move_counter);
			}
}

void	ft_key_hook(mlx_key_data_t keydata, void *param) //Funcion que se esta corriendo continuamente y que "escucha" la presion de las teclas
{
	t_game  *game;

	game = param; //Param es algo que esta en la memoria de la funcion key_hook y nosotros la cambiamos por el juego que es lo que nos interesa.
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_RELEASE)// Es la pra que se mueva cada vez que soltemos la tecla, es decir por cada pulsacion un movimiento.
		move_up(game);
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_RELEASE)// Es la pra que se mueva cada vez que soltemos la tecla, es decir por cada pulsacion un movimiento.
		move_down(game);
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_RELEASE)// Es la pra que se mueva cada vez que soltemos la tecla, es decir por cada pulsacion un movimiento.
		move_left(game);
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_RELEASE)// Es la pra que se mueva cada vez que soltemos la tecla, es decir por cada pulsacion un movimiento.
		move_right(game);
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		mlx_close_window(game->mlx);
		ft_printf("\nClosed Game-You Lose");
		return ;
	}
	collect_bones(game);
	ft_exit_game(game);
}