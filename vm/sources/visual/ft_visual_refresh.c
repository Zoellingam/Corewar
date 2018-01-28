/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_visual_refresh.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez <igomez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2018/01/28 15:31:45 by igomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_visual.h"
#include <unistd.h>

static int	ft_visual_refresh_get_color(t_visual const *this, int offset)
{
	if (0 != this->pc_position[offset])
		return (COLOR_PAIR(VISUAL_PC(this->pc_position[offset])));
	return (COLOR_PAIR(this->color[offset]));
}

void		ft_visual_refresh(t_visual const *this, int stealth)
{
	int		i;
	int		color;
	uint8_t	val;

	i = 0;
	while (i < MEM_SIZE)
	{
		color = ft_visual_refresh_get_color(this, i);
		wattron(this->win, color);
		val = (0 == stealth) ? this->arena[i] : 0;
		mvwprintw(this->win, 1 + (i >> 6), 2 + (i & 63) * 3, "%02hhx", val);
		wattroff(this->win, color);
		++i;
	}
	wrefresh(this->win);
/*	usleep(this->refresh);	*/
}
