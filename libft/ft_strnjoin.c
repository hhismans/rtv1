/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhismans <hhismans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/13 23:14:59 by hhismans          #+#    #+#             */
/*   Updated: 2016/11/18 17:32:00 by hhismans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnjoin(char const *s1, char const *s2, size_t n)
{
	char	*cpy;
	int		i;

	if (!s1 || !s2)
		return (NULL);
	if ((ft_strlen(s1) < n))
		cpy = ft_strnew(ft_strlen(s1) + ft_strlen(s2) + 1);
	else
		cpy = ft_strnew(ft_strlen(s1) + n);
	i = 0;
	while (s1[i])
	{
		cpy[i] = s1[i];
		i++;
	}
	ft_strncat(cpy, s2, n);
	return (cpy);
}
