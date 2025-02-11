/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaskour <iaskour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 09:00:48 by iaskour           #+#    #+#             */
/*   Updated: 2025/02/11 11:28:32 by iaskour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void pa(t_list **a, t_list **b)
{
    
    t_list *top_b;
    
    if(!b || !(*b))
		return ;
    
    top_b = *b;
    *b = (*b)->next;
    if(*b)
        (*b)->prev = NULL;
    top_b->next = *a;
    if(*a)
        (*a)->prev = top_b;
    *a = top_b;
    ft_putstr("pa\n", 1);
}