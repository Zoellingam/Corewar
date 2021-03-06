/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lex_word.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <Zoellingam@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2018/01/20 21:50:22 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lexer.h"
#include "ft_ctype.h"
#include "ft_printf.h"

extern t_op		g_op_tab[17];

static t_token	*ft_lex_word_get_match(t_location *loc)
{
	t_token		*token;
	size_t		len_save;
	size_t		idx_save;
	size_t		len;
	size_t		i;

	/* first loop, compare every instruction name length, and get this longest one.
		It avoid the case of matching "st" instead of "sti". */
	i = 1;
	token = 0;
	len_save = 0;
	while (i < sizeof(g_op_tab) / sizeof(0[g_op_tab]))
	{
		/* Get the len of the expected instruction.
		   We can now compare up to len with the pc */
		len = ft_strlen(g_op_tab[i].name);
		/* If we match an instruction, and if the len is
		   weither lower or unset */
		if (0 == ft_strncmp(g_op_tab[i].name, loc->pc, len)
			&& (-1 == (int)idx_save || len_save < len))
		{
			/* save instruction name length and index */
			len_save = len;
			idx_save = i;
		}
		++i;
	}

	/* Length is not 0, we matched at least one instruction name,
	   otherwise, the token is not created and the null pointer is returned */
	if (0 != len_save)
	{
		token = ft_token_new(g_op_tab[idx_save].name, len_save, TK_INSTRUCTION, loc);
		token->param_op = (int)idx_save;
	}
	return (token);
}

t_token		*ft_lex_word(t_location *loc)
{
	/* '\n' is a strict 'word' token */
	if ('\n' == loc->pc[0])
		return (ft_token_new(loc->pc, 1, TK_ENDLINE, loc));
	/* ',' is a strict 'word' parameter aswell. We do not
	    skip it since this is used in the parser analysis. */
	if (SEPARATOR_CHAR == loc->pc[0])
		return (ft_token_new(loc->pc, 1, TK_SEPARATOR, loc));
	/* Iterate over every instruction defined in op.h
	   search for the longest match to return */
	return (ft_lex_word_get_match(loc));
}
