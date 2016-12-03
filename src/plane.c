/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhismans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 10:45:51 by hhismans          #+#    #+#             */
/*   Updated: 2016/12/03 11:54:31 by hhismans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "rt.h"

t_plane *new_plane(const t_data data)
{
	t_plane *ret;

	if ((ret = (t_plane *)malloc(sizeof(t_plane))))
	{
		cpy_vector(&ret->normal, &data.vector);
		ret->d = data.data[0];
		ret->mat.diffuse_color = data.color;
		ret->mat.bright = data.data[1];
	}
	return (ret);
}

float	throw_ray_plane(const t_ray ray, const t_plane *plane)
{
	float ret;

	if (dot_product(&ray.dir, &plane->normal) == 0)
		return (NO_INTERSEC);
	ret = -(plane->normal.x * ray.o.x + plane->normal.y * ray.o.y +
			plane->normal.z * ray.o.z  + plane->d);
	ret /= (plane->normal.x * ray.dir.x + plane->normal.y * ray.dir.y +
			plane->normal.z * ray.dir.z);
	return (ret);
}

