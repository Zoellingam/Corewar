/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arena_set_int32.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <Zoellingam@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 11:33:27 by Zoellingam        #+#    #+#             */
/*   Updated: 2018/01/16 22:56:50 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_arena.h"
#include "endian.h"
#include "ft_printf.h"

void	ft_arena_set_int32(uint8_t *arena, int32_t pc, int32_t data)
{
	uint8_t	value[4];

	*(uint32_t *)value = ft_endian_convert_int32(data);
	ft_arena_set_int8(arena, pc + 0, value[0]);
	ft_arena_set_int8(arena, pc + 1, value[1]);
	ft_arena_set_int8(arena, pc + 2, value[2]);
	ft_arena_set_int8(arena, pc + 3, value[3]);
}
