/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhismans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 16:37:06 by hhismans          #+#    #+#             */
/*   Updated: 2016/12/01 14:31:04 by hhismans         ###   ########.fr       */
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
	mlx_key_hook(e->win, key_hook, e);
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
// changer
	data.type = SPHERE;
	data.color =  0x41698B;
	data.data[0] = 4;
	data.data[1] = 1;
	set_vector(&data.vector, 0,0,10);
	e->objs = new_obj(data);

	data.color = 0xffffff;
	data.data[0] = 0.5;
	data.data[1] = 1;
	set_vector(&data.vector, 6,6,-2);
	pushback_obj(e->objs, data);

/*	data.color = 0x41698B;
	data.data[1] = 1;
	set_vector(&data.vector, 0,4,10);
	pushback_obj(e->objs, data);

	data.color = 0x10f08a;
	data.data[1] = 0;
	set_vector(&data.vector, 0,-4,10);
	pushback_obj(e->objs, data);

	data.color = 0xffff00;
	data.data[1] = 0;
	set_vector(&data.vector, -4,0,10);
	pushback_obj(e->objs, data);*/

/*	data.color = 0xffffff;//1493;
	data.data[0] = 0.5;
	data.data[0] = 1;
	data.type = SPHERE;
	set_vector(&data.vector, 5,5,0);
	pushback_obj(e->objs, data);*/

	/*data.type = SPHERE;
	data.color = 0x00ff00;
	data.data[0] = 3;
	set_vector(&data.vector, 3,0,8);
	pushback_obj(e->objs, data);

	data.color = 0xffff00;
	set_vector(&data.vector, 0,3,8);
	pushback_obj(e->objs, data);

	data.color = 0x00868b;
	set_vector(&data.vector, 0,-3,8);
	pushback_obj(e->objs, data);*/

	data.type = POINT_LIGHT;
	data.color = 0xffffff;
	set_vector(&data.vector, 10,10,-10);
	e->lights = new_obj(data);
	//set_vector(&data.vector, -10,-10,10);
	//pushback_obj(e->lights,data);
	//data.color = 0xff;
	//set_vector(&data.vector, 0,0,-10);
	//pushback_obj(e->lights,data);
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
