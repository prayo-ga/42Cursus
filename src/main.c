/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prayo-ga <prayo-ga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 18:04:43 by prayo-ga          #+#    #+#             */
/*   Updated: 2024/03/25 18:38:49 by prayo-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int32_t	main(int argument_counter, char **argv)
{
	mlx_t		*mlx;
	mlx_image_t	*img;

	mlx = mlx_init(WIDTH, HEIGHT, "So Long", true);
	if (argument_counter == 2 && ft_substr(argv[1], '.', 0))
	{
		if (!mlx)
			ft_error();
		img = mlx_new_image(mlx, 256, 256);
		if (!img || (mlx_image_to_window(mlx, img, 0, 0) < 0))
			ft_error();
		mlx_put_pixel(img, 0, 0, 0x000000);
		mlx_loop(mlx);
		mlx_terminate(mlx);
		return (EXIT_SUCCESS);
	}
	else
	{
		ft_printf("Error: Archivo de mapa no válido.");
		return (EXIT_FAILURE);
	}
	return (0);
}
