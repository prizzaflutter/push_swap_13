/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaskour <iaskour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 09:30:39 by iaskour           #+#    #+#             */
/*   Updated: 2025/02/12 08:52:24 by iaskour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rra(t_list **a, int print_t)
{
	t_list	*last_a;
	t_list	*before_last_a;

	if (!a || !(*a) || !(*a)->next)
		return ;
	last_a = *a;
	before_last_a = NULL;
	while (last_a->next)
	{
		before_last_a = last_a;
		last_a = last_a->next;
	}
	if (before_last_a)
		before_last_a->next = NULL;
	last_a->next = *a;
	*a = last_a;
	if (print_t)
		ft_putstr("rra\n", 1);
}
