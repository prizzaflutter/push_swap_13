/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaskour <iaskour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 20:48:47 by iaskour           #+#    #+#             */
/*   Updated: 2025/01/21 18:04:16 by iaskour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Mandatory/push_swap.h"

static int	count_lengh(int number)
{
	int	counter;

	counter = 0;
	if (number < 0)
	{
		number = -number;
		counter++;
	}
	if (number == 0)
		return (1);
	while (number != 0)
	{
		number /= 10;
		counter++;
	}
	return (counter);
}

char	*ft_itoa(int n)
{
	char			*str;
	unsigned int	number;
	size_t			length;

	number = n;
	if (n < 0)
		number = -n;
	length = count_lengh(n);
	str = (char *)malloc((length + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	str[length] = '\0';
	while (length > 0 && number != 0)
	{
		length--;
		str[length] = (number % 10) + 48;
		number /= 10;
	}
	if (n < 0)
		str[0] = '-';
	else if (n == 0)
		str[0] = '0';
	return (str);
}
