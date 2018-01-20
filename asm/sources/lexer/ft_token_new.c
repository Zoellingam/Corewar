/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_token_new.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <Zoellingam@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2018/01/20 18:32:10 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_lexer.h"

t_token	*ft_token_new(char const *data, size_t len, int kind, t_location *loc)
{
	t_token	*token;

	token = (t_token *)ft_memalloc(sizeof(t_token));
	token->data = ft_string_ndup(data, len);
	token->kind = kind;
	/* Let the compiler copy the location by itseld */
	token->loc = *loc;
	ft_lexer_relocate(loc, len);
	return (token);
}
