/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhismans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 23:46:43 by hhismans          #+#    #+#             */
/*   Updated: 2016/11/29 04:06:24 by hhismans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_vector	*get_viewplane_upleft(const t_camera *cam)
{
	t_vector *ret;
	t_vector tmp_up;
	t_vector tmp_dir;
	t_vector tmp_right;

	cpy_vector(&tmp_up, cam->up_vunit);
	cpy_vector(&tmp_dir, cam->dir);
	cpy_vector(&tmp_right, cam->right_vunit);
	ret = new_vector(0, 0, 0);
	addv(ret, cam->o);
	addv(ret, addv(multv(&tmp_dir, -cam->vp->dist),
					multv(&tmp_up, cam->vp->height / 2.0f)));
	subv(ret, multv(&tmp_right, cam->vp->width / 2.0f));
	return (ret);
}

t_camera *cam_init(t_camera *cam)
{
	cam->o = new_vector(CAMERA_POSX, CAMERA_POSY, CAMERA_POSZ);
	cam->up_vunit = new_vector(UNIT_UPX, UNIT_UPY, UNIT_UPZ);
	cam->right_vunit = new_vector(UNIT_RIGHTX, UNIT_RIGHTY, UNIT_RIGHTZ);
	cam->dir = vectorial(cam->up_vunit, cam->right_vunit);
	cam->vp = new_vp(VP_WIDTH, VP_HEIGHT, DEFAULT_VP_DIST);
	cam->vp_upleft = get_viewplane_upleft(cam);
	cam->xinc = cam->vp->width / WIDTH;
	cam->yinc = cam->vp->height / HEIGHT;
	return (cam);
}

t_viewplane		*new_vp(float width, float height, float dist)
{
	t_viewplane *ret;
	ret = (t_viewplane *)malloc(sizeof(t_viewplane));
	if (ret)
	{
		ret->width = width;
		ret->height = height;
		ret->dist = dist;
	}
	return (ret);
}
