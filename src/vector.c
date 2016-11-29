/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhismans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 19:28:48 by hhismans          #+#    #+#             */
/*   Updated: 2016/11/29 03:48:27 by hhismans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"


float			dist(const t_vector *a, const t_vector *b)
{
	float ret;

	ret = (a->x - b->x) * (a->x - b->x)
		+ (a->y - b->y) * (a->y - b->y)
		+ (a->z - b->z) * (a->z - b->z);
	return (ret);
}

t_vector		*addv(t_vector *a, const t_vector *b)
{
	a->x += b->x;
	a->y += b->y;
	a->z += b->z;
	return (a);
}

t_vector		*subv(t_vector *a, const t_vector *b)
{
	a->x -= b->x;
	a->y -= b->y;
	a->z -= b->z;
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
	ret = new_vector(a->y * b->z - a->z * b->y,
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
	if (ret)
	{
		ret->x = x;
		ret->y = y;
		ret->z = z;
	}
	return (ret);
}

t_vector		*set_vector(t_vector *v, float x, float y, float z)
{
	v->x = x;
	v->y = y;
	v->z = z;
	return (v);
}

t_vector		*cpy_vector(t_vector *dst, const t_vector *src)
{
	dst->x = src->x;
	dst->y = src->y;
	dst->z = src->z;
	return (dst);
}

float			norme(const t_vector *vct)
{
	return (sqrtf(squared(vct->x) + squared(vct->y) + squared(vct->z)));
}

t_vector		*normalize(t_vector *vct)
{
	float vct_norme;

	vct_norme = norme(vct);
	vct->x /= vct_norme;
	vct->y /= vct_norme;
	vct->z /= vct_norme;
	return (vct);
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

