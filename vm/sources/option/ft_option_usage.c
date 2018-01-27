/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_option_usage.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez <igomez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2018/01/25 23:36:16 by igomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "option/ft_option_usage.h"
#include "libft.h"
#include <stdlib.h>
#include <unistd.h>

static char const	*g_subject_usage[] =
{
	"\nUsage: corewar <options> champion.cor [...]",
	"### CONTESTANT ######################################################",
	"your_champion.cor: Champion compiled with the asm",
	"-n N:              Set champion number for the next champion",
	"### LIMIT ###########################################################",
    "-process-limit N:  Use a pool of maximum N processes",
    "-round-limit N:    Play maximum of N rounds",
    "-start-cycle N:    Start battle when cycle counter reach this limit",
	"### DUMP ############################################################",
    "-stealth:          Hides the real content of the memory",
	"-dump N:           Dumps memory after N cycles then exits",
    "-s N:              Runs N cycles, dumps memory, pauses, then repeats",
	"-a:                Prints output from \"aff\" (Default is to hide it)",
	"### TEXT OUTPUT MODE ################################################",
    "-display:          0:  Show only essentials",
    "-v:                1:  Show lives",
    "                   2:  Show cycles",
    "                   4:  Show operations",
    "                   8:  Show deaths",
    "                   16: Show PC movements (Except for jumps)",
    "                   32: Display ncurses mode",
	"#####################################################################"
};

void				ft_option_usage(char const *error, ...)
{
	char	buf[4096];
	int		len;
	va_list	ap;
	size_t	i;

	/* Print the user message if any */
	if (0 != error)
	{
		va_start(ap, error);
		len = ft_vsprintf(buf, error, ap);
		va_end(ap);
		write(ft_stderr, buf, len);
	}
	/* Print usage */
	i = 0;
	while (i < sizeof(g_subject_usage) / sizeof(g_subject_usage[0]))
	{
		ft_fprintf(ft_stderr, "%s\n", g_subject_usage[i]);
		++i;
	}
	exit(-1);
}
