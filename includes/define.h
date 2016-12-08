/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhismans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 23:50:21 by hhismans          #+#    #+#             */
/*   Updated: 2016/12/08 21:24:08 by hhismans         ###   ########.fr       */
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

# define WIDTH 1000
# define HEIGHT 1000
# define BLUE 0xff
# define RED 0xff0000
# define BLACK 0
# define WHITE 0xffffff
# define BACKGROUND_COLOR 0

# define NO_INTERSEC -1

# define ROYAL_BLUE 0x4169E1
# define STEEL_BLUE 0x4882b4

# define DARK_SEA_GREEN 0x8fbc8f
# define FOREST_GREEN 0x228b22
# define GOLDEN 0xffd700
# define ORANGE_RED 0xff4500

# define KEY_DOWN 125
# define KEY_UP 126
enum
{
	SPHERE,
	POINT_LIGHT,
	PLANE,
	CONE
};
#endif
