/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prayo-ga <prayo-ga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 15:19:04 by prayo-ga          #+#    #+#             */
/*   Updated: 2024/05/15 21:48:25 by prayo-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	check_duplicate(char **av)
{
	char	**actual_memory;
	char	**cmpr;
	int		cntr;
	int		act_num;

	actual_memory = av + 1;
	while (*actual_memory != NULL)
	{
		act_num = ft_atoi(*actual_memory);
		cmpr = av;
		while (cmpr < actual_memory)
		{
			cntr = ft_atoi(*cmpr);
			if (act_num == cntr)
				return (FALSE);
			cmpr++;
		}
		actual_memory++;
	}
	return (TRUE);
}

int	check_correct_digit(char **av)
{
	int	lcount;
	int	word_count;

	lcount = 0;
	while (av[lcount] != NULL)
	{
		word_count = 0;
		if (av[lcount][word_count] == '-')
		{
			word_count++;
			if (av[lcount][word_count] == '-' || av[lcount][word_count] == '+')
				return (FALSE);
		}
		while (av[lcount][word_count] != '\0')
		{
			if (!ft_isdigit(av[lcount][word_count]))
				return (FALSE);
			word_count++;
		}
		if (ft_atoi(av[lcount]) < MIN_INT || ft_atoi(av[lcount]) > MAX_INT)
			return (FALSE);
		lcount++;
	}
	return (TRUE);
}

void	condition_checker(char **av)
{
	if (check_duplicate(av) == FALSE)
	{
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	if (check_correct_digit(av) == FALSE)
	{
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
}
