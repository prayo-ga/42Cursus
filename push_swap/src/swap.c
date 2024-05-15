/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prayo-ga <prayo-ga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 11:42:52 by prayo-ga          #+#    #+#             */
/*   Updated: 2024/05/06 13:18:15 by prayo-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap(t_stack **stack)
{
	t_stack	*temp;

	if (stack_size(*stack) > 1)
	{
		temp = *stack;
		*stack = (*stack)->next;
		temp->next = (*stack)->next;
		(*stack)->next = temp;
	}
}

void	swap_a(t_stack **stack_a, int flag)
{
	swap(stack_a);
	if (flag == 1)
		ft_printf("sa\n");
}

void	swap_b(t_stack	**stack_b, int flag)
{
	swap(stack_b);
	if (flag == 1)
		ft_printf("sb\n");
}

void	swap_s(t_stack **stack_a, t_stack **stack_b, int flag)
{
	swap(stack_a);
	swap(stack_b);
	if (flag == 1)
		ft_printf("ss\n");
}
