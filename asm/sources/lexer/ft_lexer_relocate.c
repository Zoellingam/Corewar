/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer_relocate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <Zoellingam@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2018/01/20 18:28:14 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_lexer.h"

void	ft_lexer_relocate(t_location *loc, size_t count)
{
	/* Advance location one by one */
	while (0 != count)
	{
		/* If we found a '\n', update the line cursor, and reset the pos cursor */
		if ('\n' == loc->pc[0])
		{
			++loc->line;
			loc->pos = 1;
		}
		/* Else, update the pos cursor */
		else
			++loc->pos;
		/* Update the pc and lower the count */
		++loc->pc;
		--count;
	}
}
