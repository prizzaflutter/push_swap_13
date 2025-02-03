/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaskour <iaskour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 08:31:24 by iaskour           #+#    #+#             */
/*   Updated: 2025/02/03 18:01:56 by iaskour          ###   ########.fr       */
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
		if (ft_atoi(tmp->content) == number)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	delete_content(void *content)
{
	free(content);
	printf("askour\n");
}
// void f()
// {
// 	system("leaks push_swap");
// }
int	initialize_stack_a(t_list **stack_a, char **argv)
{
	int		i;
	long	number;
	char	*value;
	t_list *new;
	
	i = 0;
	while (argv[i] != NULL)
	{
		if (syntax_issue(argv[i]) == 0)
			return(printf("am here in systen_issue\n"), ft_lstclear(stack_a, delete_content), 0);
		number = ft_atoi(argv[i]);
		if (number > INT_MAX || number < INT_MIN)
			return(printf("am here number > int max : \n"), ft_lstclear(stack_a, delete_content), 0);
		if (!dublicated_detected(stack_a, number))
			return(printf("am her in duplicated_detected \n"), ft_lstclear(stack_a, delete_content), 0);
		value = ft_itoa(number);
		if(!value)
			return (ft_lstclear(stack_a, delete_content), 0);
		new = ft_lstnew(value);
		if (!new)
			return(free(value), ft_lstclear(stack_a, delete_content), 0);
		ft_lstadd_back(stack_a, new);
		printf("the stack_a is 4444 : %s\n", (*stack_a)->content);
		// free(value);
		// free(new);
		// value = NULL;
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

int is_stack_a_sorted(t_list **stack_a)
{
	t_list *tmp;

	tmp = *stack_a;
	while (tmp->next)
	{
		if (ft_atoi(tmp->content) > ft_atoi(tmp->next->content))
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
void sort_stack(t_list **stack_a , t_list **stack_b)
	{
		(void)stack_a;
		(void)stack_b;
	}
int	main(int argc, char *argv[])
{
	t_list	*stack_a = NULL;
	char	**argv_splited = NULL;
	t_list	*stack_b = NULL;

	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
		argv_splited = ft_split(argv[1], ' ');
	else
		argv++;
	if (argv_splited)
		initialize_stack_a(&stack_a, argv_splited);
	else
		initialize_stack_a(&stack_a, argv);
	if(argv_splited)
		free_argv_splited(argv_splited);
	if(!is_stack_a_sorted(&stack_a))
	{
		printf("the stack size is %d\n", ft_lstsize(stack_a));
	    if(ft_lstsize(stack_a) == 2)
	        {
				printf("size is 2 =================>\n");
				sa(&stack_a);
			}
	    else if(ft_lstsize(stack_a) == 3)
	        {
				printf("size is 3 =================>\n");
				sort_3(&stack_a);
			}
			 else 
		{
				printf("sort stack \n");
				sort_stack(&stack_a, &stack_b);
			}
	}
	else 
	{
		printf("idriss here\n");
	}
	while(stack_a->next)
	{
		printf("the stack_a is : %s\n", stack_a->content);
		stack_a = stack_a->next;
	}
	printf("the stack_a is : %s\n", stack_a->content);
	return 0;
}


