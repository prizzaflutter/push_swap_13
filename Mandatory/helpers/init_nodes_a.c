/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_nodes_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaskour <iaskour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 14:39:04 by iaskour           #+#    #+#             */
/*   Updated: 2025/02/12 13:36:59 by iaskour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	set_index_median(t_list *stack)
{
	int	i;
	int	median;

	i = 0;
	if (!stack)
		return ;
	median = ft_lstsize(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i <= median)
			stack->above_median = 1;
		else
			stack->above_median = 0;
		stack = stack->next;
		++i;
	}
}

t_list	*get_max_node(t_list *stack)
{
	t_list	*max_node;
	long	max_value;

	max_node = NULL;
	max_value = LONG_MIN;
	while (stack)
	{
		if (stack->content > max_value)
		{
			max_value = stack->content;
			max_node = stack;
		}
		stack = stack->next;
	}
	return (max_node);
}

void	set_target_a(t_list *a, t_list *b)
{
	t_list	*current_b;
	t_list	*target_node;
	long	best_target;

	while (a)
	{
		best_target = LONG_MIN;
		target_node = NULL;
		current_b = b;
		while (current_b)
		{
			if (current_b->content < a->content
				&& current_b->content > best_target)
			{
				best_target = current_b->content;
				target_node = current_b;
			}
			current_b = current_b->next;
		}
		if (!target_node)
			target_node = get_max_node(b);
		a->target_node = target_node;
		a = a->next;
	}
}

void	set_cost_a(t_list *a, t_list *b)
{
	int	size_a;
	int	size_b;

	size_a = ft_lstsize(a);
	size_b = ft_lstsize(b);
	while (a)
	{
		a->cost = a->index;
		if (a->above_median == 0)
			a->cost = size_a - (a->index);
		if (a->target_node->above_median == 1)
			a->cost += a->target_node->index;
		else
			a->cost += size_b - (a->target_node->index);
		a = a->next;
	}
}

void	set_cheapest(t_list *stack)
{
	t_list	*cheapest_node;
	long	cheapest_value;
	t_list	*tmp;

	if (!stack)
		return ;
	cheapest_node = NULL;
	cheapest_value = LONG_MAX;
	tmp = stack;
	while (tmp)
	{
		tmp->cheapest = 0;
		if (tmp->cost < cheapest_value)
		{
			cheapest_value = tmp->cost;
			cheapest_node = tmp;
			if (cheapest_value == 0)
				break ;
		}
		tmp = tmp->next;
	}
	if (cheapest_node)
		cheapest_node->cheapest = 1;
}
