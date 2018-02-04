/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_option_parse.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez <igomez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2018/02/04 14:27:59 by igomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_OPTION_PARSE_H
# define FT_OPTION_PARSE_H

# include <stddef.h>

typedef struct		s_option_parser
{
	int				state;
	int				*next_arg;
	int				argc;
	char			**argv;
}					t_option_parser;

typedef struct		s_option_map
{
	char			*opt;
	size_t			len;
	int				state;
}					t_option_map;

struct s_option;

void				ft_option_parse(struct s_option *this, int argc, char **argv);

void				ft_option_attribute_number(struct s_option *this);

#endif
