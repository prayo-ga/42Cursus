/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prayo-ga <prayo-ga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 12:09:22 by prayo-ga          #+#    #+#             */
/*   Updated: 2024/02/28 11:31:15 by prayo-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "./utils/mt_utils.h"

void	send_signal(int pid, unsigned char octet)
{
	int				count_bit;
	unsigned char	octet_tmp;

	count_bit = 8;
	octet_tmp = octet;
	while (count_bit > 0)
	{
		octet_tmp = octet >> count_bit;
		if (octet_tmp % 2 == 0)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(100);
	}
}

int main (int argc, char **argv)
{

}
