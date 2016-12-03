/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhismans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 16:56:15 by hhismans          #+#    #+#             */
/*   Updated: 2016/12/03 18:07:07 by hhismans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "rt.h"

t_cone *new_cone(const t_data data)
{
	t_sphere *ret;

	if ((ret = (t_cone *)malloc(sizeof(t_cone))))
	{
		cpy_vector(&ret->c, &data.vector); // set center
		ret->angle = data.data[0];
		ret->mat.diffuse_color = data.color;
		ret->mat.bright = data.data[1];
	}
	return (ret);
}

float	throw_ray_cone(const t_ray ray, const t_cone *cone)
{
	float a;
	float b;
	float c;
	float ret_t1;
	float ret_t2;
	float delta;

	a = squared(ray.dir.x) + squared(ray.dir.y) - squared(ray.dir.z) * squared(tan(PI / 3));
	b = 2 * (ray.dir.x * (ray.o.x - sphere->c.x)
			+ ray.dir.y * (ray.o.y - sphere->c.y)
			- ray.dir.z * (ray.o.z - sphere->c.z) * squared(tan(PI/3)));
	c = squared(ray.o.x - sphere->c.x) + squared(ray.o.y - sphere->c.y) -
		squared(ray.o.z - sphere->c.z) * squared(tan(PI/3)) - squared(sphere->r);

	//printf("\ta = %f, b = %f, c = %f\n", a, b, c);
	delta = det(a,b,c);
	if (delta >= 0)
	{
		ret_t1 = (-b + sqrtf(delta)) / 2 * a;
		if (ret_t1 < 0) ret_t1 = NO_INTERSEC;
		ret_t2 = (-b - sqrtf(delta)) / 2 * a;
		if (ret_t2 < 0) ret_t2 = NO_INTERSEC;
		return ((ret_t1 < ret_t2) ? (ret_t1) : (ret_t2));
	}
	return (NO_INTERSEC);
}
