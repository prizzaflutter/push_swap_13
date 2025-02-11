#include "../push_swap.h"
#include <stdio.h>



t_list *get_min_node (t_list *stack)
{
    t_list *min_node = NULL;
    long min_value;

    min_value = LONG_MAX;
    while (stack)
    {
        if(stack->content < min_value)
        {
            min_value = stack->content;
            min_node = stack;
        }
        stack = stack->next;
    }
    return min_node;
}


void min_on_top (t_list **a)
{
	t_list *min_node;

	min_node = get_min_node(*a);
	while ((*a)->content != min_node->content)
	{
		if(min_node->above_median)
			ra(a, 1);
		else
			rra(a, 1);
	}
}


void set_target_b (t_list *a, t_list *b)
{
	t_list *current_a;
	t_list *target_node;
	long   best_target;

	while (b)
	{
		best_target = LONG_MAX;
		target_node = NULL;
		current_a = a;
		while (current_a)
		{
			
			if(current_a->content > b->content && current_a->content < best_target)
			{
				best_target = current_a->content;
				target_node = current_a;
			}
			current_a = current_a->next;
		}
		if(!target_node)
			target_node = get_min_node(a);
		b->target_node = target_node;
		b = b->next;
	}
}

void set_cost_b (t_list *a, t_list *b)
{
	int size_b;
	int size_a;

	size_a = ft_lstsize(a);
	size_b = ft_lstsize(b);
	while(b)
	{
		b->cost = b->index;
		if(b->above_median == 0)
			b->cost = size_b - (b->index);
		if(b->target_node->above_median == 1)
			b->cost += b->target_node->index;
		else
			b->cost += size_a - b->target_node->index;
		b = b->next;
	}
}
