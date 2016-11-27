/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhismans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 16:28:52 by hhismans          #+#    #+#             */
/*   Updated: 2016/11/27 05:29:16 by hhismans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "rt.h"

t_sphere *new_sphere(const t_data data)
{
	t_sphere *ret;

	if ((ret = (t_sphere*)malloc(sizeof(t_sphere))))
	{
		cpy_vector(&ret->c, &data.vector); // set center
		ret->r = data.data[0];
		ret->color = data.color;
	}
	return (ret);
}
