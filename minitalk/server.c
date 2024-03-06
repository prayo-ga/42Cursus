/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prayo-ga <prayo-ga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 11:56:02 by prayo-ga          #+#    #+#             */
/*   Updated: 2024/02/29 19:53:46 by prayo-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "./libft/libft.h"
#include "./libft/ft_printf.h"

void	manage(int sendsignal)
{
	static unsigned char	buff;
	static int				received_signal;

	buff |= (sendsignal == SIGUSR1);
	received_signal++;
	if (received_signal == 8)
	{
		ft_printf("%c", buff);
		received_signal = 0;
		buff = 0;
	}
	else
		buff <<= 1;
}

int	main(void)
{
	ft_printf("El ID del cliente es: %i\n", getpid());
	signal(SIGUSR1, manage);
	signal(SIGUSR2, manage);
	while (1)
		pause();
	return (0);
}
