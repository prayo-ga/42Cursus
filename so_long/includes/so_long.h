/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prayo-ga <prayo-ga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 17:54:53 by prayo-ga          #+#    #+#             */
/*   Updated: 2024/03/26 14:16:09 by prayo-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define WIDTH 512
# define HEIGHT 512

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include "../lib/mlx42/include/MLX42/MLX42.h"

# include "utils.h"
# include "hooks.h"

typedef struct s_game
{
    mlx_t *mlx;
    mlx_image_t *player;
    int player_x;
    int player_y;
    int count_moves;
}   t_game;

#endif