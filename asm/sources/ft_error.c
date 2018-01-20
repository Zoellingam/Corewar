/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <Zoellingam@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2018/01/20 22:00:36 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_lexer.h"
# include "ft_printf.h"
# include "ft_ctype.h"
# include <unistd.h>
# include <stdarg.h>
# include <string.h>

static void	ft_print_line(char const *line, t_string *data)
{
	char	line1[1024];
	char	line2[1024];
	char	*p1;
	char	*p2;
	char	*tmp;

	p1 = line1;
	p2 = line2;
	while (0 != ft_strncmp(line, data->str, data->len))
	{
		*p1++ = *line;
		*p2++ = (0 == ft_isspace(*line)) ? ' ' : *line;
		++line;
	}
	p1 = ft_stpcpy(p1, "\033[31;1m");
	p2 = ft_stpcpy(p2, "\033[32;1m^");
	tmp = data->str;
	while (0 != *tmp)
	{
		*p1++ = *tmp++;
		*p2++ = '~';
	}
	p1 = ft_stpcpy(p1, "\033[0m");
	p2 = ft_stpcpy(p2, "\033[0m");
	ft_fprintf(ft_stderr, "%s\n%s\n", line1, line2);
}

int			ft_error(t_location *loc, t_token *token, char const *format, ...)
{
	char	tmp[4096];
	va_list	ap;
	int		n;

	++loc->error;
	va_start(ap, format);
	n = ft_vsprintf(tmp, format, ap);
	if ('\n' == tmp[n - 1])
		tmp[n - 1] = 0;
	va_end(ap);
	if (0 == token)
	{
		ft_fprintf(ft_stderr, "%s\n", tmp);
		return (0);
	}
	ft_fprintf(ft_stderr, "{bold:%s:%d:%d:} {bred:error:} {bold:\"%s\" %s}\n",
		token->loc.file,
		token->loc.line,
		token->loc.pos,
		token->data->str,
		tmp);
	ft_print_line(loc->tab[token->loc.line - 1], token->data);
	return (0);
}
