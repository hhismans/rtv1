/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_absval.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhismans <hhismans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 09:15:46 by hhismans          #+#    #+#             */
/*   Updated: 2016/11/14 14:06:42 by hhismans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_dabs(double n)
{
	double n_absolute;

	if (n < 0)
		n_absolute = -n;
	else
		n_absolute = n;
	return (n_absolute);
}
