/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhismans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 03:44:33 by hhismans          #+#    #+#             */
/*   Updated: 2016/11/29 12:24:19 by hhismans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

/*
** ill use this list to store all object in the scene
** ill explore all this object and detect who is the nearest
*/

t_obj_list		*new_obj(t_data data)
{
	t_obj_list *ret;


	void * (*new_obj_tab[2])(t_data) = {
		(void *)new_sphere,
		(void *)new_light
	};
	if ((ret = (t_obj_list *)malloc(sizeof(t_obj_list))))
	{
		ret->type = data.type;
		ret->obj = new_obj_tab[data.type](data);
		ret->next = NULL;
	}
	return (ret);
}

t_obj_list		*pushback_obj(t_obj_list *list, t_data data)
{
	if (list)
	{
		while (list->next)
			list = list->next;
		list->next = new_obj(data);
	}
	else
	{
		return (new_obj(data));
	}
	return (list);
}
