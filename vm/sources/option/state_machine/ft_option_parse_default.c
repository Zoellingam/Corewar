/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_option_parse_default.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez <igomez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2018/01/24 13:54:14 by igomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "option/ft_option_state_machine.h"
#include "option/ft_option_parse.h"
#include "ft_option.h"
#include "libft.h"

static const t_option_map	g_option_map[] =
{
	{ "-process-limit", 14, OPT_STATE_PROCESS_LIMIT },
	{ "-round-limit", 12, OPT_STATE_ROUND_LIMIT },
	{ "-start-cycle", 12, OPT_STATE_START_CYCLE },
	{ "-stealth", 8, OPT_STATE_STEALTH },
	{ "-display", 8, OPT_STATE_DISPLAY },
	{ "-dump", 5, OPT_STATE_DUMP },
	{ "-v", 2, OPT_STATE_DISPLAY },
	{ "-s", 2, OPT_STATE_S },
	{ "-n", 2, OPT_STATE_N },
	{ "-a", 2, OPT_STATE_A }
};

void	ft_option_parse_default(t_option *this, t_option_parser *parser)
{
	size_t	i;

	/* State scheduler. Parse args and setup state for the next call */
	i = 0;
	while (i < sizeof(g_option_map) / sizeof(g_option_map[0]))
	{
		if (0 == ft_strncmp(*parser->argv, g_option_map[i].opt, g_option_map[i].len))
		{
			parser->state = g_option_map[i].state;
			return ;
		}
		++i;
	}
	parser->state = OPT_STATE_CHAMPION;
	(void)this;
}
