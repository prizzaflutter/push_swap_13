#include "../push_swap.h"
#include <stdio.h>


void process_for_push (t_list **stack, t_list *top_node, char stack_name)
{
	while (*stack != top_node)
	{
		if(stack_name == 'a')
		{
			if (top_node->above_median)
				ra(stack);
			else
				rra(stack);
		}
		else if (stack_name == 'b')
		{
			if(top_node->above_median)
				rb(stack);
			else
				rrb(stack);
		}
	}
	
}

t_list *get_cheapest_node (t_list *stack)
{
	t_list *cheapest_node = stack;
	t_list *tmp = stack;
	while (tmp)
	{
		if (tmp->cost < cheapest_node->cost)
			cheapest_node = tmp;
		tmp = tmp->next;
	}
	return cheapest_node;
}

void rotate_both (t_list **stack_a, t_list **stack_b, t_list *cheapest_node)
{
	while (*stack_a != cheapest_node && *stack_b != cheapest_node->target_node)
		rr(stack_a, stack_b);
	set_index_median(*stack_a);
	set_index_median(*stack_b);
}

void reverse_rotate_both (t_list **stack_a, t_list **stack_b, t_list *cheapest_node)
{
	while (*stack_a != cheapest_node && *stack_b != cheapest_node->target_node)
		rrr(stack_a, stack_b);
	set_index_median(*stack_a);
	set_index_median(*stack_b);
}

void move_a_to_b (t_list **stack_a , t_list **stack_b)
{
	t_list *cheapest_node = get_cheapest_node(*stack_a);
	
	if (cheapest_node->above_median == 1 && cheapest_node->target_node->above_median == 1)
		rotate_both(stack_a, stack_b, cheapest_node);
	else if (cheapest_node->above_median == 0 && cheapest_node->target_node->above_median == 0)
		reverse_rotate_both(stack_a, stack_b, cheapest_node);
	process_for_push(stack_a, cheapest_node, 'a');
	process_for_push(stack_b, cheapest_node->target_node, 'b');
	pb(stack_b, stack_a);
}


void move_b_to_a (t_list **stack_a, t_list **stack_b)
{
	process_for_push(stack_a, (*stack_b)->target_node, 'a');
	pa(stack_a, stack_b);
}