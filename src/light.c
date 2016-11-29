/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhismans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 12:07:22 by hhismans          #+#    #+#             */
/*   Updated: 2016/11/29 12:37:45 by hhismans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_point_light *new_light(t_data data)
{
	t_point_light *ret;

	if ((ret = (t_point_light*)malloc(sizeof(t_point_light))))
	{
		cpy_vector(&ret->pos, &data.vector); // set center
		ret->color = data.color;
	}
	return (ret);
}
