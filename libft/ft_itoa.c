/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prayo-ga <prayo-ga@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:32:19 by prayo-ga          #+#    #+#             */
/*   Updated: 2023/11/09 15:41:58 by prayo-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_numlen(int num)
{
	int	i;

	i = 0;
	if (num <= 0)
		i++;
	while (num)
	{
		i++;
		num = num / 10;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*ptr;
	int		i;
	long	number;

	i = ft_numlen(n);
	number = n;
	ptr = malloc(sizeof(char) * (i + 1));
	if (ptr == NULL)
		return (NULL);
	if (number < 0)
	{
		ptr[0] = '-';
		number = -number;
	}
	if (number == 0)
		ptr[0] = '0';
	ptr[i--] = '\0';
	while (number)
	{
		ptr[i] = (number % 10) + '0';
		i--;
		number = number / 10;
	}
	return (ptr);
}
