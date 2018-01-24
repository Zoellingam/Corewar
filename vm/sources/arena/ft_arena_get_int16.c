/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arena_get_int16.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <Zoellingam@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 11:33:27 by Zoellingam        #+#    #+#             */
/*   Updated: 2018/01/16 22:48:15 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_arena.h"
#include "endian.h"
#include "ft_printf.h"

int16_t	ft_arena_get_int16(uint8_t *arena, int32_t pc)
{
	int8_t	value[2];

	value[0] = ft_arena_get_int8(arena, pc + 0);
	value[1] = ft_arena_get_int8(arena, pc + 1);
	return (ft_endian_convert_int16(*(int16_t *)value));
}
