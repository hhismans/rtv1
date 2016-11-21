/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhismans <hhismans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 19:47:24 by hhismans          #+#    #+#             */
/*   Updated: 2014/11/11 09:49:04 by hhismans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	char	*ptr;
	size_t	i;

	i = 0;
	if (size == 0)
		return (NULL);
	ptr = (char *)malloc(sizeof(char) * size);
	if (!ptr)
		return (NULL);
	while (i < size)
	{
		ptr[i] = '\0';
		i++;
	}
	return ((void *)ptr);
}
