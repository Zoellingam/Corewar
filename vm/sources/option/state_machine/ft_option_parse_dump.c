/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_option_parse_dump.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez <igomez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2018/01/24 00:27:40 by igomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "option/ft_option_state_machine.h"
#include "option/ft_option_parse.h"
#include "ft_option.h"

void		ft_option_parse_dump(t_option *this, t_option_parser *parser)
{
	/* Setup lvalue for 'ft_option_parse_number' */
	parser->next_arg = &this->dump;
	/* Setup rvalue for 'ft_option_parse_number' */
	if ('=' == (*parser->argv)[5])
		*parser->argv += 6;
	else
	{
		--parser->argc;
		++parser->argv;
	}
	/* Notify the scheduler */
	parser->state = OPT_STATE_NUMBER;
}
