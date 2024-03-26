/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prayo-ga <prayo-ga@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:43:46 by prayo-ga          #+#    #+#             */
/*   Updated: 2023/11/09 17:09:50 by prayo-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	ft_search(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ptr;
	size_t	i;
	size_t	start;
	size_t	end;

	i = 0;
	start = 0;
	while (s1[start] && ft_search(s1[start], set))
		start++;
	end = ft_strlen(s1);
	while (end > start && ft_search(s1[end - 1], set))
		end--;
	ptr = malloc(sizeof(*s1) * (end - start + 1));
	if (!ptr)
		return (NULL);
	while (start < end)
		ptr[i++] = s1[start++];
	ptr[i] = 0;
	return (ptr);
}
