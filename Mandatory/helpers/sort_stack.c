/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaskour <iaskour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 18:03:46 by iaskour           #+#    #+#             */
/*   Updated: 2025/02/11 15:58:11 by iaskour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	get_minumum_to_top(t_list **stack_a)
{
	t_list	*tmp;
	int		min;
	int		index;
	int		i;

	index = 0;
	i = 0;
	tmp = *stack_a;
	min = tmp->content;
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
	if (index <= ft_lstsize(*stack_a) / 2)
		while ((*stack_a)->content != min)
			ra(stack_a, 1);
	else
		while ((*stack_a)->content != min)
			rra(stack_a, 1);
}

void	init_nodes_a(t_list *stack_a, t_list *stack_b)
{
	set_index_median(stack_a);
	set_index_median(stack_b);
	set_target_a(stack_a, stack_b);
	set_cost_a(stack_a, stack_b);
	set_cheapest(stack_a);
}

void	init_nodes_b(t_list *stack_a, t_list *stack_b)
{
	set_index_median(stack_a);
	set_index_median(stack_b);
	set_target_b(stack_a, stack_b);
}

void	sort_stack(t_list **stack_a, t_list **stack_b)
{
	int	size_of_a;
	int	size_of_b;

	size_of_a = ft_lstsize(*stack_a);
	if (size_of_a-- > 3 && !is_stack_a_sorted(*stack_a))
		pb(stack_b, stack_a);
	if (size_of_a-- > 3 && !is_stack_a_sorted(*stack_a))
		pb(stack_b, stack_a);
	while (size_of_a-- > 3 && !is_stack_a_sorted(*stack_a))
	{
		init_nodes_a(*stack_a, *stack_b);
		move_a_to_b(stack_a, stack_b);
	}
	sort_3(stack_a);
	size_of_b = ft_lstsize(*stack_b);
	while (size_of_b-- > 0)
	{
		init_nodes_b(*stack_a, *stack_b);
		move_b_to_a(stack_a, stack_b);
	}
	set_index_median(*stack_a);
	get_minumum_to_top(stack_a);
}
