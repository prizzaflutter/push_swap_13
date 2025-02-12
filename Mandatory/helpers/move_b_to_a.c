/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_b_to_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaskour <iaskour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 08:28:48 by iaskour           #+#    #+#             */
/*   Updated: 2025/02/12 08:38:47 by iaskour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	move_b_to_a(t_list **stack_a, t_list **stack_b)
{
	process_for_push(stack_a, (*stack_b)->target_node, 'a');
	pa(stack_a, stack_b);
}
