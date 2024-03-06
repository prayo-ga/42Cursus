/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prayo-ga <prayo-ga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 12:09:22 by prayo-ga          #+#    #+#             */
/*   Updated: 2024/02/29 20:06:21 by prayo-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "./libft/libft.h"
#include "./libft/ft_printf.h"

void	send_signal(int pid, unsigned char octet)
{
	int				count_bit;
	unsigned char	octet_tmp;

	octet_tmp = octet;
	count_bit = 8;
	while (count_bit-- > 0)
	{
		octet_tmp = octet >> count_bit;
		if (octet_tmp % 2 == 0)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(100);
	}
}

int	main(int argc, char **argv)
{
	int		pid;
	char	*store_message;
	int		string_counter;

	if (argc != 3)
	{
		ft_printf("No hay suficientes argumentos\n");
		return (0);
	}
	pid = ft_atoi(argv[1]);
	store_message = argv[2];
	string_counter = 0;
	while (store_message[string_counter])
	{
		send_signal(pid, (unsigned char)store_message[string_counter]);
		string_counter++;
	}
	ft_printf("Está ha sido la cantidad de caracteres enviados: %i\n",
		string_counter);
	return (0);
}
