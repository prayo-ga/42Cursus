/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prayo-ga <prayo-ga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 17:53:05 by prayo-ga          #+#    #+#             */
/*   Updated: 2024/01/31 17:58:39 by prayo-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_free(char *buffer1, char *buffer2)
{
	char	*tem;

	tem = ft_strjoin(buffer1, buffer2);
	if (buffer1)
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
		res = ft_calloc(1, 1);
	if (!res)
		return (NULL);
	buff = ft_calloc(BUFFER_SIZE + 2, sizeof(char));
	if (!buff)
		return (NULL);
	r_byte = 1;
	while (r_byte > 0)
	{
		r_byte = read(fd, buff, BUFFER_SIZE);
		if (r_byte == -1)
		{
			free(buff);
			return (buff = NULL, NULL);
		}
		buff[r_byte] = '\0';
		res = ft_free(res, buff);
		if (ft_strchr(buff, '\n'))
			break ;
	}
	return (free(buff), res);
}

char	*ft_next_line(char *buff)
{
	int		ox;
	int		oy;
	char	*line;

	oy = 0;
	while (buff[oy] && buff[oy] != '\n')
		oy++;
	if (!buff[oy])
	{
		free(buff);
		return (NULL);
	}
	line = ft_calloc((ft_strlen(buff) - oy + 2), sizeof(char));
	if (!line)
	{
		free(buff);
		return (NULL);
	}
	oy++;
	ox = 0;
	while (buff[oy])
		line[ox++] = buff[oy++];
	line[ox] = '\0';
	free(buff);
	return (line);
}

char	*ft_current_line(char *buff)
{
	int		i;
	char	*line;

	i = 0;
	while (buff[i] && buff[i] != '\n')
		i++;
	line = (char *)ft_calloc(i + 2, sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (buff[i] && buff[i] != '\n')
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
		buffer[fd] = NULL;
		return (NULL);
	}
	buffer[fd] = ft_read_fd(fd, buffer);
	if (!buffer[fd] || buffer[0] == '\0')
	{
		free(buffer);
		buffer[fd] = NULL;
		return (NULL);
	}
	line = ft_current_line(buffer[fd]);
	buffer[fd] = ft_next_line(buffer[fd]);
	return (line);
}
