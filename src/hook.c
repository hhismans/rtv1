/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhismans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 16:06:14 by hhismans          #+#    #+#             */
/*   Updated: 2016/12/08 16:13:03 by hhismans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int		expose(t_env *e)
{
	e->expose_function(e);
	return (0);
}

void	display(t_env *e)
{
	int i;
	int j;

	i = 0;
	while (i < WIDTH)
	{
		j = 0;
		while (j < HEIGHT)
		{
			mlx_pixel_put_img(e->img, i, j, e->get_pixel_color(i, j, e));
			j++;
		}
		i++;
	}
	printf("done\n");
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
}


int			key_hook(int keycode, t_env *e)
{
	if (keycode == 53)
	{
		mlx_destroy_image(e->mlx, e->img);
		mlx_destroy_window(e->mlx, e->win);
		exit(0);
	}
	if (keycode == KEY_DOWN)
	{
		((t_point_light *)e->lights->obj)->pos.y-=1;
		printf("keydown %f\n",((t_point_light *)e->lights->obj)->pos.y);
		((t_point_light *)e->lights->obj)->pos.x-=1;
	//	((t_point_light *)e->lights->obj)->pos.z-=0.1;
		//((t_sphere *)e->objs->obj)->c.y+=1;
	}
	if (keycode == KEY_UP)
	{
		//((t_sphere *)e->objs->obj)->c.y-=1;
		((t_point_light *)e->lights->obj)->pos.y+=1;
		((t_point_light *)e->lights->obj)->pos.x+=1;
	//	((t_point_light *)e->lights->obj)->pos.z+=0.1;
	}
	printf("keycode %d\n", keycode);
	expose(e);
	return (0);
}
