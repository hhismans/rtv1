/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhismans <hhismans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 09:26:30 by hhismans          #+#    #+#             */
/*   Updated: 2014/11/11 09:35:36 by hhismans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void		**ft_taballoc(size_t size)
{
	void	**tab;
	size_t	i;

	i = 0;
	tab = (void **)malloc(sizeof(void *) * (size + 1));
	while (i <= size)
	{
		tab[i] = NULL;
		i++;
	}
	return (tab);
}
