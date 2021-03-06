/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arena_set_int8.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez <igomez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 11:33:27 by Zoellingam        #+#    #+#             */
/*   Updated: 2018/01/28 22:48:07 by igomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_visual.h"
#include "ft_arena.h"

void	ft_arena_set_int8(t_visual *visual, int32_t pc, int8_t val, int number)
{
	visual->board.arena[LOOP(pc)] = val;
	visual->board.color[LOOP(pc)] = number;
}
