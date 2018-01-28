/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_handle_k.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez <igomez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 11:33:27 by Zoellingam        #+#    #+#             */
/*   Updated: 2018/01/28 15:22:26 by igomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private/ft_pf_impl.h"
#include "ft_string.h"

void	ft_pf_handle_k(t_pf_buf *p, t_printf *pf)
{
	char	buf[30];
	time_t	date;
	char	*s;
	size_t	len;

	date = (time_t)pf->arg.i;
	ctime_r(&date, buf);
	s = ft_strchr(buf, '\n');
	if (0 != *s)
		*s = 0;
	len = ft_strnlen(buf, pf->precision);
	ft_pf_pre_padd(p, len, pf);
	ft_pf_buffer_push(p, buf, len);
	ft_pf_post_padd(p, len, pf);
}
