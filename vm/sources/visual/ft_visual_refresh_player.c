/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_visual_refresh_player.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez <igomez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2018/01/28 15:43:54 by igomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_process.h"
#include "ft_visual.h"
#include "ft_vm.h"
#include <unistd.h>

void		ft_visual_refresh_player(t_visual const *this, t_process const *process)
{
	WINDOW	*win;

	win = this->win_player[process->parent_number - 1];
	wattron(win, COLOR_PAIR(0) | A_BOLD);
	mvwprintw(win, 4, 7, "Live per round: %d", process->live_per_round);
	mvwprintw(win, 6, 7, "Last cycle: %d", process->last_live_cycle);
	wattroff(win, COLOR_PAIR(0) | A_BOLD);
    wrefresh(win);
}
