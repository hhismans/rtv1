/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhismans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 16:28:52 by hhismans          #+#    #+#             */
/*   Updated: 2016/11/28 06:07:58 by hhismans         ###   ########.fr       */
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

void	set_ray(t_ray *ray, t_vector *dest, t_vector *origine)
{
	ray->dir.x = dest->x - origine->x;
	ray->dir.y = dest->y - origine->y;
	ray->dir.z = dest->z - origine->z;
	cpy_vector(&ray->o, origine);
}

int		get_color(int x, int y, t_env *e)
{
	t_vector		vp_pos;
	t_obj_list		*objs;
	float			t;
	float			t_tmp;
	t_obj_list		*object_hitted;
	t_ray			ray;

	objs = e->objs;
	set_vector(&vp_pos, e->cam->vp_upleft->x + x * e->cam->xinc,
			e->cam->vp_upleft->y + y * e->cam->yinc,
			e->cam->vp_upleft->z);
	set_ray(&ray, &vp_pos, e->cam->o);
	t = FLT_MAX;
	while (objs)
	{
		if (objs->type == SPHERE)
			t_tmp = throw_ray_sphere(ray, (t_sphere *)(objs->obj));
		if (t_tmp <= t)
			object_hitted = objs->obj;
		objs = objs->next;
	}
	return (((t_sphere *)object_hitted->obj)->color);
}


float	det(float a, float b, float c)
{
	return (b * b - 4 * a * c);
}

float	squared(float nb)
{
	return (nb * nb);
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

	delta = det(a,b,c);
	if (det >= 0)
	{
		ret_t1 = (-b + sqrtf(delta)) / 2 * a;
		if (ret_t1 < 0) ret_t1 = FLT_MAX;
		ret_t2 = (-b - sqrtf(delta)) / 2 * a;
		if (ret_t2 < 0) ret_t2 = FLT_MAX;
		return ((ret_t1 < ret_t2) ? (ret_t1) : (ret_t2));
	}
	return (-1);
}
