/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhismans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 23:50:21 by hhismans          #+#    #+#             */
/*   Updated: 2016/11/29 12:05:58 by hhismans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

# include <float.h>

# define CAMERA_POSX 0
# define CAMERA_POSY 0
# define CAMERA_POSZ -100

# define UNIT_UPX 0
# define UNIT_UPY 1
# define UNIT_UPZ 0

# define UNIT_RIGHTX 1
# define UNIT_RIGHTY 0
# define UNIT_RIGHTZ 0

# define VP_WIDTH 20
# define VP_HEIGHT 20
# define DEFAULT_VP_DIST 100

# define WIDTH 640
# define HEIGHT 640
# define BLUE 0xff
# define RED 0xff0000
# define BLACK 0
# define WHITE 0xffffff
# define BACKGROUND_COLOR 0

# define NO_INTERSEC FLT_MIN

enum
{
	SPHERE,
	POINT_LIGHT
};
#endif
