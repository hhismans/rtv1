/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhismans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 23:46:43 by hhismans          #+#    #+#             */
/*   Updated: 2016/11/26 06:54:27 by hhismans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_camera *cam_init(t_camera *cam)
{
	cam->o = new_vector(CAMERA_POSX, CAMERA_POSY, CAMERA_POSZ);
	cam->up_vunit = new_vector(UNIT_UPX, UNIT_UPY, UNIT_UPZ);
	cam->right_vunit = new_vector(UNIT_RIGHTX, UNIT_RIGHTY, UNIT_RIGHTZ);
	cam->dir = vectorial(cam->up_vunit, cam->right_vunit);
	cam->vp = new_vp(VP_WIDTH, VP_HEIGHT, DEFAULT_VP_DIST);
	//cam->vw_upleft = ;
	cam->xinc = cam->vp->width / WIDTH;
	cam->yinc = cam->vp->height / HEIGHT;
	return (cam);
}


t_viewplane		*new_vp(int width, int float, float dist)
{
	t_viewplane *ret;
	ret = (t_viewplane *)malloc(sizeof(t_viewplane));
	ret->width = width;
	ret->height = height;
	ret->dist = dist;
	return (ret);
}

t_vector	*get_viewplane_upleft(t_camera *cam)
{
	t_vector *ret;

	ret = new_vector(0, 0, 0);
	addv(ret, cam->o);
	addv(ret, addv(multv(cam->dir, cam->vp.dist),
					multv(cam->up_vunit, cam->vp.height / 2.0f)));
	addv(ret, -multv(cam->right_vunit, cam->vp.width / 2.0f));
	return (ret);
}


