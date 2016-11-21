/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhismans <hhismans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 01:14:52 by hhismans          #+#    #+#             */
/*   Updated: 2015/03/16 13:58:31 by hhismans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static	size_t		word_counter(char const *s, char c)
{
	size_t		i;
	size_t		nbr_word;

	nbr_word = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && s[i] != '\0')
			nbr_word++;
		if (s[i] != c)
		{
			while (s[i] != c && s[i] != '\0')
				i++;
		}
		else
			i++;
	}
	return (nbr_word);
}

static	size_t		size_next_word(char const *s, char c, size_t *index)
{
	size_t i;
	size_t nbr_char;

	i = 0;
	nbr_char = 0;
	while (s[*index + i] == c)
		i++;
	while (s[*index + i + nbr_char] && s[*index + i + nbr_char] != c)
		nbr_char++;
	*index = *index + i + nbr_char;
	return (nbr_char);
}

static	void		**taballoc(size_t size)
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

static void			fill_tab(char **words, const char *s, char c,
		size_t nbr_word)
{
	size_t i;
	size_t index;
	size_t size_word;
	size_t j;

	i = 0;
	index = 0;
	while (i < nbr_word)
	{
		size_word = size_next_word(s, c, &index);
		j = 0;
		while (j < size_word)
		{
			words[i][j] = s[index - size_word + j];
			j++;
		}
		words[i][j] = '\0';
		i++;
	}
}

char				**ft_strsplit(char const *s, char c)
{
	size_t	i;
	size_t	nbr_word;
	size_t	index;
	char	**words;

	if (!s)
		return (NULL);
	i = 0;
	index = 0;
	nbr_word = word_counter(s, c);
	if (!(words = (char **)taballoc(nbr_word)))
		return (NULL);
	while (i < nbr_word)
	{
		words[i] = ft_strnew(size_next_word(s, c, &index));
		if (!words[i])
			return (NULL);
		i++;
	}
	i = 0;
	index = 0;
	fill_tab(words, s, c, nbr_word);
	return (words);
}
