/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer_read.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <Zoellingam@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2018/01/20 18:27:00 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"
# include "ft_lexer.h"
# include "ft_ctype.h"
# include "ft_string.h"

static int	ft_lexer_skip(t_location *loc)
{
	/* Skip every space, but no endline */
	if (0 != ft_isspace(loc->pc[0]) && '\n' != loc->pc[0])
	{
		/* Advance lexer by 1 char */
		ft_lexer_relocate(loc, 1);
		/* Advance lexer by one char as long as we pars that space */
		while (0 != ft_isspace(loc->pc[0]) && '\n' != loc->pc[0])
			ft_lexer_relocate(loc, 1);
		/* Return true since we parsed at least one space */
		return (1);
	}
	/* Comment, skip everything untile endline; */
	if (COMMENT_CHAR == loc->pc[0] || ';' == loc->pc[0])
	{
		/* Advance lexer by 1 char */
		ft_lexer_relocate(loc, 1);
		/* Skip everything untile endline */
		while (0 != loc->pc[0] && '\n' != loc->pc[0])
			ft_lexer_relocate(loc, 1);
		return (1);
	}
	/* Return false: we matched no space nor comment */
	return (0);
}

static const	t_lex_rule	g_lex_rule[] =
{
	&ft_lex_header, 
	&ft_lex_label,
	&ft_lex_word,
	&ft_lex_reg,
	&ft_lex_dir,
	&ft_lex_ind
};

t_token		*ft_lexer_read(t_lexer *lexer)
{
	t_token		*p;
	size_t		i;

	/* Keep skipping every known pattern */
	while (0 != ft_lexer_skip(&lexer->loc))
		continue ;
	/* Try every lexing rules functions */
	i = 0;
	while (i < sizeof(g_lex_rule) / sizeof(g_lex_rule[0]))
	{
		/* Try every rules from g_lex_rule. Add to the lexer list
		   the first token that succeeded */
		p = g_lex_rule[i](&lexer->loc);
		if (0 != p)
		{
			ft_list_add_tail(&p->list, &lexer->token_head);
			return (p);
		}
		++i;
	}
	return (0);
}
