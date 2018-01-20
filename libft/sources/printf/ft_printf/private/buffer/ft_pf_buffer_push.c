/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_buffer_push.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <Zoellingam@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 11:33:27 by Zoellingam        #+#    #+#             */
/*   Updated: 2018/01/20 22:05:21 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private/ft_pf_impl.h"
#include "ft_string.h"
#include <stdlib.h>
#include <stdint.h>
#include <errno.h>

static void	ft_pf_buffer(t_pf_buf *p, char const *data, size_t size)
{
	extern int	errno;

	if (0 < p->limit)
	{
		if (p->limit >= size)
		{
			if (0 != p->buffer)
				ft_strncpy(p->buffer + p->nb, data, size);
			p->nb += size;
			p->limit -= size;
		}
		else
		{
			if (0 != p->buffer)
				ft_strncpy(p->buffer + p->nb, data, p->limit);
			p->nb += p->limit;
			p->limit = 0;
		}
	}
	else
		errno = ENOMEM;
}

static void	ft_pf_buffer_alloc(t_pf_buf *p, char const *data, size_t size)
{
	size_t	capacity;

	/* Next power of two of p->nb+size */
	capacity = 1;
	while (capacity < p->nb + size)
		capacity <<= 1;
	if (p->alloc_capacity < capacity)
	{
		p->alloc_capacity = capacity;
		p->buffer = (char *)realloc(p->buffer, p->alloc_capacity * sizeof(char));
	}
	ft_strncpy(p->buffer + p->nb, data, size);
	p->nb += size;
	p->limit -= size;
}

void		ft_pf_buffer_push(t_pf_buf *p, char const *data, size_t size)
{

	if (p->buffer_malloc == PF_ALLOC_ON)
		ft_pf_buffer_alloc(p, data, size);
	else
		ft_pf_buffer(p, data, size);
}

