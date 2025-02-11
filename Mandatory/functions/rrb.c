/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaskour <iaskour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 09:44:51 by iaskour           #+#    #+#             */
/*   Updated: 2025/02/11 11:30:36 by iaskour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void rrb(t_list **b, int print_t)
{
	t_list *last_b;
	t_list *before_last_b;
	
	if(!b || !(*b)|| !(*b)->next)
		return ;
	last_b = *b;
	while (last_b->next)
		last_b = last_b->next;
	before_last_b = last_b->prev;
	before_last_b->next = NULL;
	last_b->prev = NULL;
	last_b->next = *b;
	(*b)->prev = last_b;
	*b = last_b;
	if(print_t)
		ft_putstr("rrb\n", 1);
}