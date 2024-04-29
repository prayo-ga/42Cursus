/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prayo-ga <prayo-ga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 21:28:42 by prayo-ga          #+#    #+#             */
/*   Updated: 2024/04/27 21:28:42 by prayo-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void    rotate_a(t_strack **stack_a, int *cost_a)
{
    if (*cost_a < 0)
    {
        while (*cost_a < 0)
        {
            rotate_left_a(stack_a 1)
            (*cost_a)++;
        }
    }
    if (*cost_a > 0)
    {
        while (*cost_a > 0)
        {
            rotate_right_a(stack_a, 1);
            (*cost_a)--;
        }
    }
}

voidrotate_b(t_stack **stack_b, int *cost_b)
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