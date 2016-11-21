/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhismans <hhismans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/13 22:25:28 by hhismans          #+#    #+#             */
/*   Updated: 2014/12/30 18:20:54 by hhismans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strndup(const char *s1, size_t n)
{
	size_t		len;
	size_t		i;
	char		*cpy;

	i = 0;
	len = ft_strlen((char*)s1);
	if (len <= n)
		cpy = ft_strnew(len);
	else
		cpy = ft_strnew(n);
	while (i < len && i < n)
	{
		cpy[i] = s1[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}
