/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhismans <hhismans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 17:30:22 by hhismans          #+#    #+#             */
/*   Updated: 2014/11/08 17:23:25 by hhismans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int		absolute_value(int n)
{
	unsigned int n_absolute;

	if (n < 0)
		n_absolute = -n;
	else
		n_absolute = n;
	return (n_absolute);
}

static size_t			size_of_int(int n)
{
	size_t			size;
	unsigned int	n_pos;

	size = 1;
	if (n < 0)
		size++;
	n_pos = absolute_value(n);
	while (n_pos >= 10)
	{
		n_pos = n_pos / 10;
		size++;
	}
	return (size);
}

static size_t			power_10(size_t n)
{
	size_t i;
	size_t rslt;

	i = 0;
	rslt = 1;
	while (i < n)
	{
		rslt *= 10;
		i++;
	}
	return (rslt);
}

static void				fill_cpy(char *cpy, size_t n, size_t size,
		size_t size_2)
{
	size_t i;

	i = 0;
	if (cpy[0] == '-')
		i++;
	while (i < size_2)
	{
		cpy[i] = ((n / power_10(size - i)) % 10 + '0');
		if (size + 2 == size_2 && i == size_2 - 2)
			return ;
		i++;
	}
}

char					*ft_itoa(int n)
{
	char	*cpy;
	size_t	size;
	size_t	size_2;
	size_t	n_pos;

	size = size_of_int(n);
	size_2 = size;
	cpy = ft_strnew(size);
	if (n < 0)
	{
		cpy[0] = '-';
		size_2++;
	}
	n_pos = absolute_value(n);
	size--;
	fill_cpy(cpy, n_pos, size, size_2);
	return (cpy);
}
