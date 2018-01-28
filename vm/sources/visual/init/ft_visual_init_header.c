/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_visual_init_header.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez <igomez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2018/01/28 23:27:42 by igomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual/ft_visual_header.h"

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

void		ft_visual_init_header(t_visual_header *this)
{
    size_t  i;

    /* Create header box */
    this->win = newwin(19, 85, 0, 200);
    box(this->win, '|', '-');
    /* Write corewar header */
    i = 0;
    while (i < sizeof(g_header) / sizeof(g_header[0]))
    {
    	wattron(this->win, COLOR_PAIR(0) | A_BOLD);
    	mvwprintw(this->win, 1 + i, 2, g_header[i]);
    	wattroff(this->win, COLOR_PAIR(0) | A_BOLD);
    	++i;
    }
    this->refresh = 20000;
    wrefresh(this->win);
}
