/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_option_parse_stealth.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez <igomez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2018/01/24 13:51:57 by igomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "option/ft_option_state_machine.h"
#include "option/ft_option_parse.h"
#include "ft_option.h"

void		ft_option_parse_stealth(t_option *this, t_option_parser *parser)
{
	/* setup stealth mode */
	this->stealth = 1;
	/* notify the scheduler */
	parser->state = OPT_STATE_DEFAULT;
	/* skip argument */
	++parser->argv;
	--parser->argc;
}
