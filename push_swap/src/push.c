/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prayo-ga <prayo-ga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 12:57:55 by prayo-ga          #+#    #+#             */
/*   Updated: 2024/05/06 13:05:57 by prayo-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push(t_stack **stack_one, t_stack **stack_two)
{
	t_stack	*temp;

	if (stack_size(*stack_two) >= 1)
	{
		temp = *stack_two;
		*stack_two = (*stack_two)->next;
		temp->next = *stack_one;
		*stack_one = temp;
	}
}

void	push_a(t_stack **stack_a, t_stack **stack_b, int flag)
{
	push(stack_a, stack_b);
	if (flag == 1)
		ft_printf("pa\n");
}

void	push_b(t_stack **stack_a, t_stack **stack_b, int flag)
{
	push(stack_b, stack_a);
	if (flag == 1)
		ft_printf("pb\n");
}
