/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prayo-ga <prayo-ga@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 14:29:00 by prayo-ga          #+#    #+#             */
/*   Updated: 2023/11/13 21:13:48 by prayo-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countword(char const *s, char c)
{
	int	word_count;
	int	in_word;

	in_word = 0;
	word_count = 0;
	while (*s)
	{
		if (in_word == 0 && *s != c)
		{
			in_word += 1;
			word_count++;
		}
		if (in_word == 1 && *s == c)
			in_word -= 1;
		s++;
	}
	return (word_count);
}

static void	ft_free(char **str, int index)
{
	while (index-- > 0)
		free(str[index]);
	free(str);
}

static int	ft_len(char const *str, char c, int index)
{
	int	i;

	i = 0;
	while (str[index] && str[index++] != c)
		i++;
	return (i);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		i;
	int		index;
	int		word_count;
	int		len;

	i = 0;
	index = -1;
	word_count = ft_countword(s, c);
	str = malloc(sizeof(char *) * (word_count + 1));
	if (!str)
		return (NULL);
	while (++index < word_count)
	{
		while (s[i] == c)
			i++;
		len = ft_len(s, c, i);
		str[index] = ft_substr(s, i, len);
		if (!(str[index]))
			return (ft_free(str, index), NULL);
		i += len;
	}
	str[index] = NULL;
	return (str);
}
