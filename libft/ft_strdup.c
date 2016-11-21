/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhismans <hhismans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 15:59:30 by hhismans          #+#    #+#             */
/*   Updated: 2014/11/11 07:18:39 by hhismans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	int		len;
	int		i;
	char	*cpy;

	i = 0;
	len = ft_strlen((char*)s1) + 1;
	cpy = (char*)malloc(sizeof(char) * len);
	while (i < len)
	{
		cpy[i] = s1[i];
		i++;
	}
	return (cpy);
}
