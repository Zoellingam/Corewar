/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_option_attribute_number.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez <igomez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2018/01/24 00:29:44 by igomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "option/ft_option_state_machine.h"
#include "option/ft_option_parse.h"
#include "option/ft_option_usage.h"
#include "ft_option.h"
#include "libft.h"
#include "op.h"

static int	ft_option_attribute_number_exist(t_option *this, int number)
{
	size_t	i;

	if (number <= MAX_PLAYERS)
	{
		i = 0;
		while (i < this->ch_count)
		{
			if (number == this->ch_opt[i].n)
				return (1);
			++i;
		}
	}
	return (0);
}

void		ft_option_attribute_number(t_option *this)
{
	size_t	i;
	int		champion_number;

	i = 0;
	while (i < this->ch_count)
	{
		if (0 == this->ch_opt[i].n)
		{
			/* Setup champion number as positive value */
			champion_number = 1;
			while (ft_option_attribute_number_exist(this, champion_number))
				++champion_number;
			this->ch_opt[i].n = champion_number;
		}
		/* Create quick reference to be used in linear time */
		this->champion[this->ch_opt[i].n - 1] = &this->ch_opt[i];
		++i;
	}
}
