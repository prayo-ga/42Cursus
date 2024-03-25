/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prayo-ga <prayo-ga@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 17:18:40 by prayo-ga          #+#    #+#             */
/*   Updated: 2023/12/04 19:00:37 by prayo-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int		ft_printchar(char c);
int		ft_printstr(char *str);
int		ft_printdec(int num);
int		ft_printunsigned(unsigned int num);
int		ft_printhex(unsigned long long num, char c);
int		ft_printptr(unsigned long long ptr);
int		ft_printf(const char *format, ...);
int		ft_countnum(long long num);
void	ft_putnbr(int num);

#endif
