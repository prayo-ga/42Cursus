/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: prayo-ga <prayo-ga@student.42malaga.com    +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2024/04/27 21:28:42 by prayo-ga          #+#    #+#             */
/*   Updated: 2024/04/27 21:28:42 by prayo-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rotate_a(t_stack **stack_a, int *cost_a)
{
	if (*cost_a > 0)
	{
		while (*cost_a > 0)
		{
			rotate_right_a(stack_a, 1);
			(*cost_a)--;
		}
	}
	if (*cost_a < 0)
	{
		while (*cost_a < 0)
		{
			rotate_left_a(stack_a, 1);
			(*cost_a)++;
		}
	}
}

void	rotate_b(t_stack **stack_b, int *cost_b)
{
	if (*cost_b > 0)
	{
		while (*cost_b > 0)
		{
			rotate_right_b(stack_b, 1);
			(*cost_b)--;
		}
	}
	if (*cost_b < 0)
	{
		while (*cost_b < 0)
		{
			rotate_left_b(stack_b, 1);
			(*cost_b)++;
		}
	}
}

void	algorithm(t_stack **stack_a, t_stack **stack_b, int fase)
{
	if (fase == 2)
		swap_a(stack_a, 1);
	if (fase == 3)
		second_movement(stack_a);
	if (fase > 3)
	{
		put_index(stack_a);
		first_movement(stack_a, stack_b);
		second_movement(stack_a);
		while (stack_size(*stack_b) > 0)
		{
			put_position(stack_a);
			put_position(stack_b);
			third_movement(stack_a, stack_b);
			cost_calculator(stack_a, stack_b);
			fourth_movement(stack_a, stack_b);
		}
		if (!list_sort(stack_a))
			last_movement(stack_a);
	}
}
