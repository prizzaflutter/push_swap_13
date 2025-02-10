/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaskour <iaskour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 09:15:51 by iaskour           #+#    #+#             */
/*   Updated: 2025/02/10 11:03:34 by iaskour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ra(t_list **a)
{
	t_list *top_a;
	t_list *travers;
	
	if(!a || !(*a)|| !(*a)->next)
		return ;
	top_a = *a;
	*a  = (*a)->next;
	travers = top_a;
	while (travers->next)
		travers = travers->next;
	travers->next = top_a;
	top_a->next = NULL;
	top_a->prev = travers;
	ft_putstr("ra\n", 1);
}