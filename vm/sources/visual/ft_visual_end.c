/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_visual_end.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez <igomez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2018/01/28 22:43:08 by igomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_visual.h"
#include <ncurses.h>

void	ft_visual_end(t_visual *this)
{
	size_t	i;

  	nocbreak();
	curs_set(1);
  	echo();
  	i = 0;
  	while (i < 4)
  	{
  		if (0 != this->player.win[i])
  			delwin(this->player.win[i]);
  		++i;
  	}
  	delwin(this->footer.win);
  	delwin(this->header.win);
  	delwin(this->board.win);
	endwin();
}
