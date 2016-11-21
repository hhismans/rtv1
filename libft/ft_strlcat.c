/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhismans <hhismans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 18:39:12 by hhismans          #+#    #+#             */
/*   Updated: 2014/11/10 03:33:55 by hhismans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *s1, const char *s2, size_t n)
{
	size_t	len1;
	size_t	len2;
	int		i;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (n <= len1)
		return (n + len2);
	if (n > len1 + len2)
	{
		ft_memcpy(s1 + len1, s2, len2);
		i = len1 + len2;
	}
	else
	{
		ft_memcpy(s1 + len1, s2, n - len1 - 1);
		i = n - 1;
	}
	s1[i] = '\0';
	return (len1 + len2);
}
