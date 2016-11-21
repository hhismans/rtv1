/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhismans <hhismans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 22:14:50 by hhismans          #+#    #+#             */
/*   Updated: 2014/11/08 17:27:02 by hhismans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*cpy;
	size_t	i;

	if (!s || !f)
		return (NULL);
	i = 0;
	cpy = ft_strnew(ft_strlen(s) + 1);
	while (s[i])
	{
		cpy[i] = (*f)(s[i]);
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}
