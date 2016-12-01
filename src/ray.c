/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhismans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 08:30:51 by hhismans          #+#    #+#             */
/*   Updated: 2016/12/01 11:37:47 by hhismans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	set_ray(t_ray *ray, t_vector *dest, t_vector *origine)
{
	ray->dir.x = dest->x - origine->x;
	ray->dir.y = dest->y - origine->y;
	ray->dir.z = dest->z - origine->z;
	normalize(&ray->dir);
	cpy_vector(&ray->o, origine);
}

void	set_ray_parallele(t_ray *ray, t_vector *dest)
{
	set_vector(&ray->dir, 0, 0, 1);
	cpy_vector(&ray->o, dest);
}
