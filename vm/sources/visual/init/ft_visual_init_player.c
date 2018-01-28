/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_visual_init_player.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez <igomez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2018/01/28 23:27:33 by igomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual/ft_visual_player.h"
#include "ft_process.h"
#include "ft_vm.h"

static char const	*g_player_state[] =
{
	",d88b.d88b,",
  	"88888888888",
 	"`Y8888888Y'",
    "  `Y888Y'  ",
    "    `Y'    ",
    "   alive   "
};


static void ft_visual_init_player_state(WINDOW *win)
{
    size_t  i;

    wattron(win, COLOR_PAIR(1) | A_BOLD);
    i = 0;
    while (i < sizeof(g_player_state) / sizeof(g_player_state[0]))
    {
        mvwprintw(win, 2 + i, 60, "%s", g_player_state[i]);
        ++i;
    }
    wattroff(win, COLOR_PAIR(1) | A_BOLD);
}

void        ft_visual_init_player(t_visual_player *this, t_vm const *vm)
{
    WINDOW      *win;
	t_list		*it;
	t_process	*p;

    /* Init players boxes */
    it = vm->process_head.next;
    while (it != &vm->process_head)
    {
    	p = C_PROCESS(it);
    	this->win[p->parent_number - 1] = newwin(10, 85, 12 + 11 * p->parent_number, 200);
        win = this->win[p->parent_number - 1];
	    box(win, '|', '-');
    	wattron(win, COLOR_PAIR(0) | A_BOLD);
    	mvwprintw(win, 2, 7, "Player %d", p->parent_number);
    	wattroff(win, COLOR_PAIR(0) | A_BOLD);
    	wattron(win, COLOR_PAIR(p->parent_number) | A_BOLD);
    	mvwprintw(win, 2, 17, "%s", vm->option.champion[p->parent_number - 1]->header.prog_name);
    	wattroff(win, COLOR_PAIR(p->parent_number) | A_BOLD);
        ft_visual_init_player_state(win);
    	wrefresh(win);
        it = it->next;
    }
}
