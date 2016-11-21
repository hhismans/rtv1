/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhismans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 16:17:49 by hhismans          #+#    #+#             */
/*   Updated: 2016/11/21 17:29:57 by hhismans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_H
# define RT_H

# include "mlx.h"
# include "libft.h"
# include <math.h>

typedef struct		s_vector
{
	float			x;
	float			y;
	float			z;
}					t_vector;

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
	t_vector		o;
	t_vector		vw_upleft;
	t_vector		dir;
	t_viewplave		vp;
}					t_camera;

typedef struct		s_env
{
	t_camera		cam;
}					t_camera;

typedef struct		s_sphere
{
	t_vector		c;
	float			r;
}					t_sphere;

typedef struct		s_plane
{
	t_vector		c;
	float			r;
}					t_plane;

typedef strut		s_obj;
{
	char	*type;
	void	*obj;
}					t_obj;
typedef struct		s_env
{
	t_camera		cam;
}					t_env;

int		expose(t_env *e);
int		mouse_hook(int keycode, int x, int y, t_env *e);
int		key_hook(int keycode, t_env *e);
#endif
