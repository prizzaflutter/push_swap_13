/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaskour <iaskour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 08:31:24 by iaskour           #+#    #+#             */
/*   Updated: 2025/02/12 13:26:34 by iaskour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**merge_string(char *string)
{
	char	**merged_string;

	merged_string = NULL;
	if (is_space_exist(string) == 1)
		merged_string = ft_split(string, ' ');
	else
	{
		merged_string = (char **)malloc(sizeof(char *) * 2);
		if (!merged_string)
			return (0);
		merged_string[0] = ft_strdup(string);
		merged_string[1] = NULL;
	}
	return (merged_string);
}

int	size_of_string(char **string)
{
	int	size_of_string;

	size_of_string = 0;
	while (string && string[size_of_string])
		size_of_string++;
	return (size_of_string);
}

char	**join_argument(char **merged_string, char **new_string)
{
	int		i;
	int		j;
	char	**result;

	result = (char **)malloc(sizeof(char *)
			*(size_of_string(merged_string) + size_of_string(new_string) + 1));
	if (!result)
		return (0);
	i = 0;
	while (i < size_of_string(merged_string))
	{
		result[i] = ft_strdup(merged_string[i]);
		i++;
	}
	j = 0;
	while (j < size_of_string(new_string))
	{
		result[i] = ft_strdup(new_string[j]);
		j++;
	}
	result[i + j] = NULL;
	if (merged_string)
		free_argv_splited(merged_string);
	return (result);
}

void	start_algo(char **items)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (!initialize_stack_a(&stack_a, items) || !is_stack_a_sorted(stack_a))
	{
		if (ft_lstsize(stack_a) == 2)
			sa(&stack_a);
		else if (ft_lstsize(stack_a) == 3)
			sort_3(&stack_a);
		else
			sort_stack(&stack_a, &stack_b);
	}
	free_argv_splited(items);
	ft_lstclear(&stack_a);
	ft_lstclear(&stack_b);
}

int	main(int argc, char *argv[])
{
	char	**merged_string;
	int		i;
	char	**new_string;

	i = 0;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
		merged_string = ft_split(argv[1], ' ');
	else
	{
		while (i < argc - 1 > 0)
		{
			new_string = merge_string(argv[i + 1]);
			if (!new_string)
				return (1);
			merged_string = join_argument(merged_string, new_string);
			free_argv_splited(new_string);
			i++;
		}
	}
	start_algo(merged_string);
}
