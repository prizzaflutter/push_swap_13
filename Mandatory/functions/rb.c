/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaskour <iaskour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 09:25:27 by iaskour           #+#    #+#             */
/*   Updated: 2025/02/03 09:29:20 by iaskour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rb(t_list **b)
{
	t_list *top_b;
	t_list *travers;
	if(!b || !(*b)|| !(*b)->next)
		return ;

	top_b = *b;
	*b  = (*b)->next;
	travers = top_b;
	while (travers->next)
		travers = travers->next;
	travers->next = top_b;
	top_b->next = NULL;
	top_b->prev = travers;
}