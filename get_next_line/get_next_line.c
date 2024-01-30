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

char	*ft_free(char *buffer1, char *buffer2)
{
	char*	tem;

	tem = ft_strjoin(buffer1, buffer2);
	if (buffer1 != '\0')
	{
		free(buffer1);
		buffer1 = NULL;
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
	r_byte = 1;
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

char	*ft_next_line(char *buff)
{
	int		OY;
	int		OX;
	char	*line;

	OY = 0;
	while(buff[OY] && buff[OY] != '\n')
		OY++;
	if (!buff[OY])
	{
		free(buff);
		return (NULL);
	}
	OY++;
	OX = 0;
	while (buff[OY])
		line[OX++] = buff[OY++];
	line[OX] = '\0';
	free(buff);
	return (line);
}

char	*ft_current_line(char *buff)
{
	int		i;
	char	*line;

	i = 0;
	while(buff[i] && buff[i] != '\n')
		i++;
	line = (char *)ft_calloc(i + 2, sizeof(char))
	if (!line)
		return (NULL);
	i = 0;
	while (buff[i] && buff[i] != '\n'
	{
		line[i] = buff[i];
		i++;
	}
	if (buff[i] && buff[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	buffer = ft_read_fd(fd, buffer);
	if (!buffer || buffer[0] == '\0')
	{
		free(buffer);
		buffer = NULL;
		return(NULL);
	}
	line = ft_current_line(buffer);
	buffer = ft_next_line(buffer);
	return (line);
}
