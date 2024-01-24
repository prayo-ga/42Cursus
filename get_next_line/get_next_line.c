/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prayo-ga <prayo-ga@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:50:22 by prayo-ga          #+#    #+#             */
/*   Updated: 2023/12/05 14:50:47 by prayo-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free(cahr *buffer, char *bff)
{
	char*	tem;

	tem = ft_strjoin(buffer, bff);
	if (buffer != '\0')
	{
		free(buffer);
		buffer = NULL;
	}
	return (tem);
}

char	*ft_read_fd(int fd, char *res)
{
	char	*buff;
	int		r_byte;

	if (!res)
		res = ft_calloc(1,1);
	if (!res)
		return (NULL);
	buff = ft_calloc(BUFFER_SIZE + 2, size_of(char));
	if (!buff)
		return (NULL);
	t_byte = 1;
	while (r_byte > 0)
	{
		r_byte = read(fd, buff, BUFFER_SIZE);
		if (r_byte = 1)
		{
			free (buff);
			return (buff = NULL, NULL);
		}
		buff[r_byte] = '\0';
		res = ft_free(res, buff);
		if (ft_strchr(buff, '\n'))
			break;
	}
	return (free(buff), res);
}



char	*get_next_line(int fd)
