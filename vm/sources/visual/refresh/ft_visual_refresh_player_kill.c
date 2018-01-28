/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_visual_refresh_player_kill.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez <igomez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2018/01/28 23:03:16 by igomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_process.h"
#include "ft_visual.h"
#include "ft_vm.h"
#include <unistd.h>

static char const	*g_player_state[] =
{
	"   __       ",
	"  /_/\\/\\    ",
	"  \\_\\  /    ",
	"  /_/  \\    ",
	"  \\_\\/\\ \\   ",
	"     \\_\\/   ",
    "    dead    "
};

void	ft_visual_refresh_player_kill(t_visual_player const *this, t_process const *process)
{
	WINDOW	*win;
	size_t	i;

	i = 0;
	win = this->win[process->number - 1];
    wattron(win, COLOR_PAIR(3) | A_BOLD);
    while (i < sizeof(g_player_state) / sizeof(g_player_state[0]))
    {
    	mvwprintw(win, 1 + i, 60, "%s", g_player_state[i]);
    	++i;
    }
    wattroff(win, COLOR_PAIR(3) | A_BOLD);
    wrefresh(win);
}
