/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer_del.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <Zoellingam@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2018/01/20 18:31:48 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_lexer.h"
# include "libft.h"

void	ft_lexer_del(t_lexer *lexer)
{
	size_t	i;

	/* Delete the file array */
	i = 0;
	while (0 != lexer->loc.tab[i])
	{
		ft_strdel(&lexer->loc.tab[i]);
		++i;
	}
	ft_strdel((char **)&lexer->loc.tab);
	/* Delete each tokens */
	ft_list_apply(&lexer->token_head, &ft_token_del);
}
