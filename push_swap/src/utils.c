/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prayo-ga <prayo-ga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 15:57:03 by prayo-ga          #+#    #+#             */
/*   Updated: 2024/05/15 21:52:29 by prayo-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	*stack_last(t_stack *stack)
{
	t_stack	*current;

	if (!stack)
		return (0);
	current = stack;
	while (current->next)
		current = current->next;
	return (current);
}

void	stack_add_last(t_stack **stack, t_stack *new)
{
	t_stack	*current;

	if (*stack == NULL)
		*stack = new;
	else
	{
		current = stack_last(*stack);
		current->next = new;
	}
}

int	stack_size(t_stack *stack)
{
	int		number_elements;
	t_stack	*current;

	if (!stack)
		return (0);
	number_elements = 1;
	current = stack;
	while (current->next)
	{
		number_elements++;
		current = current->next;
	}
	return (number_elements);
}

void	free_str(char **str)
{
	int	go_throw_str;

	if (str == NULL)
		return ;
	go_throw_str = 0;
	while (str[go_throw_str] != NULL)
	{
		free(str[go_throw_str]);
		go_throw_str++;
	}
	free(str);
}

int	list_sort(t_stack **stack)
{
	t_stack	*temp;

	temp = *stack;
	if (temp == NULL)
		return (TRUE);
	while (temp && temp->next)
	{
		if (temp->values > temp->next->values)
		{
			return (FALSE);
		}
		temp = temp->next;
	}
	return (TRUE);
}
