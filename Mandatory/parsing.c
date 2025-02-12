/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaskour <iaskour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 13:20:54 by iaskour           #+#    #+#             */
/*   Updated: 2025/02/12 13:40:47 by iaskour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	syntax_issue(char *argument)
{
	int	i;

	i = 0;
	while (argument[i])
	{
		if ((argument[i] == '-' || argument[i] == '+') && i == 0)
			i++;
		if (!ft_isdigit(argument[i]))
			return (0);
		i++;
	}
	return (1);
}

int	dublicated_detected(t_list **stack_a, long number)
{
	t_list	*tmp;

	tmp = *stack_a;
	while (tmp)
	{
		if (tmp->content == number)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	is_stack_a_sorted(t_list *stack_a)
{
	while (stack_a && stack_a->next)
	{
		if (stack_a->content > stack_a->next->content)
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}

int	initialize_stack_a(t_list **stack_a, char **argv)
{
	int		i;
	long	number;
	t_list	*new;

	i = 0;
	while (argv[i] != NULL)
	{
		if (syntax_issue(argv[i]) == 0)
			return (ft_putstr("Error\n", 2), ft_lstclear(stack_a), 0);
		number = ft_atoi(argv[i]);
		if (number > INT_MAX || number < INT_MIN)
			return (ft_putstr("Error\n", 2), ft_lstclear(stack_a), 0);
		if (!dublicated_detected(stack_a, number))
			return (ft_putstr("Error\n", 2), ft_lstclear(stack_a), 0);
		new = ft_lstnew(number);
		if (!new)
			return (ft_lstclear(stack_a), 0);
		ft_lstadd_back(stack_a, new);
		i++;
	}
	return (1);
}

int	is_space_exist(char *string)
{
	int	i;

	i = 0;
	if (!string)
		return (0);
	while (string[i])
	{
		if (string[i] == ' ' || string[i] == '\t')
			return (1);
		i++;
	}
	return (0);
}
