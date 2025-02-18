/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaskour <iaskour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 16:38:17 by iaskour           #+#    #+#             */
/*   Updated: 2025/02/11 15:59:01 by iaskour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	sort_3(t_list **stack_a)
{
	t_list	*beggest_node;

	beggest_node = get_max_node(*stack_a);
	if (is_stack_a_sorted(*stack_a))
		return (1);
	if (beggest_node == *stack_a)
		ra(stack_a, 1);
	else if ((*stack_a)->next == beggest_node)
		rra(stack_a, 1);
	if ((*stack_a)->content > (*stack_a)->next->content)
		sa(stack_a);
	return (1);
}
