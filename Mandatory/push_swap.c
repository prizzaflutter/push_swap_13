/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaskour <iaskour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 08:31:24 by iaskour           #+#    #+#             */
/*   Updated: 2025/02/03 08:29:53 by iaskour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	syntax_issue(char c)
{
	(void)c;
	return 1;
}

int dublicated_detected(char c)
{
	(void)c;
	return 1;
}

void	delete_content(void *content)
{
	free(content);
	printf("askour\n");
}

int	initialize_stack_a(t_list **stack_a, char **argv)
{
	int		i;
	int		number;
	t_list *new;

	i = 0;
	while (argv[i] != NULL)
	{
		if (!syntax_issue(*argv[i]))
			return(ft_lstclear(stack_a, delete_content), 0);
		number = ft_atoi(argv[i]);
		if (number > INT_MAX || number < INT_MIN)
			return(ft_lstclear(stack_a, delete_content), 0);
		if (!dublicated_detected(*argv[i]))
			return(ft_lstclear(stack_a, delete_content), 0);
		new = ft_lstnew(argv[i]);
		printf("new %s\n", new->content);
		ft_lstadd_back(stack_a, new);
		printf("new 2 %s\n", new->content);
		i++;
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	t_list	*stack_a = NULL;

	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
		argv = ft_split(argv[1], ' ');
	else 
		argv++;
	initialize_stack_a(&stack_a, argv);
	printf("stack a : %s\n", stack_a->content);
}

