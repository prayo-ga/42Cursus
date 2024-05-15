/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prayo-ga <prayo-ga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 17:07:04 by prayo-ga          #+#    #+#             */
/*   Updated: 2024/05/08 19:55:15 by prayo-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	if (stack_size(*stack) > 1)
	{
		first = *stack;
		last = *stack;
		*stack = first->next;
		while (last->next != NULL)
			last = last->next;
		last->next = first;
		first->next = NULL;
	}
}

void	rotate_right_a(t_stack **stack_a, int flag)
{
	rotate(stack_a);
	if (flag == 1)
		ft_printf("ra\n");
}

void	rotate_right_b(t_stack **stack_b, int flag)
{
	rotate(stack_b);
	if (flag == 1)
		ft_printf("rb\n");
}

void	rotate_both(t_stack **stack_a, t_stack **stack_b, int flag)
{
	rotate(stack_a);
	rotate(stack_b);
	if (flag == 1)
		ft_printf("rr\n");
}
