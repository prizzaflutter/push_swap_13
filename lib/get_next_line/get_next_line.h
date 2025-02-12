/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaskour <iaskour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 16:01:15 by iaskour           #+#    #+#             */
/*   Updated: 2025/02/12 11:07:07 by iaskour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <limits.h>
# include <unistd.h>
# include <stdlib.h>
# include "../../Mandatory/push_swap.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE	12
# endif 

char	*get_next_line(int fd);
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif 
