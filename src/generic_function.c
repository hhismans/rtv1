/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generic_function.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhismans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 08:03:28 by hhismans          #+#    #+#             */
/*   Updated: 2016/11/29 12:55:41 by hhismans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int		get_color(int x, int y, t_env *e) // ca segfault ici
{
	t_vector		vp_pos;
	t_obj_list		*objs;
	float			t;
	float			t_tmp;
	t_obj_list		*object_hitted;
	t_ray			ray;
	t_vector		hitting_point;

	objs = e->objs;
	set_vector(&vp_pos, e->cam->vp_upleft->x + x * e->cam->xinc,
			e->cam->vp_upleft->y - y * e->cam->yinc,
			e->cam->vp_upleft->z);
	set_ray(&ray, &vp_pos, e->cam->o);
	//set_ray_parallele(&ray, &vp_pos);
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
			cpy_vector(&hitting_point, addv(&ray.o, multv(&ray.dir, t_tmp)));
			t = t_tmp;
		}
		objs = objs->next;
	}
	if (object_hitted)
	{
		//printf("coucou3 %d \n",((t_sphere *)object_hitted->obj)->color);
		//ici qui aura des truc cool !
		int ret;

		ret = light(object_hitted, e, &hitting_point);
		return (ret);//((t_sphere *)object_hitted->obj)->color);
	}
	return (BLACK);
}

int		get_light_at(t_vector *normal, t_vector *hit_point, t_point_light *light, t_material *mat)
{
	t_vector	lightvector;
	float		angle;
	int			ret;

	set_vector(&lightvector, hit_point->x - light->pos.x,
										hit_point->y - light->pos.y,
										hit_point->y - light->pos.y);
	normalize(&lightvector);
	angle = dot_product(normal, &lightvector);
	if (angle <= 0)
	{
		ret = BACKGROUND_COLOR;
	}
	else
	{
		ret = mat->diffuse_color * (1-angle);
		ret &= 0xff0000;
	}
	return (ret);
}

int		light(t_obj_list *obj_hitted, t_env *e, t_vector *hit_point)
{
	t_obj_list	*objs;
	t_obj_list	*lights;
	int			ret_color;
	t_vector	normal_v;
	t_material mat;
	float t_tmp;

	lights = e->lights;
	t_ray ray;
	mat.diffuse_color = RED;

	ret_color = BACKGROUND_COLOR;
	objs = e->objs;

	/*while (lights)
	{
		while (objs)
		{
			if (objs != obj_hitted)
			{
				if (objs->type == SPHERE)
				{
					set_ray(&ray, hit_point, &((t_point_light *)(lights->obj))->pos);
					cpy_vector(&normal_v, hit_point);
					subv(&normal_v, &((t_sphere *)(objs->obj))->c);
					normalize(&normal_v);
					t_tmp = throw_ray_sphere(ray, (t_sphere *)(objs->obj));
					if (t_tmp == NO_INTERSEC)
						ret_color += get_light_at(&normal_v,hit_point, (t_point_light *)(lights->obj), &mat);
				}
			}
			objs = objs->next;
		}
		lights = lights->next;
	}*/
				set_ray(&ray, hit_point, &((t_point_light *)(lights->obj))->pos);
					cpy_vector(&normal_v, hit_point);
					subv(&normal_v, &((t_sphere *)(objs->obj))->c);
					normalize(&normal_v);
						ret_color += get_light_at(&normal_v,hit_point, (t_point_light *)(lights->obj), &mat);

	return (ret_color);
}
