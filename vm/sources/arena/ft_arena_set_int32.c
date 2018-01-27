/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arena_set_int32.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez <igomez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 11:33:27 by Zoellingam        #+#    #+#             */
/*   Updated: 2018/01/27 19:17:15 by igomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_visual.h"
#include "ft_arena.h"
#include "endian.h"

void	ft_arena_set_int32(t_visual *visual, int32_t pc, int32_t data, int number)
{
	uint8_t	value[4];

	*(uint32_t *)value = ft_endian_convert_int32(data);
	ft_arena_set_int8(visual, pc + 0, value[0], number);
	ft_arena_set_int8(visual, pc + 1, value[1], number);
	ft_arena_set_int8(visual, pc + 2, value[2], number);
	ft_arena_set_int8(visual, pc + 3, value[3], number);
}
