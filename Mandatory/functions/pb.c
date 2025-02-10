/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaskour <iaskour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 09:13:27 by iaskour           #+#    #+#             */
/*   Updated: 2025/02/10 11:03:31 by iaskour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void pb(t_list **b, t_list **a)
{
    
    t_list *top_a;
    
    if(!a || !(*a))
		return ;
    
    top_a = *a;
    *a = (*a)->next;
    if(*a)
        (*a)->prev = NULL;
    top_a->next = *b;
    if(*b)
        (*b)->prev = top_a;
    *b = top_a;
    ft_putstr("pb\n", 1);
}