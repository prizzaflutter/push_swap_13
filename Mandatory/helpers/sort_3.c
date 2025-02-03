/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaskour <iaskour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 16:38:17 by iaskour           #+#    #+#             */
/*   Updated: 2025/02/03 16:56:35 by iaskour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int sort_3 (t_list **stack_a)
{
	int first = *(int *)(*stack_a)->content;
	int second = *(int *)(*stack_a)->next->content;
	int third = *(int *)(*stack_a)->next->next->content;

	if(first > second && second > third)
		return (sa(stack_a), rra(stack_a), 1);
	else if (first > third && second < third)
		return (ra(stack_a), 1);
	else if (second > first && first > third)
		return (rra(stack_a), 1);
	else if (third > first && first > second)
		return (sa(stack_a), 1);
	else if (second > third && third > first)
		return (sa(stack_a), ra(stack_a), 1);
	return 1;
}