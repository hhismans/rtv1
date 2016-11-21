/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhismans <hhismans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 17:41:02 by hhismans          #+#    #+#             */
/*   Updated: 2014/12/30 19:24:02 by hhismans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

static int		str_process(char **line, char *str, int *first_p)
{
	if (ft_strchr(str, '\n'))
	{
		*line = ft_strndup(str, ft_strchri(str, '\n'));
		if (ft_strchr(ft_strchr(str, '\n'), '\n'))
			ft_strcpy(str, ft_strchr(str, '\n') + 1);
		else
			ft_bzero(str, BUFF_SIZE);
		return (1);
	}
	else
	{
		*line = ft_strdup(str);
		if (ft_strlen(str) != 0)
			*first_p = 3;
		ft_bzero(str, BUFF_SIZE);
		return (0);
	}
}

static int		fill_line(char **line, char *str, char *buf)
{
	char	*tmp;

	if (ft_strchr(buf, '\n'))
	{
		tmp = *line;
		*line = ft_strnjoin(*line, buf, ft_strchri(buf, '\n'));
		free(tmp);
		ft_strcpy(str, ft_strchr(buf, '\n') + 1);
		return (1);
	}
	else
	{
		tmp = *line;
		*line = ft_strjoin(*line, buf);
		free(tmp);
	}
	return (0);
}

static int		buf_process(int const fd, char **line, char *str, int *first_p)
{
	char	buf[BUFF_SIZE + 1];
	int		ret;

	ft_bzero(buf, BUFF_SIZE + 1);
	ft_bzero(str, BUFF_SIZE);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		if (fill_line(line, str, buf))
		{
			*first_p = 1;
			return (1);
		}
		*first_p = 3;
		ft_bzero(buf, BUFF_SIZE + 1);
	}
	if (*first_p == 3)
	{
		*first_p = 1;
		return (1);
	}
	if (ret == -1)
		return (ret);
	return (ret);
}

int				get_next_line(int const fd, char **line)
{
	static char	*str[256];
	static int	first_step[256] = {0};
	int			ret;

	if (BUFF_SIZE > 8000000)
		return (-1);
	if (first_step[fd] == 2)
	{
		*line = NULL;
		return (0);
	}
	if (!first_step[fd])
		(str)[fd] = (char *)ft_memalloc(BUFF_SIZE);
	first_step[fd] = 1;
	if ((ret = str_process(line, str[fd], &first_step[fd])))
		return (ret);
	if ((ret = buf_process(fd, line, str[fd], &first_step[fd])))
		return (ret);
	free(str[fd]);
	if (first_step[fd] != 2)
	{
		first_step[fd] = 2;
		return (0);
	}
	return (ret);
}
