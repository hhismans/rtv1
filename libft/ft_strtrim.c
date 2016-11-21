/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhismans <hhismans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 23:28:48 by hhismans          #+#    #+#             */
/*   Updated: 2014/11/10 22:59:14 by hhismans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			ft_isvoid(char c)
{
	if (c == ' ' || c == '\t' || c == '\n')
		return (1);
	else
		return (0);
}

static size_t		find_end(char const *s)
{
	size_t end;

	end = 0;
	if (ft_strlen(s) != 0)
		end = ft_strlen(s);
	while (end != 0)
	{
		if (!ft_isvoid(s[end - 1]))
			break ;
		end--;
	}
	return (end);
}

char				*ft_strtrim(char const *s)
{
	size_t	start;
	size_t	end;
	size_t	i;
	char	*cpy;

	if (!s)
		return (NULL);
	start = 0;
	i = 0;
	while (ft_isvoid(s[start]))
		start++;
	end = find_end(s);
	if (start > end)
		return (cpy = ft_memalloc(1));
	cpy = ft_strnew(end - start);
	while (start + i < end)
	{
		cpy[i] = s[start + i];
		i++;
	}
	return (cpy);
}
