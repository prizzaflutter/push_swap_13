/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_nodes_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaskour <iaskour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 08:23:56 by iaskour           #+#    #+#             */
/*   Updated: 2025/02/12 08:26:32 by iaskour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list	*get_min_node(t_list *stack)
{
	t_list	*min_node;
	long	min_value;

	min_value = LONG_MAX;
	min_node = NULL;
	while (stack)
	{
		if (stack->content < min_value)
		{
			min_value = stack->content;
			min_node = stack;
		}
		stack = stack->next;
	}
	return (min_node);
}

void	set_target_b(t_list *a, t_list *b)
{
	t_list	*current_a;
	t_list	*target_node;
	long	best_target;

	while (b)
	{
		best_target = LONG_MAX;
		target_node = NULL;
		current_a = a;
		while (current_a)
		{
			if (current_a->content > b->content
				&& current_a->content < best_target)
			{
				best_target = current_a->content;
				target_node = current_a;
			}
			current_a = current_a->next;
		}
		if (!target_node)
			target_node = get_min_node(a);
		b->target_node = target_node;
		b = b->next;
	}
}
