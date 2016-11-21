/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhismans <hhismans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 19:47:47 by hhismans          #+#    #+#             */
/*   Updated: 2014/11/10 23:01:13 by hhismans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t i;

	i = ft_strlen(s);
	if (c == 256)
		c = 0;
	while (i != 0)
	{
		if (c == (int)*((unsigned char *)(s + i)))
			return ((char *)s + i);
		i--;
	}
	if (s[0] == c)
		return ((char *)s);
	return (NULL);
}
