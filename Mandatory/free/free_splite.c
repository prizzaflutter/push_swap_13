/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_splite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaskour <iaskour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 15:22:13 by iaskour           #+#    #+#             */
/*   Updated: 2025/02/11 15:23:23 by iaskour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	free_argv_splited(char **argv_splited)
{
	int	i;

	i = 0;
	while (argv_splited[i])
	{
		free(argv_splited[i]);
		i++;
	}
	free(argv_splited);
}
