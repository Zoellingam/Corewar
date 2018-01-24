/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_option_parse_number.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez <igomez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2018/01/24 00:27:31 by igomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "option/ft_option_state_machine.h"
#include "option/ft_option_parse.h"
#include "option/ft_option_usage.h"
#include "ft_option.h"
#include "libft.h"

void		ft_option_parse_number(t_option *this, t_option_parser *parser)
{
	char	*p;

	p = *parser->argv;
	/* Extect digits! */
	if (0 == ft_isdigit(*p))
		ft_option_usage("Number is expected: \"%s\"\n", p);
	/* Fast atoi, regardless of sign or overflow */
	*parser->next_arg = 0;
	while (0 != ft_isdigit(*p))
		*parser->next_arg = *parser->next_arg * 10 + *p++ - '0';
	/* set back state to DEFAULT */
	parser->state = OPT_STATE_DEFAULT;
	/* Skip argument */
	++parser->argv;
	--parser->argc;
	(void)this;
}
