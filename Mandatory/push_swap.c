/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaskour <iaskour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 08:31:24 by iaskour           #+#    #+#             */
/*   Updated: 2025/02/11 10:39:14 by iaskour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	syntax_issue(char* argument)
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

int dublicated_detected(t_list **stack_a, long number)
{
	t_list *tmp;

	tmp = *stack_a;
	while (tmp)
	{
		// here may be leaks
		if (tmp->content == number)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

// void f()
// {
// 	system("leaks push_swap");
// }
int	initialize_stack_a(t_list **stack_a, char **argv)
{
	int		i;
	long	number;
	t_list *new;
	
	i = 0;
	while (argv[i] != NULL)
	{
		if (syntax_issue(argv[i]) == 0)
			return(printf("am here in systen_issue\n"), ft_lstclear(stack_a), 0);
		number = ft_atoi(argv[i]);
		if (number > INT_MAX || number < INT_MIN)
			return(printf("am here number > int max : \n"), ft_lstclear(stack_a), 0);
		if (!dublicated_detected(stack_a, number))
			return(printf("am her in duplicated_detected \n"), ft_lstclear(stack_a), 0);
		new = ft_lstnew(number);
		if (!new)
			return(ft_lstclear(stack_a), 0);
		ft_lstadd_back(stack_a, new);
		i++;
	}
	return (1);
}

void free_argv_splited(char **argv_splited)
{
	int i;

	i = 0;
	while (argv_splited[i])
	{
		free(argv_splited[i]);
		i++;
	}
	free(argv_splited);
}

int is_stack_a_sorted(t_list *stack_a)
{
	
	while (stack_a && stack_a->next)
	{
		if (stack_a->content > stack_a->next->content)
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	t_list	*stack_a = NULL;
	char	**argv_splited = NULL;
	t_list	*stack_b = NULL;

	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
		argv_splited  = ft_split(argv[1], ' ');
    
	if(argv_splited && *argv_splited != NULL)
		initialize_stack_a(&stack_a, argv_splited);
	else
		initialize_stack_a(&stack_a, argv + 1);
	if(argv_splited)
		free_argv_splited(argv_splited);
	if(!is_stack_a_sorted(stack_a))
	{
		if( ft_lstsize(stack_a) == 2)
			return (sa(&stack_a), 1);
	    else if(ft_lstsize(stack_a) == 3)
			sort_3(&stack_a);
		else 
			sort_stack(&stack_a, &stack_b);
	}
	return 0;
}


