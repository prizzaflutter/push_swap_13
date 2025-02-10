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


// void min_on_top (t_list **a)
// {
// 	t_list *min_node;

// 	min_node = get_min_node(*a);
// 	while ((*a)->content != min_node->content)
// 	{
// 		if(min_node->above_median)
// 			ra(a);
// 		else
// 			rra(a);
// 	}
// }


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
		if(target_node == NULL)
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
		if(!(b->above_median))
			b->cost = size_b - (b->index);
		if(b->target_node->above_median)
			b->cost += b->target_node->index;
		else
			b->cost += size_a - b->target_node->index;
		b = b->next;
	}
}

void set_cheapest_b (t_list *b)
{
	long cheapest_value;
	t_list *cheapest_node;

	cheapest_value = LONG_MAX;
	if(!b)
		return ;
	while (b)
	{
		if(b->cost < cheapest_value)
		{
			cheapest_value = b->cost;
			cheapest_node = b;
		}
		b = b->next;
	}
	cheapest_node->cheapest = 1;
}