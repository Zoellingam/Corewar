/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_visual_start.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez <igomez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2018/01/25 00:18:06 by igomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_visual.h"
#include "ft_vm.h"
#include "libft.h"
#include <ncurses.h>
#include <unistd.h>
#include <signal.h>
#include <sys/ioctl.h>

static int	ft_visual_window_checker(void)
{
	struct winsize	win;

	if (0 > ioctl(0, TIOCGWINSZ, (void *)&win))
	{
		ft_printf("Error: Can't access to window informations\n");
		return (0);
	}
	if (win.ws_row < 50 || win.ws_col < 200)
	{
		ft_printf("Error: The window is too small: %d/200 %d/50\n", win.ws_col, win.ws_row);
		return (0);
	}
	return (1);	
}

static void	ft_visual_signal_handler(int signal_number)
{
	while (!ft_visual_window_checker())
		usleep(500000);
	(void)signal_number;
}

void		ft_visual_start(void)
{
	ft_visual_signal_handler(0);
	signal(SIGWINCH, &ft_visual_signal_handler);
	initscr();
	noecho();
	cbreak();
	curs_set(0);
	start_color();
    init_pair(0, COLOR_BLACK, COLOR_BLACK);
	init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_CYAN, COLOR_BLACK);
    init_pair(4, COLOR_BLUE, COLOR_BLACK);
    init_pair(3, COLOR_GREEN, COLOR_BLACK);
	getch();
}
