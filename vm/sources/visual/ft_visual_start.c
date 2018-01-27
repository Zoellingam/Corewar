/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_visual_start.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez <igomez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2018/01/27 22:06:43 by igomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_process.h"
#include "ft_visual.h"
#include "ft_vm.h"
#include "libft.h"
#include "ft_vm.h"
#include <ncurses.h>
#include <unistd.h>
#include <signal.h>
#include <sys/ioctl.h>

static int	ft_visual_window_checker(void)
{
	struct winsize	win;

	if (0 > ioctl(0, TIOCGWINSZ, (void *)&win))
		ft_printf("Error: Can't access to window informations\n");
	else if (win.ws_row < 50 || win.ws_col < 200)
		ft_printf("Error: The window is too small: %d/200 %d/50\n", win.ws_col, win.ws_row);
	else
		return (1);
	return (0);
}

void		ft_visual_start(t_visual *this)
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
    this->win = newwin(66, 195, 0, 0);
    box(this->win, '|', '-');
}
