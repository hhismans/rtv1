/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhismans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 16:17:49 by hhismans          #+#    #+#             */
/*   Updated: 2016/11/26 00:47:05 by hhismans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_H
# define RT_H

# include "mlx.h"
# include "libft.h"
# include "define.h"
# include <math.h>

# define WIDTH 640
# define HEIGHT 480
# define BLUE 0xff

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
	t_vector		*o;
	t_vector		*vw_upleft;
	t_vector		*dir;
	t_vector		*up_vunit;
	t_vector		*right_vunit;
	t_viewplane		*vp;
	float			xinc;
	float			yinc;
}					t_camera;

typedef struct		s_sphere
{
	t_vector		c;
	float			r;
	int				color;
}					t_sphere;

typedef struct		s_plane
{
	t_vector		c;
	float			r;
}					t_plane;

typedef struct		s_obj
{
	char	*type;
	void	*obj;
}					t_obj;

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	void			*img;
	t_camera		cam;
	void			(*expose_function)();
	int				(*get_pixel_color)();
}					t_env;

int		expose(t_env *e);
int		mouse_hook(int keycode, int x, int y, t_env *e);
int		expose(t_env *e);
int		key_hook(int keycode, t_env *e);
int		colortest(int x, int y, t_env *e);
void	mlx_pixel_put_img(void *img_ptr, int x, int y, int color);
void	display(t_env *e);
#endif
