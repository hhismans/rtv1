/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhismans <hhismans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 01:43:22 by hhismans          #+#    #+#             */
/*   Updated: 2015/03/16 17:07:37 by hhismans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*tmp;

	tmp = (t_list *)malloc(sizeof(t_list));
	if (tmp)
	{
		tmp->content = ft_memalloc(content_size);
		if (tmp->content && content != NULL)
		{
			ft_memcpy(tmp->content, content, content_size);
			tmp->content_size = content_size;
		}
		else
		{
			free(tmp->content);
			tmp->content = NULL;
			tmp->content_size = 0;
		}
		tmp->next = NULL;
	}
	else
		tmp = NULL;
	return (tmp);
}
