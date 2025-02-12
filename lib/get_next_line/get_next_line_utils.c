/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaskour <iaskour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 16:00:01 by iaskour           #+#    #+#             */
/*   Updated: 2025/02/12 13:41:57 by iaskour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	size;
	unsigned int	lenght;
	char			*substr;
	size_t			i;

	if (s == NULL)
		return (NULL);
	size = (unsigned int) ft_strlen(s);
	lenght = (unsigned int) len;
	if (start > size || size == 0)
		return (ft_strdup(""));
	if (lenght > (size - start))
		lenght = (size - start);
	substr = (char *)malloc((lenght + 1) * sizeof(char));
	if (substr == NULL)
		return (NULL);
	i = 0;
	while (i < lenght)
	{
		substr[i] = s[start];
		i++;
		start++;
	}
	substr[i] = '\0';
	return (substr);
}
