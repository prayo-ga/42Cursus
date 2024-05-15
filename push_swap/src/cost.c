/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prayo-ga <prayo-ga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 11:48:41 by prayo-ga          #+#    #+#             */
/*   Updated: 2024/05/04 15:43:06 by prayo-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	check_even(int size)
{
	int	half_index;

	if (size % 2 == 0)
		half_index = size / 2;
	else
		half_index = (size / 2) + 1;
	return (half_index);
}

int	absolute_value(int values)
{
	if (values < 0)
		return (values * -1);
	return (values);
}

t_stack	*calculate_cheap(t_stack **stack_b)
{
	t_stack	*copy;
	t_stack	*cheap;

	copy = *stack_b;
	cheap = copy;
	while (copy)
	{
		if (absolute_value(copy->cost_a) + absolute_value(copy->cost_b)
			< absolute_value(cheap->cost_a) + absolute_value(cheap->cost_b))
			cheap = copy;
		copy = copy->next;
	}
	return (cheap);
}

void	cost_calculator(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*copy_b;
	int		size_a;
	int		size_b;
	int		half_a;
	int		half_b;

	copy_b = *stack_b;
	size_a = stack_size(*stack_a);
	size_b = stack_size(*stack_b);
	half_a = check_even(size_a);
	half_b = check_even(size_b);
	while (copy_b)
	{
		copy_b->cost_b = copy_b->position - 1;
		if (copy_b->position > half_b)
			copy_b->cost_b = (size_b - copy_b->position + 1) * -1;
		copy_b->cost_a = copy_b->target - 1;
		if (copy_b->target > half_a)
			copy_b->cost_a = (size_a - copy_b->target + 1) * -1;
		copy_b = copy_b->next;
	}
}
