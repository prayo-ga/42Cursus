/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prayo-ga <prayo-ga@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:46:36 by prayo-ga          #+#    #+#             */
/*   Updated: 2023/12/08 16:44:34 by prayo-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_search(char const *context, int i, va_list *args)
{
	int	c;

	c = 0;
	if (context[i] == 'c')
		c += ft_printchar(va_arg(*args, int));
	if (context[i] == 's')
		c += ft_printstr(va_arg(*args, char *));
	if (context[i] == 'p')
		c += ft_printptr(va_arg(*args, unsigned long long));
	if (context[i] == 'u')
		c += ft_printunsigned(va_arg(*args, unsigned int));
	if (context[i] == 'd' || context[i] == 'i')
		c += ft_printdec(va_arg(*args, int));
	if (context[i] == 'x' || context[i] == 'X')
		c += ft_printhex(va_arg(*args, unsigned int), context[i]);
	if (context[i] == '%')
		c += ft_printchar('%');
	return (c);
}

int	ft_printf(char const *format, ...)
{
	va_list	args;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (write(1, "", 0) == (-1))
		return (-1);
	va_start(args, format);
	while (format[i])
	{
		if (format[i] != '%')
			j += ft_printchar(format[i]);
		else
		{
			i++;
			j += ft_search(format, i, &args);
		}
		i++;
	}
	va_end(args);
	return (j);
}
