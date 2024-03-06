/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aux.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prayo-ga <prayo-ga@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 17:21:21 by prayo-ga          #+#    #+#             */
/*   Updated: 2023/12/04 18:13:35 by prayo-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int num)
{
	if (num == -2147483648)
	{
		ft_printchar('-');
		ft_printchar('2');
		num = 147483648;
	}
	if (num < 0)
	{
		ft_printchar('-');
		num *= -1;
	}
	if (num >= 0 && num <= 9)
		ft_printchar(num + 48);
	else
	{
		ft_putnbr(num / 10);
		ft_putnbr(num % 10);
	}
}

int	ft_countnum(long long num)
{
	int	i;

	i = 0;
	while (num >= 10)
	{
		i++;
		num /= 10;
	}
	return (i + 1);
}

int	ft_printptr(unsigned long long ptr)
{
	int	i;

	i = 0;
	i += ft_printstr("0x");
	i += ft_printhex(ptr, 'x');
	return (i);
}
