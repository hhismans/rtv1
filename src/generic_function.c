/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generic_function.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhismans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 08:03:28 by hhismans          #+#    #+#             */
/*   Updated: 2016/12/08 19:24:14 by hhismans         ###   ########.fr       */
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
	int  i = 0;
	while (objs)
	{
		i++;
		set_ray(&ray, &vp_pos, e->cam->o);
		if (objs->type == SPHERE)
		{
			t_tmp = throw_ray_sphere(ray, (t_sphere *)(objs->obj));
			}
		if (objs->type == PLANE)
		{
			t_tmp = throw_ray_plane(ray, (t_plane *)(objs->obj));
		}
		if (t_tmp < t && t_tmp != NO_INTERSEC && t_tmp > 0)
		{
			object_hitted = objs;
			cpy_vector(&hitting_point, addv(&ray.o, multv(&ray.dir, t_tmp)));
			t = t_tmp;
		}
		objs = objs->next;
	}
	if (object_hitted)
	{
		if (x < WIDTH)
		{
			//printf("object_hitted color : %#08x\n", ((t_plane *)object_hitted->obj)->mat.diffuse_color);
			//printf("t = : %f\n", t);
		}
		//printf("coucou3 %d \n",((t_sphere *)object_hitted->obj)->color);
		//ici qui aura des truc cool !
		int ret;

		ret = light(object_hitted, e, &hitting_point, (x == WIDTH /2 && y == HEIGHT/2));

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

float	y_xsquared(float x)
{
	float ret;

	return (x);
	if ((ret = 1 / squared(x) > 1))
		return (1);
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

int		get_light_at(t_vector *normal, t_vector *hit_point, t_point_light *light, t_material *mat, int debug)
{
	(void)debug;
	t_vector	lightvector;
	float		angle;
	int			ret;
	float		dist_lh;

	dist_lh = dist_(hit_point, &light->pos);
	set_vector(&lightvector, hit_point->x - light->pos.x,
										hit_point->y - light->pos.y,
										hit_point->z - light->pos.z);
	normalize(&lightvector);
	angle = dot_product(&lightvector, normal);
	if (angle <= 0)
	{
		ret = BACKGROUND_COLOR;
		revertv(normal);
		angle = dot_product(&lightvector, normal);
	}
	else
	{
		ret = mult_color(light_filter(mat->diffuse_color, light->color), y_xsquared(dist_lh) * (sqrtf(angle)));
		/*if (mat->bright)
			ret = add_color(ret, mult_color(light->color, y_xsquared(dist_) * angle * angle *angle * angle * angle * angle * angle * angle * angle * angle));*/
	}
	return (ret);
}

float	dot_light(t_vector *normal, t_vector *hit_point, t_point_light *light)
{
	t_vector lightvector;
	set_vector(&lightvector, hit_point->x - light->pos.x,
										hit_point->y - light->pos.y,
										hit_point->z - light->pos.z);
	return (dot_product(normal, &lightvector));
}


int		light(t_obj_list *obj_hitted, t_env *e, t_vector *hit_point, int debug)
{
	t_obj_list	*objs;
	t_obj_list	*lights;
	int			ret_color;
	t_vector	normal_v;
	float t_tmp;
	float light_to_point_dist;

	t_material *mat;
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
				set_ray(&ray, hit_point, &((t_point_light *)(lights->obj))->pos);
				if (objs->type == SPHERE)
				{
					t_tmp = throw_ray_sphere(ray, (t_sphere *)(objs->obj));
				}
				if (objs->type == PLANE)
				{
					t_tmp = throw_ray_plane(ray, (t_plane *)(objs->obj));
				}
				if (objs->type == CONE)
				{
					t_tmp = throw_ray_plane(ray, (t_plane *)(objs->obj));
				}
				if (t_tmp < light_to_point_dist && t_tmp != NO_INTERSEC && t_tmp > 0)
					there_is_obstacle = 1;
					break;
			}
			objs = objs->next;
		}
		if (!there_is_obstacle)
		{
			set_ray(&ray, hit_point, &((t_point_light *)(lights->obj))->pos);
			if (obj_hitted->type == SPHERE)
			{
				cpy_vector(&normal_v, hit_point);
				subv(&normal_v, &((t_sphere *)(obj_hitted->obj))->c);
				mat = &((t_sphere*)obj_hitted->obj)->mat;
				revertv(&normal_v);
			}
			else if (obj_hitted->type == PLANE)
			{
				cpy_vector(&normal_v, &((t_plane *)(obj_hitted->obj))->normal);
				mat = &((t_plane*)obj_hitted->obj)->mat;
				if (dot_light(&normal_v,hit_point, (t_point_light *)(lights->obj)) < 0)
					revertv(&normal_v);
			}
			normalize(&normal_v);
			ret_color = add_color(ret_color, get_light_at(&normal_v,hit_point, (t_point_light *)(lights->obj), mat, debug));
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
