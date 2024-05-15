/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prayo-ga <prayo-ga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 14:47:48 by prayo-ga          #+#    #+#             */
/*   Updated: 2024/05/15 17:48:23 by prayo-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	first_movement(t_stack **stack_a, t_stack **stack_b)
{
	int	size;
	int	i;
	int	push;

	size = stack_size(*stack_a);
	i = 0;
	push = 0;
	while (size > 6 && i < size && push < size / 2)
	{
		if ((*stack_a)->index < size / 2)
		{
			push_b(stack_a, stack_b, 1);
			push++;
		}
		else
			rotate_right_a(stack_a, 1);
		i++;
	}
	while (size - push > 3)
	{
		push_b(stack_a, stack_b, 1);
		push++;
	}
}

void	second_movement(t_stack **stack_a)
{
	t_stack	*first;
	t_stack	*middle;
	t_stack	*last;

	first = *stack_a;
	middle = first->next;
	last = middle->next;
	if (first->values > middle->values && first->values > last->values)
	{
		rotate_right_a(stack_a, 1);
		second_movement(stack_a);
	}
	if (first->values < middle->values && middle->values > last->values)
	{
		rotate_left_a(stack_a, 1);
		second_movement(stack_a);
	}
	if (first->values > middle->values && first->values < last->values)
		swap_a(stack_a, 1);
}

void	third_movement(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*target;
	t_stack	*copy_a;
	t_stack	*copy_b;
	int		left_over;

	target = index_max(stack_a);
	copy_a = *stack_a;
	copy_b = *stack_b;
	while (copy_b)
	{
		if (copy_b->index > target->index)
			copy_b->target = index_min(stack_a)->position;
		left_over = target->index - copy_b->index;
		calculate_target(copy_a, copy_b, &left_over);
		copy_a = *stack_a;
		copy_b = copy_b->next;
	}
}

void	fourth_movement(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*cheap;

	cheap = calculate_cheap(stack_b);
	while (cheap->cost_a < 0 && cheap->cost_b < 0)
	{
		reverse_rotate_both(stack_a, stack_b, 1);
		cheap->cost_a++;
		cheap->cost_b++;
	}
	while (cheap->cost_a > 0 && cheap->cost_b > 0)
	{
		rotate_both(stack_a, stack_b, 1);
		cheap->cost_a--;
		cheap->cost_b--;
	}
	rotate_a(stack_a, &(cheap->cost_a));
	rotate_b(stack_b, &(cheap->cost_b));
	push_a(stack_a, stack_b, 1);
}

void	last_movement(t_stack **stack_a)
{
	int	first;
	int	size;

	size = stack_size(*stack_a);
	first = index_min(stack_a)->index;
	if (first > size / 2)
	{
		while ((*stack_a)->index < size)
			rotate_left_a(stack_a, 1);
	}
	else
	{
		while ((*stack_a)->index != 1)
			rotate_right_a(stack_a, 1);
	}
}
