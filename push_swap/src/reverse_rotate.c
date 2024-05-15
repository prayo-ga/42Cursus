/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prayo-ga <prayo-ga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 15:08:59 by prayo-ga          #+#    #+#             */
/*   Updated: 2024/05/08 19:54:10 by prayo-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	reverse_rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	if (*stack && (*stack)->next)
	{
		last = *stack;
		while (last->next != NULL)
			last = last->next;
		first = *stack;
		while (first->next != last)
			first = first->next;
		first->next = NULL;
		last->next = *stack;
		*stack = last;
	}
}

void	rotate_left_a(t_stack **stack_a, int flag)
{
	reverse_rotate(stack_a);
	if (flag == 1)
		ft_printf("rra\n");
}

void	rotate_left_b(t_stack **stack_b, int flag)
{
	reverse_rotate(stack_b);
	if (flag == 1)
		ft_printf("rrb\n");
}

void	reverse_rotate_both(t_stack **stack_a, t_stack **stack_b, int flag)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	if (flag == 1)
		ft_printf("rrr\n");
}
