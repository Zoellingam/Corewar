/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_visual.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez <igomez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2018/01/27 22:03:24 by igomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VISUAL_H
# define FT_VISUAL_H

# include <stdint.h>
# include <ncurses.h>
# include "op.h"

# define VISUAL_PC(x)	((x) + MAX_PLAYERS)

typedef struct			s_visual
{
	WINDOW				*win;
	uint8_t				arena[MEM_SIZE];
	uint8_t				color[MEM_SIZE];
	uint8_t				pc_position[MEM_SIZE];
}						t_visual;

void					ft_visual_start(t_visual *this);

void					ft_visual_refresh(t_visual const *this, int stealth);

void					ft_visual_end(t_visual *this);

#endif
