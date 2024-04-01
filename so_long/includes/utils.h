/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prayo-ga <prayo-ga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 17:57:11 by prayo-ga          #+#    #+#             */
/*   Updated: 2024/03/26 12:47:52 by prayo-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdio.h>
# include "../lib/mlx42/include/MLX42/MLX42.h"
# include "../lib/libft/libft.h"
# include <fcntl.h>

void    ft_error(void);
mlx_image_t *charge_texture(mlx_t *mlx, char *way);

#endif