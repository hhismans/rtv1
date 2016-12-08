/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhismans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 16:17:49 by hhismans          #+#    #+#             */
/*   Updated: 2016/12/08 16:55:59 by hhismans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_H
# define RT_H

# include "mlx.h"
# include "libft.h"
# include "define.h"

# include <stdlib.h>
# include <math.h>
# include <stdio.h>
# include <float.h>
# include <unistd.h>

typedef struct		s_vector
{
	float			x;
	float			y;
	float			z;
}					t_vector;

typedef struct		s_material
{
	int				diffuse_color;
	int				bright;
}					t_material;

typedef struct		s_ray
{
	t_vector		o;
	t_vector		dir;
}					t_ray;

typedef struct		s_viewplane
{
	float			width;
	float			height;
	float			dist;
}					t_viewplane;

typedef struct		s_camera
{
	t_vector		*o;
	t_vector		*vp_upleft;
	t_vector		*dir;
	t_vector		*up_vunit;
	t_vector		*right_vunit;
	t_viewplane		*vp;
	float			xinc;
	float			yinc;
}					t_camera;

typedef struct		s_plane
{
	t_vector		normal;
	float			d;
	t_material		mat;
}					t_plane;

typedef struct		s_sphere
{
	t_vector		c;
	t_material		mat;
	float			r;
	int				color;
}					t_sphere;

typedef struct		s_cone
{
	t_vector		c;
	t_material		mat;
	float			angle;
	int				color;
}					t_cone;

typedef struct			s_obj_list
{
	int					type;
	void				*obj;
	struct s_obj_list	*next;
}						t_obj_list;

typedef struct		s_env
{
	t_obj_list		*objs;
	t_obj_list		*lights;
	void			*mlx;
	void			*win;
	void			*img;
	t_camera		*cam;
	void			(*expose_function)();
	int				(*get_pixel_color)();
}					t_env;

typedef struct		s_data
{
	t_vector	vector;
	float		data[2];
	int			color;
	int			type;
}					t_data;


typedef struct		s_point_light
{
	t_vector	pos;
	int color;
}					t_point_light;


t_sphere		*new_sphere(const t_data data);
t_plane			*new_plane(const t_data data);

t_cone *new_cone(const t_data data);

t_obj_list		*new_obj(t_data data);
t_obj_list		*pushback_obj(t_obj_list *list, t_data data);

int				expose(t_env *e);
int				mouse_hook(int keycode, int x, int y, t_env *e);
int				expose(t_env *e);
int				key_hook(int keycode, t_env *e);
int				colortest(int x, int y, t_env *e);
void			mlx_pixel_put_img(void *img_ptr, int x, int y, int color);
void			display(t_env *e);

t_camera		*cam_init(t_camera *cam);
t_vector		*set_vector(t_vector *v, float x, float y, float z);
t_vector		*new_vector(float x, float y, float z);
t_vector		*multv(t_vector *a, const float operand);
t_vector		*vectorial(const t_vector *a, const t_vector *b);
t_vector		*scalar(t_vector *a, const t_vector *b);
t_vector		*addv(t_vector *a, const t_vector *b);
float			dist(const t_vector *a, const t_vector *b);
t_vector		*normalize(t_vector *vct);
float			norme(const t_vector *vct);
float			dot_product(const t_vector *a, const t_vector *b);
t_vector *revertv(t_vector *vct);

float			throw_ray_sphere(const t_ray ray, const t_sphere *sphere);
float			throw_ray_plane(const t_ray ray, const t_plane *plane);
float			throw_ray_cone(const t_ray ray, const t_sphere *sphere);

t_vector		*cpy_vector(t_vector *dst, const t_vector *src);

t_viewplane		*new_vp(float width, float height, float dist);
t_vector		*get_viewplane_upleft(const t_camera *cam);
t_vector		*subv(t_vector *a, const t_vector *b);


float	det(float a, float b, float c);
float	squared(float nb);
int		get_color(int x, int y, t_env *e);
//typedef void * (*new_obj_fct)(t_data);

//ray
void	set_ray(t_ray *ray, t_vector *dest, t_vector *origine);
void	set_ray_parallele(t_ray *ray, t_vector *dest);

int		get_light_at(t_vector *normal, t_vector *hit_point, t_point_light *light, t_material *mat, int debug);
int		light(t_obj_list *obj_hitted, t_env *e, t_vector *hit_point, int debug);

t_point_light *new_light(t_data data);


#endif
