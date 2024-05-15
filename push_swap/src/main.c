/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prayo-ga <prayo-ga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 14:59:27 by prayo-ga          #+#    #+#             */
/*   Updated: 2024/05/15 21:48:24 by prayo-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// void	leaks(void)
// {
// 	system("leaks -q push_swap");
// }

void	free_stack(t_stack **stack)
{
	t_stack	*node;
	t_stack	*temp;

	node = *stack;
	while (node)
	{
		temp = node->next;
		free(node);
		node = temp;
	}
	free(stack);
}

void	init_program(t_stack ***stack_a, t_stack ***stack_b)
{
	*stack_a = (t_stack **)malloc(sizeof(t_stack *));
	if (*stack_a == NULL)
	{
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	**stack_a = NULL;
	*stack_b = (t_stack **)malloc(sizeof(t_stack *));
	if (*stack_b == NULL)
	{
		free(*stack_a);
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	**stack_b = NULL;
}

char	**check_arguments(int ac, char *av[])
{
	char	**str;

	if (ac < 2)
		exit(EXIT_FAILURE);
	else if (ac == 2)
	{
		str = ft_split(av[1], ' ');
		if (str == NULL)
		{
			write(2, "Error\n", 6);
			exit(EXIT_FAILURE);
		}
		condition_checker(str);
		return (str);
	}
	else
	{
		condition_checker(av + 1);
		return (av + 1);
	}
}

int	main(int ac, char **av)
{
	t_stack	**stack_a;
	t_stack	**stack_b;
	char	**str;
	int		i;

	init_program(&stack_a, &stack_b);
	str = check_arguments(ac, av);
	i = 0;
	while (str[i] != NULL)
	{
		if (!stack_transfer(str[i], stack_a))
		{
			write(2, "Error\n", 6);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	if (!list_sort(stack_a))
		algorithm(stack_a, stack_b, i);
	if (ac == 2)
		free_str(str);
	if (ft_strcmp(av[1], "") == 0 || ft_strcmp(av[1], " ") == 0
		|| ft_strcmp(av[1], "-") == 0)
		write(2, "Error\n", 6);
	return (free_stack(stack_a), free_stack(stack_b), 0);
}
