/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhismans <hhismans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 18:51:02 by hhismans          #+#    #+#             */
/*   Updated: 2014/11/11 07:12:37 by hhismans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char			*dst_t;
	const char		*src_t;

	src_t = src;
	dst_t = dst;
	if (dst <= src)
		return (ft_memcpy(dst, src, len));
	src_t += len;
	dst_t += len;
	while (len)
	{
		dst_t--;
		src_t--;
		*dst_t = *src_t;
		len--;
	}
	return (dst);
}
