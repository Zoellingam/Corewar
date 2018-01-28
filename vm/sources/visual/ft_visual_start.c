/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_visual_start.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez <igomez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2018/01/28 15:13:35 by igomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_process.h"
#include "ft_visual.h"
#include "ft_vm.h"
#include "libft.h"
#include "ft_vm.h"
#include <ncurses.h>
#include <curses.h>
#include <unistd.h>
#include <signal.h>
#include <locale.h>
#include <sys/ioctl.h>

static char const	*g_header[] =
{
	" ::::::::   ::::::::  :::::::::  :::::::::: :::       :::     :::     :::::::::  ",
	":+:    :+: :+:    :+: :+:    :+: :+:        :+:       :+:   :+: :+:   :+:    :+: ",
	"+:+        +:+    +:+ +:+    +:+ +:+        +:+       +:+  +:+   +:+  +:+    +:+ ",
	"+#+        +#+    +:+ +#++:++#:  +#++:++#   +#+  +:+  +#+ +#++:++#++: +#++:++#:  ",
	"+#+        +#+    +#+ +#+    +#+ +#+        +#+ +#+#+ +#+ +#+     +#+ +#+    +#+ ",
	"#+#    #+# #+#    #+# #+#    #+# #+#         #+#+# #+#+#  #+#     #+# #+#    #+# ",
	" ########   ########  ###    ### ##########   ###   ###   ###     ### ###    ### ",
	"---------------------------------------------------------------------------------"
};

static int	ft_visual_window_checker(void)
{
	static int const	x = 70;
	static int const	y = 285;
	struct winsize		win;

	if (0 > ioctl(0, TIOCGWINSZ, (void *)&win))
		ft_printf("Error: Can't access to window informations\n");
	else if (win.ws_row < x || win.ws_col < y)
		ft_printf("Error: The window is too small: %d/%d %d/%d\n",
			win.ws_col, win.ws_row, y, x);
	else
		return (1);
	return (0);
}

static void	ft_visual_start_init_windows(t_vm *vm)
{
	size_t		i;
	t_list		*it;
	t_process	*p;

	/* Create arena box */
    vm->visual.win = newwin(66, 195, 0, 0);
    box(vm->visual.win, '|', '-');
    /* Create game data box */
    vm->visual.win_info = newwin(17, 85, 0, 200);
    box(vm->visual.win_info, '|', '-');
    /* Write corewar header */
    i = 0;
    while (i < sizeof(g_header) / sizeof(g_header[0]))
    {
    	wattron(vm->visual.win_info, COLOR_PAIR(0) | A_BOLD);
    	mvwprintw(vm->visual.win_info, 1 + i, 2, g_header[i]);
    	wattroff(vm->visual.win_info, COLOR_PAIR(0) | A_BOLD);
    	++i;
    }
    /* Init players boxes */
    it = vm->process_head.next;
    while (it != &vm->process_head)
    {
    	p = C_PROCESS(it);
    	vm->visual.win_player[p->parent_number] = newwin(10, 85, 12 + 11 * p->parent_number, 200);
	    box(vm->visual.win_player[p->parent_number], '|', '-');
    	wattron(vm->visual.win_player[p->parent_number], COLOR_PAIR(0) | A_BOLD);
    	mvwprintw(vm->visual.win_player[p->parent_number], 2, 2, "Player %d", p->parent_number);
    	wattroff(vm->visual.win_player[p->parent_number], COLOR_PAIR(0) | A_BOLD);
    	wattron(vm->visual.win_player[p->parent_number], COLOR_PAIR(p->parent_number) | A_BOLD);
    	mvwprintw(vm->visual.win_player[p->parent_number], 2, 12, "%s", vm->option.champion[p->parent_number - 1]->header.prog_name);
    	wattroff(vm->visual.win_player[p->parent_number], COLOR_PAIR(p->parent_number) | A_BOLD);
    	wrefresh(vm->visual.win_player[p->parent_number]);
    	it = it->next;
    }
}

void		ft_visual_start(t_vm *vm)
{
	while (!ft_visual_window_checker())
		usleep(500000);
	initscr();
	noecho();
	cbreak();
	curs_set(0);
	start_color();
    init_pair(0, COLOR_BLACK, COLOR_BLACK);
	init_pair(1, COLOR_GREEN, COLOR_BLACK);
    init_pair(2, COLOR_BLUE, COLOR_BLACK);
    init_pair(3, COLOR_RED, COLOR_BLACK);
    init_pair(4, COLOR_CYAN, COLOR_BLACK);
	init_pair(1 + MAX_PLAYERS, COLOR_BLACK, COLOR_GREEN);
    init_pair(2 + MAX_PLAYERS, COLOR_BLACK, COLOR_BLUE);
    init_pair(3 + MAX_PLAYERS, COLOR_BLACK, COLOR_RED);
    init_pair(4 + MAX_PLAYERS, COLOR_BLACK, COLOR_CYAN);
    ft_visual_start_init_windows(vm);
    vm->visual.refresh = 20000;
}
