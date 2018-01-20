/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <Zoellingam@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2018/01/20 18:30:24 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_lexer.h"

static int	ft_lexer_init_split(int const c)
{
	/* Split the file with '\n' separator. If this character is not used in
	   the header name or in the header comment, this should do the trick */
	return ('\n' == c);
}

void		ft_lexer_init(t_lexer *lexer, char const *file, char const *content)
{
	ft_memset(&lexer->loc, 0, sizeof(lexer->loc));
	/* Get the file splitted, each line stored in a separated char* */
	lexer->loc.tab = ft_strsplit(content, &ft_lexer_init_split);
	INIT_LIST_HEAD(lexer->token_head);
	/* Pc start on start of file content */
	lexer->loc.pc = content;
	lexer->loc.file = file;
}
