/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhismans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 16:28:52 by hhismans          #+#    #+#             */
/*   Updated: 2016/12/01 15:38:13 by hhismans         ###   ########.fr       */
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
		ret->mat.diffuse_color = data.color;
		ret->mat.bright = data.data[1];
	}
	return (ret);
}

void	stdout_sphere(t_sphere *sphere)
{
	printf("sphere centre : (%f, %f, %f)\n", sphere->c.x, sphere->c.y,sphere->c.z);
	printf("sphere radius: %f\n", sphere->r);
	printf("sphere color: %d\n", sphere->color);
	printf("\n");
}

float	throw_ray_sphere(const t_ray ray, const t_sphere *sphere)
{
	float a;
	float b;
	float c;
	float ret_t1;
	float ret_t2;
	float delta;

	a = squared(ray.dir.x) + squared(ray.dir.y) + squared(ray.dir.z);
	b = 2 * (ray.dir.x * (ray.o.x - sphere->c.x)
			+ ray.dir.y * (ray.o.y - sphere->c.y)
			+ ray.dir.z * (ray.o.z - sphere->c.z));
	c = squared(ray.o.x - sphere->c.x) + squared(ray.o.y - sphere->c.y) +
		squared(ray.o.z - sphere->c.z) - squared(sphere->r);

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

/*
float	throw_ray_plan(const t_ray ray, const t_plane *plane)
{
	float ret;

	ret = - (plane.
	return ();
}*/
