/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prayo-ga <prayo-ga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 14:39:31 by prayo-ga          #+#    #+#             */
/*   Updated: 2024/05/08 21:36:28 by prayo-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	calculate_target(t_stack *copy_a, t_stack *copy_b, int *rest)
{
	while (copy_a)
	{
		if (copy_b->index < copy_a->index)
		{
			if (copy_a->index - copy_b->index <= *rest)
			{
				*rest = copy_a->index - copy_b->index;
				copy_b->target = copy_a->position;
			}
		}
		copy_a = copy_a->next;
	}
}

t_stack	*index_max(t_stack **stack_a)
{
	t_stack	*copy;
	t_stack	*max;

	copy = *stack_a;
	max = *stack_a;
	while (copy)
	{
		if (copy->values > max->values)
			max = copy;
		copy = copy->next;
	}
	return (max);
}

t_stack	*index_min(t_stack **stack_a)
{
	t_stack	*copy;
	t_stack	*min;

	copy = *stack_a;
	min = *stack_a;
	while (copy)
	{
		if (copy->values < min->values)
			min = copy;
		copy = copy->next;
	}
	return (min);
}

void	put_index(t_stack **stack)
{
	t_stack	*current;
	t_stack	*compare;

	current = *stack;
	while (current)
	{
		compare = *stack;
		current->index = 1;
		while (compare)
		{
			if (compare->values < current->values)
				current->index++;
			compare = compare->next;
		}
		current = current->next;
	}
}

void	put_position(t_stack **stack)
{
	t_stack	*temp;
	int		i;

	temp = *stack;
	i = 1;
	while (temp)
	{
		temp->position = i;
		temp = temp->next;
		i++;
	}
}
