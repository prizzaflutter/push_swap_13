/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_a_to_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaskour <iaskour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 08:33:46 by iaskour           #+#    #+#             */
/*   Updated: 2025/02/12 08:37:49 by iaskour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	process_for_push(t_list **stack, t_list *top_node, char stack_name)
{
	while (*stack != top_node)
	{
		if (stack_name == 'a')
		{
			if (top_node->above_median)
				ra(stack, 1);
			else
				rra(stack, 1);
		}
		else if (stack_name == 'b')
		{
			if (top_node->above_median)
				rb(stack, 1);
			else
				rrb(stack, 1);
		}
	}
}

t_list	*get_cheapest_node(t_list *stack)
{
	while (stack)
	{
		if (stack->cheapest == 1)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

void	rotate_both(t_list **stack_a, t_list **stack_b, t_list *cheapest_node)
{
	while (*stack_a != cheapest_node && *stack_b != cheapest_node->target_node)
		rr(stack_a, stack_b);
	set_index_median(*stack_a);
	set_index_median(*stack_b);
}

void	reverse_rotate_both(t_list **stack_a,
		t_list **stack_b, t_list *cheapest_node)
{
	while (*stack_a != cheapest_node && *stack_b != cheapest_node->target_node)
		rrr(stack_a, stack_b);
	set_index_median(*stack_a);
	set_index_median(*stack_b);
}

void	move_a_to_b(t_list **stack_a, t_list **stack_b)
{
	t_list	*cheapest_node;

	cheapest_node = get_cheapest_node(*stack_a);
	if (!cheapest_node)
		return ;
	if (cheapest_node->above_median == 1
		&& cheapest_node->target_node->above_median == 1)
		rotate_both(stack_a, stack_b, cheapest_node);
	else if (cheapest_node->above_median == 0
		&& cheapest_node->target_node->above_median == 0)
		reverse_rotate_both(stack_a, stack_b, cheapest_node);
	process_for_push(stack_a, cheapest_node, 'a');
	process_for_push(stack_b, cheapest_node->target_node, 'b');
	pb(stack_b, stack_a);
}
