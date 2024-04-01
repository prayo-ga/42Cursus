/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prayo-ga <prayo-ga@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 19:06:54 by prayo-ga          #+#    #+#             */
/*   Updated: 2023/11/15 19:35:10 by prayo-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdio.h"

char	*ft_strmapi(char const *s, char (*f) (unsigned int, char))
{
	char	*c;
	size_t	i;

	c = (char *)s;
	i = 0;
	if (!s || !f)
		return (NULL);
	c = (char *)malloc(ft_strlen(s) + 1);
	if (!c)
		return (NULL);
	while (i < ft_strlen(s))
	{
		c[i] = f(i, s[i]);
		i++;
	}
	c[i] = '\0';
	return (c);
}
