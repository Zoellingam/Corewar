/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_option_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez <igomez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2018/01/24 00:28:26 by igomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "option/ft_option_parse.h"
#include "ft_option.h"

void	ft_option_init(t_option *this, int argc, char **argv)
{
	/* Parse options */
	ft_option_parse(this, argc - 1, argv + 1);
	/* Generate champion's number */
	ft_option_attribute_number(this);
}
