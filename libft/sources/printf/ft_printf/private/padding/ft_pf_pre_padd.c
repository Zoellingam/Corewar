/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_pre_padd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <Zoellingam@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/27 02:35:02 by Zoellingam        #+#    #+#             */
/*   Updated: 2018/01/20 22:12:50 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private/ft_pf_impl.h"

void	ft_pf_pre_padd(t_pf_buf *p, size_t n, t_printf *pf)
{
	int32_t		c;
	int32_t		len;

	if (~pf->flags & PF_FLAG_MINUS)
	{
		c = (PF_FLAG_ZERO & pf->flags) ? '0' : ' ';
		len = (int32_t)n;
		while (len < pf->width)
		{
			ft_pf_buffer_add(p, c);
			--pf->width;
		}
	}
}
