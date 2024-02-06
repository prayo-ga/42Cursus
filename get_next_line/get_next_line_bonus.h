/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prayo-ga <prayo-ga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 16:09:45 by prayo-ga          #+#    #+#             */
/*   Updated: 2024/01/31 16:09:45 by prayo-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
#include <limits.h>
//Definimos un buffer size por defecto
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
size_t	ft_strlen(const char *str);
void	ft_bzero(void *s, size_t n);
void	*ft_bzero(void *s, size_t n);
char	*ft_strjoin(const char *s1, const char *s2);

#endif
