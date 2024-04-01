/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prayo-ga <prayo-ga@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 12:01:29 by prayo-ga          #+#    #+#             */
/*   Updated: 2023/11/07 12:55:47 by prayo-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*s;
	unsigned char	*d;

	if ((!dst && !src) && n)
		return (NULL);
	i = 0;
	s = (unsigned char *) src;
	d = (unsigned char *) dst;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dst);
}
