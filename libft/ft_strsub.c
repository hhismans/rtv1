/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhismans <hhismans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 22:58:55 by hhismans          #+#    #+#             */
/*   Updated: 2014/11/08 16:35:36 by hhismans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	int		i;
	char	*cpy;

	if (!s)
		return (NULL);
	i = 0;
	cpy = ft_strnew(len);
	if (!cpy)
		return (NULL);
	while (start + i < start + len)
	{
		cpy[i] = s[start + i];
		i++;
	}
	return (cpy);
}
