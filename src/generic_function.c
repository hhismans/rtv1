/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generic_function.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhismans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 08:03:28 by hhismans          #+#    #+#             */
/*   Updated: 2016/12/01 16:15:13 by hhismans         ###   ########.fr       */
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
	object_hitted = NULL;
	t = FLT_MAX;
	while (objs)
	{
		set_ray(&ray, &vp_pos, e->cam->o);
		if (objs->type == SPHERE)
			t_tmp = throw_ray_sphere(ray, (t_sphere *)(objs->obj));
/*		if (objs->type == PLAN)
		{
			t_tmp = throw_ray_sphere(ray, (t_sphere *)(objs->obj));
		}*/
		if (t_tmp < t && t_tmp != NO_INTERSEC)
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
		if (x == WIDTH / 2 + 10 && y == HEIGHT / 2)
			printf("color : %d\n", ((t_sphere *)object_hitted->obj)->mat.bright);

		ret = light(object_hitted, e, &hitting_point);

		return (ret);//((t_sphere *)object_hitted->obj)->color);
	}
	return (BLACK);
}

int		mult_color(int color, float mult)
{
	int r;
	int g;
	int b;

	r = ((color & 0xff0000) >> 16) * mult;
	g = ((color & 0xff00) >> 8) * mult;
	b = ((color & 0xff)) * mult;
	return ((r << 16) + (g << 8) + b);
}

int		light_filter(int color, int light)
{
	int r;
	int g;
	int b;

	r = ((color & 0xff0000) >> 16) * ((float)((light & 0xff0000) >> 16) / 255);
	g = ((color & 0xff00) >> 8) * ((float)((light & 0xff00) >> 8) / 255);
	b = ((color & 0xff)) * ((float)((light & 0xff)) / 255);
//sweet
	return ((r << 16) + (g << 8) + b);
}

int		add_color(int color1, int color2)
{
	int r;
	int v;
	int b;

	r = ((0xff0000 & color1) >> 16)  + ((0xff0000 & color2) >> 16);
	v = ((0xff00 & color1) >> 8)  + ((0xff00 & color2) >> 8);
	b = (0xff & color1) + (0xff & color2);
	r = r > 0xff ? 0xff : r;
	v = v > 0xff ? 0xff : v;
	b = b > 0xff ? 0xff : b;
	return ((r << 16) + (v << 8) + b);
}

int		get_light_at(t_vector *normal, t_vector *hit_point, t_point_light *light, t_material *mat)
{
	t_vector	lightvector;
	float		angle;
	int			ret;

	set_vector(&lightvector, hit_point->x - light->pos.x,
										hit_point->y - light->pos.y,
										hit_point->z - light->pos.z);
	normalize(&lightvector);
	angle = dot_product(&lightvector, normal);
	if (angle <= 0)
	{
		ret = BACKGROUND_COLOR;
	}
	else
	{
		ret = mult_color(light_filter(mat->diffuse_color, light->color), angle);
		if (mat->bright)
			ret = add_color(ret, mult_color(light->color, angle * angle *angle * angle * angle * angle * angle * angle * angle * angle));
	}
	return (ret);
}

float	dist_(t_vector *a, t_vector *b)
{
	t_vector v;

	v.x = a->x - b->x;
	v.y = a->y - b->y;
	v.z = a->z - b->z;
	return(norme(&v));
}



int		light(t_obj_list *obj_hitted, t_env *e, t_vector *hit_point)
{
	t_obj_list	*objs;
	t_obj_list	*lights;
	int			ret_color;
	t_vector	normal_v;
	float t_tmp;
	float light_to_point_dist;

	int			there_is_obstacle;
	lights = e->lights;
	t_ray ray;

	ret_color = BACKGROUND_COLOR;

	while (lights)
	{
		light_to_point_dist = dist_(&((t_point_light *)(lights->obj))->pos, hit_point);
	//	printf("ltop %f \n", light_to_point_dist);
		t_tmp = FLT_MAX;
		there_is_obstacle = 0;
		objs = e->objs;
		while (objs)
		{
			if (objs != obj_hitted)
			{
				if (objs->type == SPHERE)
				{
					set_ray(&ray, hit_point, &((t_point_light *)(lights->obj))->pos);
					/*cpy_vector(&normal_v, hit_point);
					subv(&normal_v, &((t_sphere *)(objs->obj))->c);
					normalize(&normal_v);
					revertv(&normal_v);*/
					t_tmp = throw_ray_sphere(ray, (t_sphere *)(objs->obj));
	//					printf("ttmp %f \n", t_tmp);
					if (t_tmp < light_to_point_dist && t_tmp != NO_INTERSEC)
						there_is_obstacle = 1;
						break;
				}
			}
			objs = objs->next;
		}
		if (!there_is_obstacle)
		{
			set_ray(&ray, hit_point, &((t_point_light *)(lights->obj))->pos);
			cpy_vector(&normal_v, hit_point);
			subv(&normal_v, &((t_sphere *)(obj_hitted->obj))->c);
			normalize(&normal_v);
			revertv(&normal_v);
			ret_color = add_color(ret_color, get_light_at(&normal_v,hit_point, (t_point_light *)(lights->obj), &((t_sphere*)obj_hitted->obj)->mat));
		}
		lights = lights->next;
	}
	/*			set_ray(&ray, hit_point, &((t_point_light *)(lights->obj))->pos);
					cpy_vector(&normal_v, hit_point);
					subv(&normal_v, &((t_sphere *)(objs->obj))->c);
					normalize(&normal_v);
						ret_color += get_light_at(&normal_v,hit_point, (t_point_light *)(lights->obj), &mat);*/

	return (ret_color);
}
