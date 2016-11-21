/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhismans <hhismans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 18:39:05 by hhismans          #+#    #+#             */
/*   Updated: 2014/11/10 22:51:19 by hhismans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t					i;
	char unsigned			*dst_temp;
	const char	unsigned	*src_temp;

	dst_temp = (char unsigned *)dst;
	src_temp = (const char unsigned *)src;
	i = 0;
	while (i < n)
	{
		*dst_temp++ = src_temp[i];
		if (src_temp[i] == (unsigned char)c)
			return (dst_temp);
		i++;
	}
	return (NULL);
}
