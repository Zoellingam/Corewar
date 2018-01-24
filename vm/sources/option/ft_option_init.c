/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_option_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez <igomez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2018/01/24 11:59:48 by igomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "option/ft_option_parse.h"
#include "ft_option.h"

static void	ft_option_init_setup_counters(t_option *this)
{
	this->s = -1;
	this->dump = -1;
	this->round_limit = -1;
	this->process_limit = -1;
}

void		ft_option_init(t_option *this, int argc, char **argv)
{
	/* Init values */
	ft_option_init_setup_counters(this);
	/* Parse options */
	ft_option_parse(this, argc - 1, argv + 1);
	/* Generate champion's number */
	ft_option_attribute_number(this);
}
