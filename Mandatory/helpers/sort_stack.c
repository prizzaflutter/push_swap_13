/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaskour <iaskour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 18:03:46 by iaskour           #+#    #+#             */
/*   Updated: 2025/02/10 18:03:50 by iaskour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stdio.h>

void get_minumum_to_top (t_list **stack_a)
{
	t_list *tmp = *stack_a;
	int min = tmp->content;
	int index = 0;
	int i = 0;
	int stack_size = ft_lstsize(*stack_a);
	while (tmp)
	{
		if (tmp->content < min)
		{
			min = tmp->content;
			index = i;
		}
		i++;
		tmp = tmp->next;
	}
	if (index <=  stack_size / 2)
	{
		while ((*stack_a)->content != min)
			ra(stack_a);
	}
	else
	{
		while ((*stack_a)->content != min)
			rra(stack_a);
	}
}


void init_nodes_a (t_list *stack_a, t_list *stack_b)
{
	set_index_median(stack_a);
	set_index_median(stack_b);
	set_target_a(stack_a, stack_b);
	set_cost_a(stack_a, stack_b);
	set_cheapest(stack_a);
}
void init_nodes_b (t_list *stack_a, t_list *stack_b)
{
	set_index_median(stack_a);
	set_index_median(stack_b);
	set_target_b(stack_a, stack_b);
	// set_cost_b(stack_a, stack_b);
	// set_cheapest_b(stack_b);
}


void print_stack(t_list *stack)
{
    while (stack)
    {
        printf("%d\n", stack->content);
        stack = stack->next;
    }
}


void sort_stack (t_list **stack_a, t_list **stack_b)
{
	int size_of_a = ft_lstsize(*stack_a);
	if (size_of_a-- > 3 && !is_stack_a_sorted(*stack_a))
		pb(stack_b, stack_a);
	if (size_of_a-- > 3 && !is_stack_a_sorted(*stack_a))
		pb(stack_b, stack_a);
	while(size_of_a-- > 3 && !is_stack_a_sorted(*stack_a))
	{
		init_nodes_a(*stack_a, *stack_b);	
		move_a_to_b(stack_a, stack_b);
	}
	sort_3(stack_a);
	// get_maximun_to_top(stack_b);
	int size_of_b = ft_lstsize(*stack_b);
	while(size_of_b-- > 0)
	{
		init_nodes_b(*stack_a, *stack_b);
		move_b_to_a(stack_a, stack_b);
	}
	set_index_median(*stack_a);
	// min_on_top(stack_a);
	get_minumum_to_top(stack_a);
	// print_stack(*stack_a);
}

