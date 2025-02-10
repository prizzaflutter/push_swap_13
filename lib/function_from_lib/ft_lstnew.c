/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaskour <iaskour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 11:06:33 by iaskour           #+#    #+#             */
/*   Updated: 2025/02/07 16:16:38 by iaskour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Mandatory/push_swap.h"

t_list	*ft_lstnew(int content)
{
	t_list	*head;

	head = malloc(sizeof(struct s_list));
	if (head == NULL)
		return (NULL);
	head->content = content;
	head->next = NULL;
	head->prev = NULL;
	return (head);
}
