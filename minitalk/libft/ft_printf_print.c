/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prayo-ga <prayo-ga@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 17:06:13 by prayo-ga          #+#    #+#             */
/*   Updated: 2023/12/04 19:06:28 by prayo-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printdec(int num)
{
	long int	i;

	i = 0;
	ft_putnbr(num);
	if (num >= 0)
		return (ft_countnum(num));
	i = (long int)num * (-1);
	return (ft_countnum(i) + 1);
}

int	ft_printchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_printstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (ft_printstr("(null)"));
	while (str[i] != '\0')
	{
		ft_printchar(str[i]);
		i++;
	}
	return (i);
}

int	ft_printhex(unsigned long long num, char c)
{
	unsigned long long	i;

	i = 0;
	if (num >= 16)
		i += ft_printhex(num / 16, c);
	if (c == 'x')
		ft_printchar("0123456789abcdef"[num % 16]);
	if (c == 'X')
		ft_printchar("0123456789ABCDEF"[num % 16]);
	i++;
	return (i);
}

int	ft_printunsigned(unsigned int num)
{
	int	i;

	i = 0;
	if (num >= 10)
		i += ft_printunsigned(num / 10);
	ft_printchar(num % 10 + '0');
	i++;
	return (i);
}
