/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhismans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 19:28:48 by hhismans          #+#    #+#             */
/*   Updated: 2016/11/26 00:11:30 by hhismans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_vector		*addv(t_vector *a, const t_vector *b)
{
	a->x += b->x;
	a->y += b->y;
	a->z += b->z;
	return (a);
}

t_vector		*scalar(t_vector *a, const t_vector *b)
{
	a->x += b->x;
	a->y += b->y;
	a->z += b->z;
	return (a);
}

t_vector		*vectorial(const t_vector *a, const t_vector *b)
{
	t_vector *ret;
	ret = new_vector(a->y * b->z - a.z * b.y,
						a->z * b->x - a->x * b->z,
						a->x * b->y - a->y * b->x);
	return (ret);
}

t_vector		*multv(t_vector *a, const float operand)
{
	a->x *= operand;
	a->y *= operand;
	a->z *= operand;
	return (a);
}

t_vector		*new_vector(float x, float y, float z)
{
	t_vector *ret;

	ret = (t_vector *)malloc(sizeof(t_vector));
	ret->x = x;
	ret->y = y;
	ret->z = z;
}

t_vector		*set_vector(t_vector *v, float x, float y, float z)
{
	v->x = x;
	v->y = y;
	v->z = z;
}

/*int main()
{
	t_camera *cam;
	t_vector a, b;
	cam = (t_camera *)malloc(sizeof(t_camera));
	cam->o.x = 0;
	cam->o.y = 0;
	cam->o.z = 0;
	b.x = 1;
	b.y = 2;
	b.z = 3;
	addv(&cam->o, &b);
	printf("%f\n", cam->o.x);
}*/

