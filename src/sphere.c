/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhismans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 16:28:52 by hhismans          #+#    #+#             */
/*   Updated: 2016/11/29 06:23:37 by hhismans         ###   ########.fr       */
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
	normalize(&ray->dir);
	cpy_vector(&ray->o, origine);
}

void	set_ray_parallele(t_ray *ray, t_vector *dest)
{
	set_vector(&ray->dir, 0, 0, 1);
	cpy_vector(&ray->o, dest);
}

void	stdout_sphere(t_sphere *sphere)
{
	printf("sphere centre : (%f, %f, %f)\n", sphere->c.x, sphere->c.y,sphere->c.z);
	printf("sphere radius: %f\n", sphere->r);
	printf("sphere color: %d\n", sphere->color);
	printf("\n");
}

int		get_color(int x, int y, t_env *e) // ca segfault ici
{
	t_vector		vp_pos;
	t_obj_list		*objs;
	float			t;
	float			t_tmp;
	t_obj_list		*object_hitted;
	t_ray			ray;

	objs = e->objs;
	set_vector(&vp_pos, e->cam->vp_upleft->x + x * e->cam->xinc,
			e->cam->vp_upleft->y - y * e->cam->yinc,
			e->cam->vp_upleft->z);
	//set_ray(&ray, &vp_pos, e->cam->o);
	set_ray_parallele(&ray, &vp_pos);
	//printf("ray (%f %f %f)\n", ray.dir.x,ray.dir.y, ray.dir.z);
	//printf("vp_ul (%f %f %f)\n", e->cam->vp_upleft->x,e->cam->vp_upleft->y, e->cam->vp_upleft->z);
	t = FLT_MAX;
	object_hitted = NULL;
	while (objs)
	{
		if (objs->type == SPHERE)
		{
			t_tmp = throw_ray_sphere(ray, (t_sphere *)(objs->obj));
			//stdout_sphere((t_sphere *)(objs->obj));
			//printf("t_tmp %f!\n", t_tmp);
		}
/*		if (objs->type == PLAN)
		{
			t_tmp = throw_ray_sphere(ray, (t_sphere *)(objs->obj));
		}*/
		if (t_tmp <= t && t_tmp > 0)
		{
			object_hitted = objs;
			t = t_tmp;
		}
		objs = objs->next;
	}
	if (object_hitted)
	{
		//printf("coucou3 %d \n",((t_sphere *)object_hitted->obj)->color);
		return (((t_sphere *)object_hitted->obj)->color);
	}
	return (BLACK);
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

	//printf("\ta = %f, b = %f, c = %f\n", a, b, c);
	delta = det(a,b,c);
	if (delta >= 0)
	{
		ret_t1 = (-b + sqrtf(delta)) / 2 * a;
		if (ret_t1 < 0) ret_t1 = FLT_MAX;
		ret_t2 = (-b - sqrtf(delta)) / 2 * a;
		if (ret_t2 < 0) ret_t2 = FLT_MAX;
		return ((ret_t1 < ret_t2) ? (ret_t1) : (ret_t2));
	}
	return (-1);
}

/*
float	throw_ray_plan(const t_ray ray, const t_plane *plane)
{
	float ret;

	ret = - (plane.
	return ();
}*/
