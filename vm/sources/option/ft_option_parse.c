/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_option_parse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez <igomez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2018/01/26 00:23:57 by igomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "option/ft_option_state_machine.h"
#include "option/ft_option_parse.h"
#include "option/ft_option_usage.h"
#include "ft_option.h"
#include "libft.h"
#include "op.h"

static const t_state_machine	g_option_state_machine[] =
{
	[OPT_STATE_DEFAULT] = &ft_option_parse_default,
	[OPT_STATE_A] = &ft_option_parse_a,
	[OPT_STATE_N] = &ft_option_parse_n,
	[OPT_STATE_S] = &ft_option_parse_s,
	[OPT_STATE_DUMP] = &ft_option_parse_dump,
	[OPT_STATE_NUMBER] = &ft_option_parse_number,
	[OPT_STATE_DISPLAY] = &ft_option_parse_display,
	[OPT_STATE_STEALTH] = &ft_option_parse_stealth,
	[OPT_STATE_CHAMPION] = &ft_option_parse_champion,
	[OPT_STATE_START_CYCLE] = &ft_option_parse_start_cycle,
	[OPT_STATE_ROUND_LIMIT] = &ft_option_parse_round_limit,
	[OPT_STATE_PROCESS_LIMIT] = &ft_option_parse_process_limit,
};

void	ft_option_parse(t_option *this, int argc, char **argv)
{
	t_option_parser	parser;

	/* Init state machine */
	parser.argc = argc;
	parser.argv = argv;
	parser.next_arg = 0;
	parser.state = OPT_STATE_DEFAULT;
	/* state machine loop */
	while (0 != parser.argc && 0 != parser.argv)
		g_option_state_machine[parser.state](this, &parser);
	/* Check for champions */
	if (0 == this->ch_count)
		ft_option_usage("Error: There is no champion\n");
	/* Check for valide finale state */
	else if (OPT_STATE_DEFAULT != parser.state)
		ft_option_usage("Error: Arguments are invalide\n");
}
