/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prayo-ga <prayo-ga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 18:07:49 by prayo-ga          #+#    #+#             */
/*   Updated: 2024/05/15 18:07:49 by prayo-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

# define FALSE 0
# define TRUE 1

# define MIN_INT -2147483648
# define MAX_INT 2147483647

typedef struct s_stack
{
	int				values;
	int				index;
	int				position;
	int				target;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
}	t_stack;

void	rotate_a(t_stack **stack_a, int *cost_a);
void	rotate_b(t_stack **stack_b, int *cost_b);
void	algorithm(t_stack **stack_a, t_stack **stack_b, int fase);
void	free_stack(t_stack **stack);
void	init_program(t_stack ***stack_a, t_stack ***stack_b);
char	**check_arguments(int ac, char *av[]);
int		main(int ac, char **av);
void	rotate(t_stack **stack);
void	rotate_right_a(t_stack **stack_a, int flag);
void	rotate_right_b(t_stack **stack_b, int flag);
void	rotate_both(t_stack **stack_a, t_stack **stack_b, int flag);
void	reverse_rotate(t_stack **stack);
void	rotate_left_a(t_stack **stack_a, int flag);
void	rotate_left_b(t_stack **stack_b, int flag);
void	reverse_rotate_both(t_stack **stack_a, t_stack **stack_b, int flag);
int		check_duplicate(char **av);
int		check_correct_digit(char **av);
void	condition_checker(char **av);
int		check_even(int size);
t_stack	*calculate_cheap(t_stack **stack_b);
void	cost_calculator(t_stack **stack_a, t_stack **stack_b);
void	*stack_last(t_stack *stack);
void	stack_add_last(t_stack **stack, t_stack *new);
int		stack_size(t_stack *stack);
void	free_str(char **str);
int		list_sort(t_stack **stack);
void	swap(t_stack **stack);
void	swap_a(t_stack **stack_a, int flag);
void	swap_b(t_stack	**stack_b, int flag);
void	swap_s(t_stack **stack_a, t_stack **stack_b, int flag);
void	push(t_stack **stack_one, t_stack **stack_two);
void	push_a(t_stack **stack_a, t_stack **stack_b, int flag);
void	push_b(t_stack **stack_a, t_stack **stack_b, int flag);
void	calculate_target(t_stack *copy_a, t_stack *copy_b, int *reset);
t_stack	*index_max(t_stack **stack_a);
t_stack	*index_min(t_stack **stack_a);
void	put_index(t_stack **stack);
void	put_position(t_stack **stack);
int		stack_transfer(char *value_str, t_stack **stack);
void	first_movement(t_stack **stack_a, t_stack **stack_b);
void	second_movement(t_stack **stack_a);
void	third_movement(t_stack **stack_a, t_stack **stack_b);
void	fourth_movement(t_stack **stack_a, t_stack **stack_b);
void	last_movement(t_stack **stack_a);

#endif