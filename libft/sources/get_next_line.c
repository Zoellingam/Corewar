/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez <igomez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2018/02/04 14:23:28 by igomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "ft_string.h"
#include <unistd.h>
#include <stdlib.h>

static int  ft_gnl_precheck(char *data, char **line)
{
	char        *cursor;

	cursor = ft_strchr(data, '\n');
	if (0 != cursor)
		*cursor++ = 0;
	*line = ft_strdup(data);
	if (0 != cursor)
	{
		ft_memmove(data, cursor, ft_strlen(cursor) + 1);
		return (1);
	}
	ft_memset(data, 0, BUFF_SIZE);
	return (0);
}

static int  ft_gnl_postcheck(char *buf, char *data, char **line)
{
	char        *cursor;
	char        *tmp;
	size_t      len;

	cursor = ft_strchr(buf, '\n');
	if (0 != cursor)
		*cursor++ = 0;
	tmp = *line;
	len = ft_strlen(*line);
	*line = (char *)malloc(len + ft_strlen(buf) + 1);
	ft_strcpy(*line, tmp);
	ft_strcpy(*line + len, buf);
	ft_strdel(&tmp);
	if (0 != cursor)
	{
		ft_strcpy(data, cursor);
		return (1);
	}
	return (0);
}

int         get_next_line(int const fd, char **line)
{
	static char	data[BUFF_SIZE + 1];
	char        buf[BUFF_SIZE + 1];
	int         r;

	if (0 == line || 0 > fd)
		return (-1);
	r = ft_gnl_precheck(data, line);
	if (0 == r)
	{
		while (0 != (r = read(fd, buf, BUFF_SIZE)))
		{
			if (0 > r)
				return (-1);
			buf[r] = 0;
			r = ft_gnl_postcheck(buf, data, line);
			if (0 != r)
				return (r);
		}
		r = (0 != **line);
	}
	return (r);
}
