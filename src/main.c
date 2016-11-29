/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhismans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 16:37:06 by hhismans          #+#    #+#             */
/*   Updated: 2016/11/29 12:49:22 by hhismans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

/*
** salut c'est un com
**
*/
int		init_mlx(t_env *e)
{
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, WIDTH, HEIGHT, "RTv1 by hhismans");
	e->img = mlx_new_image(e->mlx, WIDTH, HEIGHT);
	if (!e->mlx || !e->win || !e->img)
	{
		printf("error mlx init\n");
		exit(0);
	}
	//mlx_key_hook(e->win, key_hook, e);
	//mlx_mouse_hook(e->win, mouse_hook, e);
	mlx_expose_hook(e->win, expose, e);
	//mlx_hook(e->win, MOTION_NOTIFY, PTR_MOTION_MASK, motion_hook, e);
	mlx_loop(e->mlx);
	return (0);
}

int colortest()
{
	return (BLUE);
}

void	init_env(t_env *e)
{
	e->get_pixel_color = get_color;
	e->expose_function = display; // rename cette fct display de mes couilles
	e->cam = (t_camera *)malloc(sizeof(t_camera)); // chelou aussi
	cam_init(e->cam);
// a changer
	t_data	data;
	data.color = BLUE;
	data.data[0] = 2;
	data.type = SPHERE;
	set_vector(&data.vector, 0,0,3);
// changer
	e->objs = new_obj(data);
/*	data.type = SPHERE;
	data.color = RED;
	data.data[0] = 2;
	set_vector(&data.vector, 0,2,3);
	pushback_obj(e->objs, data);

	data.type = SPHERE;
	data.color = 0x00ff00;
	data.data[0] = 2;
	set_vector(&data.vector, 2.5,4,3);
	pushback_obj(e->objs, data);*/

	data.type = POINT_LIGHT;
	data.color = WHITE;
	set_vector(&data.vector, 0,0,0);
	e->lights = new_obj(data);
}

void	mlx_pixel_put_img(void *img_ptr, int x, int y, int color)
{
	char	*data;
	int		bbp;
	int		sizeline;
	int		endian;
	int		i;

	data = mlx_get_data_addr(img_ptr, &bbp, &sizeline, &endian);
	bbp /= 8;
	i = x * bbp + y * sizeline;
	if (WIDTH * bbp + HEIGHT * sizeline < i)
		return ;
	if (x >= 0 && y >= 0)
	{
		data[i] = color;
		data[i + 1] = color >> 8;
		data[i + 2] = color >> 16;
	}
}
void debug_cam_info(t_camera *cam)
{
	printf("salut \n");
	printf("dist vp%f\n", cam->vp->dist);
	printf("upunit %f %f %f\n", cam->up_vunit->x, cam->up_vunit->y,cam->up_vunit->z);
	printf("rightunit %f %f %f\n", cam->right_vunit->x, cam->right_vunit->y,cam->right_vunit->z);
	printf("viewpointUL %f %f %f\n", cam->vp_upleft->x, cam->vp_upleft->y,cam->vp_upleft->z);
}

int main()
{
	t_env e;
	t_camera cam;

	init_env(&e);
	printf("list %d %f\n", e.objs->type, ((t_sphere *)e.objs->obj)->r);
	debug_cam_info(e.cam);
	cam_init(&cam);
	init_mlx(&e);
	return (0);
}
