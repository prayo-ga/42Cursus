/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prayo-ga <prayo-ga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 18:40:19 by prayo-ga          #+#    #+#             */
/*   Updated: 2024/03/26 13:09:00 by prayo-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

void    ft_error(void)
{
	fprintf(stderr, "Error: %s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

mlx_image_t	*charge_texture(mlx_t *mlx, char *way)
{
	mlx_texture_t   *texture;
	mlx_image_t     *image;
	
	texture = mlx_load_png(way);
	if (texture == NULL)
	{
		free(texture);
		ft_error();
	}
	image = mlx_texture_to_image(mlx, texture);
	if (image == NULL)
	{
		free(image);
		ft_error();
	}
	if (mlx_image_to_window(mlx, image, 0, 0) != 0)
		ft_error();
	return (image);
}