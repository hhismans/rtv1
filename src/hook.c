/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhismans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 16:06:14 by hhismans          #+#    #+#             */
/*   Updated: 2016/11/25 23:46:12 by hhismans         ###   ########.fr       */
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
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
}

/*t_vector	*get_viewplane_upleft(t_env *e)
{
	t_vector	*cam_pos;
	t_vector	*cam_dir;
	float		dist_cam_vp;
	t_viewplane	*vp;
	
	t_vector vp_upleft;

	cam_pos;
	v1 = multv(cam_dir * vp->dist);
	v2 = multv(e
}*/
