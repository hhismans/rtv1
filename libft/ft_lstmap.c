/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhismans <hhismans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 00:21:19 by hhismans          #+#    #+#             */
/*   Updated: 2014/11/10 22:50:07 by hhismans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *tmp;
	t_list *tmp_2;

	tmp = NULL;
	tmp = (*f)(lst);
	tmp_2 = tmp;
	while (lst->next)
	{
		tmp->next = (*f)(lst->next);
		tmp = tmp->next;
		lst = lst->next;
	}
	return (tmp_2);
}
