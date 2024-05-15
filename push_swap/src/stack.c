/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prayo-ga <prayo-ga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 15:24:32 by prayo-ga          #+#    #+#             */
/*   Updated: 2024/05/15 20:44:53 by prayo-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	stack_transfer(char *value_str, t_stack **stack)
{
	int		value;
	t_stack	*new_node;

	value = ft_atoi(value_str);
	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (new_node == NULL)
	{
		write(2, "Error8\n", 7);
		return (0);
	}
	new_node->values = value;
	new_node->position = 0;
	new_node->target = 0;
	new_node->index = 0;
	new_node->cost_a = 0;
	new_node->cost_b = 0;
	new_node->next = NULL;
	stack_add_last(stack, new_node);
	return (1);
}
