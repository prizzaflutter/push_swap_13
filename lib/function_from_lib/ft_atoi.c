/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaskour <iaskour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 10:38:48 by iaskour           #+#    #+#             */
/*   Updated: 2025/02/03 15:26:35 by iaskour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Mandatory/push_swap.h"
#include <stdio.h>

long	ft_atoi(const char *str)
{
	long	num;
	long	holder;
	long	muns;

	holder = 0;
	while (*str != '\0' && ((*str >= 9 && *str <= 13) || (*str == 32)))
		str++;
	muns = 1;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			muns = -1;
		str++;
	}
	num = 0;
	while (ft_isdigit(*str))
	{
		num = num * 10 + (*str - '0');
		if (num < holder)
			return (-(muns + 1) / 2);
		holder = num;
		str++;
	}
	return (num * muns);
}
