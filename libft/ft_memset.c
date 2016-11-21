/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhismans <hhismans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 16:07:03 by hhismans          #+#    #+#             */
/*   Updated: 2014/11/04 17:55:30 by hhismans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t n)
{
	char	*b_temp;
	size_t	i;

	b_temp = b;
	i = 0;
	while (i < n)
	{
		b_temp[i] = c;
		i++;
	}
	return (b);
}
