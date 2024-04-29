/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prayo-ga <prayo-ga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 21:02:54 by prayo-ga          #+#    #+#             */
/*   Updated: 2024/04/27 21:02:54 by prayo-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

# define FASLE 0
# defide TRUE 1

# define MIN_INT -2147483648
# define MAX_INT 2147483647

tydef struct s_stack_node
{
    int				values;
    int				index;
    int				positive;
	int				target;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
}					t_stack;
