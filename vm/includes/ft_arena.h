/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arena.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez <igomez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2018/01/24 01:25:29 by igomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ARENA_H
# define FT_ARENA_H

# include <stdint.h>
# include "op.h"

# define LOOP(x)	(((x) % MEM_SIZE) + (((x) < 0) ? MEM_SIZE : 0))

int8_t	ft_arena_get_int8(uint8_t *arena, int32_t pc);
void	ft_arena_set_int8(uint8_t *arena, int32_t pc, int8_t val);

int16_t	ft_arena_get_int16(uint8_t *arena, int32_t pc);

int32_t	ft_arena_get_int32(uint8_t *arena, int32_t pc);
void	ft_arena_set_int32(uint8_t *arena, int32_t pc, int32_t val);

#endif
