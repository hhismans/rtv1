/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhismans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 16:37:06 by hhismans          #+#    #+#             */
/*   Updated: 2016/11/21 17:30:00 by hhismans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"


int		init_mlx(t_env *e)
{
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, WIDTH, HEIGHT, "RTv1 by hhismans");
	e->img = mlx_new_image(e->mlx, WIDTH, HEIGHT);
	mlx_key_hook(e->win, key_hook, e);
	mlx_mouse_hook(e->win, mouse_hook, e);
	mlx_expose_hook(e->win, expose, e);
	//mlx_hook(e->win, MOTION_NOTIFY, PTR_MOTION_MASK, motion_hook, e);
	mlx_loop(e->mlx);
	return (0);
}

void	init_env(t_env *e)
{

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
int main()
{

	return (0);
}
